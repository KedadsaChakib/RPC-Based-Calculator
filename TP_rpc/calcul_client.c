/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <limits.h> //added
#include "calcul.h"

CLIENT * clnt;  //added


void test_addition (uint param1,uint param2){
	response * resultat;
	data parametre;

	/*1.Preparer les arguments */
	parametre.arg1 = param1;
	parametre.arg2 = param2;
	printf("Appel de la fonction CALCUL_ADDITION avec les parametres: %u et %u \n",parametre.arg1,parametre.arg2);

	/* 2. Appel de la fontion distante*/

	resultat = calcul_addition_1 (&parametre,clnt);
	if (resultat == (response*)NULL) {
		clnt_perror(clnt,"call failed");
		clnt_destroy(clnt);
		exit(EXIT_FAILURE);
	}
	else if (resultat->errno == 0)
	{
		printf("Le resultat de l'addition es: %u \n\n",resultat->somme);
	}else{
		printf("La fonction distante ne peut faire l'addition a cause d'un overflow \n\n");
	}
	
}




void 
calcul_1(char *host)
{
	CLIENT *clnt;
	void  *result_1;
	char *calcul_null_1_arg;
	response  *result_2;
	data  calcul_addition_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCUL, VERSION_UN, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = calcul_null_1((void*)&calcul_null_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = calcul_addition_1(&calcul_addition_1_arg, clnt);
	if (result_2 == (response *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	
	//calcul_1 (host);
	clnt = clnt_create(host,CALCUL,VERSION_UN,"udp");
	if(clnt == NULL){
		clnt_pcreateerror(host);
		exit(1);
	}
	test_addition (UINT_MAX -15,10);
	test_addition (UINT_MAX, 10);

	clnt_destroy (clnt);
	exit (EXIT_SUCCESS);
}
