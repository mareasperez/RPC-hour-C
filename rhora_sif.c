//rhora_sif.c
#include <time.h>
#include <stdio.h>
#include <rpc/rpc.h>
#include <time.h>
#include "rhora.h"
extern segactual * obten_segundos_1_svc(void *p1, struct svc_req *p2)
{
int resultado;
 time_t s;
 segactual *segundos_actuales;
//se reserva espacio para almacenar el resultado
 segundos_actuales = (segactual *) malloc (sizeof(struct segactual));
//Se llama al procedimiento local
 resultado = obten_segundos(&s);
if(resultado == -1) //error de ejecución del procedimiento local
 segundos_actuales->status = HORA_NOK;
else //el procedimiento local se ejecutó correctamente
 {
 segundos_actuales->status = HORA_OK;
 segundos_actuales->segactual_u.segundos = s;
 }
return segundos_actuales;
}