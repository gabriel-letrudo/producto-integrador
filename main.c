# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>

# define CAD_MAX    50
# define MAX        5
# define SMALL      10
# define TRUE       1
# define FALSE      0

struct infoLibro{
    char titulo         [CAD_MAX];
    char autor          [CAD_MAX];
    char editorial      [CAD_MAX];
    char clave          [SMALL];
    char numPags        [SMALL];
};

typedef struct infoLibro tipoLibro;

struct _tipoPila{
    int tope;
    struct infoLibro tipoLibro  [MAX];
};

typedef struct _tipoPila tipoPila;

void inicializa(tipoPila *pPila){
    pPila->tope == -1;
}

int vacia(tipoPila *pPila){
    if(pPila->tope == -1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int llena(tipoPila *pPila){
    if(pPila->tope == MAX){
        printf("Memoria llena\n");
        getch();
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/*
void pilaTope(tipoPila *pPila){
    if(vacia(pPila)){
        printf("Pila vacia\n");
    }
    else{
        printf("%d\n",pPila->tipoLibro[pPila->tope]);
    }
}
*/
void push(tipoPila *pPila, tipoLibro *pLibro){
    if(!llena(pPila)){
        pPila->tipoLibro[pPila->tope++] = *pLibro;
    }
}

tipoLibro pop(tipoPila *pPila){
    if(!vacia(pPila)){
        return(pPila->tipoLibro[--pPila->tope]);
    }
    else{
        printf("Memoria libre; no hay libros por borrar\n");
    }
}

void muestraMenu(void);

void muestraLibros(tipoPila *pPila){
    tipoLibro *pLibroActual;
    int i;

    pLibroActual = &pPila->tipoLibro[0];

    for(i=0; i<MAX; ++i){
        printf("Libro: %s\n",pLibroActual->titulo);
        printf("Autor: %s\n",pLibroActual->autor);
        printf("Editorial: %s\n",pLibroActual->editorial);
        printf("Clave: %s\n",pLibroActual->clave);
        printf("Numero de paginas: %s\n",pLibroActual->numPags);
        pLibroActual = ++pLibroActual;
        printf("\n");
        //break;
    }
}

int main(void){


    struct infoLibro nuevoLibro;
    struct _tipoPila nuevaPila = {0};
    char tituloLibro            [CAD_MAX];
    char autorLibro             [CAD_MAX];
    char editorialLibro         [CAD_MAX];
    char claveLibro             [SMALL];
    char buscarClaveLibro       [SMALL];
    char pagsLibro              [SMALL];

    char op;
    inicio:
    system("cls");

    inicializa(&nuevaPila);

    printf("%d\n\n",nuevaPila.tope);

    muestraMenu();
    op=getchar();
    fflush(stdin);

    switch(op){
    case '1':
        system("cls");
        if(!llena(&nuevaPila)){
            printf("Ingrese el titulo del libro: ");
            scanf("%[^\n]",tituloLibro);

            strcpy(nuevoLibro.titulo,tituloLibro);

            fflush(stdin);

            printf("Ingrese la clave del Libro: ");
            scanf("%[^\n]",claveLibro);

            strcpy(nuevoLibro.clave,claveLibro);

            fflush(stdin);

            printf("Ingrese el nombre completo del Autor: ");
            scanf("%[^\n]",autorLibro);

            strcpy(nuevoLibro.autor,autorLibro);

            fflush(stdin);

            printf("Ingrese el nombre de la Editorial: ");
            scanf("%[^\n]",editorialLibro);

            strcpy(nuevoLibro.editorial,editorialLibro);

            fflush(stdin);

            printf("Ingrese el numero de paginas: ");
            scanf("%s",pagsLibro);

            strcpy(nuevoLibro.numPags,pagsLibro);

            fflush(stdin);

            push(&nuevaPila,&nuevoLibro);
        }
        goto inicio;
        break;
    case '2':
        system("cls");
        //printf("%s\n",nuevoLibro.titulo);
        //printf("%s\n",nuevoLibro.clave);
        printf("\n\n\t\t\t=====BUSCAR POR CLAVE DE LIBRO====\n\n\n");
        printf("Ingrese la clave del libro a buscar: ");
        scanf("%[^\n]",buscarClaveLibro);
        fflush(stdin);
        getch();
        goto inicio;
        break;
    case '3':
        system("cls");
        muestraLibros(&nuevaPila);
        getch();
        goto inicio;
        break;
    case '4':
        EXIT_SUCCESS;
        break;
    default:
        printf("Opcion invalida\n");
        getch();
        goto inicio;
    }

    printf("\n\n");

    system("pause");

    return 0;
}

void muestraMenu(void){
    char menu[][26] = {"Insertar libro","Buscar por clave de libro","Borrar libro","Salir"};
    int i;

    printf("\n\t\t\t   ======ACERVO DE LIBROS======\n\n\n");
    for(i=0; i<4; ++i){
        printf("%d. %s\n",(i+1),menu[i]);
    }
    printf("\n\nOpcion: ");
}
