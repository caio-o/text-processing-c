#include "textoInvertido.h"
#include "textoBruto.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int nOcorrencias (struct vocabulo *v)
{
	int ret = 1;
	struct ocorrencia *at = v->ocorrencias->head;
	while (at->prox != NULL)
	{
		at = at->prox;
		ret++;
	}

	return ret;
}

void buscaImprime (const char *str, textoInv *txt, const char *buffer)
{
	struct vocabulo *v = busca (str, txt);

	if (v != NULL)
	{
		struct ocorrencia *at = v->ocorrencias->head;
		int tam = nOcorrencias(v);
		int cont = 1;
		int input = 0;

		printf("Encontrado: %s, com %d ocorrencias totais.\n", v->str, tam);

		do 
		{
			printf("Ocorrencia %d/%d, na posicao %d:\n\n", cont, tam, at->pos);

			imprimeParte(buffer, at->pos - 50, at->pos + 50);

			printf("\nEscolha: [1] Ver prox. ocorrencia.    [2] Terminar busca.\n");
			
			do scanf("%d", &input); 
			while (input < 1 || input > 2);
			
			at = at->prox;
			cont++;
		} while (cont <= tam && input != 2);	

		printf("Fim da busca.\n");
	}
	else
	{
		printf("Nao encontrado.\n");
	}

}

struct vocabulo* busca (const char *str, textoInv *txt)
{
	struct vocabulo *at = txt->head;

	while(at != NULL && strcmp(at->str, str) != 0)
	{
		at = at->prox;
	}

	return at;
}

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
	int i;
	struct vocabulo *ret = (struct vocabulo*) malloc (sizeof(struct vocabulo));

	ret->prox = NULL;

	ret->str = strdup(str);

	ret->ocorrencias = (listaOcorrencias*) malloc (sizeof(listaOcorrencias));
	ret->ocorrencias->head = criaOcorrencia(pos);
	ret->ocorrencias->tail = ret->ocorrencias->head;

	return ret;
}

// TODO: revisar e simplificar funcao
void adVocabulo(const char *str, int pos, struct vocabulo **head)
{
	struct vocabulo *aux = criaVocabulo(str, pos); // vai receber o novo nodo quando for necessario
	
	// para contemplar o caso em que a palavra esta no comeco do arquivo
	if (*head == NULL || strcmp ((*head)->str, str) > 0)
	{
		aux = criaVocabulo(str, pos);
		aux->prox = (*head);

		*head = aux;
	}
	else if (!strcmp ((*head)->str, str)) // se as palavras sao iguais
	{
		adOcorrencia (pos, (*head)->ocorrencias); // adicionar ocorrencia apenas
	}

	// para contemplar os outros casos
	else
	{
		struct vocabulo *at = *head;

		while(at->prox != NULL && strcmp(at->prox->str, str) < 0)
		{
			at = at->prox;
		}

		if (at->prox != NULL && strcmp(at->prox->str, str) == 0)
		{
			//destroiVocabulo (novoNodo);

			// Palavra ja encontrada antes. Registrar posicao da nova ocorrencia apenas.
			adOcorrencia (pos, at->prox->ocorrencias); 
		}

		else
		{
			aux = criaVocabulo (str, pos);
			aux->prox = at->prox;
			
			at->prox = aux;
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
		{
			adVocabulo (extraiPalavra (buffer, i, j-1), i, &(txt->head));
		}

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
	FILE *tmp2 = fopen(nomeDoArquivo, "w");

	stdout = tmp2;

	imprimeTextoInv(txt);

	stdout = tmp;

	fclose(tmp2);
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
