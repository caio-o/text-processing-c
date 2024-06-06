#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "textoInvertido.h"

int main (void)
{
	int tam;
	struct vocabulo **pHead;
	char *buffer;
	tam = leArquivo("teste.txt", &buffer);
	
	textoInv *txt = criaTextoInv(buffer, tam);

	if (txt == NULL) 
	{
		return 1;
	}

	imprimeTextoInv(txt);

	printf("\nTAIL: ");
	imprimeVocabulo(txt->tail);

	destroiTextoInv (txt);

	return 0;
}
