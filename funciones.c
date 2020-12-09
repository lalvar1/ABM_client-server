#include "ABM.h"


int altas(struct nodo **ppio)
{
  struct nodo *p;
  
  if(!(p=(struct nodo*)malloc(sizeof(struct nodo))))
  {
    printf("No hay memoria suficiente.\n");
    return 1;
  }
  
  system("clear");
  printf("\n");
  printf("Ingrese el Legajo:\t");
  scanf("%u", &(p->alumno.legajo));
  printf("Ingrese el Nombre:\t");
  __fpurge(stdin);
  fgets(p->alumno.nombre, 20, stdin);
  printf("Ingrese el Apellido:\t");
  __fpurge(stdin);
  fgets(p->alumno.apellido, 20, stdin);
  printf("Ingrese el N° de Telefono:\t");
  scanf("%u", &(p->alumno.telefono));
  printf("Calle : \t");
  __fpurge(stdin);
  fgets(p->alumno.calle, 30, stdin);
  printf("Numero :\t");
  scanf("%hd", &(p->alumno.numero));
  printf("Materia que cursa : \t");
  __fpurge(stdin);
  fgets(p->alumno.materia, 30, stdin);
  printf("Ingrese nota del Parcial 1:\t");
  scanf("%hd", &(p->alumno.P1));
  printf("Ingrese nota del Parcial 2:\t");
  scanf("%hd", &(p->alumno.P2));

  p->next=*ppio;
  *ppio=p;
  
  //Carga La lista en el archivo
  escribirdata(p);
  return 0;	// linea agregada por Ayudante
}

int bajas(struct nodo **ppio)
{
 
  unsigned int ingresado;
  struct nodo *p,*aux;
    
  if(*ppio==NULL)
  {
    printf("\nLista VACIA");
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
    return(0);   
  }
  
  __fpurge(stdin);
  printf("\nIngrese el legajo del alumno a dar de baja\t");
  scanf("%u",&ingresado);
  for(p=*ppio; ingresado!=p->alumno.legajo && p->next; p=p->next);

  if(p==*ppio && p->alumno.legajo==ingresado)					// Si es el 1er elemento
  {
    *ppio=p->next;
    free(p);
    printf("\nAlumno dado de baja");
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
   return(0);
  }

  if(p->next==NULL && ingresado!=p->alumno.legajo )  // Si no lo encuentra
  {
    printf("\nEl legajo no esta en la lista");
    printf("\n\nPresione enter p/ seguir");
    __fpurge(stdin);
    getchar();
    return(0);
  }
  else
  {                                      // Elemento del 2do al ultimo 
      for(aux=*ppio; aux->next!=p; aux=aux->next);
      aux->next=p->next;
      free(p);
      printf("\nAlumno dado de baja");
      printf("\n\nPresione enter p/ seguir");
      __fpurge(stdin);
      getchar();;
      return(0);
   }
   
}

int modif(struct nodo **ppio)
{
  short opcion;
  unsigned int ingresado;
  struct nodo *p;
  
    if(*ppio==NULL)
	{
	printf("\nNo hay datos");
	printf("\n\nPresione enter p/ seguir");
	__fpurge(stdin);
	getchar();
	return(0);
	}
	
	printf("Ingrese legajo del alumno a modificar\n");
	scanf("%u",&ingresado);
	
	for(p=*ppio; ingresado!=p->alumno.legajo && p->next; p=p->next); //busco por legajo
	
	
    
  do{
    menuModif();
    scanf ("%hd", &opcion); 
    switch(opcion)
    {
      case 1: printf("Nuevo Legajo: ");
	      scanf("%u", &(p->alumno.legajo));
	      __fpurge(stdin);
	      if(p->next==NULL && ingresado!=p->alumno.legajo )    // Si no lo encuentra
	      printf("\nNo esta en la lista");
	      break;
      case 2: printf("Nuevo Nombre: ");
	      fgets(p->alumno.nombre, 20, stdin);
	      __fpurge(stdin);
	      if(p->next==NULL && ingresado!=p->alumno.legajo )    // Si no lo encuentra
	      printf("\nNo esta en la lista");
      
      break;
      case 3: printf("Nuevo apellido: ");
	      fgets(p->alumno.apellido, 20, stdin);
	      __fpurge(stdin);
	      if(p->next==NULL && ingresado!=p->alumno.legajo )    // Si no lo encuentra
	      printf("\nNo esta en la lista");
	      break;
      case 4: printf("Nuevo telefono: ");
	      scanf("%u", &(p->alumno.telefono));
	      __fpurge(stdin);
	      if(p->next==NULL && ingresado!=p->alumno.legajo )    // Si no lo encuentra
	      printf("\nNo esta en la lista");
	      break;
      case 5: printf("Nueva materia: ");
	      fgets(p->alumno.materia, 30, stdin);
	      __fpurge(stdin);
	      if(p->next==NULL && ingresado!=p->alumno.legajo )    // Si no lo encuentra
	      printf("\nNo esta en la lista");
              break;
         }
  }while(opcion!=0);
  
  return(0);
  

}


void liberar(struct nodo **ppio)
{
  struct nodo *p;
  for(p=*ppio;p;p=*ppio)
  {
    *ppio=p->next;
    free(p);
  }
  printf("\n\n\tMemoria Liberada! \n\n");
}

int listar(struct nodo *p)
{
  
  if(!p)
  {
	  printf("La lista esta vacia\n");
	  return 1;
  }
  else
  {__fpurge(stdin);
    printf("Legajo\tNombre\t\tApellido\tTelefono\tCalle\t\tNumero\t\tMateria\t\tParcial 1\tParcial 2\n");
    for( ;p;p=p->next){
      printf("%u\t %s\t\t\t%s\t\t\t\t\t%u\t %s\t\t\t\t\t\t\t\t\t %hd\t\t%s\t\t\t\t\t\t\t\t\t\t\t\t\t %hd\t\t\t%hd\n\n", p->alumno.legajo,p->alumno.nombre,p->alumno.apellido, p->alumno.telefono, p->alumno.calle, p->alumno.numero, p->alumno.materia, p->alumno.P1, p->alumno.P2);
      
    }
  }
  
  printf("\nPresiones Enter para continuar...  ");
  __fpurge(stdin);
  getchar();
  return 0;	//linea agregada por ayudante.
}


//lee el archivo data 
int leerdata(struct nodo **ppio)   
{
  FILE *fp;
  struct datos aux;
  struct nodo *p,*nuevo;

  system("clear");
  if(!(fp=fopen("data","rb")))
  {
    printf("No se puede abrir el archivo\n");
    return 1;
  }
  
  fread(&aux,sizeof(struct datos),1,fp);
  while(!feof(fp))
  {
    if(!(nuevo=(struct nodo *)malloc(sizeof(struct nodo))))
    {
      printf("No hay memoria suficiente\n");
      return 1;
    }
    
    nuevo->alumno=aux;
    if(!*ppio)
    {
      nuevo->next=*ppio;
      *ppio=nuevo;
    }
    else{
      for(p=*ppio;p->next;p=p->next);
      nuevo->next=NULL;
      p->next=nuevo;
    }

    fread(&aux,sizeof(struct datos),1,fp);
  }
  fclose(fp);
return 0;
}
//escribe la lista en el archivo data, de no existir este crea uno.
int escribirdata(struct nodo *ppio)  
{
  FILE *fp;
  struct nodo *p;
  if(!(fp=fopen("data","wb")))
  {
    printf("No se puede abrir el archivo\n");
    return 1;
  }

  for(p=ppio;p;p=p->next)
    fwrite(&(p->alumno),sizeof(struct datos),1,fp);
  
  fclose(fp);
  return 0;
}

void menuMain(void)
{
  
  printf ("\n\n\t\t\t | Base de Datos |\n");
  
  printf ("\t1. Altas\n");
  printf ("\t2. Bajas\n");
  printf ("\t3. Modificaciones\n");
  printf ("\t4. Consultas\n\n");
  printf ("\t0. Salir\n\n");
  
  printf ("\t\t# Seleccione una opcion: ");
}

void menuBajas(void)
{
  
  printf ("\n\n\t\t\t | MENU BAJAS |\n");

  printf ("\t1. Legajo\n\n");
//   printf ("\t2. Nombre\n");
//   printf ("\t3. Apellido\n");
//   printf ("\t4. Telefono\n");
//   printf ("\t5. Materia\n\n");
//   
  printf ("\t0. Voler Atras\n\n");
  
  printf ("\t\t# Seleccione una opcion para Buscar: ");
}

void menuModif(void)
{
  
  printf ("\n\n\t\t\t | MENU MODIFICACIONES |\n");

  printf ("\t1. Legajo\n");
  printf ("\t2. Nombre\n");
  printf ("\t3. Apellido\n");
  printf ("\t4. Telefono\n");
  printf ("\t5. Materia\n\n");
  
  printf ("\t0. Volver Atras\n\n");
  
  printf ("\t\t# Seleccione una opcion que desee Modificar: ");
}


struct nodo * Buscar(struct nodo **ppio,struct nodo *c)
{
  struct nodo *p; 
  
  p=*ppio;
  if(!p)
  {
    printf("\nLista VACIA");
    return(p);
  }
  for(p=*ppio; c->alumno.legajo!=p->alumno.legajo && p->next; p=p->next);
  if(p && p->alumno.legajo==c->alumno.legajo)					
  return(p);

//   if(p->next==NULL && c->alumno.legajo!=p->alumno.legajo )  // Si no lo encuentra
  else
  {
    printf("\nEl legajo solicitado por el cliente no esta en la lista\n");
    return(p=NULL);
    
  }
    return 0;		// linea agregada por ayudante
  
}

void listar_nodo(struct nodo *p)
{
  
  if(p==NULL)
  
	  printf("La lista esta vacia\n");
	 
  else
    
  
      printf("%u\t %s\t\t\t%s\t\t\t\t\t%u\t\t %s\t\t\t\t\t\t\t\t\t %hd\t\t%s\t\t\t\t\t\t\t\t\t\t\t\t\t %hd\t\t\t%hd\n", p->alumno.legajo,p->alumno.nombre,p->alumno.apellido, p->alumno.telefono, p->alumno.calle, p->alumno.numero, p->alumno.materia, p->alumno.P1, p->alumno.P2);
     
     
   

}