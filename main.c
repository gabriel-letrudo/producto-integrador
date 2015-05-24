/*
*       Daniel Rodríguez - Gabriel Pérez Guerrero - @ 21/Mayo/2015 // Actualizado: 23/Mayo/2015
*
* Diseño e implementación de la solución para el almacenamiento de un acervo de libros para una biblioteca.
* Implementación de una estructura Pila y una estructura para la información de los libros.
*
* Producto_Integrador_-_Libros.c
*
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>

# define CAD_MAX    50  //Tamaño máximo de una cadena
# define MAX        5   //Capacidad máxima de la memoria - tamaño máximo de libros a guardar
# define SMALL      10  //Tamaño mínimo de una cadena
# define TRUE       1
# define FALSE      0

//Creamos una estructura con los campos para los datos del libro
struct infoLibro{
    char titulo         [CAD_MAX];
    char autor          [CAD_MAX];
    char editorial      [CAD_MAX];
    char clave          [SMALL];
    char numPags        [SMALL];
};

//Definimos una variable del tipo de estructura infoLibro, con el identificador tipoLibro
typedef struct infoLibro tipoLibro;

//Creamos una estructura de tipo _tipoPila para controlar el almacenamiento de libros
struct _tipoPila{
    int tope;
    struct infoLibro tipoLibro  [MAX];
};

//Definimos una variable del tipo de estructura _tipoLibro, con el identificador tipoPila
//Ojo: la estructura es _tipoPila, mientras que tipoPila es el identificador de la variable de ese tipo de estructura
typedef struct _tipoPila tipoPila;

//Inicializamos la pila
void inicializa(tipoPila *pPila){
    pPila->tope == -1;
}

//Verificamos si está vacía
int vacia(tipoPila *pPila){
    if(pPila->tope == -1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

//Verificamos si está llena
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

//Inserta un elemento (libro) nuevo a la pila
void push(tipoPila *pPila, tipoLibro *pLibro){
    //Si la pila NO está llena
    if(!llena(pPila)){
        pPila->tipoLibro[pPila->tope++] = *pLibro;
    }
}

//Remueve un elemento (libro) de la pila
tipoLibro pop(tipoPila *pPila){
    //Si la pila NO está vacía
    if(!vacia(pPila)){
        return(pPila->tipoLibro[--pPila->tope]);
    }
    else{
        printf("Memoria libre; no hay libros por borrar\n");
    }
}

//Prototipo de función que muestra el menú de opciones
void muestraMenu(void);

//Muestra los libros apilados
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

//Función principal
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

    //Esta línea es para verificar si se están almacenando los libros en la pila
    printf("%d\n\n",nuevaPila.tope);

    muestraMenu();
    op=getchar();
    //fflush(stdin) para evitar cualquier bug con carácteres ingresados
    fflush(stdin);

    switch(op){
    case '1':
        system("cls");
        if(!llena(&nuevaPila)){
            printf("Ingrese el titulo del libro: ");
            scanf("%[^\n]",tituloLibro);

            //Copiamos tituloLibro en nuevoLibro.titulo
            strcpy(nuevoLibro.titulo,tituloLibro);

            fflush(stdin);

            printf("Ingrese la clave del Libro: ");
            scanf("%[^\n]",claveLibro);

            //Copiamos claveLibro en nuevoLibro.clave
            strcpy(nuevoLibro.clave,claveLibro);

            fflush(stdin);

            printf("Ingrese el nombre completo del Autor: ");
            scanf("%[^\n]",autorLibro);

            //Copiamos autorLibro en nuevoLibro.autor
            strcpy(nuevoLibro.autor,autorLibro);

            fflush(stdin);

            printf("Ingrese el nombre de la Editorial: ");
            scanf("%[^\n]",editorialLibro);

            //Copiamos editorialLibro en nuevoLibro.editorial
            strcpy(nuevoLibro.editorial,editorialLibro);

            fflush(stdin);

            printf("Ingrese el numero de paginas: ");
            scanf("%s",pagsLibro);

            //Copiamos pagsLibro en nuevoLibro.numPags
            strcpy(nuevoLibro.numPags,pagsLibro);

            fflush(stdin);

            //Insertamos los datos anteriores en la pila
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
        //Esta línea es para verificar si se están almacenando los datos en la pila por cada libro
        //muestraLibros(&nuevaPila);
        getch();
        goto inicio;
        break;
    case '4':
        //TERMINA EXITOSAMENTE EL PROGRAMA
        EXIT_SUCCESS;
        break;
    default:
        //En caso de ingresar cualquier carácter inválido
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
