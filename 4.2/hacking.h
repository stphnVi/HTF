//vuelca la memoria pura en bytes hexadecimales y en el formato dividido
//que se puede mostrar
void fatal(char *message){
  char error_message[100];
  strcpy(error_message, "[!!] Fatal Error");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}
//una función de envoltura de malloc para comprobar errores
void *ec_malloc(unsigned int size){
  void *ptr;
  ptr = malloc(size);
  if(ptr == NULL)
    fatal("in ec_malloc() on memory allocation");
  return ptr;
}


//add
void dump(const unsigned char*data_buffer, const unsigned int length){
  unsigned char byte;
  unsigned int i, j;
  for(i=0; i < length; i++){
    byte= data_buffer[i];
    printf("%02x ",data_buffer[i]);// muestra los bytes en hexadecimales
    if(((i%16)==15)|| (i==length-1)){
      for(j=0; j < 15-(i%16); j++)
        printf("  ");
      printf("| ");
      for(j=(i-(i%16)); j<= i ; j++){//muestra los bytes que se pueden mostrar en la linea.
        byte = data_buffer[j];
        if((byte > 31) && (byte < 127))// fuera del rango de caracteres que se pueden mostrar de la linea
          printf("%c", byte);
        else
          printf(".");
      }
      printf("\n");//final de la linea del volcado (cada linea tiene 16 bytes)
    }// final del if
  }// final de for

}
