#ifndef COLOR_MACROS_H
#define COLOR_MACROS_H

// font attributes
#define FT_BOLD      "\033[1m"
#define FT_UNDERLINE "\033[4m"

//background color
#define BG_BLACK     "\033[40m"
#define BG_RED       "\033[41m"
#define BG_GREEN     "\033[42m"
#define BG_YELLOW    "\033[43m"
#define BG_LIGHTBLUE "\033[44m"
#define BG_MAGENTA   "\033[45m"
#define BG_BLUE      "\033[46m"
#define BG_WHITE     "\033[47m"

// font color
#define CL_BLACK(s)     "\033[30m" << s << "\033[0m"
#define CL_RED(s)       "\033[31m" << s << "\033[0m"
#define CL_GREEN(s)     "\033[32m" << s << "\033[0m"
#define CL_YELLOW(s)    "\033[33m" << s << "\033[0m"
#define CL_LIGHTBLUE(s) "\033[34m" << s << "\033[0m"
#define CL_MAGENTA(s)   "\033[35m" << s << "\033[0m"
#define CL_BLUE(s)      "\033[36m" << s << "\033[0m"
#define CL_WHITE(s)     "\033[37m" << s << "\033[0m"

#define FG_BLACK     "\033[30m"
#define FG_RED       "\033[31m"
#define FG_GREEN     "\033[32m"
#define FG_YELLOW    "\033[33m"
#define FG_LIGHTBLUE "\033[34m"
#define FG_MAGENTA   "\033[35m"
#define FG_BLUE      "\033[36m"
#define FG_WHITE     "\033[37m"

#define FG_NORM      "\033[0m"

#endif
