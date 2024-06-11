/*************************************************************/
/**   HEADER que declara todas as funcoes do programa.       */
/*************************************************************/

#ifndef __HEADERS_H
#define __HEADERS_H

void imprimeParte(const char *buff, int i, int j);

void imprimeSetinha(int pos);

int leArquivo (char *nome, char **buffer);

int letraOuNumero(char c);

int menorDoPar (int a, int b);

char* extraiPalavra(char *buffer, int i, int j);

#endif
