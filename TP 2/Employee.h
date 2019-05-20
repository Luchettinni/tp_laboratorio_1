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
/** \brief para mostrar que todas las posiciones del array estan vacias, marca todas ellas como VACIAS
 * \param listOfEmployees es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \return void
 */
void initEmployees(sEmployee listOfEmployees[], int lenght);

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre
 * \param listOfEmployees es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return void
 */

void addEmployee( sEmployee employee[], int lenght, int id, char name[], char lastName[],float salary,int sector );

/** \brief muestra en pantalla cada elemento del array de empleados
 * \param employee es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \return void
 */
void printEmployees(sEmployee employee[], int length);

/** \brief ordena el array de empleados de manera ascendente si el argumento "order" es 1, y decendente si es 0
 * \param employee es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \param order [1] indica ordenamiento ascendente - [0] indica ordenamiento decendente
 * \return void
 */
void sortEmployees(sEmployee employee[], int lenght, int order);

/** \brief elimina a un empleado por id ( rellena isEmpty con un 1 )
 * \param employee es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \param id int
 * \return void
 */
void removeEmployee(sEmployee employee[], int lenght, int id);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 * \param employee es el array de empleados
 * \param lenght es el tamañano del array de empleados
 * \param id int
 * \return retorna el indice del array en el que se encuentra el empleado solicitado o retorna -1 si no logra encontrarlo.
 */
int findEmployeeById(sEmployee employee[], int lenght,int id);

/** \brief
 * \param
 * \param
 * \return
 */

//---------------------------------------------------------------------------------------------------
// FUNCIONES DE MENU

/** \brief muestra en pantalla un menu de opciones y al mismo tiempo, pregunta que opcion desea ejecutar de dicho menu
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuPrincipal ();

/** \brief muestra en pantalla un menu para modificar los distintos campos de un empleado
 * \param employee es el array de empleados
 * \param id es correspondiente al empleado a modificar
 * \param tam es el tamañano del array de empleados
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuModificar (sEmployee employee[], int *id, int tam);

/** \brief muestra en pantalla un menu de opciones y al mismo tiempo, pregunta que opcion desea ejecutar de dicho menu
 * \return retorna una opcion ingresada por el usuario correspondiente a las que se muestran en pantalla,
 */
int menuDeInformes ();

//---------------------------------------------------------------------------------------------------
// FUNCIONES PROPIAS

void findLastId(sEmployee employee[], int length, int* lastId);

void informarTotalYProm (sEmployee employee[], int tam);

void initEstruct(sEmployee employee[], int tam);
