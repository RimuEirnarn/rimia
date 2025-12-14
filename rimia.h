#ifndef RIMIA_IMPL
#define RIMIA_IMPL
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "rimia_err.h"

#define not !
#define or ||
#define and &&
#define true 1
#define false 0

// else if
#define elif else if
// class -> typedef struct
#define class typedef struct
// is value true?
#define iftrue(value) if (value == true)
// generic for loop. Use i to mark as current turn, no start.
#define frange(end) for (int i=0; i <= (end-1); i++)
// generic for loop. Use current to mark as current turn.
#define for_range(end) for (int current=0; current <= (end-1); current++)
// generic for loop. Use i to mark it as current turn.
#define fsrange(start, end) for (int i=start; i <= (end-1); i++)
// generic for loop. Use current to mark it as current turn
/**
 * @brief Generic for-loop range. Verbose version
 * @param start starter, must less than end
 * @param end end? must bigger than start
 */
#define for_srange(start, end) for (int current=start; current <= (end-1); current++)
/**
 * @brief Geneirc for-loop range with step. Use i as current turn.
 * @param start starter, must less than end
 * @param end end, must bigger than start.
 * @param step step, must be a positive integer or it'll be forever loop.
 */
#define fssrange(start, end, step) for (int i=start; i <= (end-1); i+=step)
/**
 * @brief Geneirc for-loop range with step. Verbose version. Use current as current turn
 * @param start starter, must less than end
 * @param end end, must bigger than start.
 * @param step step, must be a positive integer or it'll be forever loop.
 */
#define for_stepsrange(start, end, step) for (int current=start; current <= (end-1); current+=step)
// for loop, end, step.
#define fstrange(end, step) for (int i=0; i <= (end-1); i+=step)
// for loop, end, step.
#define for_steprange(end, step) for (int current=0; current <= (end-1); current+=step)
#define forloop(var, end) for int ((int) ##var=0; ##var <= (end-1); ##var++)

// isn't it a str?
// Simple while (true)
#define forever while (true)
// repeat of (turn) because, why not?
#define repeat(turn) for (int _i___iaefasda = 0; _i___iaefasda <= (turn-1); _i___iaefasda++)

class String {
    char* value;
    int length;
} String;

String str(char* value) {
    String str = { value, strlen(value) };
    return str;
}

#define STR_FMT "%.*s"
#define STR_ARGS(sv) (int) (sv).length, (sv).value

// printf("[%zu]\t-> " STR_FMT "\n", STR_ARGS(str));

void sigsegv_handler(int signal) {
    char fmt[1024];
    sprintf(fmt, "[Code %d] Segmentation fault (core dumped? idk)", signal);
    raise_from("OSError", fmt);
}

#define protect() signal(SIGSEGV, sigsegv_handler)

/*
"%.*s" -> count, string

Message UnknownRori's Channel

*/
#endif
