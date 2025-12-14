# Rimia — Rimu's Dynamic Array

What do you expect?

How to use:

```c
DEFINE_DA(int, MyInt);

int main() {
    MyInt arr = MyInt_init();
    arr.push(&arr, 67);
    printf("-> %d\n", arr.data[0]);
    arr.pop(&arr);
    arr.free();
    return 0;
}
```

What is exposed:

1. `.push()`
2. `.pop()`
3. `.free()`
4. `.init()`
5. `.data`
6. `.count`
7. `.capacity`

Additional exposure (with rimia.h):

1. (macros) `not`, `or`, `and`, `true`, `false`
2. (macros) `elif`, `frange(end)`, `for_range(end)`, `fsrange(start, end)`, `for_srange(start, end)`, `fssrange(start, end, step)`, `for_ssrange(start, end, step)`, `fstrange(end, step)`, `for_steprange(end, step)`, `for_loop(var, end)`, `forever`, `repeat(turn)`
3. String, str, `STR_FMT` (Macro), `STR_ARGS` (Macro)

Additional exposure (with rimia_err.h):

1. Exceptions (`raise`, `throw`, ...)

