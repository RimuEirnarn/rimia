#ifndef RIMIA_DA_H
#include <stdlib.h>
#include "rimia_err.h"
#define RIMIA_DA_H

#define DEFINE_DA(TYPE, NAME) \
    typedef struct NAME NAME; \
    struct NAME { \
        TYPE *data; \
        size_t capacity; \
        size_t count; \
        void (*push)(NAME*, TYPE); \
        TYPE (*pop)(NAME*); \
        void (*free)(NAME*); \
    }; \
    static inline void NAME##_push(NAME *self, TYPE item) { \
        if (self->capacity == self->count) {\
            self->capacity = self->capacity ? self->capacity * 2 : 4; \
            self->data = realloc(self->data, self->capacity * sizeof(TYPE)); \
            TYPE *tmp = realloc(self->data, self->capacity * sizeof(TYPE)); \
            if (!tmp) raise_from("MemoryError", "Realloc failed");\
            self->data = tmp;\
        } \
        self->data[self->count++] = item; \
    } \
    static inline TYPE NAME##_pop(NAME *self) { \
        if (self->count == 0) { \
            raise_from("IndexError", "Cannot pop from empty array"); \
        } \
        return self->data[--self->count]; \
    } \
    static inline void NAME##_free(NAME *self) {\
        free(self->data); \
        self->data = NULL; \
        self->count = self->capacity = 0; \
    } \
    static inline NAME NAME##_init() { \
        NAME self = (NAME){}; \
        self.push = NAME##_push; \
        self.pop = NAME##_pop; \
        self.free = NAME##_free; \
        return self; \
    } \

#define foreach_varda(var, self) for (size_t var = 0; (var) < self.count; ++(var))
#define foreach_da(self) for (size_t i = 0; i < (self).count; i++)

#endif
