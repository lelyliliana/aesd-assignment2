#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "validate_username.h" // Asegúrate de incluir el encabezado correcto

void test_validate_username() {
    // Caso 1: Nombre de usuario válido
    assert(validate_username("lelyliliana") == true);

    // Caso 2: Nombre de usuario con espacios (inválido)
    assert(validate_username("lely liliana") == false);

    // Caso 3: Nombre de usuario vacío (inválido)
    assert(validate_username("") == false);

    // Caso 4: Nombre de usuario demasiado largo (inválido)
    assert(validate_username("este_nombre_de_usuario_es_muy_largo") == false);

    // Caso 5: Nombre de usuario con caracteres especiales (inválido)
    assert(validate_username("lely@liliana!") == false);
}

int main() {
    // Ejecutar las pruebas
    test_validate_username();

    // Mensaje de éxito si todas las pruebas pasan
    printf("Todas las pruebas pasaron correctamente.\n");

    return 0;
}

