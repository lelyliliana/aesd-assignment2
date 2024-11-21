#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USERNAME_EXPECTED "lelyliliana" 

int main() {
    const char *filename = "conf/username.txt";
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Error: No se pudo abrir el archivo %s\n", filename);
        return 1;
    }

    char username[50]; 
    if (fgets(username, sizeof(username), file) == NULL) {
        fprintf(stderr, "Error: El archivo %s está vacío o no se puede leer\n", filename);
        fclose(file);
        return 1;
    }

    size_t len = strlen(username);
    if (len > 0 && username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }

    if (strcmp(username, USERNAME_EXPECTED) != 0) {
        fprintf(stderr, "Error: El nombre de usuario '%s' no coincide con '%s'\n", username, USERNAME_EXPECTED);
        fclose(file);
        return 1;
    }

    printf("El nombre de usuario '%s' es válido.\n", username);
    fclose(file);
    return 0;
}

