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
        //int tam;
} listaOcorrencias;

struct vocabulo
{
        char* str;
        listaOcorrencias ocorrencias;
};

typedef struct
{
        struct vocabulo *head;
        struct vocabulo *tail;
        //int tam;
} textoInv;

void imprimeTextoInv(textoInv txt);

#endif
