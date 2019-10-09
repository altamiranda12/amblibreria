void informes(eSocios socios[], int tamSocios, eAutores autores[], int tamAutores, eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos);
void listarLibrosPorTitulo(eLibros libros[], int tam);
void listarSociosPorApellido(eSocios socios[], int tam);
void listarSociosPorFechaDeterminada(eSocios socios[], int tamSocios, ePrestamos prestamos[], int tamPrestamos);
void listarLibrosPorFechaDeterminada(ePrestamos prestamos[], int tamPrestamos, eLibros libros[], int tamLibros);
void socioRealizoMasSolicitudesAPrestamo(ePrestamos prestamos[], int tamPrestamos, eSocios socios[], int tamSocios);
void librosMenosSolicitadosAPrestamo(eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos);
void librosSolicitadosPorSocioDeterminado(eSocios socios[], int tamSocios, eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos);
void sociosSolicitarUnLibroDeterminado(eLibros libros[], int tamLibros, eSocios socios[], int tamSocios, ePrestamos prestamos[], int tamPrestamos);
void diasCuyasSolicitudesNoSuperanPromedio(ePrestamos prestamos[], int tamPrestamos);
void totalGeneralYPromedioDiarios(ePrestamos prestamos[], int tamPrestamos);