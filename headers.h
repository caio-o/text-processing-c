/*************************************************************/
/**   HEADER que declara todas as funcoes do programa.       */
/*************************************************************/

#ifndef __HEADERS_H
#define __HEADERS_H

void imprimeParte(const char *buff, int i, int j);

int leArquivo (char *nome, char **buffer);

int letraOuNumero(char c);

char* extraiPalavra(char *buffer, int i, int j);

#endif
