#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "socio.h"
#include "informes.h"
#include "input.h"

#define TAM_SOCIOS 8
#define TAM_AUTORES 10
#define TAM_LIBROS 20
#define TAM_PRESTAMOS 160

int main()
{

    eSocios socios[TAM_SOCIOS];
    eAutores autores[TAM_AUTORES];
    eLibros libros[TAM_LIBROS];
    ePrestamos prestamos[TAM_PRESTAMOS];

    char salir = 'n';

    initSocios(socios, TAM_SOCIOS);
    initLibros(libros, TAM_LIBROS);
    initAutores(autores, TAM_AUTORES);
    initPrestamos(prestamos, TAM_PRESTAMOS);

//    hardCodingSocios(socios, TAM_SOCIOS);

 //   hardCodingPrestamos(prestamos, TAM_PRESTAMOS);

  //  hardCodingPrestamos(prestamos, TAM_PRESTAMOS);



        do{
            switch(menuPrincipal()){

            case 1:
                abmLibreria(socios, TAM_SOCIOS, autores, TAM_AUTORES, libros, TAM_LIBROS, prestamos, TAM_PRESTAMOS);
                break;

            case 2:
                informes(socios, TAM_SOCIOS, autores, TAM_AUTORES, libros, TAM_LIBROS, prestamos, TAM_PRESTAMOS);
                break;

            case 3:
                getChar(&salir, "\nIngrese 's' para salir o 'n' para continuar: ", "Ingrese solo 's' o 'n': ", 's', 'n');
                salir = tolower(salir);

                if(salir == 'n')
                    break;

                break;

            default:
                printf("Ingresa un opcion valida\n\n");
                system("pause");
                break;

            }

        }while(!(salir == 's'));


    return 0;
}
