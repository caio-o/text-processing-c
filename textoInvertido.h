#ifndef TEXTOINVERTIDO_H
#define TEXTOINVERTIDO_H

struct ocorrencia
{	
	int pos;
	struct ocorrencia *prox;
};

typedef struct
{	
	struct ocorrencia *head;
	struct ocorrencia *tail;
} listaOcorrencias;

struct vocabulo
{	
	char *str;
	struct vocabulo *prox;
	listaOcorrencias *ocorrencias;
};

typedef struct
{
	struct vocabulo *head;
	struct vocabulo *tail;
} textoInv;

// Busca padrao no arquivo invertido e imprime o trecho do texto em que ele aparece.
// ENTRADA: padrao, ptr. pro arquivo invertido, ptr. pro buffer
void buscaImprime (const char *str, textoInv *txt, const char *buffer);

// Busca palavra no txt
// RETORNO: ptr. do seu nodo, ou NULL se ela nao existir.
struct vocabulo* busca (const char* str, textoInv *txt);

// Garante que o TAIL do *txt seja de fato o ultimo nodo
void atualizaTail (textoInv *txt);

// CONSTRUTORA DO VOCABULO (nodo do textoInv)
// ENTRADA: PALAVRA e POSICAO NO TEXTO (em char/byte)
struct vocabulo* criaVocabulo (const char *str, int pos);

// DESTRUTORA DO VOCABULO (nodo do textoInv)
// ENTRADA: ENDERECO DO NODO
void destroiVocabulo (struct vocabulo *voc);

// F. QUE ADICIONA VOCABULO A UM TEXTO INVERTIDO
// ENTRADA:          PALAVRA    || POSICAO ||  PTR. DO HEAD DO TEXTO INVERTIDO
void adVocabulo (const char *str, int pos, struct vocabulo **head);

// CONSTRUTORA do arquivoInvertido, a partir de um texto simples
// ENTRADA: buffer, tamanho
textoInv *criaTextoInv (char *buffer, int tam);
void destroiTextoInv (textoInv *txt); // destrutora 

void imprimeVocabulo (struct vocabulo *v);
void imprimeTextoInv (textoInv *txt);
void salvaTextoInv (textoInv *txt, char *nomeDoArquivo);

struct ocorrencia* criaOcorrencia (int pos);       // CONSTRUTORA da ocorrencia
void adOcorrencia (int pos, listaOcorrencias *pL); // F. QUE INSERE a ocorrencia
listaOcorrencias* criaListaOc (int pos);           // CONSTRUTORA | ENTRADA: posicao da primeira ocorrencia

#endif
