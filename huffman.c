#include "textoInverido.h"

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
