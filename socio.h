typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{
    int codigoAutor;
    char apellido[31];
    char nombre[31];

}eAutores;

typedef struct{
    int codigoLibro;
    char titulo[51];
    int codigoAutor;


}eLibros;

typedef struct{
   int codigoSocio;
   char apellido[40];
   char nombre[40];
   char sexo;
   char telefono[40];
   char email[40];
   int isEmpty;  // -1 baja logica 0 baja completa
   eFecha fechaAsociado;

}eSocios;

typedef struct{
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;
    int isEmpty;


}ePrestamos;


int menuPrincipal();
int menuDeOpciones();
int menuDeOpcionesInformes();
void abmLibreria(eSocios socios[], int tamSocios, eAutores autores[], int tam_autores,eLibros libros[], int tamLibros, ePrestamos prestamos[], int tam_prestamos);
void initSocios(eSocios socios[], int tam);

//int initSocios(eSocios socios[], int tam);

//void hardCodingSocios(eSocios socios[], int tam);
void initLibros(eLibros libros[], int tamLibros);
void initAutores(eAutores autores[], int tamAutores);
void initPrestamos(ePrestamos pres[], int tam);
//void hardCodingPrestamos(ePrestamos prestamos[], int tam);
int buscarFechaExistente(ePrestamos prestamos[], int tam, int dia, int mes, int anio);
int buscarEspacioSocio(eSocios socios[], int tam);
int buscarEspacioPrestamo(ePrestamos prestamos[], int tam);
int buscarLibros(eLibros libros[], int tamLibros, int codigoLibro);
int asignarCodigoSocio(eSocios socios[], int tam);
int asignarCodigoPrestamos(ePrestamos prestamos[], int tam);
int listarSocios(eSocios socios[], int tam);
void listarLibros(eLibros libros[], int tam);
void listarAutores(eAutores autores[], int tam);
int buscarSocio(eSocios socios[], int tam, int codigoSocio);
int altaSocio(eSocios socios[], int tam);
int menuModificar(eSocios socios);
void altaPrestamo(ePrestamos prestamos[], int tamPrestamos, eLibros libros[], int tamLibros, eSocios socios[], int tamSocio);
void modificarSocios(eSocios socios[], int tam);
void bajaSocio(eSocios socios[], int tam, ePrestamos pres[], int tamPrestamos);

