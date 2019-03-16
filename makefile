#makefile :v
all: cliente servidor
cliente: rhora.o rhora_cif.o rhora_clnt.o rhora_xdr.o
	gcc -o cliente rhora.o rhora_cif.o rhora_clnt.o rhora_xdr.o
rhora_clnt.c: rhora.x
	rpcgen -C rhora.x
rhora_svc.c: rhora.x
	rpcgen -C rhora.x
rhora_xdr.c: rhora.x
	rpcgen -C rhora.x
rhora.h: rhora.x
	rpcgen -C rhora.x
rhora.o: rhora.c
	gcc -c rhora.c
rhora_cif.o: rhora_cif.c rhora.h
	gcc -c rhora_cif.c
rhora_clnt.o: rhora_clnt.c
	gcc -c rhora_clnt.c
rhora_xdr.o: rhora_xdr.c
	gcc -c rhora_xdr.c
servidor: rhora_svc.o rhora_sif.o rhora_srp.o rhora_xdr.o
	gcc -o servidor rhora_svc.o rhora_sif.o rhora_srp.o rhora_xdr.o
rhora_sif.o: rhora_sif.c rhora.h
	gcc -c rhora_sif.c
rhora_srp.o: rhora_srp.c
	gcc -c rhora_srp.c
rhora_svc.o: rhora_svc.c
	gcc -c rhora_svc.c
clean: 
	rm -f cliente servidor rhora_clnt.c rhora_svc.c rhora_xdr.c rhora.h *.o