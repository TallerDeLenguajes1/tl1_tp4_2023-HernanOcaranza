#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int autoIncremento = 1;

typedef struct Tarea
{
    int TareaId;
    char* Descripcion;
    int Duracion;
} Tarea;

//Declaracion de Funciones
void InicializarListaDeTareas(Tarea** listaTareas, int cantidadTareas);

void CargarListaDeTareas(Tarea** listaTareas, int cantidadTareas);

void MostrarTarea(Tarea* tarea);

void MostrarListaTareas(Tarea** listaTareas, int cantidadTareas);

//Funcion principal
int main ()
{
    int cantTareas, i, res = 0;    
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantTareas);

    Tarea** pTareasPendientes = (Tarea**) malloc((sizeof(Tarea*)) * cantTareas);
    Tarea** pTareasRealizadas = (Tarea**) malloc((sizeof(Tarea*)) * cantTareas);
    
    InicializarListaDeTareas(pTareasPendientes, cantTareas);
    InicializarListaDeTareas(pTareasRealizadas, cantTareas);

    //Cargar Tareas
    CargarListaDeTareas(pTareasPendientes, cantTareas);

    //Listar Tareas preguntando cual se realizo
    for(i = 0; i < cantTareas; i++)
    {
        MostrarTarea(pTareasPendientes[i]);
        printf("\n\nSe realizo esta tarea? (1|si) / (0|no): ");
        scanf("%d", &res);
        if(res == 1)
        {
            pTareasRealizadas[i] = pTareasPendientes[i];
            pTareasPendientes[i] = NULL;
        }
    }

    //Mostrando tareas Realizadas
    printf("\n\nTareas realizadas:");
    MostrarListaTareas(pTareasRealizadas, cantTareas);

    //Mostrando tareas pendientes
    printf("\n\nTareas pendientes:");
    MostrarListaTareas(pTareasPendientes, cantTareas);

    //Liberar memoria
    for (i = 0; i < cantTareas; i++)
    {
        if(pTareasPendientes[i] != NULL)
        {
            free(pTareasPendientes[i]->Descripcion);
            free(pTareasPendientes[i]);
        }
        else //Si la tarea no esta pendiente, esta realizada
        {
            free(pTareasRealizadas[i]->Descripcion);
            free(pTareasRealizadas[i]);
        }
    }
    free(pTareasPendientes);
    free(pTareasRealizadas);
    return 0;
}

//Desarrollo de Funciones
void InicializarListaDeTareas(Tarea** listaTareas, int cantidadTareas)
{
    int i;
    for (i = 0; i < cantidadTareas; i++)
    {
        listaTareas[i] = NULL;
    }
}

void CargarListaDeTareas(Tarea** listaTareas, int cantidadTareas)
{
    int i;
    char* buff;
    for (i = 0; i < cantidadTareas; i++)
    {
        listaTareas[i] = (Tarea*) malloc(sizeof(Tarea));

        listaTareas[i]->TareaId = autoIncremento;
        autoIncremento++;
        printf("\nIngrese la descripcion de la tarea %d: ", i+1);
        fflush(stdin);
        gets(buff);        
        listaTareas[i]->Descripcion = (char*) malloc(strlen(buff) + 1);
        strcpy(listaTareas[i]->Descripcion, buff);
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &listaTareas[i]->Duracion);
    }
}

void MostrarTarea(Tarea* tarea)
{
    printf("\n\nTarea Numero %d", tarea->TareaId);
    printf("\nDescripcion: ");
    puts(tarea->Descripcion);
    printf("Duracion: %d", tarea->Duracion);
}

void MostrarListaTareas(Tarea** listaTareas, int cantidadTareas)
{
    int i;
    for (i = 0; i < cantidadTareas; i++)
    {
        if (listaTareas[i] != NULL)
        {
            MostrarTarea(listaTareas[i]);
        }
    }
}