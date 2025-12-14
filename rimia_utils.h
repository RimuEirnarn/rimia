#ifndef RIMIA_UTILS
#define RIMIA_UTILS

#if defined(_WIN32)
    #define API __delspec(dllexport)
#else
    #define API __attribute__((visibility("default")))
#endif

#endif
