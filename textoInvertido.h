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

void buscaImprime (const char *str, textoInv *txt, const char *buffer);
struct vocabulo* busca (const char* str, textoInv *txt);

void atualizaTail (textoInv *txt);

struct ocorrencia* criaOcorrencia (int pos);

// CONSTRUTORA DO VOCABULO (nodo do textoInv)
// ENTRA:                        PALAVRA      || POSICAO NO TEXTO (em char)
struct vocabulo* criaVocabulo (const char *str, int pos);

// DESTRUTORA DO VOCABULO (nodo do textoInv)
// ENTRA:               ENDERECO DO NODO
void destroiVocabulo (struct vocabulo *voc);

// F. QUE ADICIONA VOCABULO A UM TEXTO INVERTIDO
// ENTRA:            PALAVRA    || POSICAO ||  PTR. DO HEAD DO TEXTO INVERTIDO
void adVocabulo (const char *str, int pos, struct vocabulo **head);

listaOcorrencias* criaListaOc(int pos);

textoInv *criaTextoInv (char *buffer, int tam);
void destroiTextoInv (textoInv *txt);

void imprimeVocabulo (struct vocabulo *v);
void imprimeTextoInv (textoInv *txt);
void salvaTextoInv (textoInv *txt, char *nomeDoArquivo);

struct ocorrencia* criaOcorrencia (int pos);
void adOcorrencia (int pos, listaOcorrencias *pL);
listaOcorrencias* criaListaOc (int pos);

#endif
