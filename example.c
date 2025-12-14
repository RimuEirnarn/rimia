#include <stdio.h>
#include "rimia.h"
#include "rimia_da.h"

DEFINE_DA(int, IntArray);

int main() {
    IntArray arr = IntArray_init();
    arr.push(&arr, 67);
    arr.push(&arr, 69);

    frange(50) {
        arr.push(&arr, i);
    }
    printf("Total: %ld\n", arr.count);

    foreach_varda(itercount, arr) {
        printf("%zu -> %d\n", itercount, arr.data[itercount]);
    }

    arr.pop(&arr);
}
