# include <stdio.h>
# include <stdlib.h>

int read_int_from_file(const char * path)
{
    FILE *file = fopen(path, "r");
    char buffer[32] = {0};

    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }

    fgets(buffer, sizeof(buffer), file);

    fclose(file);

    return atoi(buffer);
}







