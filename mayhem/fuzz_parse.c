#include "mjson.h"
#include <stdint.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    const char *p;
    int n;
    const char *s, *path;
    char as_str[size + 1];
    size_t size1, size2;

    // Create a non-const copy of the fuzzer data and null-terminate it
    memcpy(as_str, data, size);
    as_str[size] = '\0';

    // Split the input data into two strings
    size1 = (3 * size) / 4;
    size2 = size - size1;

    s = (const char *) as_str;
    as_str[size1 - 1] = '\0';
    path = (const char *)(data + size1);


    mjson_find(s, size, path, &p, &n);
    return 0;
}
