#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* File(char *file_name) {

    FILE* in;
    in = fopen(file_name, "r");
    if(in == NULL) exit(0);

    char* buffer_in = malloc(256 * sizeof(char));
    fgets(buffer_in, 256, in);
    fclose(in);
    return buffer_in;
}
