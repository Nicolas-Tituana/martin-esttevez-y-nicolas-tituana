#include <stdio.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBATORIA 6

int main() {
    char materias[NUM_ASIGNATURAS][20] = {"Matematica", "Historia", "Lengua"};
    int notas[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    int i, j;

    printf("INGRESO DE CALIFICACIONES \n\n");
    for (i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Estudiante %d:\n", i + 1);
        for (j = 0; j < NUM_ASIGNATURAS; j++) {
            int resultado;
            do {
                printf("  Ingrese la nota de %s (0-10): ", materias[j]);
                resultado = scanf("%d", &notas[i][j]);
                if (resultado != 1) {
                    printf("  Error: Debe ingresar un numero valido.\n");
                    while (getchar() != '\n');
                    notas[i][j] = -1; 
                } else if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  Error: La nota debe estar entre 0 y 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
        printf("\n");
    }