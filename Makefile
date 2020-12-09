main=ABM
funciones_src=funciones
server_src = server
client_src = client
sock_lib_src = sock-lib

base: $(main).o $(funciones_src).o 
		gcc -o ABM $(main).o $(funciones_src).o  
		@echo "ABM Creada"

server: $(server_src).o $(sock_lib_src).o $(funciones_src).o 
	@echo "-Creando el Server"
	gcc -o server $(server_src).o $(sock_lib_src).o $(funciones_src).o -Wall

client: $(client_src).o $(sock_lib_src).o $(funciones_src).o 
	@echo "-Creando el Client"
	gcc -o client $(client_src).o $(sock_lib_src).o $(funciones_src).o -Wall

run_server:
	./server
run_client:
	./client localhost 3490
run_base:
	./ABM

clean:
	@echo "Eliminando archivos"
	rm -f *.lst *.o *.*~ *~ *.out server client

$(main).o:	$(main).c
		gcc -c -o $(main).o $(main).c -Wall

$(funciones_src).o:$(funciones_src).c
		gcc -c -o $(funciones_src).o $(funciones_src).c -Wall 
	
$(server_src).o: $(server_src).c
	gcc -c -o $(server_src).o $(server_src).c -Wall 
	
$(client_src).o: $(client_src).c
	gcc -c -o  $(client_src).o $(client_src).c -Wall
	
$(sock_lib_src).o: $(sock_lib_src).c
	gcc -c -o  $(sock_lib_src).o $(sock_lib_src).c -Wall