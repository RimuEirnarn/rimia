#include <stdio.h>
#include "rimia.h"
#include "rimia_da.h"

DEFINE_DA(int, IntArray);

int main() {
    //IntArray arr = IntArray_init();
    DA_INIT(IntArray, arr);
    arr.push(&arr, 67);
    arr.push(&arr, 69);

    frange(50) {
        arr.push(&arr, i);
    }

    printf("Total: %ld\n", arr.count);

    foreach_vida(arr, index, value) {
        printf("%zu -> %d\n", index, value);
    }

    arr.pop(&arr);
    arr.free(&arr);
}
