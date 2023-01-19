#include <stdlib.h>
#include <stdio.h>


typedef struct
{
    char nombre[20];
    char pais[20];
    int puntos;
} participante;
// en esta parte cree una structura en donde le dire que ocupare un nombre maximo 20 caracteres al igual que un pais y un puntos de tipo entero

typedef struct n
{
    participante p;
    struct n *izquierda;
    struct n *derecha;
} Nodo;
//creamos el nodo y le damos esos punteros a izquierda y derecha



void insertar(participante, Nodo **);
int Cadenita(char *, char *);
void Orden(Nodo *);
void posiciones(Nodo *);
void nacion(Nodo *);
//las funciones que ocupare

void insertar(participante p, Nodo **raiz)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->p = p;
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;

    Nodo *padre;
    Nodo *actual;

    actual = *raiz;
    if(actual == NULL)
    {
        *raiz = nuevo;
        return;
    }
    
    while(1)
    {
        padre = actual;
        if(Cadenita(p.nombre, actual->p.nombre) == 1)
        {
            actual = actual->derecha;
            if(actual == NULL)
            {
                padre->derecha = nuevo;
                return;
            }
        }
        else
        {
            actual = actual->izquierda;
            if(actual == NULL)
            {
                padre->izquierda = nuevo;
                return;
            }
        }
    }
}
// aqui implemnete todo el arbol binario agregando que se va ordenar alfabeticamente los nodos 

int Cadenita(char *x, char *y)
{
    int i = 0, j = 0;
    while(x[i] != 0 && y[i] != 0){
	
        if(x[i] < y[i])
            return -1;
        else if(x[i] > y[i])
            return 1;

    if(x[i] == 0 || y[i] == 0)
        if(x[i] != 0)
            return 1;
        else if(y[i] != 0)
            return -1;
            i++;
        }

    return 0;
}
//esta funcion es la que esta encargada de ordenarlo alfabeticamnete para llegar al arbol


void Orden(Nodo *raiz)
{
    if(raiz!= NULL){
        Orden(raiz->izquierda);
        printf("%s, %s, +%d puntos por su medalla\n ",raiz->p.nombre,raiz->p.pais,raiz->p.puntos);
        Orden(raiz->derecha);
    }
}
// funcion de ordenamiento podemos notar que es un inOrder para que se note bien ese orden descendente  
void posicion(Nodo *raiz)
{
    if(raiz!= NULL){
        posicion(raiz->izquierda);
        printf(" %s obtuvo en total %d puntos en las ESCOlimpiadas\n ",raiz->p.pais,raiz->p.puntos);
        posicion(raiz->derecha);
    }
}
//funcion de ordenamiento que ocupe para imprimir los puntos obtenidos por pais

void nacion(Nodo *raiz)
{
    if(raiz!= NULL){
        nacion(raiz->izquierda);
        printf(" Participante: %s Pais: %s \n ",raiz->p.nombre,raiz->p.pais);
        nacion(raiz->derecha);
    }
}
//funcion de ordenamiento que implemente para imprimir los participantes con su pais

int main()
{
	//implemnete un menu para que fuese mas comodo el poder manipularlo
	int input = 0;
	printf("Las ESCOlimpiadas 20223\n");
	printf("Recordemos que los valores de las medallas son:...\nMedalla de Oro 10pts\nMedalla de Plata 5pts\nMedalla de Bronce 2pts\n");
do {
printf("\nQue Quieres Saber De la Competencia  - \n");
printf("\t1 : Lista de los 51 Jugadores \n"); //puse 51 participantes ya que el examen decia (por lo menos 50) entonces agregue uno mas por cualquier cosa 
printf("\t2 : Participantes de Mexico\n"); //mostrara los participantes de ese pais
printf("\t3 : Participantes de Canada  \n");//mostrara los participantes de ese pais
printf("\t4 : Participantes de EUA \n");//mostrara los participantes de ese pais
printf("\t5 : Participantes de Francia \n");//mostrara los participantes de ese pais
printf("\t6 : Participantes de Unite Kingdom (UK) \n");//mostrara los participantes de ese pais
printf("\t7 : Participantes de Colombia  \n");//mostrara los participantes de ese pais
printf("\t8 : Participantes de Italia  \n");//mostrara los participantes de ese pais

printf("\t9 : Quienes Tuvieron Medalla De Oro? \n");// participantes que obtuvieron oro
printf("\t10 : Quienes Tuvieron Medalla De Plata?\n");// participantes que obtuvieron plata
printf("\t11 : Quienes Tuvieron Medalla De Bronce?  \n");// participantes que obtuvieron bronce
printf("\t12 : La Suma De Los Puntos Por Sus Medallas \n"); //total de puntos obtenidos
printf("\n\t0 : Salir\n");
printf("\nSeleccionaste > ");
scanf(" %i", &input);
switch (input){
case 0:{
exit(0);
}
case 1:{
	FILE *archivo = fopen("ListaDe51Participantes.txt", "rt");//implemento el archivo y le indico que lea
    participante aux; // creamos un nodo auxiliar 
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0) //puse que sea >0 ya que al leer el archivo .txt al llegar a una linea que no pueda leer dar -1 entonces saldra del rango
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los Participantes Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 2:{
	FILE *archivo = fopen("ParticipantesMexico.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Mexicanos Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 3:{
	FILE *archivo = fopen("ParticipantesCanada.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Canadienses Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 4:{
	FILE *archivo = fopen("ParticipantesEUA.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Americanos Ordenados por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 5:{
	FILE *archivo = fopen("ParticipantesFrancia.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Franceses  Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 6:{
	FILE *archivo = fopen("ParticipantesUK.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Inlgeses Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 7:{
	FILE *archivo = fopen("ParticipantesColombia.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Colombianos Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 8:{
	FILE *archivo = fopen("ParticipantesItalia.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los participantes Italianos Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    nacion(raiz);

break;
}
case 9:{
	FILE *archivo = fopen("BaseDatosOro.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los ganadores de Oro Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    Orden(raiz);

break;
}
case 10:{
		FILE *archivo = fopen("BaseDatosPlata.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los ganadores de Plata Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    Orden(raiz);

break;
}
case 11:{
		FILE *archivo = fopen("BaseDatosBronce.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los ganadores de Bronce Ordenados Alfabeticamente por Arbol Binario son: \n\n");
    Orden(raiz);

break;
}
case 12:{
	FILE *archivo = fopen("BaseDeDatosPosiciones.txt", "rt");
    participante aux;
    Nodo *raiz = NULL;

    while(fscanf(archivo, "%s %s %d", aux.nombre, aux.pais, &aux.puntos) > 0)
    {
        //printf(" %s, %s, %d\n",aux.nombre,aux.pais,aux.puntos);
        insertar(aux, &raiz);
    }
    printf("Los Paises Quedaron de la siguiente manera \n\n");
    posicion(raiz);
	
break;
}

default:{
break;
}
}
} while (input != 0);
    
    
    
}