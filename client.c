#include "sock-lib.h"
#include "ABM.h"
#define NO_ALUMNO -1
#define ALUMNO 1

int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int opcion,escuchar;	
	int flag_seguir_conectado=0;
	struct nodo *p,*c;		
	unsigned int aux;		//linea agregada por el ayudante
	int flag=0;

/* Tratamiento de la línea de comandos. */
	if (argc < 3)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
        }

	sockfd = conectar (argc, argv);
	
	system("clear");

	if(!(c=(struct nodo*)malloc(sizeof(struct nodo))))
 				
  			printf("\nMemoria Insuficiente\n");

	if(!(p=(struct nodo*)malloc(sizeof(struct nodo))))
 				
  			printf("\nMemoria Insuficiente\n");
 				

	printf("\nQue Desea Hacer\? \n\t 1- Buscar Alumno \n\t 2- Listar Todo \n\t 0- Salir\n\t Escriba la opcion: ");
	__fpurge(stdin);
	scanf("%d",&opcion);	
	while(opcion !=0 && opcion !=1 && opcion !=2)
	{
	  puts("opcion incorrecta, ingresela de nuevo\n");
	  scanf("%d",&opcion);
	}
	
	write(sockfd,&opcion,sizeof(opcion));

	if(opcion!=0)
	{
	do
	{
		if(flag_seguir_conectado>0)
			{
			sockfd = conectar (argc, argv);
			printf("\nQue Desea Hacer\? \n\t 1- Buscar alumno \n\t 2- Listar registro entero \n\t 0- Terminar conexion\n\t Escriba la opcion: ");
			__fpurge(stdin);			
			scanf("%d",&opcion);

			write(sockfd,&opcion,sizeof(opcion));			
			}

		if(!opcion)
			{
			close(sockfd);
			}
		if(opcion==1)
			{

			printf("\nIngrese el Legajo: ");
			scanf("%u",&aux);
			c->alumno.legajo=aux;
			write(sockfd,c,sizeof(struct nodo));
			read(sockfd,&flag,sizeof(flag));
			
		if(flag==NO_ALUMNO)
		  puts("el legajo no esta en la lista\n");
		
		if(flag==ALUMNO)
		{
			read(sockfd,p,sizeof(struct nodo));
		
		
			printf("Legajo\tNombre\t\tApellido\tTelefono\tCalle\t\tNumero\t\tMateria\t\tParcial 1\tParcial 2\n");;
			listar_nodo(p);
		}

			}
		if(opcion==2)
		{
printf("Legajo\tNombre\t\tApellido\tTelefono\tCalle\t\tNumero\t\tMateria\t\tParcial 1\tParcial 2\n");
do
			{
			read(sockfd,p,sizeof(struct nodo));
			
			listar_nodo(p);
			}while(p->next!=NULL);
			
			
		}
		printf("\nDesea seguir conectado con el servidor\n\t 1- Seguir conectado \n\t 0- Terminar conexion\n\t Escriba la opcion: ");
		__fpurge(stdin);
		scanf("%d",&escuchar);		
			
		
		write(sockfd,&escuchar,sizeof(escuchar));
		flag_seguir_conectado=1;
		}while(opcion && escuchar);
		}

	free(p);
	free(c);
	close(sockfd);
	return 0;
}


