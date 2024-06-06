#include "textoInvertido.h"
#include "headers.h"
#include <string.h>
#include <stdlib.h>

void atualizaTail (textoInv *txt)
{
	if (txt->head == NULL)
	{
		txt->tail = NULL;
	}
	else
	{
		struct vocabulo *at = txt->head;

		while(at->prox != NULL)
		{
			at = at->prox;
		}

		txt->tail = at;
	}
}

void adOcorrencia (int pos, listaOcorrencias *pL)
{
	struct ocorrencia *oc = criaOcorrencia (pos);

	pL->tail->prox = oc;
	pL->tail = oc;
}

struct ocorrencia* criaOcorrencia (int pos)
{
	struct ocorrencia *ret = (struct ocorrencia*) malloc (sizeof(struct ocorrencia));

	ret->pos = pos;
	ret->prox = NULL;

	return ret;
}

struct vocabulo* criaVocabulo(const char *str, int pos)
{
	struct vocabulo *ret = (struct vocabulo*) malloc (sizeof(struct vocabulo));

	ret->str = strdup(str);
	ret->prox = NULL;

	ret->ocorrencias = (listaOcorrencias*) malloc (sizeof(listaOcorrencias));
	ret->ocorrencias->head = criaOcorrencia(pos);
	ret->ocorrencias->tail = ret->ocorrencias->head;

	return ret;
}

void adVocabulo(const char *str, int pos, struct vocabulo **head)
{
	struct vocabulo *novoNodo = criaVocabulo(str, pos);

	if (*head == NULL || strcmp ((*head)->str, str) > 0)
	{
		novoNodo->prox = (*head);
		*head = novoNodo;
	}
	else if (strcmp ((*head)->str, str) == 0) // TODO: CONSERTAR CHECAGEM DUPLA
	{
		destroiVocabulo (novoNodo);

		adOcorrencia (pos, (*head)->ocorrencias);
	}
	else
	{
		struct vocabulo *at = *head;

		while(at->prox != NULL && strcmp(at->prox->str, str) < 0)
		{
			at = at->prox;
		}

		if (at->prox != NULL && strcmp(at->prox->str, str) == 0)
		{
			destroiVocabulo (novoNodo);

			adOcorrencia (pos, at->prox->ocorrencias); // Palavra ja encontrada antes. Registrar posicao da nova ocorrencia apenas.
		}

		else
		{
			novoNodo->prox = at->prox;
			at->prox = novoNodo;
		}
	}
}

textoInv* criaTextoInv (char *buffer, int tam)
{
	int i = 0;
	int j = 0;

	textoInv *txt = (textoInv*) malloc (sizeof(textoInv));
	txt->head = NULL;
	txt->tail = NULL;

	while (i < tam)
	{
		do j++; while (letraOuNumero (buffer[i]) && j < tam && letraOuNumero (buffer[j]));

		if (buffer[i] != '\n')
			adVocabulo (extraiPalavra (buffer, i, j-1), i, &(txt->head));

		i = j;
	}

	if (txt->head == NULL)
	{
		free(txt);

		printf("From criaTextoInv(): text empty, NULL return value.\n");

		return NULL;
	}

	else 
	{
		atualizaTail(txt);
		return txt;
	}
}

void destroiTextoInv (textoInv *txt)
{
	struct vocabulo *at = txt->head;
	struct vocabulo *aux;

	while (at != NULL)
	{
		aux = at;
		at = at->prox;
		destroiVocabulo(aux);
	}

	free(txt);
}

void destroiVocabulo (struct vocabulo *voc)
{
	struct ocorrencia *at = voc->ocorrencias->head;
	struct ocorrencia *aux;

	while (at != NULL)
	{
		aux = at;
		at = at->prox;
		free(aux);
	}

	free(voc->str);
	free(voc);
}

void salvaTextoInv (textoInv *txt, char *nomeDoArquivo)
{
	FILE *tmp = stdout;

	stdout = fopen(nomeDoArquivo, "w");

	imprimeTextoInv(txt);

	fclose(stdout);

	stdout = tmp;
}

void imprimeVocabulo (struct vocabulo *v)
{
	struct ocorrencia *ocAt = v->ocorrencias->head;
	printf ("%s", v->str);

	while (ocAt != NULL)
	{
		printf (" %d", ocAt->pos);
		ocAt = ocAt->prox;
	}

	printf("\n");
}

void imprimeTextoInv (textoInv *txt)
{
	struct vocabulo *atual = txt->head;

	while (atual != NULL)
	{
		imprimeVocabulo (atual);

		atual = atual->prox;
	}
}
