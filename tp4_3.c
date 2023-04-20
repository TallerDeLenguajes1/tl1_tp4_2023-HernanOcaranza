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

typedef struct {
    Tarea tarea;
    Tnodo* sig;
} Tnodo;

// ----------------------- Definicion de Funciones ----------

Tnodo* crearLista();
Tarea crearTarea(char* desc, int dur);
void MostrarTarea(Tarea tarea);
Tnodo * crearNodo(Tarea tarea);
void InsertarNodo(Tnodo** start, Tnodo* nuevoNodo);
void InsertarNodoAlFinal(Tnodo* start, Tnodo* nuevaTarea);
Tnodo* quitarNodo(Tnodo** start, int id);
void MostrarTareas(Tnodo* lista);

// ----------------------- Funcion Principal ----------------
//TODO
int main()
{
    int res;
    Tnodo* start = crearLista();

    do
    {
        printf("\n****** MENU ******");

        scanf("%d", &res);
    } while (res != 0);
    
    return 0;
}

// ----------------- Desarrollo de Funciones ---------------
Tnodo* crearLista()
{
    return NULL;
}

Tarea crearTarea(char* desc, int dur)
{
    Tarea nuevaTarea;
    nuevaTarea.TareaId = autoIncremento;
    autoIncremento++;
    nuevaTarea.Descripcion = (char*) malloc(strlen(desc) + 1);
    strcpy(nuevaTarea.Descripcion, desc);
    nuevaTarea.Duracion = dur;
}

void MostrarTarea(Tarea tarea)
{
    printf("\n\nTarea Numero %d", tarea.TareaId);
    printf("\nDescripcion: ");
    puts(tarea.Descripcion);
    printf("Duracion: %d", tarea.Duracion);
}

Tnodo * crearNodo(Tarea tarea)
{
    Tnodo* nuevoNodo = (Tnodo*) malloc(sizeof(Tnodo));
    nuevoNodo->tarea = tarea;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

void InsertarNodo(Tnodo** start, Tnodo* nuevoNodo)
{
    nuevoNodo->sig = *start;
    *start = nuevoNodo;
}

void InsertarNodoAlFinal(Tnodo* start, Tnodo* nuevaTarea)
{
    Tnodo* aux = start;
    while (aux->sig)
    {
        aux = aux->sig;
    }
    aux->sig = nuevaTarea;
}

Tnodo* quitarNodo(Tnodo** start, int id)
{
    Tnodo* aux = *start;
    Tnodo* auxAnterior = *start;
    
    while(aux && aux->tarea.TareaId != id)
    {
        auxAnterior = aux;
        aux = aux->sig;
    }

    if(aux)
    {
        if(aux == *start)
        {
            (*start) = (*start)->sig;        
        }
        else
        {
            auxAnterior->sig = aux->sig;
        }
        aux->sig = NULL;
    }
    return aux;
}

void EliminarNodo (Tnodo* nodo)
{
    if(nodo)
    {
        if(nodo->tarea.Descripcion)
        {
            free(nodo->tarea.Descripcion);
        }
        free(nodo);
    }
}

void EliminarLista(Tnodo** lista)
{
    Tnodo* aux = *lista;
    Tnodo* auxSiguiente = *lista;
    while(aux)
    {
        auxSiguiente = aux->sig;
        EliminarNodo(aux);
        aux = auxSiguiente;        
    }
}

void EliminarLista2(Tnodo** lista)
{    
    while(*lista)
    {
        EliminarNodo(quitarNodo(*lista, (*lista)->tarea.TareaId));
        (*lista) = (*lista)->sig;
    }
}

void MostrarTareas(Tnodo* lista)
{
    while(lista)
    {
        MostrarTarea(lista->tarea);
        lista = lista->sig;
    }
}