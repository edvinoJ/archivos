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
	size_t read, write;
	while((read = orige.lee(BUFSIZ))>0){
		write = final.escribe((void *)orige.get_contenido(), read);
		printf("[%lu]->%lu\n",read,write);
	}
	printf("Termina la replica%s\n", argv[2]);
	printf("Comparacion entre [%s]->[%s]\n",argv[1], argv[2]);
	
	Archivo uno(argv[1]);
	Archivo dos(argv[2]);
	size_t read1, read2;
	bool isEqual = true;
	while(isEqual){
		read1 = uno.lee(BUFSIZ);
		read2 = dos.lee(BUFSIZ);
		printf("[%lu][%lu]\n",read1, read2 );
		if(read1!=read2){
			isEqual = false;
			break;
		}
		if(read1<=0 || read2<=0){
			break;
		}
	}
	printf("Es igual:%d\n", isEqual);
	return 0;
}