#include <stdio.h>
// Variables que podemos cambiar
#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBATORIA 6

int main() {
    char materias[NUM_ASIGNATURAS][20] = {"Matematica", "Historia", "Lengua"};
    int notas[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    int i, j;
    //Ingresamos los Vectores


// para ingresar las notas de los estudiantes
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
    
    // Variables para calcular promedios, maximos, minimos, aprobados y reprobados
    float promedio_estudiante[NUM_ESTUDIANTES] = {0};
    float promedio_asignatura[NUM_ASIGNATURAS] = {0};
    int max_estudiante[NUM_ESTUDIANTES], min_estudiante[NUM_ESTUDIANTES];
    int max_asignatura[NUM_ASIGNATURAS], min_asignatura[NUM_ASIGNATURAS];
    int aprobados[NUM_ASIGNATURAS] = {0}, reprobados[NUM_ASIGNATURAS] = {0};
    
    printf("\n RESULTADOS \n\n");
    
    // Calcular promedios, maximos y minimos por estudiante I= NUMERO E ESTUDIANTES J= NUMERO DE ASIGNATURAS COMO SOLO0 VEMOS PROMEIO J = 0
    for (i = 0; i < NUM_ESTUDIANTES; i++) {
        int suma = 0;
        max_estudiante[i] = notas[i][0];
        min_estudiante[i] = notas[i][0];
        // IMPRIMIMOS LA NOTA MAS ALTA Y LA MAS BAJA DE CADA ESTUDIANTE
        for (j = 0; j < NUM_ASIGNATURAS; j++) {
            suma += notas[i][j];
            if (notas[i][j] > max_estudiante[i]) max_estudiante[i] = notas[i][j];
            if (notas[i][j] < min_estudiante[i]) min_estudiante[i] = notas[i][j];
        }
        promedio_estudiante[i] = (float)suma / NUM_ASIGNATURAS;
        printf("Estudiante %d: Promedio = %.2f  Nota mas alta = %d  Nota mas baja = %d\n",
               i + 1, promedio_estudiante[i], max_estudiante[i], min_estudiante[i]);
    }
     printf("\n");
    for (j = 0; j < NUM_ASIGNATURAS; j++) {
        int suma = 0;
        max_asignatura[j] = notas[0][j];
        min_asignatura[j] = notas[0][j];
        
        for (i = 0; i < NUM_ESTUDIANTES; i++) {
            suma += notas[i][j];
            if (notas[i][j] > max_asignatura[j]) max_asignatura[j] = notas[i][j];
            if (notas[i][j] < min_asignatura[j]) min_asignatura[j] = notas[i][j];
            if (notas[i][j] >= NOTA_APROBATORIA) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
        promedio_asignatura[j] = (float)suma / NUM_ESTUDIANTES;
    }
    // IMPRIMIMOS EL PROMEDIO POR ASIGNATURA, LA NOTA MAS ALTA Y LA MAS BAJA DE CADA ASIGNATURA
    printf(" PROMEDIO POR ASIGNATURA \n");
    for (j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: Promedio = %.2f | Mas alta = %d | Mas baja = %d\n",
               materias[j], promedio_asignatura[j], max_asignatura[j], min_asignatura[j]);
    }
        printf("\n APROBADOS Y REPROBADOS POR ASIGNATURA \n");
    for (j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: Aprobados = %d | Reprobados = %d\n",
               materias[j], aprobados[j], reprobados[j]);
    }
    
    return 0;
}
