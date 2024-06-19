/*************************************************************************/
/**   HEADER que declara todas as funcoes que lidam com texto bruto.     */
/*************************************************************************/

#ifndef __TEXTO_BRUTO
#define __TEXTO_BRUTO

void imprimeParte(const char *buff, int i, int j);

void buscaForcaBruta(const char *padrao, int m, const char *texto, int n);

// E N T R A D A: nome de um arquivo, ponteiro para um buffer a ser alocado
// PROCESSAMENTO: Guarda o conteudo do arquivo chamado <nome> em <*buffer>, apos este ter sido alocado.
// R E T O R N O: Tamanho do buffer em caracteres.
int leArquivo (char *nome, char **buffer);

// ENTRADA: char c
// RETORNO: 0, se <c> eh letra ou numero (em ASCII), ou se <c> eh (parte de) um caracter unicode (c > 127)
//          1, no caso contrario
int letraOuNumero(char c);

// ENTRADA: 2 numeros a e b.
// RETORNO: o menor deles.
int menorDoPar (int a, int b);

// ENTRADA: Texto <*buffer>, posicoes <i> e <j>
// RETORNO: string que contem uma copia do conteudo do buffer, de <i> a <j>,
//          e termina em '\0' (null byte).
char* extraiPalavra(char *buffer, int i, int j);

#endif
