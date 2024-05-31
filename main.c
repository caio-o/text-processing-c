#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main (void)
{
	int tam;
	char *buffer;
	tam = leArquivo("Historia.txt", &buffer);

	printf("TAMAMNHO: %d", tam);
	printf("TEXTO:\n");
	printf("%s\n", buffer);

	printf("\nFIM:\n");
	imprimeParte(buffer, tam-101, tam-1);
	
	return 0;
}
