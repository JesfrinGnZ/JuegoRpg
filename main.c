/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jesfrin
 *
 * Created on 5 de agosto de 2018, 12:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

//Variables usadas a lo largo del programa


//Estrucuturas

typedef struct {//Contador para crear personajes
    int n;
} Contador;

typedef struct {//Personajes que se podran usar a lo largo del juego
    char nombre[20];
    int codigo;
    int puntosDeVida;
    int puntosDeMana; //Sirven para curar al personaje, solo se consume un punto por curacion
    int nivel; //Segun experiencia
    int experiencia; //Sirve para usbir de nivel
    int oro; //Sirve para comprar cosas de la tienda
    int cantidadDeVictorias; //Sirven para el punteo(archivos)
    int cantidadDeDerrotas; //Sirven para el punteo(archivos)
    int cantidadDePotion;
    int cantidadDeHiPotion;
    int cantidadDeMPotion;
} Personaje;

void menuPrincipal(Personaje *personajeUsado) {

    int opcion = 0;

    do {

        printf("\n**************************************************************\n");
        printf("\n\n\t\t\tMENU PRINCIPAL\n");
        printf("\n**************************************************************\n");
        printf("\n\t\tIngrese la opcion que desea\n");
        printf("1)A la Carga\n");
        printf("2)Tienda\n");
        printf("3)ZzzZzz\n");
        printf("4)Status\n");
        printf("5)Mejor punteo\n");
        printf("6)Cambiar de personaje\n");
        printf("7)Salir del juego\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                //menuaLaCarga();
                break;
            case 2:
                //menuTienda();
                break;
            case 3:
                //menudormir();
                break;
            case 4:
                //menuStatus();
                break;
            case 5:
                //menuMejorPunteo();
                break;
            case 6:
                break;
            case 7:
                printf("\n\t\t\tFIN DEL JUEGO");
                opcion = 2;
             
            default:
                printf("\n\n\t\t\t\tINSTRUCCION NO VALIDA, PRUEBE DE NUEVO\n\n");
                opcion = 0;
                break;
        }
    } while (opcion == 0);
}

int buscarCodigo() {//Utilizado en buscarPersonaje
    FILE *archivoContador;
    Contador contadorActual = {1};

    archivoContador = fopen("Contador.bin", "rb"); //acceder solo a lectura
    if (archivoContador == NULL) {//No existe el archivo
        archivoContador = fopen("Contador.bin", "ab"); //ccedes para escritura sin sobreescribir, lo crea si no existe
        fwrite(&contadorActual, sizeof (contadorActual), 1, archivoContador);
        return 1;
    } else {
        //No es nulo
        fread(&contadorActual, sizeof (contadorActual), 1, archivoContador); //Se lee el contador actual
        contadorActual.n++; //Este es el valor a utilizar y a guardar
        archivoContador = fopen("Contador.bin", "wb"); //Flujo para escritura
        fwrite(&contadorActual, sizeof (contadorActual), 1, archivoContador); //Se escribe el numero que se uso
        return contadorActual.n;

    }
    fclose(archivoContador);

}

/*
void crearPersonaje(FILE *archivoPersonajes) {
    Personaje personajeNuevo;

    archivoPersonajes = fopen("Personajes.bin", "ab"); //Creamos el archivo
    printf("Escriba el nombre de su personaje\n"); //Se piden datos para el personaje
    //Datos del personaje
    scanf("%s", personajeNuevo.nombre);
    personajeNuevo.codigo = buscarCodigo();
    //Se guarda el personaje
    fwrite(&personajeNuevo, sizeof (personajeNuevo), 1, archivoPersonajes);
    printf("Personaj Creado\n");
}
 */

Personaje crearPersonaje(Personaje *personajeActual){
    
}

Personaje modificarPersonaje(FILE *archivoPersonajes, Personaje *personajeActual) {//Pasar el personaje actual ya con sus cambios, y el archivo;

}

void mostrarPersonajes(FILE *archivoPersonajes) {
    Personaje personajeActual;
    archivoPersonajes = fopen("Personajes.bin", "rb"); //Ya existe el archivo(lectura)
    printf("%-50s", "NOMBRE DEL PERSONAJE");
    printf("%-50s", "CODIGO DEL PERSONAJE");
    printf("%s", "NIVEL\n");
    while (fread(&(personajeActual), sizeof (personajeActual), 1, archivoPersonajes)) {
        printf("%-50s", personajeActual.nombre);
        printf("%-50d", personajeActual.codigo);
        printf("%d\n", personajeActual.nivel);


    }

}

Personaje seleccionarPersonaje(FILE *archivoPersonajes) {
    int codigoDelPersonaje;
    Personaje personajeActual;
    //
    int repeticion = 0;
    do {
        printf("\nIngrese el codigo del personaje que deseea escojer\n");
        fflush(stdin);
        scanf("%d", &codigoDelPersonaje);

        archivoPersonajes = fopen("Personajes.bin", "rb");
        while (fread(&(personajeActual), sizeof (personajeActual), 1, archivoPersonajes)) {
            /*
                        printf("\nCodigo dentro del while:%d y nombre %s\n", personajeActual.codigo, personajeActual.nombre);
             */
            //Error en condicional
            if (personajeActual.codigo == codigoDelPersonaje) {
                //Lo comentado de abajo puede servir para ver como funciona el while 
                //printf("\nCodigo dentro del while:%d\n y nombre %s", personajeActual.codigo, personajeActual.nombre);
                return personajeActual;
            }
        }
        printf("No se ha encontrado al personaje, pruebe de nuevo\n");
    } while (repeticion == 0);

}

Personaje buscarPersonaje() {//El general, busca ara mostrar o crear 

    FILE *archivoPersonaje;
    Personaje personajeNuevo;

    archivoPersonaje = fopen("Personajes.bin", "rb"); //Accedemos solo a lectura
    if (archivoPersonaje == NULL) {
        printf("\n......No existen personajes.Cree el suyo\n");
        archivoPersonaje = fopen("Personajes.bin", "ab"); //Creamos el archivo
        printf("Escriba el nombre de su personaje"); //Se piden datos para el personaje
        //Datos del personaje
        scanf("%s", personajeNuevo.nombre);
        personajeNuevo.codigo = buscarCodigo();
        personajeNuevo.nivel = 0;
        //Se guarda el personaje
        fwrite(&personajeNuevo, sizeof (personajeNuevo), 1, archivoPersonaje);


    } else {
        int opcion;
        printf("\n\nDesea crear un nuevo personaje[0], o usar alguno de los siguientes[1]??\n\n");
        mostrarPersonajes(&archivoPersonaje);
        scanf("%d", &opcion);
        if (opcion == 0) {
            archivoPersonaje = fopen("Personajes.bin", "ab"); //Creamos el archivo
            printf("Escriba el nombre de su personaje\n"); //Se piden datos para el personaje
            //Datos del personaje
            scanf("%s", personajeNuevo.nombre);
            personajeNuevo.codigo = buscarCodigo();
            personajeNuevo.nivel = 0;
            //Se guarda el personaje
            fwrite(&personajeNuevo, sizeof (personajeNuevo), 1, archivoPersonaje);
            printf("Personaj Creado\n");
        } else {
            printf("\n\t\t\tESCOJA SU PERSONAJE\n");
            mostrarPersonajes(&archivoPersonaje);
            personajeNuevo = seleccionarPersonaje(&archivoPersonaje);
            printf("\nNombre del personaje seleccionado:%s\n", personajeNuevo.nombre);
        }



    }
    fclose(archivoPersonaje);
    return personajeNuevo;
}


//Textos

void tituloPrincipal() {
    int i;
    printf("\n     ======================================================================\n");
    printf("\t\t\t    JUEGO RPG\n");
    printf("\t   Adentrate en un mundo de diversion sin limites\n");
    printf("\t\t    Copyright 2018 | :v :v :v\n");
    printf("     ======================================================================\n");

    i = 0;
    putchar('\n');
    for (; i < 80; i++) {
        putchar('_');
    }
}

/*
void modificarPersonaje(FILE *archivoPersonajes,Personaje *personaje){
    
}
 */

int main(int argc, char** argv) {
    Personaje personajeUsado;
    /*
        Contador nuevo;
        nuevo.n=5;
        printf("Numeo es 5::%i", nuevo.n);
     */
    tituloPrincipal();
    personajeUsado = buscarPersonaje();
    menuPrincipal(&personajeUsado);
}

//Un metodo para crear un personaje completamente nuevo