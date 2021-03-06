#include <list>
#include <set>
#include "g2o_frontend/boss/serializer.h"
#include "g2o_frontend/boss/deserializer.h"
#include "g2o_frontend/boss_map/reference_frame.h"
#include "g2o_frontend/boss_map/reference_frame_relation.h"
#include "g2o_frontend/boss_map/image_sensor.h"
#include "g2o_frontend/boss_map/laser_sensor.h"
#include "g2o_frontend/boss_map/imu_sensor.h"
#include "g2o_frontend/boss_map/sensor_data_synchronizer.h"
#include "g2o_frontend/boss_map/robot_configuration.h"

using namespace boss_map;
using namespace boss;
using namespace std;

StringSensorMap sensors;
StringReferenceFrameMap  frames;
std::vector<boss::Serializable*> objects;
std::vector<BaseSensorData*> sensorDatas;

const char* banner[]={
  "boss_path_generator: adds the odometry constraint between consecutive frames of  atime-ordered log",
  "",
  "usage: boss_path_generator filein fileout",
  "example: boss_path_generator test_sync.log test_sync_odom.log", 0
};

void printBanner (){
  int c=0;
  while (banner[c]){
    cerr << banner [c] << endl;
    c++;
  }
}


int main(int argc, char** argv) {
  if (argc < 3) {
    printBanner();
    return 0;
  }
  std::string filein = argv[1];
  std::string fileout = argv[2];



  Deserializer des;
  des.setFilePath(filein.c_str());

  Serializer ser;
  ser.setFilePath(fileout.c_str());
  
  cerr <<  "running path generator  with arguments: filein[" << filein << "] fileout: [" << fileout << "]" << endl;

  std::vector<BaseSensorData*> sensorDatas;
  RobotConfiguration* conf = readLog(sensorDatas, des);
  cerr << "# frames: " << conf->frameMap().size() << endl;
  cerr << "# sensors: " << conf->sensorMap().size() << endl;
  cerr << "# sensorDatas: " << sensorDatas.size() << endl;

  conf->serializeInternals(ser);
  ser.writeObject(*conf);

  TSCompare comp;
  std::sort(sensorDatas.begin(), sensorDatas.end(), comp);

  ReferenceFrame* previousReferenceFrame = 0;
  for (size_t i = 0; i< sensorDatas.size(); i++){
    BaseSensorData* data = sensorDatas[i];
    ser.writeObject(*data->robotReferenceFrame());
    ser.writeObject(*data);

    ReferenceFrame* from = previousReferenceFrame;
    ReferenceFrame* to = data->robotReferenceFrame();
    if (from && from!=to) {
      ReferenceFrameRelation* rel = new ReferenceFrameRelation;
      rel->setFromReferenceFrame(from);
      rel->setToReferenceFrame(to);
      rel->setTransform(from->transform().inverse() * to->transform());
      rel->setInformationMatrix(Eigen::Matrix<double, 6,6>::Identity());
      ser.writeObject(*rel);
    }
    previousReferenceFrame = to;
    cerr << 'R';
  }

}

