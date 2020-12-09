#include "ABM.h"


int main (void)
{
  struct nodo *inicio=NULL;
  int estado;
  short opcion;
  
  //Cargo el contenido del archivo a la lista 
  estado=leerdata(&inicio);
  if(estado)
    printf("No existe el archivo, cargue un registro para crearlo.\n");
  
  
  // Muestro el Menu del ABM
  do{
    menuMain();
    scanf ("%hd", &opcion); 
    switch(opcion)
    {
      case 1: altas(&inicio);	break;
      case 2: bajas(&inicio);	break;
      case 3: modif(&inicio);	break;
      case 4: listar(inicio);	break;
      case 0: liberar(&inicio); exit(0);	break;
    }
  }while(opcion!=0);
  
  
return 0;
}
