//rhora_cif.c
#include <time.h>
#include <rpc/rpc.h>
#include "rhora.h"
#define Rmaquina "192.168.163.10"
static CLIENT *clte_rhora;
int obten_segundos(time_t *s)
{
struct segactual *segundos;
//se crea un cliente del servicio de hora
 clte_rhora = clnt_create(Rmaquina, HORA_PROGRAM, HORA_VERSION, "udp");
if(clte_rhora == NULL)
 return -1;

 segundos = (struct segactual*) malloc (sizeof(struct segactual));
//se realiza la rpc
 segundos = obten_segundos_1(NULL, clte_rhora);
if(segundos == NULL) //error de comunicación con el servidor
 return -1;
else if (segundos->status == HORA_NOK) //error de ejecución
 return -1;
else // se recogen los segundo devueltos
 *s = (time_t)segundos->segactual_u.segundos;
}