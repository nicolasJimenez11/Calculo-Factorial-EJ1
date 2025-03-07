#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LENGTH 10

// Estructura para representar a un estudiante
typedef struct {
    char *nombre;   
    char *apellido;      
    unsigned char edad : 7;  
    char id[MAX_ID_LENGTH];  
    float *calificaciones;   
    size_t num_calificaciones;
} Estudiante;

size_t memoria_utilizada = 0;  // Variable global para seguir el uso de memoria

// Función para agregar un nuevo estudiante
void agregar_estudiante(Estudiante **estudiantes, size_t *num_estudiantes, 
                        const char *nombre, const char *apellido, unsigned char edad, 
                        const char *id, float *calificaciones, size_t num_calificaciones) {
    // Asignación de memoria para un nuevo estudiante
    Estudiante *nuevo_estudiante = malloc(sizeof(Estudiante));
    if (!nuevo_estudiante) {
        printf("Error al asignar memoria para el estudiante.\n");
        return;
    }

    // Asignación dinámica de memoria para el nombre, apellido y calificaciones
    nuevo_estudiante->nombre = malloc(strlen(nombre) + 1);
    nuevo_estudiante->apellido = malloc(strlen(apellido) + 1);
    nuevo_estudiante->calificaciones = malloc(sizeof(float) * num_calificaciones);

    if (!nuevo_estudiante->nombre || !nuevo_estudiante->apellido || !nuevo_estudiante->calificaciones) {
        printf("Error al asignar memoria para los datos del estudiante.\n");
        free(nuevo_estudiante);  // Liberamos la memoria ya asignada
        return;
    }

    // Copiar los datos del estudiante
    strcpy(nuevo_estudiante->nombre, nombre);
    strcpy(nuevo_estudiante->apellido, apellido);
    nuevo_estudiante->edad = edad;
    strncpy(nuevo_estudiante->id, id, MAX_ID_LENGTH);
    nuevo_estudiante->num_calificaciones = num_calificaciones;
    memcpy(nuevo_estudiante->calificaciones, calificaciones, sizeof(float) * num_calificaciones);

    // Actualizamos la memoria utilizada
    memoria_utilizada += sizeof(Estudiante) + strlen(nombre) + 1 + strlen(apellido) + 1 + sizeof(float) * num_calificaciones;

    // Agregar el nuevo estudiante al arreglo dinámico
    *estudiantes = realloc(*estudiantes, sizeof(Estudiante) * (*num_estudiantes + 1));
    (*estudiantes)[*num_estudiantes] = *nuevo_estudiante;
    (*num_estudiantes)++;

    printf("Estudiante %s %s agregado correctamente. Memoria utilizada: %zu bytes.\n", nombre, apellido, memoria_utilizada);
}

// Función para actualizar los datos de un estudiante existente
void actualizar_estudiante(Estudiante *estudiantes, size_t num_estudiantes, const char *id, 
                           const char *nuevo_nombre, const char *nuevo_apellido, unsigned char nueva_edad, 
                           float *nuevas_calificaciones, size_t num_nuevas_calificaciones) {
    for (size_t i = 0; i < num_estudiantes; i++) {
        if (strcmp(estudiantes[i].id, id) == 0) {
            // Liberamos la memoria previamente asignada al estudiante
            free(estudiantes[i].nombre);
            free(estudiantes[i].apellido);
            free(estudiantes[i].calificaciones);

            // Asignamos nueva memoria para los datos actualizados
            estudiantes[i].nombre = malloc(strlen(nuevo_nombre) + 1);
            estudiantes[i].apellido = malloc(strlen(nuevo_apellido) + 1);
            estudiantes[i].calificaciones = malloc(sizeof(float) * num_nuevas_calificaciones);

            if (!estudiantes[i].nombre || !estudiantes[i].apellido || !estudiantes[i].calificaciones) {
                printf("Error al asignar memoria para los nuevos datos del estudiante.\n");
                return;
            }

            // Actualizamos los datos del estudiante
            strcpy(estudiantes[i].nombre, nuevo_nombre);
            strcpy(estudiantes[i].apellido, nuevo_apellido);
            estudiantes[i].edad = nueva_edad;
            estudiantes[i].num_calificaciones = num_nuevas_calificaciones;
            memcpy(estudiantes[i].calificaciones, nuevas_calificaciones, sizeof(float) * num_nuevas_calificaciones);

            printf("Estudiante con ID %s actualizado correctamente.\n", id);
            return;
        }
    }
    printf("Estudiante con ID %s no encontrado.\n", id);
}

// Función para eliminar un estudiante por su ID
void eliminar_estudiante(Estudiante **estudiantes, size_t *num_estudiantes, const char *id) {
    for (size_t i = 0; i < *num_estudiantes; i++) {
        if (strcmp((*estudiantes)[i].id, id) == 0) {
            // Reducimos la memoria utilizada antes de liberar
            memoria_utilizada -= sizeof(Estudiante) + strlen((*estudiantes)[i].nombre) + 1 + 
                                 strlen((*estudiantes)[i].apellido) + 1 + 
                                 sizeof(float) * (*estudiantes)[i].num_calificaciones;

            // Liberamos la memoria del estudiante
            free((*estudiantes)[i].nombre);
            free((*estudiantes)[i].apellido);
            free((*estudiantes)[i].calificaciones);

            // Desplazamos los estudiantes restantes en el array
            for (size_t j = i; j < *num_estudiantes - 1; j++) {
                (*estudiantes)[j] = (*estudiantes)[j + 1];
            }

            // Reducimos el tamaño del array dinámico
            *estudiantes = realloc(*estudiantes, sizeof(Estudiante) * (*num_estudiantes - 1));
            (*num_estudiantes)--;

            printf("Estudiante con ID %s eliminado correctamente. Memoria liberada: %zu bytes.\n", id, memoria_utilizada);
            return;
        }
    }
    printf("Estudiante con ID %s no encontrado.\n", id);
}

// Función para mostrar la memoria total utilizada
void mostrar_memoria_utilizada() {
    printf("Memoria total utilizada: %zu bytes\n", memoria_utilizada);
}

int main() {
    Estudiante *estudiantes = NULL;  // Puntero a la lista dinámica de estudiantes
    size_t num_estudiantes = 0;     // Contador de estudiantes

    // Creamos un conjunto de calificaciones para un estudiante
    float calificaciones1[] = {85, 90, 78};
    agregar_estudiante(&estudiantes, &num_estudiantes, "Carlos", "Gomez", 20, "12345678", calificaciones1, 3);
    mostrar_memoria_utilizada();

    // Actualizamos los datos del estudiante
    float nuevas_calificaciones[] = {88, 92, 80};
    actualizar_estudiante(estudiantes, num_estudiantes, "12345678", "Carlos", "Gomez", 21, nuevas_calificaciones, 3);
    mostrar_memoria_utilizada();

    // Eliminamos al estudiante de la lista
    eliminar_estudiante(&estudiantes, &num_estudiantes, "12345678");
    mostrar_memoria_utilizada();

    // Liberamos la memoria antes de terminar el programa
    free(estudiantes);

    return 0;
}
