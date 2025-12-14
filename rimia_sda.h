#ifndef RIMIA_DA
#include <stdlib.h>
#include "rimia_err.h"
#include "rimia_utils.h"
#define RIMIA_DA

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
    API inline void NAME##_push(NAME *self, TYPE item) { \
        if (self->capacity == self->count) {\
            self->capacity = self->capacity ? self->capacity * 2 : 4; \
            self->data = realloc(self->data, self->capacity * sizeof(TYPE)); \
        } \
        self->data[self->count++] = item; \
    } \
    API inline TYPE NAME##_pop(NAME *self) { \
        if (self->count == 0) { \
            raise_from("IndexError", "Cannot pop from empty array"); \
        } \
        return self->data[--self->count]; \
    } \
    API inline void NAME##_free(NAME *self) {\
        free(self->data); \
        self->data = NULL; \
        self->count = self->capacity = 0; \
    } \
    API inline NAME NAME##_init() { \
        NAME self = (NAME){}; \
        self.push = NAME##_push; \
        self.pop = NAME##_pop; \
        self.free = NAME##_free; \
        return self; \
    } \

#endif
