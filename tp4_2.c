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

int main ()
{
    int cantTareas, i, res = 0;
    char* buff;
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantTareas);

    Tarea** pTareasPendientes = (Tarea**) malloc((sizeof(Tarea*)) * cantTareas);
    Tarea** pTareasRealizadas = (Tarea**) malloc((sizeof(Tarea*)) * cantTareas);
    for (i = 0; i < cantTareas; i++)
    {
        pTareasPendientes[i] = NULL;
        pTareasRealizadas[i] = NULL;
    }

    //Cargar Tareas
    for (i = 0; i < cantTareas; i++)
    {
        pTareasPendientes[i] = (Tarea*) malloc(sizeof(Tarea));

        pTareasPendientes[i]->TareaId = autoIncremento;
        autoIncremento++;
        printf("\nIngrese la descripcion de la tarea %d: ", i+1);
        fflush(stdin);
        gets(buff);
        pTareasPendientes[i]->Descripcion = (char*) malloc(strlen(buff) + 1);
        strcpy(pTareasPendientes[i]->Descripcion, buff);
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &pTareasPendientes[i]->Duracion);
    }

    //Listar Tareas
    for(i = 0; i < cantTareas; i++)
    {
        printf("\nTarea Numero %d", pTareasPendientes[i]->TareaId);
        printf("\nDescripcion: ");
        puts(pTareasPendientes[i]->Descripcion);
        printf("Duracion: %d", pTareasPendientes[i]->Duracion);
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
    for (i = 0; i < cantTareas; i++)
    {
        if (pTareasRealizadas[i] != NULL)
        {
            printf("\n\nTarea Numero %d", pTareasRealizadas[i]->TareaId);
            printf("\nDescripcion: ");
            puts(pTareasRealizadas[i]->Descripcion);
            printf("Duracion: %d", pTareasRealizadas[i]->Duracion);
        }
    }

    //Mostrando tareas pendientes
    printf("\n\nTareas pendientes:");
    for (i = 0; i < cantTareas; i++)
    {
        if (pTareasPendientes[i] != NULL)
        {
            printf("\n\nTarea Numero %d", pTareasPendientes[i]->TareaId);
            printf("\nDescripcion: ");
            puts(pTareasPendientes[i]->Descripcion);
            printf("Duracion: %d", pTareasPendientes[i]->Duracion);
        }
    }
    

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