/****************************************************************************/
/**  Este arquivo contem a implementacao das funcoes que                   **/
/**  lidam com o processamento, a busca e a impressao do texto bruto       **/
/**  as quais funcoes estao declaradas e documentadas em textoBruto.h      **/
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "textoBruto.h"

int letraOuNumero(char c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || (c == '-') || (c == '_') || ((char)127 < c));
}

char* extraiPalavra (char *buffer, int i, int j)
{
	char *ret = (char*) malloc (sizeof(char) * (j - i + 2)); // +2 para dar espaco para o '\0'
	int tam = j - i + 1;

	for(int k = 0; k < tam; k++)
	{
		if ('A' <= buffer[i] && buffer[i] <= 'Z') // Se eh letra maiuscula,
			ret[k] = buffer[i] + 32;          // copia como minuscula;           TODO: MAKE IT WORK WITH UNICODE
		else                                      // senao
			ret[k] = buffer[i];               // copia o caracter como esta.

		i++;
	}

	ret[tam] = '\0'; // a string retornada termina em '\0' para poder usar strdup(), strcpy(), etc.

	return ret;
}

void imprimeParte(const char *buff, int i, int j)
{
	// TODO: TESTAR - talvez seja mais rapido copiar para uma string (depois de colocar '0') e imprimir como %s
	//                a depender do tamanho do intervalo a ser imprimido.
	for (/* i = i */ ; i <= j; i++)
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

	fread (*buffer, sizeof(char), tam, arquivo);

	fclose (arquivo);

	return tam;
}

int menorDoPar (int a, int b)
{
	if (a < b)    return a;
	else          return b;
}

void buscaForcaBruta(const char *padrao, int tamP, const char *texto, int tamT)
{
	int i;
	int j;
	int k;

	for (i = 0; i < (tamT - tamP + 1); i++)
	{ 
		j = 0;
		k = i;

		while(j < tamP && padrao[j] == texto[k])
		{
			j++;
			k++;
		}

		if(j >= m) printf("Padrao encontrado na posicao: %3d\n", i);
	}
}
