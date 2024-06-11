#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int letraOuNumero(char c)
{
	return ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (48 <= c && c <= 57) || (c == '-') || (c == '_') || (192 <= c));
}

char* extraiPalavra (char *buffer, int i, int j)
{
	char *ret = (char*) malloc (sizeof(char) * (j - i + 2));
	int tam = j - i + 1;

	for(int k = 0; k < tam; k++)
	{
		if ('A' <= buffer[i] && buffer[i] <= 'Z') 
			ret[k] = buffer[i] + 32;
		else
			ret[k] = buffer[i];

		i++;
	}

	ret[tam] = '\0';

	return ret;
}

void imprimeParte(char *buff, int i, int j)
{
	for (i = i; i <= j; i++)
	{
		printf("%c", buff[i]);
	}

	printf("\n");
}

int leArquivo(char *nome, char **buffer)
{
	FILE *arquivo = fopen(nome, "r");
	int tam;

	fseek (arquivo, 0L, SEEK_END);

	tam = ftell (arquivo);
	*buffer = (char*) malloc(tam * sizeof(char));

	rewind (arquivo);

	fread(*buffer, sizeof(char), tam, arquivo);

	fclose(arquivo);

	return tam;
}

