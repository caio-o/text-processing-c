#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "textoInvertido.h"
#define FILE_NAME "Historia.txt"

int main (void)
{
	int tam;
	//struct vocabulo *teste;
	char *buffer;
	tam = leArquivo(FILE_NAME, &buffer);
	
	textoInv *txt = criaTextoInv(buffer, tam);

	if (txt == NULL) 
	{
		return 1;
	}

	imprimeTextoInv(txt);

	//teste = busca("beto", txt);
	
	printf("\n\n\n\n        BUSCA SEQUENCIAL DE quem: \n");
	//if (teste != NULL) imprimeVocabulo(teste);
	//else printf("\"beto\" NAO ENCONTRADO!\n");
	buscaImprime("quem", txt, buffer);

	destroiTextoInv (txt);

	return 0;
}
