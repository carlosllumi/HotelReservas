#include "funciones.h"
#include <stdio.h>
#include <string.h>

void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char tipo[40];
    printf("Ingrese el tamaño de habitacion que desea buscar: ");
    scanf("%s", tipo);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tipo) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Elija el número de la habitación que desea reservar: ");
    scanf("%d", numHabitacion);
}

void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]) {
    char hotel[40];
    printf("Ingrese el nombre del hotel que desea buscar: ");
    scanf("%s", hotel);
    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }
    printf("Elija el número de la habitación que desea reservar: ");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[][3][40], char clientes[][2][40], int reservas[][4]) {
    char nombre[40], cedula[40];
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre);
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);

    int i = 0;
    while (i < 10 && reservas[i][0] != -1) {
        i++;
    }

    if (i < 10) {
        strcpy(clientes[i][0], nombre);
        strcpy(clientes[i][1], cedula);
        reservas[i][0] = numHabitacion;
        printf("Reserva realizada correctamente.\n");
    } else {
        printf("No hay reservas disponibles.\n");
    }
}

void buscarReservaPorCedula(int *numReserva, char clientes[][2][40], int reservas[][4]) {
    char cedula[40];
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);

    *numReserva = -1;
    for (int i = 0; i < 10; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            *numReserva = i;
            break;
        }
    }

    if (*numReserva == -1) {
        printf("No se encontró ninguna reserva para la cédula ingresada.\n");
    }
}

void imprimirReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva != -1) {
        printf("Reserva encontrada:\n");
        printf("Cliente: %s\n", reservas[numReserva][0] != -1 ? habitaciones[reservas[numReserva][0]][0] : "N/A");
        printf("Habitación: %s - %s - %s\n", habitaciones[reservas[numReserva][0]][0], habitaciones[reservas[numReserva][0]][1], habitaciones[reservas[numReserva][0]][2]);
        printf("Precio: %.2lf\n", precios[reservas[numReserva][0]]);
    }
}

void pagarReserva(int numReserva, int reservas[][4], char habitaciones[][3][40], double precios[]) {
    if (numReserva != -1) {
        double total = precios[reservas[numReserva][0]];
        printf("Reserva a pagar:\n");
        printf("Cliente: %s\n", reservas[numReserva][0] != -1 ? habitaciones[reservas[numReserva][0]][0] : "N/A");
        printf("Habitación: %s - %s - %s\n", habitaciones[reservas[numReserva][0]][0], habitaciones[reservas[numReserva][0]][1], habitaciones[reservas[numReserva][0]][2]);
        printf("Precio: %.2lf\n", total);

    
        reservas[numReserva][3] = 1;
        printf("Reserva pagada correctamente.\n");
    }
}



