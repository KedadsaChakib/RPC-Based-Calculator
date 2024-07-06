/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"

void *
calcul_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

response *
calcul_addition_1_svc(data *argp, struct svc_req *rqstp)
{
	static response  result;
	unsigned int max;
	result.errno =0;

	max = argp-> arg1 + argp->arg2;

	if (result.somme<max){
		result.errno=1;
	}

	/*
	 * insert server code here
	 */

	return &result;
}
