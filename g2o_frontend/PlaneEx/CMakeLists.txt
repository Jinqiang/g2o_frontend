
ADD_EXECUTABLE(
  plane_g2o_application
  plane_g2o.cpp
  extractionUtils.h
)
SET_TARGET_PROPERTIES(plane_g2o_application PROPERTIES OUTPUT_NAME plane_g2o_application)
INCLUDE_DIRECTORIES(plane_g2o_application ${CSPARSE_INCLUDE_DIR} )

TARGET_LINK_LIBRARIES(plane_g2o_application
    ncurses
    sensor_data_library
    ${QT_LIBRARIES}
    ${G2O_TYPES_SLAM2D}
    ${G2O_TYPES_SLAM2D_ADDONS}
    ${G2O_TYPES_SLAM3D}
    ${G2O_TYPES_SLAM3D_ADDONS}
    ${G2O_TYPES_DATA}
    ${G2O_CORE_LIBRARY}
    ${G2O_SOLVER_CSPARSE}
    ${G2O_STUFF_LIBRARY}
    ${G2O_SOLVER_CSPARSE_EXTENSION}
    ${CSPARSE_LIBRARY}
    ${PCL_LIBRARIES}
  )
