#include "textoInvertido.h"
#include "headers.h"

//colocar isso em textoInvertido.c
int wordFrequencyFromString (const char *str, textoInv *txt)
{
        int ret = 0;
        struct vocabulo *v = busca(str, txt);

        if (v != NULL)
        {
                ret++;
                struct ocorrencia *at = v->ocorrencias->head;

                while(at->prox != NULL)
                {
                        at = at->prox;
                        ret++;
                }
        }

        return ret;
}

int wordFreqFromNode (struct vocabulo *v)
{
        int ret = 1;

        struct ocorrencia *at = v->ocorrencias->head;

        while(at->prox != NULL)
        {                                                                                                                           
                at = at->prox;                                                                                                      
                ret++;
        }

        return ret;
}

/**
NAO ADICIONAR 0, PARA GUARDAR ATE 2
ADICIONAR 1   0, PARA GUARDAR ATE 4
ADICIONAR 2   0, PARA GUARDAR ATE 8
ETC.

int lim = 2;
int x = 0; //casas a esquerda
while (PARIDADE > lim)
{
        lim *= 2;

        x++;
}

PARIDADE 1 --> NAO ADICIONAR
PARIDADE 2 --> NAO ADICIONAR
PARIDADE 3 --> ADIICONAR 1 CASA
PARIDADE 4 --> ADICIONAR 1 CASA
PARIDADE 5 --> ADICIONAR 2 CASAS
PARIDADE 6 --> ADICIONAR 2 CASAS


rosa |  0 | 0 4 12 17 50
para | 100 | 24 43 55
cada | 101 | 12 22 33
uma  | 110 |

*/
/** COMPRESSAO */

// RAZAO DE COMPRESSAO: TAM_COMP / TAM_ORIG
//  100 kb --> 30 kb  : 30 %
// HUFFMAN EM CARACT. : 60 %
// HUFFMAN EM PALAVR. : 25 %

// SIMBOLOS MAIS USADOS
// LISTA PODE SER INTEGRADA COM O TEXTO INVERTIDO
// 1.  0
// 2. 10
// 3. 11
// 4. 
// 5. 

// 3 formas do codigo de HUFFMAN
//     1. arvore canonica
//     2. (0) (10) (110) (1110) (11110) 
//     3. tamanho depende do n de vezes que aparece

// fatores:   VEL DE COMPRESSAO
//            LEGIBILIDADDE (casamento de cadeias) NO ARQ. COMPACTADO
//            ACESSIBILIDADE DO TEXTO EM PONTOS ESPEC.
