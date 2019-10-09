#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "input.h"
#include "socio.h"


int menuPrincipal(){

    int input, temp, status;

    system("cls");
    printf("- - - - - - MENU PRINCIPAL - - - - - -\n\n");
    printf("1 - ABM\n\n2 - LISTAR E INFORMAR\n\n3 - SALIR\n\n\n");

    printf(">> ");
     status = scanf("%d", &input);

     while(status!=1){

        while((temp=getchar()) != EOF && temp != '\n');
        printf("La opcion tiene que ser numerica >> ");
        status = scanf("%d", &input);

    }


    return input;
}

void abmLibreria(eSocios socios[], int tamSocios, eAutores autores[], int tamAutores, eLibros libros[],int tamLibros ,ePrestamos prestamos[], int tamPrestamos){

    static int flag = 0;
    int opcion;
    int status;

    do{
            switch((opcion=menuDeOpciones())){
            case 1:
                status = altaSocio(socios, tamSocios);
                if(status != -1)
                    flag = 1;

                system("pause");

                break;

            case 2:
                if(flag)
                    modificarSocios(socios, tamSocios);
                else
                    printf("\nDebe dar de alta por lo menos un socio\n\n");

                 system("pause");
                break;

            case 3:
                if(flag)
                    bajaSocio(socios, tamSocios, prestamos, tamPrestamos);
                else
                    printf("\nDebe dar de alta por lo menos un socio\n\n");

                system("pause");
                break;
            case 4:
                if(listarSocios(socios, tamSocios) == -1){
                    printf("\n\tNo hay socios que mostrar\n\n");
                }

                system("pause");
                break;

            case 5:

                listarLibros(libros, tamLibros);
                system("pause");
                break;

            case 6:
                listarAutores(autores, tamAutores);
                system("pause");
                break;

            case 7:
                if(flag)
                    altaPrestamo(prestamos, tamPrestamos, libros, tamLibros, socios , tamSocios);
                else
                    printf("\nDebe dar de alta por lo menos un socio\n\n");
                system("pause");
                break;

            case 8:
                //atras
                break;

            default:
                printf("INGRESE UNA OPCION VALIDA [1 - 8]\n\n");
                system("pause");
                break;
            }

    }while(!(opcion == 8));


}

int menuDeOpciones(){

    system("cls");

    int input, temp, status;
    printf("- - - - - - MENU DE OPCIONES - - - - - -\n\n");
    printf("1 - ALTA SOCIO\n\n2 - MODIFICAR SOCIO\n\n3 - BAJA\n\n4 - LISTAR SOCIO\n\n5 - LISTAR LIBROS\n\n6 - LISTAR AUTORES\n\n7 - PRESTAMOS (ALTA)\n\n8 - ATRAS\n\n\n\n");

    printf(">> ");
    status = scanf("%d", &input);

     while(status!=1){

        while((temp=getchar()) != EOF && temp != '\n');
        printf("La opcion tiene que ser numerica >> ");
        status = scanf("%d", &input);

    }
    return input;
}

int altaSocio(eSocios socios[], int tam){

    int indice;
    int retorno = -1;
    indice = buscarEspacioSocio(socios, tam);

    if(indice == -1){
        printf("No hay espacio en el sistema\n\n");
    }else{

       system("cls");
       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       getString(socios[indice].nombre, "Ingresa nombre >> ", "Debe tener mas de 1 caracter y menos de 51 >> ", 1, 51);

       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       getString(socios[indice].apellido, "Ingresa apellido >> ", "Debe tener mas de 1 caracter y menos de 51 >> ", 1, 51);

       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       getChar(&socios[indice].sexo, "Ingresa sexo [m/f] >> ", "Ingrese solo m o f >> ", 'm', 'f');

       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       getString(socios[indice].telefono, "Ingresa telefono >> ", "No debe tener mas de 16 digitos ni menos de 1 >> ", 1, 16);

       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       getString(socios[indice].email, "Ingresa email >> ", "No debe tener mas de 31 caracteres ni menos de 1 >> ", 1, 31);

       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       fflush(stdin);
       printf("Ingrese fecha de ingreso\n");
       getInt(&socios[indice].fechaAsociado.dia, "Dia >> ", "Dia no valido >> ", 1, 31 );
       getInt(&socios[indice].fechaAsociado.mes, "Mes >> ", "Mes no valido >> ", 1, 12);
       getInt(&socios[indice].fechaAsociado.anio, "Anio >> ", "Anio no valido, Rango debe ser entre 2010 - 2019 >> ",2010, 2019);
       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
       socios[indice].codigoSocio = asignarCodigoSocio(socios, tam);

       socios[indice].isEmpty = 0;
       printf("\n\n\t\t\t\tSE HA HECHO EL ALTA\n");
       printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n");

       retorno = 0;

    }

    return retorno;
}

/* HARCODEO DE LOS SOCIOS */

/*void hardCodingSocios(eSocios socios[], int tam){

    int i;
     eSocios auxVec[5] = {
<<<<<<< HEAD
        {1000, "calderon" , "gilberto" , 'm',  "11-5009 5932", "calderongilberto3@gmail.com", 0, {12, 4, 2018}},
        {1001, "calderon", "luis", 'm', "11-3323 2424", "jse@gmail.com", 0, {13, 4, 2018}},
        {1002, "cabrera", "juan" , 'm', "11-2334 0934", "cabrerajuan@gmail.com", 0, {14, 4,2018}},
        {1003, "martinez", "maria", 'f', "11-3424-2534", "maria@gmail.com", 0, {5, 2, 2019}},
        {1004, "rodriguez", "sabrina", 'f', "11-2342-4215", "dsdg@gmail.com", 0, {9, 2, 2019}}
    };

    for(i = 0; i < tam; i++){
        if(i != 5){
=======
        {100, "calderon" , "gilberto" , 'm',  "11-5009 5932", "calderongilberto3@gmail.com", 0, {12, 4, 2018}},
        {101, "calderon", "luis", 'm', "11-3323 2424", "jse@gmail.com", 0, {13, 4, 2018}},
        {102, "cabrera", "juan" , 'm', "11-2334 0934", "cabrerajuan@gmail.com", 0, {14, 4,2018}},
        {103, "martinez", "maria", 'f', "11-3424-2534", "maria@gmail.com", 0, {5, 2, 2019}},
        {104, "rodriguez", "sabrina", 'f', "11-2342-4215", "dsdg@gmail.com", 0, {9, 2, 2019}}
    };

    for(i = 0; i < tam; i++){
        if(i != 4){
>>>>>>> 4efcc79093439c03219ad32219b371e5b67cba77
            if(socios[i].isEmpty == 1){
                socios[i] = auxVec[i];
            }
        }else
            break;
    }

<<<<<<< HEAD
}*/


/*void initSocios(eSocios socios[], int tam){

    for(int i = 0 ; i < tam; i++)
        socios[i].isEmpty = 1;


=======
}
*/

int initSocios(eSocios socios[], int tam){

    int ok = -1;

    for(int i = 0 ; i < tam; i++){

        socios[i].isEmpty = 1;

    }

    if(socios[tam - 1].isEmpty == 1)
        ok = 0;

    return ok;

}

int buscarEspacioSocio(eSocios socios[], int tam){

    int indice = -1;

    for(int i = 0; i < tam; i++){


        if(socios[i].isEmpty == 1){

            indice = i;
            break;
        }
    }

    return indice;
}

int asignarCodigoSocio(eSocios socios[], int tam){


    int codigoSocio = 1000;

    for(int i= 0; i < tam; i++){

        if(socios[i].isEmpty){
            break;}
        else
             codigoSocio++;
    int codigoSocio = 100;

    for(int i= 0; i < tam; i++){

        if(socios[i].isEmpty == 1){
            codigoSocio = codigoSocio;
            break;
        }else{

            codigoSocio++;
        }

    }

    return codigoSocio;
}


int listarSocios(eSocios socios[], int tam){

    system("cls");
    int counter = 0;
    int seMostro = -1;

    printf("    codigo nombre  apellido sexo telefono   email    Fecha Ingreso\n\n");
    for(int i = 0; i < tam; i++){
      if(socios[i].isEmpty == 0){
        printf("--> %d %s %s %c %s %s %d/%d/%d\n\n", socios[i].codigoSocio, socios[i].nombre, socios[i].apellido, socios[i].sexo, socios[i].telefono, socios[i].email, socios[i].fechaAsociado.dia, socios[i].fechaAsociado.mes, socios[i].fechaAsociado.anio);
        counter++;
        seMostro = 0;
      }
    }

    return seMostro;
}

void bajaSocio(eSocios socios[], int tam, ePrestamos pres[], int tamPrestamos){

    int codigoSocio;
    int indice;;
    int ok;
    char resp;

    ok = listarSocios(socios, tam);

    if(ok == 0){

        getInt(&codigoSocio, "\n\nIngrese codigo socio >> ", "Ingrese un numero valido >> ", 0, INT_MAX);

        indice = buscarSocio(socios, tam, codigoSocio);

        if(indice == -1){

            printf("\nNo se pudo encontrar el socio de codigo %d\n\n", codigoSocio);
        }else{

            getChar(&resp, "Esta seguro que quiere darle de baja [s/n] >> ", "Ingrese solo [s/n] >> ", 's', 'n');
            if(resp == 's'){
                printf("\n\n\t\t  Se ha hecho la baja\n\n");
                socios[indice].isEmpty = 1;

                for(int i = 0 ; i < tamPrestamos; i++){ // si doy de baja el socio tambien doy de baja sus prestamos
                    if(pres[i].codigoSocio == socios[indice].codigoSocio && pres[i].isEmpty == 0){
                        pres[i].isEmpty = 1;
                    }
                }

            }else{
                printf("\n\n\t\t  No se hecho la baja\n\n");
            }

        }

    }else{
        printf("\n\tNo hay socios que mostrar\n\n");
    }

}

int buscarSocio(eSocios socios[], int tam, int codigoSocio){

    int indice = -1;

    for(int i = 0; i < tam; i++){

        if(codigoSocio == socios[i].codigoSocio && socios[i].isEmpty == 0){
            indice = i;
            break;
        }
    }

        return indice;
}

void listarLibros(eLibros libros[], int tam){

        system("cls");
        printf("\n---------------------------------------------------------\n");
        printf("|   CODIGO LIBRO  |         TITULO       | CODIGO AUTOR |\n");
    for(int i = 0; i < tam; i++){
        printf("|    %10d   | %20s |  %10d  |\n", libros[i].codigoLibro, libros[i].titulo, libros[i].codigoAutor );
    }
}

void initLibros(eLibros libros[], int tamLibros){
    eLibros vec[] = {
        {2001, "Paula", 103},
        {2002, "Lenguaje C", 102},
        {2003, "Poemas de amor", 105},
        {2004, "Rayuela", 101},
        {2005,"Adulterio", 104},
        {2006, "Obras", 106},
        {2007, "Romeo y Julieta", 107},
        {2008, "Infierno", 108},
        {2009, "Infancia", 109},
        {2010, "Anne", 110},
        {2011, "La Espia", 104},
        {2012, "Amor", 103},
        {2013, "Soneto 130", 107},
        {2014, "Otelo", 107},
        {2015, "Bestiario", 101},
        {2016, "La Autopista", 101},
        {2017, "Convivio", 108},
        {2018, "Estravagario", 105},
        {2019, "El Zahir", 104},
        {2020, "Valquirias",104}
    };

    for(int i =0 ; i < tamLibros; i++){
        libros[i] = vec[i];
    }

}

void initAutores(eAutores autores[], int tamAutores){

    eAutores vec[] = {
        {101, "Cortazar", "Julio"},
        {102, "Richie", "Denis"},
        {103, "Allende", "Isabel"},
        {104, "Coelho", "Paulo"},
        {105, "Neruda", "Pablo"},
        {106, "Juan", "Rulfo"},
        {107, "Shakespeare", "William"},
        {108, "Alighieri","Dante"},
        {109, "Tolstoi", "Leon"},
        {110, "Frank", "Ana"}

        };

    for(int i = 0; i < tamAutores; i++){

        autores[i] = vec[i];
    }
}

void listarAutores(eAutores autores[], int tam){

     system("cls");
     printf("\n-------------------------------------------------------------------\n");
     printf("|   CODIGO AUTOR  |         NOMBRE       |         APELLIDO       |\n");
      for(int i = 0; i < tam; i++){
        printf("|    %10d   | %20s |  %20s  |\n", autores[i].codigoAutor, autores[i].nombre, autores[i].apellido );

    }
}

void altaPrestamo(ePrestamos prestamos[], int tamPrestamos, eLibros libros[], int tamLibros, eSocios socios[], int tamSocio){

    int indice;
    int codigoLibro;
    int codigoSocio;
    int dia, mes, anio;
    int indiceLibro;
    int indiceSocio;

    indice = buscarEspacioPrestamo(prestamos, tamPrestamos);

    if(indice == -1){
        printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
    }else{

        system("cls");
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
        listarLibros(libros, tamLibros);
        getInt(&codigoLibro, "\nIngrese codigo >> ", "Ingrese un numero valido >> ", 0 , INT_MAX);
        indiceLibro = buscarLibros(libros, tamLibros , codigoLibro);

        while(indiceLibro == -1){
            printf("\nNo se encontro el codigo %d, ", codigoLibro);
            getInt(&codigoLibro, "Ingrese codigo >> ", "Ingrese un numero valido >> ", 0 , INT_MAX);
            indiceLibro = buscarLibros(libros, tamLibros , codigoLibro);
        }

        system("cls");
        listarSocios(socios, tamSocio);
        getInt(&codigoSocio, "Ingrese codigo >> ", "Ingrese un numero valido >> ", 0, INT_MAX);
        indiceSocio = buscarSocio(socios, tamSocio, codigoSocio);

        while(indiceSocio == -1){
            printf("\nNo se encontro el codigo %d, ", codigoSocio);
            getInt(&codigoSocio, "Ingrese codigo >> ", "Ingrese un numero valido >> ", 0 , INT_MAX);
            indiceSocio = buscarSocio(socios, tamSocio, codigoSocio);
        }

        system("cls");
        printf("---------------------------\n");
        printf("| Ingrese Fecha Prestamo |\n");
        printf("---------------------------\n");

        getInt(&dia, "Ingrese dia >> ", "Ingrese un dia valido >> ", 1, 31);
        getInt(&mes, "Ingrese mes >> ", "Ingrese un mes valido >> ", 1 ,12);
        getInt(&anio, "Ingrese anio >> ", "Ingrese un anio valido, Rango debe ser entre 2010 - 2019 >> ", 2010, 2019);

        while(anio < socios[indiceSocio].fechaAsociado.anio && (mes <= socios[indiceSocio].fechaAsociado.mes ||
            mes >= socios[indiceSocio].fechaAsociado.mes || dia >= socios[indiceSocio].fechaAsociado.dia
              || dia <= socios[indiceSocio].fechaAsociado.dia)){

            system("cls");
            printf("---------------------------\n");
            printf("| Ingrese Fecha Prestamo |\n");
            printf("---------------------------\n");
            printf("EL SOCIO SE DIO DE ALTA EN LA FECHA: %d/%d/%d, Por favor ingrese una fecha valida\n\n",socios[indiceSocio].fechaAsociado.dia,
                                                                                                           socios[indiceSocio].fechaAsociado.mes,
                                                                                                           socios[indiceSocio].fechaAsociado.anio);

            getInt(&dia, "Ingrese dia >> ", "Ingrese un dia valido >> ", 1, 31);
            getInt(&mes, "Ingrese mes >> ", "Ingrese un mes valido >> ", 1 ,12);
            getInt(&anio, "Ingrese anio >> ", "Ingrese un anio valido, Rsngo debe estar entre 2010 - 2019 >> ", 2010, 2019);
        }


        prestamos[indice].codigoPrestamo = asignarCodigoPrestamos(prestamos, tamPrestamos);
        prestamos[indice].codigoSocio = codigoSocio;
        prestamos[indice].codigoLibro = codigoLibro;
        prestamos[indice].fechaPrestamo.dia = dia;
        prestamos[indice].fechaPrestamo.mes = mes;
        prestamos[indice].fechaPrestamo.anio = anio;
        prestamos[indice].isEmpty = 0;

        printf("\n\nSe ha hecho el alta exitosamente\n\n");
    }

}

int buscarEspacioPrestamo(ePrestamos prestamos[], int tam){

    int indice = -1;

    for(int i = 0; i < tam; i++){
        if(prestamos[i].isEmpty == 1){

            indice = i;
            break;
        }
    }

    return indice;
}

int asignarCodigoPrestamos(ePrestamos prestamos[], int tam){

    int codigoPrestamo = 1;

    for(int i= 0; i < tam; i++){


        if(prestamos[i].isEmpty)
            break;
        else
            codigoPrestamo++;

        if(prestamos[i].isEmpty == 1){
            codigoPrestamo = codigoPrestamo;
            break;
        }else{
            codigoPrestamo++;
        }

    }

    return codigoPrestamo;
}

/* HARDCODEO DE LOS PRESTAMOS */
/*void hardCodingPrestamos(ePrestamos prestamos[], int tam){

    int i;
    ePrestamos auxVec[6] = {
<<<<<<< HEAD
    {1, 2020, 1000, {5, 1, 2019},0},
    {2, 2002, 1001, {5, 1, 2019}, 0},
    {3, 2013, 1002, {9, 6, 2019}, 0},
    {4, 2002, 1000, {5, 7, 2019}, 0},
    {5, 2009, 1003,{13, 8, 2019},0},
    {6, 2004, 1001, {30,9, 2019},0},
=======
    {1, 2020, 100, {5, 1, 2019},0},
    {2, 2002, 101, {5, 1, 2019}, 0},
    {3, 2013, 102, {9, 6, 2019}, 0},
    {4, 2002, 100, {5, 7, 2019}, 0},
    {5, 2009, 103,{13, 8, 2019},0},
    {6, 2004, 101, {30,9, 2019},0},
>>>>>>> 4efcc79093439c03219ad32219b371e5b67cba77
// codigo prestamo, codigo libro, codigo socios, fecha, isEmpty
    };

   for(i = 0; i < tam; i++){
        if(i != 6){
            if(prestamos[i].isEmpty == 1){
                prestamos[i] = auxVec[i];
            }
        }else
            break;

    }
}
<<<<<<< HEAD
*/


/*void initPrestamos(ePrestamos pres[], int tam){

    for(int i = 0 ; i < tam; i++)
       pres[i].isEmpty = 1;



*/

void initPrestamos(ePrestamos pres[], int tam){

    for(int i = 0 ; i < tam; i++){
       pres[i].isEmpty = 1;

    }


}

int buscarLibros(eLibros libros[], int tamLibros, int codigoLibro){

    int indice = -1;
    for(int i = 0; i < tamLibros; i++){

        if(libros[i].codigoLibro == codigoLibro){
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarFechaExistente(ePrestamos prestamos[], int tam, int dia, int mes, int anio){

    int existe = 1;

    for(int i = 0; i < tam; i++){
        if(prestamos[i].fechaPrestamo.dia == dia && prestamos[i].fechaPrestamo.mes == mes && prestamos[i].fechaPrestamo.anio == anio && prestamos[i].isEmpty == 0){
            existe = 0;
            break;
        }
    }

    return existe;
}


void modificarSocios(eSocios socios[], int tam){

    int codigo;
    int indice;
    int opcion;
    char nNombre[1024];
    char nApellido[1024];
    char nSexo;
    char nTelefono[1024];
    char nEmail[1024];
    char respuesta;
    int ok;


    ok = listarSocios(socios, tam);

    if(ok == 0){
        getInt(&codigo, "Ingrese codigo: ", "Ingrese un numero valido: ", 0, INT_MAX-1);

        indice = buscarSocio(socios, tam, codigo);

        if(indice == -1){
            printf("\n\nNo se pudo encontrar el socio de codigo %d", codigo);
        }else{

            do{
                switch((opcion=menuModificar(socios[indice]))){
                case 1:
                    system("cls");
                    printf("\t\tMODIFICAR NOMBRE\n\n");
                    getString(nNombre, "Ingrese nombre: ", "Debe estar entre 1 y 51 caracteres: ", 1, 51);
                    printf("\n\n");
                    getChar(&respuesta, "Esta seguro que quiere realizar el cambio? [s/n] ", "Ingrese una opcion valida! [s/n] ", 's', 'n');
                    if(respuesta == 's'){
                        strcpy(socios[indice].nombre ,nNombre);
                        printf("\n\nSe ha hecho el cambio correctamente\n\n");
                    }else{
                        printf("\n\nNo se ha realizado ningun cambio\n\n");
                    }
                    system("pause");
                  break;

                case 2:
                    system("cls");
                    printf("\t\tMODIFICAR APELLIDO\n\n");
                    getString(nApellido, "Ingrese apellido: ", "Debe estar entre 1 y 51 caracteres: ",1, 51);
                    printf("\n\n");
                    getChar(&respuesta, "Esta seguro que quiere realizar el cambio? [s/n] ", "Ingrese una opcion valida! [s/n] ", 's', 'n');
                    if(respuesta == 's'){
                        strcpy(socios[indice].apellido ,nApellido);
                        printf("\n\nSe ha hecho el cambio correctamente\n\n");
                    }else{
                        printf("\n\nNo se ha realizado ningun cambio\n\n");
                    }
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    printf("\t\tMODIFICAR SEXO\n\n");
                    getChar(&nSexo, "Ingrese sexo [m/f]: ", "Sexo no valido, ingrese [m/f]: ",'m', 'f');
                    printf("\n\n");
                    getChar(&respuesta, "Esta seguro que quiere realizar el cambio? [s/n] ", "Ingrese una opcion valida! [s/n] ", 's', 'n');
                    if(respuesta == 's'){
                        socios[indice].sexo = nSexo;
                        printf("\n\nSe ha hecho el cambio correctamente\n\n");
                    }else{
                        printf("\n\nNo se ha realizado ningun cambio\n\n");
                    }
                    system("pause");

                    break;

                case 4:
                     system("cls");
                    printf("\t\tMODIFICAR TELEFONO\n\n");
                    getString(nTelefono, "Ingrese telefono: ", "Debe estar entre 1 y 51 caracteres: ",1, 16);
                    printf("\n\n");
                    getChar(&respuesta, "Esta seguro que quiere realizar el cambio? [s/n] ", "Ingrese una opcion valida! [s/n] ", 's', 'n');
                    if(respuesta == 's'){
                        strcpy(socios[indice].telefono ,nTelefono);
                        printf("\n\nSe ha hecho el cambio correctamente\n\n");
                    }else{
                        printf("\n\nNo se ha realizado ningun cambio\n\n");
                    }
                    system("pause");

                    break;

                case 5:
                    system("cls");
                    printf("\t\tMODIFICAR EMAIL\n\n");
                    getString(nEmail, "Ingrese email: ", "Debe estar entre 1 y 51 caracteres: ",1, 31);
                    printf("\n\n");
                    getChar(&respuesta, "Esta seguro que quiere realizar el cambio? [s/n] ", "Ingrese una opcion valida! [s/n] ", 's', 'n');
                    if(respuesta == 's'){
                        strcpy(socios[indice].email ,nEmail);
                        printf("\n\nSe ha hecho el cambio correctamente\n\n");
                    }else{
                        printf("\n\nNo se ha realizado ningun cambio\n\n");
                    }
                    system("pause");

                    break;

                case 6:
                    //salir
                    break;

                default:
                    printf("Ingrese una opcion valida\n\n");
                    break;
                }
            }while(opcion != 6);
        }
    }else{
        printf("\n\tNo hay socios que mostrar\n\n");
    }
}

int menuModificar(eSocios socio){

    int opcion;
    system("cls");
    printf("\t\t*****MODIFICAR SOCIO*****\n\n");
    printf("--> %d %s %s %c %s %s\n\n", socio.codigoSocio, socio.apellido, socio.nombre, socio.sexo, socio.email, socio.telefono);
    printf("1- Modificar nombre\n\n");
    printf("2- Modificar apellido\n\n");
    printf("3- Modificar sexo\n\n");
    printf("4- Modificar telefono\n\n");
    printf("5- Modificar email\n\n");
    printf("6- Atras\n\n\n");

    getInt(&opcion, "Ingrese una opcion >> ", "Ingrese un numero valido >> ", 0, INT_MAX-1);
    return opcion;
}
