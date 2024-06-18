#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int letraOuNumero(char c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || (c == '-') || (c == '_') || ((char)127 < c));
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

void imprimeParte(const char *buff, int i, int j)
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

int menorDoPar (int a, int b)
{
	if (a < b)    return a;
	else          return b;
}

void buscaForcaBruta(const char *padrao, int m, const char *texto, int n)
{
	int i;
	int j;
	int k;

	for (i = 0; i < (n - m); i++)
	{ 
		j = 0;
		k = i;

		while(j < m && padrao[j] == texto[k])
		{
			j++;
			k++;
		}
		if(j == m) printf("Padrao encontrado na posicao: %3d\n", i);
	}
}
