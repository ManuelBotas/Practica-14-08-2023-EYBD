#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf;

typedef struct
{
  long int cod;
  char desc[25];
  int cant;
  float pre;
} registro;

typedef struct elemento
{
  registro datos;
  struct elemento *sig;
} nodo;

void Tecla(void);
int menu(void);
void cargapila(nodo**,registro[], int);
void mostrar(FILE*);
int pilaVacia(nodo*);
nodo desapilar(nodo**);
void eliminarPila(nodo**);
void listarPila(nodo*);
void apilar(nodo**, nodo*);
nodo *ingresarDato(int, registro[]);

int main() {
    registro info[] = {
    {100235, "Nebulizador", 50, 145.20},
    {100312, "Tensiometro", 120, 159.35},
    {200045, "Caloventor", 35, 46.00},
    {200511, "Estufa halogena", 15, 72.58},
    {400805, "Afeitadora", 100, 215.40},
    {400322, "Cortadora de Cabello", 210, 29.45}
    };

    registro infocom[] = {
    {500100, "Reproductor de DVD", 24, 200.53},
    {100312, "Tensiometro", 50, 159.35},
    {500235, "Televisor 21", 30, 565.60},
    {200511, "Estufa halogena", 30, 72.58}
    };

    nodo *pila_info, *pila_infocom;
    int op, Cant_Elementos;
    pila_info = NULL;
    pila_infocom = NULL;

    system("color 0a");

    do {
        op = menu();
        switch (op) {
            case 1:
                Cant_Elementos = sizeof(info) / sizeof(info[0]);
                cargapila(&pila_info, info, Cant_Elementos);
                Cant_Elementos = sizeof(infocom) / sizeof(infocom[0]);
                cargapila(&pila_infocom, infocom, Cant_Elementos);
                break;
            case 2:
                p("WIP\n");
                break;
            case 3:
                p("WIP\n");
                break;
            case 4:
                p("WIP\n");
                break;
            case 5:
                p("WIP\n");
                break;
        }
    } while (op != 5);
    return 0;
}

void Tecla(void)
{
	printf("\nPresione una tecla para continuar...");
	getch();
}

int menu(void)
{
  int op;
  do
  {
    system("cls");
    printf("\n\t\t\t\t MENU DE OPCIONES (PILAS)\n\n");
    printf("\n\n\t\t\t\t - CARGAR DATOS INICIALES     <1>\n");
    printf("\n\n\t\t\t\t - AGREGAR DATOS                      <2>\n");
    printf("\n\n\t\t\t\t - LISTAR DATOS                         <3>\n");
    printf("\n\n\t\t\t\t - CARGAR EN ARCHIVO               <4>\n");
    printf("\n\n\t\t\t\t - BORRAR Y SALIR                       <5>\n");
    printf("\n\n\t\t\t\t - INGRESE OPCION  [1-5]:  ");
    scanf("%d", &op);
  } while (op < 1 || op > 5);
  return op;
}

void cargapila(nodo**x,registro y[], int z)
{
    int i;
    nodo *q;
    for(i=0;i<z;i++)
    {
        q=ingresarDato(i,y);
        apilar(&(*x),q);
    }
}

void mostrar(FILE*x)
{
   registro r;
    p("\n\t\t CONTENIDO DE LOS REGISTROS EN EL ARCHIVO\n\n");
    p("\n\n Codigo\t\tNombre\t\t\tCantidad\t\tPrecio\n\n");
    rewind(x);
    fread(&r,sizeof(r),1,x);
	while(!feof(x))
	{
		p("\n\n%3d\t\t%-20s\t%6d\t\t\t%6.2f",r.cod,r.desc,r.cant,r.pre);
		fread(&r,sizeof(r),1,x);
	}
}

int pilaVacia(nodo *pl)
{
    if (pl == NULL)
    {
        printf("\n\nPILA VACIA\n\n");
        system("pause");
 
        return 0;
    }
    else
        return 1;
}
nodo desapilar(nodo **pl)
{
    nodo dato, *aux;
    aux = *pl;
    dato = **pl;
    *pl = (*pl)->sig;
    free(aux);
    return dato;
}

void eliminarPila(nodo **pl) 
{
    nodo *aux;
    while (*pl) 
    {
        aux = *pl;
        *pl = (*pl)->sig;
        free(aux);
    }
}

void listarPila(nodo *pl)
{
    printf("CONTENIDO DE LA PILA\n\n");
    while (pl)
    {
        printf("%6d \t %-20s %4d \t %8.2f\n", pl->datos.cod, pl->datos.desc, pl->datos.cant, pl->datos.pre);
        pl = pl->sig;
    }
    printf("\n\n");
    system("pause");
}

void apilar(nodo **pl, nodo *d)
{
    d->sig = *pl;
    *pl = d;
}

nodo *ingresarDato(int i, registro y[])
{
    nodo *q;
    q = (nodo*)malloc(sizeof(nodo));
    q->datos = y[i];
    q->sig = NULL;
    return q;
}