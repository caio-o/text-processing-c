/*************************************************************************/
/**   HEADER que declara todas as funcoes que lidam com texto bruto.     */
/*************************************************************************/

#ifndef __TEXTO_BRUTO
#define __TEXTO_BRUTO

void imprimeParte(const char *buff, int i, int j);

void buscaForcaBruta(const char *padrao, int m, const char *texto, int n);

int leArquivo (char *nome, char **buffer);

int letraOuNumero(char c);

int menorDoPar (int a, int b);

char* extraiPalavra(char *buffer, int i, int j);

#endif
