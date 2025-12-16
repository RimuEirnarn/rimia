#ifndef RIMIA_DA_H
#include <stdlib.h>
#include "rimia_err.h"
#define RIMIA_DA_H

// Define dynamic array by type to name
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

// Initialize dynamic array so you don't need to pass Type_init().
#define DA_INIT(type, name) type name = type##_init()

// For-loop of the dynamic array. Pass your variable name and the instance.
#define for_varda(var, self) for (size_t var = 0; (var) < self.count; ++(var))
// For-loop of the dynamic array. It uses "i" var. Don't foret to pass the instance.
#define for_da(self) for_varda(i)

// Dynamic Array Foreach. Pass the instance, index name, var name.
#define foreach_vida(self, idx, name) \
    for (size_t (idx) = 0; (idx) < (self).count; (idx)++) \
        for (int _rda_once = 1; _rda_once; _rda_once = 0)\
        for (__typeof__((self).data[(idx)]) (name) = (self).data[(idx)]; _rda_once; _rda_once = 0)

// Dynamic Array Foreach. Only need the instance. Uses "i" and "val".
#define foreach_da(self) foreach_vida(self, i, val)
// Dynamic Array Foreach. Only need the instance and var name. Uses "i".
#define foreach_vda(self, name) foreach_vida(self, i, name)

// Dynamic Array Foreach BY reference. Only need the instance and var name. Uses "_i".
#define foreach_vda_ref(arr, var)\
    for (size_t _i = 0; _i < (arr).count; ++_i)\
        for (int _once = 1; _once; _once = 0)\
            for (__typeof__((self).data[i]) *var = &(arr).data[_i]; _once; _once = 0)

#endif
