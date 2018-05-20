#include "Archivo.h"
Archivo::Archivo(string filename){
	nombreArchivo = filename;
	fd = open(filename.c_str(), O_RDONLY);
	contenido = NULL;
}
Archivo::Archivo(string filename, int banderas, mode_t modo){
	nombreArchivo = filename;
	fd = open(filename.c_str(), banderas, modo);
	contenido = NULL;
}
size_t Archivo::lee(size_t nbytes){
	contenido = (char *) realloc(contenido, nbytes);
	num_bytes = read(fd, contenido, nbytes);
	if(num_bytes!= nbytes){
		contenido = (char *)realloc(contenido, num_bytes+1);
	}
	return num_bytes;

}
size_t Archivo::escribe(void * buffer, size_t nbytes){
	num_bytes = write(fd, (char *)buffer,nbytes);
	return nbytes;
	
}
size_t Archivo::obtieneNum_bytes(){
	return num_bytes;
}
const char * Archivo::get_contenido(){
	return contenido;
}
Archivo::~Archivo(){
	close(fd);
	//delete [] contenido;
}