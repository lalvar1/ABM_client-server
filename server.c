#include "sock-lib.h"
#include "ABM.h"
#define NO_ALUMNO -1 
#define ALUMNO 1

int main(void)
{
	int sockdup;
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	struct nodo *p,*c;
	int opcion,escuchar,flag=0;
	

	

	struct nodo *ppio=NULL;
	leerdata(&ppio);

	if ((sockfd = Open_conection (&my_addr)) == -1)
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}
	
	system("clear");

	do
	{
		sockdup = Aceptar_pedidos (sockfd);

		if(!(p=(struct nodo*)malloc(sizeof(struct nodo))))
 	  	printf("\nMemoria Insuficiente\n");
		if(!(c=(struct nodo*)malloc(sizeof(struct nodo))))		//Lineas agregadas por el ayudante
 	  	printf("\nMemoria Insuficiente\n");
 		

	printf("\nEscuchando\n");
	__fpurge(stdin);
	read(sockdup,&opcion,sizeof(opcion));
		if(opcion!=0)
		{
		if(opcion==1)
			{	

			read(sockdup,c,sizeof(struct nodo));
// 			p=Buscar(&ppio,&c);
			p=Buscar(&ppio,c);			//Linea agregada por el ayudante
			if(p==NULL)
			{
			  flag=NO_ALUMNO;
			  write(sockdup,&flag,sizeof(flag));
			  
			}
			else
			{
			  flag=ALUMNO;
			  write(sockdup,&flag,sizeof(flag));
			 
			write(sockdup,p,sizeof(struct nodo));
			}
		
			}
		if(opcion==2)
			{

		for(p=ppio;p!=NULL; p=p->next)
			write(sockdup,p,sizeof(struct nodo));
			}
	read(sockdup,&escuchar,sizeof(escuchar));
	if(escuchar==1)
		{	
		system("clear");
		printf("\nEl cliente quiere seguir conectado\n\n");
		}
		}
	}while(escuchar!=0 && opcion!=0);
	
	if(!escuchar)
	  puts("El cliente no quiere seguir, se cerrara la conexion\n");
	
	free(p);
	free(c);
	close(sockdup);
	
return(0);

}