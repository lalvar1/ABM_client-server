#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


struct datos  {
		  unsigned int legajo;
		  char nombre[21];
		  char apellido[21];
		  unsigned int telefono;
		  char materia[31];
		  char calle[31];
		  short numero;
		  short P1;
		  short P2;  
};

struct nodo {
	      struct datos alumno;
	      struct nodo *next;
};

int altas(struct nodo **ppio);
int bajas(struct nodo **ppio);
int modif(struct nodo **ppio);
int listar(struct nodo *p);
void liberar(struct nodo **ppio);
int leerdata(struct nodo **);
int escribirdata(struct nodo *);
void menuMain(void);
void menuBajas(void);
void menuModif(void);
struct nodo *Buscar(struct nodo **,struct nodo*);
void listar_nodo(struct nodo *p);

