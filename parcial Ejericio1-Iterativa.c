//calculo factorial de manera iterativa
#include <stdio.h>
#include<time.h>

unsigned long long factorial(int n) { // el unsigned long long sirve para almacenar datos sin signo de gran tamaño
    unsigned long long resultado = 1;//se pone el long long porque si no el calculo no daria bien el resultado
    for (int i = 1; i <= n; i++) { 
        resultado *= i;
    }
    return resultado;
}

int main() {
    int valor;
    printf("Ingrese el valor que desea calcular su factorial: ");
    scanf("%d", &valor);

    if (valor < 0) {
        printf("No es posible calcular el factorial de un número negativo.\n");
    } else {

        clock_t start, end;
        double tiempo_ejecucion;

        start = clock();  // Iniciar medición

        unsigned long long resultado = factorial(valor);

        end = clock();  // Finalizar medición

        tiempo_ejecucion = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("El resultado del factorial de %d es %llu.\n", valor, resultado);
        printf("Memoria utilizada por 'resultado': %lu bytes\n", sizeof(resultado));
        printf("Tiempo de ejecucion: %f segundos\n", tiempo_ejecucion);
        
    }
    return 0;
}