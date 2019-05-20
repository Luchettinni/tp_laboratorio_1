typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployee;

void initEmployees(sEmployee* listOfEmployees, int lenght);

void addEmployees( sEmployee employee[], int lenght, int id, char name[], char lastName[],float salary,int sector );

void printEmployees(sEmployee employee[], int length);

void sortEmployees(sEmployee employee[], int lenght, int order);

void removeEmployee(sEmployee employee[], int lenght, int id);

int findEmployeeById(sEmployee employee[], int lenght,int id);

int findLastId(sEmployee employee[], int length);

void informarTotalYProm (sEmployee employee[], int tam);

//---------------------------------------------------------------------------------------------------

int menuPrincipal ();

int menuModificar (sEmployee employee[], int *id, int tam);

int menuDeInformes ();
