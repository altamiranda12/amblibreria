#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "input.h"
#include "socio.h"
#include "informes.h"

/******************** INFORMES  ***************************/

void informes(eSocios socios[], int tamSocios, eAutores autores[], int tamAutores, eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos){

    int opcion;


    do{
        opcion = menuDeOpcionesInformes();

        switch(opcion){

        case 1:
            totalGeneralYPromedioDiarios(prestamos, tamPrestamos);
            system("pause");
            break;

        case 2:
            diasCuyasSolicitudesNoSuperanPromedio(prestamos, tamPrestamos);
            system("pause");
            break;

        case 3:
            sociosSolicitarUnLibroDeterminado(libros, tamLibros, socios, tamSocios, prestamos, tamPrestamos);
            system("pause");
            break;

        case 4:
            librosSolicitadosPorSocioDeterminado(socios, tamSocios, libros, tamLibros, prestamos, tamPrestamos);
            system("pause");
            break;

        case 5:
            librosMenosSolicitadosAPrestamo(libros, tamLibros, prestamos, tamPrestamos);
            system("pause");
            break;

        case 6:
            socioRealizoMasSolicitudesAPrestamo(prestamos, tamPrestamos, socios, tamSocios);
            system("pause");
            break;

        case 7:
            listarLibrosPorFechaDeterminada(prestamos, tamPrestamos, libros, tamLibros);
            system("pause");
            break;

        case 8:
            listarSociosPorFechaDeterminada(socios, tamSocios, prestamos, tamPrestamos);
            system("pause");
            break;
        case 9:
            listarLibrosPorTitulo(libros, tamLibros);
            system("pause");
            break;

        case 10:
            listarSociosPorApellido(socios, tamSocios);
            system("pause");
            break;

        case 11:
            // atras
            //...
            //...
            break;

        default:
            printf("Ingrese una opcion valida [1 - 11]\n\n");
            system("pause");
            break;

        }
    }while(!(opcion == 11));

}

int menuDeOpcionesInformes(){

   int input, temp, status;
    system("cls");
    printf("- - - - - - - - - - - - - - INFORMES - - - - - - - - - - - - - - - \n\n");
    printf("1- Total general y promedio diario de la solicitudes de prestamos\n\n");
    printf("2- Cantidad de dias cuyas solicitudes no superan el promedio\n\n");
    printf("3- Listar socios que solicitaron un determinado libro\n\n");
    printf("4- Listar libros que fueron solicitados por un determinado socio\n\n");
    printf("5- Listar el/los libro/libros menos solicitados a prestamo\n\n");
    printf("6- Listar el/los socio/socios que realizaron mas solicitudes a prestamo\n\n");
    printf("7- Listar todos los libros solicitados en una fecha determinada\n\n");
    printf("8- Listar todos los socios que realizaron al menos una solicitud a prestamos en una fecha determinada\n\n");
    printf("9- Listar todos los libros ordenados por titulo\n\n");
    printf("10- Listar todos los socios por apellido\n\n");
    printf("11- Atras\n\n\n\n");

    printf(">> ");

    status = scanf("%d", &input);

     while(status!=1){

        while((temp=getchar()) != EOF && temp != '\n');
        printf("La opcion tiene que ser numerica >> ");
        status = scanf("%d", &input);

    }
    return input;

}

// letra j
void listarSociosPorApellido(eSocios socios[], int tam){

    int i, j;
    int cont = 0;

    eSocios temp;

    for(i = 1; i < tam ; i++){

        temp = socios[i];
        j = i-1;
        while( j>=0 && strcmp(socios[j].apellido, temp.apellido) > 0){

            socios[j+1] = socios[j];
            j--;
        }
        socios[j+1]=temp;
     }
    system("cls");

    printf("    codigo nombre  apellido sexo telefono   email    Fecha Ingreso\n\n");
    for(int i = 0; i < tam; i++){
          if(socios[i].isEmpty == 0){
            printf("--> %d %s %s %c %s %s %d/%d/%d\n\n", socios[i].codigoSocio, socios[i].nombre, socios[i].apellido, socios[i].sexo, socios[i].telefono, socios[i].email, socios[i].fechaAsociado.dia, socios[i].fechaAsociado.mes, socios[i].fechaAsociado.anio);
            cont++;

          }
    }
    if(cont == 0)
        printf("--> No hay socios que mostrar. . .\n\n");


}



// letra i
void listarLibrosPorTitulo(eLibros libros[], int tam){

    int j;
    eLibros aux;
    int flagNoEstaOrdenado = 1;

    while (flagNoEstaOrdenado == 1){

         flagNoEstaOrdenado = 0;
        for (j = 1; j < tam; j++){

            if(strcmp(libros[j].titulo, libros[j - 1].titulo) > 0){
                 aux = libros[j];
                 libros[j] = libros[j - 1];
                 libros[j - 1] = aux;
                 flagNoEstaOrdenado = 1;
            }
        }
    }

    system("cls");
        printf("\n---------------------------------------------------------\n");
        printf("|   CODIGO LIBRO  |         TITULO       | CODIGO AUTOR |\n");
    for(int i = 0; i < tam; i++){
        printf("|    %10d   | %20s |  %10d  |\n", libros[i].codigoLibro, libros[i].titulo, libros[i].codigoAutor );
    }




}



// letra h
void listarSociosPorFechaDeterminada(eSocios socios[], int tamSocios, ePrestamos prestamos[], int tamPrestamos){

    system("cls");
    eSocios auxSocio;  // variable auxiliar creada, para evitar la impresion repetido por pantalla de un socio
    int dia;
    int mes;
    int anio;
    int existe;
    int cont = 0;
    int cont2 = 0;
    int flag = 0;
    eFecha fechas; // auxiliar que me sirve para evitar imprimir repetidas fechas

    // imprimo en pantalla las distintas fechas en la que se han hecho los prestamos
        printf("\nFechas de los prestamos:\n\n");
        for(int i = 2009; i < 2020;i++){
            for(int j = 0; j< 12; j++){
                for(int k = 0; k< 31;k++){
                    for(int l = 0; l < tamPrestamos; l++){
                        if(prestamos[l].isEmpty == 0 && prestamos[l].fechaPrestamo.dia == k+1 &&
                           prestamos[l].fechaPrestamo.mes == j+1 && prestamos[l].fechaPrestamo.anio == i+1){

                            cont++;
                            fechas.dia = prestamos[l].fechaPrestamo.dia;
                            fechas.mes = prestamos[l].fechaPrestamo.mes;
                            fechas.anio = prestamos[l].fechaPrestamo.anio;
                        }
                    }
                    if(cont > 0){
                        printf("--> %d/%d/%d\n\n", fechas.dia, fechas.mes, fechas.anio);
                        cont2++;
                    }
                    cont = 0;
                }
            }
        }

        if(cont2 == 0){
            printf("\n\tNo se ha hecho ninguna solicitud a prestamo por los momentos\n\n");
        }else{
            printf("\nIngrese una fecha\n\n");
            getInt(&dia, "Ingrese dia >> ", "Dia no valido >> ", 1, 31);
            getInt(&mes, "Ingrese mes >> ", "Mes no valido >> ", 1, 12);
            getInt(&anio, "Ingrese anio >> ", "Anio no valido, Rango debe estar entre 2010 - 2019 >> ", 2010, 2019);

            existe = buscarFechaExistente(prestamos, tamPrestamos, dia, mes, anio); // con la funcion compruebo solo si existe por lo menos un prestamos en esa fecha


            if(existe){
                printf("\nNo se ha realizado ningun prestamo en la fecha ingresada\n\n");
            }else{

                system("cls");
                printf("\n\nSocios que realizaron al menos una solicitud a prestamos en %d/%d/%d:\n\n", dia, mes, anio);
                for(int i = 0; i < tamPrestamos; i++){
                    if(prestamos[i].fechaPrestamo.dia == dia && prestamos[i].fechaPrestamo.mes == mes && prestamos[i].fechaPrestamo.anio == anio){

                        for(int j = 0; j < tamSocios; j++){
                            if(prestamos[i].codigoSocio == socios[j].codigoSocio && socios[j].isEmpty == 0){
                                if(flag == 0 || auxSocio.codigoSocio != socios[j].codigoSocio){

                                   printf("--> %d  %s  %s\n\n",socios[j].codigoSocio, socios[j].nombre, socios[j].apellido);
                                   flag = 1;
                                }
                                auxSocio = socios[j];
                            }
                        }
                    }
                }
            }

       }

}

// letra g
void listarLibrosPorFechaDeterminada(ePrestamos prestamos[], int tamPrestamos, eLibros libros[], int tamLibros){

    system("cls");
    eLibros auxLibro;
    int dia;
    int mes;
    int anio;
    int existe;
    int cont= 0;
    int cont2 = 0;
    int flag = 0;
    eFecha fechas;


    system("cls");
    // imprimo en pantalla las distintas fechas en la que se han hecho los prestamos
    printf("\nFechas de los prestamos:\n\n");
        for(int i = 2009; i < 2020;i++){
            for(int j = 0; j< 12; j++){
                for(int k = 0; k< 31;k++){
                    for(int l = 0; l < tamPrestamos; l++){
                        if(prestamos[l].isEmpty == 0 && prestamos[l].fechaPrestamo.dia == k+1 &&
                           prestamos[l].fechaPrestamo.mes == j+1 && prestamos[l].fechaPrestamo.anio == i+1){

                            cont++;
                            fechas.dia = prestamos[l].fechaPrestamo.dia;
                            fechas.mes = prestamos[l].fechaPrestamo.mes;
                            fechas.anio = prestamos[l].fechaPrestamo.anio;
                        }
                    }
                    if(cont > 0){
                        printf("--> %d/%d/%d\n\n", fechas.dia, fechas.mes, fechas.anio);
                        cont2++;
                    }
                    cont = 0;
                }
            }
        }

        if(cont2 == 0){
            printf("\n\tNo se ha hecho ninguna solicitud a prestamo por los momentos\n\n");
        }else{
            printf("\nIngrese una fecha\n\n");
            getInt(&dia, "Ingrese dia >> ", "Dia no valido >> ", 1, 31);
            getInt(&mes, "Ingrese mes >> ", "Mes no valido >> ", 1, 12);
            getInt(&anio, "Ingrese anio >> ", "Anio no valido, Rango debe ser entre 2010 - 2019 >> ", 2010, 2019);

            existe = buscarFechaExistente(prestamos,tamPrestamos, dia, mes, anio);// con la funcion compruebo solo si existe por lo menos un prestamos en esa fecha

            if(existe){
                printf("\nNo se ha realizado ningun prestamo en la fecha ingresada\n\n");
            }else{

                system("cls");
                printf("Libros solicitados a prestamo en %d/%d/%d:\n\n", dia, mes, anio);
                for(int i = 0; i < tamPrestamos; i++){
                    if(prestamos[i].fechaPrestamo.dia == dia && prestamos[i].fechaPrestamo.mes == mes && prestamos[i].fechaPrestamo.anio == anio){
                        for(int j = 0; j < tamLibros; j++){
                            if(prestamos[i].codigoLibro == libros[j].codigoLibro){
                                if(libros[j].codigoLibro != auxLibro.codigoLibro || flag == 0){
                                    printf("--> %d %s\n\n", libros[j].codigoLibro, libros[j].titulo);
                                    flag = 1;
                                }
                                auxLibro = libros[j];
                            }
                        }
                    }

                }

            }

        }

}



//letra f

void socioRealizoMasSolicitudesAPrestamo(ePrestamos prestamos[], int tamPrestamos, eSocios socios[], int tamSocios){

    system("cls");
   int maximo;
   int cont = 0;
   int cont2 = 0;
   int cont3 = 0;
   int flag = 0;

   // busco el mayor de todas las solicitudes hechas por un socio o varios socios
   for(int i = 0; i < tamSocios; i++){

        for(int j = 0; j < tamPrestamos; j++){

             if(socios[i].codigoSocio == prestamos[j].codigoSocio && prestamos[j].isEmpty == 0){
                cont++;
             }
        }

        if(cont == 0) // Si el socio no ha solicitado a prestamos aun ni tampoco se ha dado de alta busco otro
            continue;

        if(flag == 0 || maximo < cont){
            maximo = cont;
            flag = 1;
        }
        cont = 0;
   }

   // imprimo por psntalla el/los socio/socios que mss solicito/solitaron a prestamo
   printf("\n\nEl/Los Socio/Socios que mas solicito/solicitaron a prestamo:\n\n");
   for(int i = 0; i < tamSocios; i++){
        for(int  j = 0; j < tamPrestamos ; j++){
            if(socios[i].codigoSocio == prestamos[j].codigoSocio && prestamos[j].isEmpty == 0){
                cont2++;
            }
        }

        if(maximo == cont2){
            printf("--> %d  %s  %s  %c  %s  %s\n\n",socios[i].codigoSocio, socios[i].nombre, socios[i].apellido, socios[i].sexo, socios[i].telefono, socios[i].email);
            cont3++;
        }
        cont2 = 0;

   }

   if(cont3 == 0){
        printf("\n\tNo hay socios que mostrar\n\n");
   }

}

// LETRA E
void librosMenosSolicitadosAPrestamo(eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos){

    system("cls");
    int minimo;
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    int flag = 0;

    // busco la cantidad de veces que menos se han solicitado a prestamos
    for(int i = 0; i < tamLibros; i++){
        for(int j = 0; j < tamPrestamos; j++){
            if(libros[i].codigoLibro == prestamos[j].codigoLibro && prestamos[j].isEmpty == 0){
                cont++;
            }

        }
        if(cont == 0)
            continue;

        if(flag == 0 || minimo > cont){
            minimo = cont;
            flag =1;
        }
        cont = 0;
    }

    // imprimo en pantalla el menos solicitado o los menos solicitados
    printf("\n\nEl/Los libro/libros menos solicitado/solicitados:\n\n");
    for(int i = 0; i < tamLibros; i++){
        for(int j = 0; j < tamPrestamos; j++){
          if(libros[i].codigoLibro == prestamos[j].codigoLibro && prestamos[j].isEmpty == 0){
                cont2++; // cont2 cuenta las veces de un libro se ha solicitado a prestamo
            }
        }
        if(minimo == cont2){
            printf("--> %d  %s\n\n", libros[i].codigoLibro, libros[i].titulo);
            cont3++;
        }
        cont2 = 0;
    }

    if(cont3 == 0)
        printf("\n\tNo se ha solicitado a prestamo ningun libro\n\n");


}

// letra D

void librosSolicitadosPorSocioDeterminado(eSocios socios[], int tamSocios, eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos){


    int codigo;
    int indice;
    int cont = 0;
    int ok;

    ok = listarSocios(socios, tamSocios);

    if(ok != -1){

        printf("\n\n");

        getInt(&codigo, "Ingrese codigo socio >> ", "Ingrese un numero valido >> ", 0, INT_MAX-1);

        indice = buscarSocio(socios, tamSocios, codigo);
    }

    if(indice == -1 ){
        printf("\nNo se ha podido encontrar el socio\n\n");
    }else if(ok == -1){
        printf("\n\tNo hay socios que mostrar\n\n");
    }else{

        system("cls");
        //imprimo en pantalla los libros solicitados por el socio ingresado
        printf("\n%d %s %s:\n\n\n", socios[indice].codigoSocio, socios[indice].nombre, socios[indice].apellido);
        printf("   Autor Titulo   Codigo  Fecha de prestamo\n\n");
        for(int i = 0; i < tamPrestamos; i++){
            if(socios[indice].codigoSocio == prestamos[i].codigoSocio){
                for(int j = 0; j < tamLibros; j++){
                    if(prestamos[i].codigoLibro == libros[j].codigoLibro){
                        printf("--> %d  %s  %d  %d/%d/%d\n\n",libros[j].codigoAutor, libros[j].titulo, libros[j].codigoLibro, prestamos[i].fechaPrestamo.dia, prestamos[i].fechaPrestamo.mes, prestamos[i].fechaPrestamo.anio);
                        cont++;
                    }
                }
            }
        }

        // imprime un mensaje en caso de que no haya pedido a prestamos un libro
        if(cont == 0)
            printf("--> El socio no ha dado de alta ningun libro\n\n");

    }

}

// letra c
void sociosSolicitarUnLibroDeterminado(eLibros libros[], int tamLibros, eSocios socios[], int tamSocios, ePrestamos prestamos[], int tamPrestamos){

    int codigo;
    int indice;
    int cont = 0;

    listarLibros(libros, tamLibros);
    printf("\n\n");
    getInt(&codigo, "Ingrese codigo >> ", "Ingrese un nummero valido >> ", 0, INT_MAX-1);

    indice = buscarLibros(libros, tamLibros, codigo);

    if(indice == -1){
        printf("\nNo se ha podido encontrar el libro\n\n");

    }else{

        system("cls");
        printf("\n%d %s:\n\n", libros[indice].codigoLibro, libros[indice].titulo);
        printf("   codigo   nombre  apellido fecha solicitado\n\n");
                for(int i = 0; i < tamPrestamos; i++){
                    if(libros[indice].codigoLibro == prestamos[i].codigoLibro){
                            for(int j = 0; j < tamSocios; j++){
                                if(socios[j].isEmpty == 0 && socios[j].codigoSocio == prestamos[i].codigoSocio){
                                    printf("--> %d  %s  %s  %d/%d/%d\n\n",socios[j].codigoSocio ,socios[j].nombre, socios[j].apellido, prestamos[i].fechaPrestamo.dia, prestamos[i].fechaPrestamo.mes, prestamos[i].fechaPrestamo.anio);
                                    cont++;
                                }
                            }
                    }
                }


        if(cont == 0)
            printf("--> El libro no ha sido solicitado aun\n\n");

    }
}

// letra B
void diasCuyasSolicitudesNoSuperanPromedio(ePrestamos prestamos[], int tamPrestamos){

    int dias = 0;
    int flag = 0;
    int flag2 = 0;
    float promedio;
    int solicitudes = 0;
    int totalGeneral = 0;
    int cantidadDiasMenorPromedio = 0;

/* CALCULO PRIMERO EL PROMEDIO */
    for(int i = 2009; i < 2020; i++){
        for(int j = 0; j < 12; j++){
            for(int k = 0; k < 31; k++){
                for(int l = 0 ; l < tamPrestamos; l++){
                    if(prestamos[l].isEmpty == 0 && prestamos[l].fechaPrestamo.dia == k+1 && prestamos[l].fechaPrestamo.mes == j+1 &&
                       prestamos[l].fechaPrestamo.anio == i+1 ){
                        totalGeneral++; // cuento los prestamos
                        flag = 1; // me da la senal de que puedo contar con ese dia
                    }
                }
               if(flag)
                dias++; // cuento los dias en las que se realiizaron prestamos

                flag = 0;
            }
        }
    }

    promedio = (float) totalGeneral / dias;

    /* BUSCO Y CUENTO LOS DIAS CUYAS SOLICITUDES A PRESTAMOS NO SUPERAN EL PROMEDIO */
        for(int i = 2009 ; i < 2020; i++){
            for(int j = 0; j < 12; j++){
                for(int k = 0; k < 31; k++){
                    for(int l = 0; l < tamPrestamos; l++){
                        if(prestamos[l].isEmpty ==0 && prestamos[l].fechaPrestamo.dia == k+1 && prestamos[l].fechaPrestamo.mes == j+1
                           && prestamos[l].fechaPrestamo.anio == i+1){

                            solicitudes++; //cuento las solicitudes a prestamos en una fecha
                            flag2 = 1; // me da la senal de que es un dia valido
                        }

                    }
                    if(solicitudes < promedio && flag2 == 1)
                                cantidadDiasMenorPromedio++;

                                solicitudes = 0;
                                flag2 = 0;

                }

            }

        }



    printf("\nCantidad de dias que no superan el promedio: %d\n\n", cantidadDiasMenorPromedio);

}


//letra A

void totalGeneralYPromedioDiarios(ePrestamos prestamos[], int tamPrestamos){

    int totalGeneral = 0;
    int dias = 0;
    int flag = 0;
    float promedio;

    for(int i = 2009; i < 2020; i++){
        for(int j = 0; j < 12; j++){
            for(int k = 0; k< 31; k++){
                for(int l = 0 ; l < tamPrestamos; l++){
                    if(prestamos[l].isEmpty == 0 && prestamos[l].fechaPrestamo.dia == k+1
                       && prestamos[l].fechaPrestamo.mes == j+1 && prestamos[l].fechaPrestamo.anio == i+1){

                        totalGeneral++; // cuento los prestamos
                        flag = 1; // me da la senal de que puedo contar con ese dia
                    }
                }
               if(flag)
                dias++; // cuento los dias en las que se realiizaron prestamos

                flag = 0;
            }
        }
    }
    if(totalGeneral != 0)
    promedio = (float) totalGeneral / dias;
    else
        promedio = 0;

    printf("\nTotal general: %d\n", totalGeneral);
    printf("Promedio diarios %.2f\n\n", promedio);

}

