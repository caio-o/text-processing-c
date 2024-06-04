#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

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
	FILE *arquivo = fopen("Historia.txt", "r");
	int tam;

	fseek (arquivo, 0L, SEEK_END);

	tam = ftell (arquivo);
	*buffer = (char*) malloc(tam * sizeof(char));

	rewind (arquivo);

	fread(*buffer, sizeof(char), tam, arquivo);

	fclose(arquivo);

	return tam;
}

textoInv leArquivoInv(char *nome)
{
        FILE *arquivo = fopen("Historia.txt", "r");

        char *vocabulo = []

        char c;
        int i = 0;

        while (c != ' ' && cont < 100)
        {
                /// checar se a palavra eh pontuacao
                c = fgetc(arquivo);
                
                vocabulo [i] = c

                if (ehPont (c))
                {
                        vocabulo[i] = '\0';
                        guardaPont(c);
                }

                fscanf(arquivo, "%[^!-/:;]", vocabulo);

                i++;
        }
}
