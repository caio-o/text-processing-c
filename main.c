#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "textoInvertido.h"
#define FILE_NAME "Historia.txt"

int main (void)
{
	int tam;
	struct vocabulo **pHead;
	char *buffer;
	tam = leArquivo(FILE_NAME, &buffer);
	
	textoInv *txt = criaTextoInv(buffer, tam);

	if (txt == NULL) 
	{
		return 1;
	}

	imprimeTextoInv(txt);

	printf("\n(teste) TAIL: ");
	imprimeVocabulo(txt->tail);

	destroiTextoInv (txt);

	return 0;
}
