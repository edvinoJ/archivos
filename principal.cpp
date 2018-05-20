#include "Archivo.h"
#include <cstdio>
int main(int argc, char const *argv[])
{
	if(argc < 3){
		perror("Error faltan algumentos -source -destination\n");
		return -1;
	}
	Archivo orige(argv[1]);
	Archivo final(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 777);
	size_t read;
	while((read = orige.lee(BUFSIZ))>0){
		final.escribe((void *)orige.get_contenido(), read);
	}
	printf("Termina la replica%s\n", argv[2]);
	return 0;
}