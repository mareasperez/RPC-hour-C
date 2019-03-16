#include <time.h> 
int obten_segundos (time_t *s) {  //Obtención de los segundos desde el sistema operativo
time(s);
  if(s == NULL)
  {   return -1;}
  else
       return 0; } 