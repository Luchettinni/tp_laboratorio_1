typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployee;

//---------------------------------------------------------------------------------------------------
// FUNCIONES QUE PIDE EL TRABAJO PRACTICO

/** \brief inicializa la estructura de "sEmployee" con sus campos "isEmpty" en "1"
 * \param listOfEmployees es la estructura a inicializar
 * \param lenght es el tamañano de la previamente mencionada
 * \return retorna (-1) si no logro inicializarla o (0) en caso de exito
 */
int initEmployees(sEmployee* listOfEmployees, int lenght);

/** \brief Agrega en una estructura de tipo "sEmpleoyee" existente, los valores recibidos como parámetros, en la primer posición libre que encuentre la funcion en dicha estructura.
 * \param employee es la estructura a utilizar
 * \param lenght es el tamañano de la previamente mencionada
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return retorna (-1) si no tuvo exito o ( un entero >= 0 ) si tuvo exito
 */
int addEmployee(sEmployee* employee, int lenght, int id, char name[], char lastName[],float salary,int sector );

/** \brief imprime en pantalla cada elemento de la estructura
 * \param employee es la estructura a imprimir
 * \param lenght es el tamañano de la previamente mencionada
 * \return retorna (-1) si no tuvo exito o (0) si tuvo exito
 */
int printEmployees(sEmployee* employee, int length);

/** \brief ordena los elementos de la estructura de tipo "sEmployee" de manera ascendente si el parametro "order" es 1, y decendente si es 0
 * \param employee es la estructura a ordenar
 * \param lenght es el tamañano de la previamente mencionada
 * \param order [1] indica ordenamiento ascendente - [0] indica ordenamiento decendente
 * \return retorna (-1) si no tuvo exito o (0) si tuvo exito
 */
int sortEmployees(sEmployee* employee, int lenght, int order);

/** \brief elimina un elemento de la estructura a travez de una baja logica
 * \param employee es la estructura a utilizar
 * \param lenght es el tamañano de la previamente mencionada
 * \param id se utiliza para buscar el elemento a eliminar
 * \return retorna (-1) si no tuvo exito o (0) si tuvo exito
 */
int removeEmployee(sEmployee* employee, int lenght, int id);

/** \brief Busca un empleado por su ID
 * \param employee es la estructura a utilizar
 * \param lenght es el tamañano de la previamente mencionada
 * \param id se utiliza para buscar al empleado
 * \return retorna (-1) si no tiene exito o retorna el indice en el que se encuentra el empleado solicitado
 */
int findEmployeeById(sEmployee* employee, int lenght,int id);

//---------------------------------------------------------------------------------------------------
// FUNCIONES DE MENU

/** \brief muestra en pantalla un menu de opciones y al mismo tiempo, pregunta que opcion desea ejecutar de dicho menu
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuPrincipal ();

/** \brief muestra en pantalla un menu para modificar los distintos campos de un empleado
 * \param employee es la estructura a utilizar
 * \param tam es el tamañano de la previamente mencionada
 * \param id es correspondiente al empleado a modificar
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuModificar (sEmployee employee[], int *id, int tam);

/** \brief muestra en pantalla un menu de opciones y al mismo tiempo, pregunta que opcion desea ejecutar de dicho menu
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuDeInformes ();

//---------------------------------------------------------------------------------------------------
// FUNCIONES PROPIAS

/** \brief busca el ultimo ID de una lista de empleados
 * \param employee es la estructura a utilizar
 * \param lenght es el tamañano de la previamente mencionada
 * \param lastId es el ultimo ID hasta el momento ( y la funcion se encarga de sobreescribirlo en caso de que exista otro ID mayor a este )
 * \return retorna (-1) si no tuvo exito al encontrar el ultimo ID o (0) si tuvo exito
 */
int findLastId(sEmployee* employee, int length, int* lastId);

/** \brief calcula e informa el total y promedio de los salarios y cuantos empleados superan el salario promedio.
 * \param employee es la estructura a utilizar para calcular y listar
 * \param lenght es el tamañano de la previamente mencionada
 * \return retorna (-1) no tuvo exito o (0) si logro hacer todos los calculos e informar
 */
int informarTotalYProm (sEmployee* employee, int tam);

/** \brief carga los campos de una estructura
 * \param employee es la estructura a utilizar para calcular y listar
 * \param lenght es el tamañano de la previamente mencionada
 * \return retorna (-1) si no tuvo exito o (0) si logro cargarlos correctamente
 */
int initEstruct(sEmployee* employee, int tam);
