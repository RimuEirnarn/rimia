#include <stdio.h>
#include "rimia.h"
#include "rimia_da.h"

DEFINE_DA(int, IntArray);

int main() {
    IntArray arr = IntArray_init();
    arr.push(&arr, 67);
    arr.push(&arr, 69);

    fsrange(0, arr.length) {
        printf("%d -> %d\n", i, arr.data[i]);
    }

    arr.pop(&arr);
    printf("Total: %ld\n", arr.length);
}