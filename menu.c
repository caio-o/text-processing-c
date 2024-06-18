#include <stdio.h>
#include <stdlib.h>
#include "textoBruto.h"
#include "textoInvertido.h"
#include "menu.h"

#ifdef LINUX
void limpaTela (void)
{
	system("clear"); // Para terminais rodando em Shell e derivados, como o do LINUX e do BSD
}
#endif

#ifndef LINUX
void limpaTela (void)
{
	system("cls"); // Para o cmd do WINDOWS
}
#endif

void espera (int n)
{
	printf("\n----------------------------");
	printf("\n--- ENTER PARA CONTINUAR ---");
	printf("\n----------------------------\n");

	for(int i = 0; i < n; i ++) 
		getchar(); // Espera input do usuario
}

// AVISO: Manter sempre compativel com o enum OpcaoDoMenu, definido em menu.h
void imprimeMenuPrincipal (void)
{
	printf ("Escolha:\n");
	printf ("[1] Ler arquivo e fazer arquivo invertido.\n");
	printf ("[2] Mostrar arquivo invertido.\n");
	printf ("[3] Buscar palavra no arquivo invertido.\n");
	printf ("[4] Salvar arquivo invertido em txt.\n");
	printf ("[5] Buscar palavra por forca bruta.\n");
	printf ("[6] Sair.\n");
}

OpcaoDoMenu escolhaDoUsuario (void)
{
	OpcaoDoMenu escolha;

	do    scanf ("%d", &escolha);
	while (escolha < 1 || escolha > SAIR);

	return escolha;
}

void executaMenuPrincipal (void)
{
	OpcaoDoMenu inputMenu;           // Inteiro que representa escolha do usuario
	
	char nome[127];                  // Para ler o nomes de arquivos e padroes buscados
	
	int        tam;                  // tamanho do buffer em caracteres ou bytes
	char       *buffer   = NULL;     // Buffer do texto bruto a ser lido
	textoInv   *txt      = NULL;     // Arquivo invertido gerado a partir do texto

	do
	{
		limpaTela();

		imprimeMenuPrincipal();

		inputMenu = escolhaDoUsuario();

		switch (inputMenu)
		{
		case FAZER_ARQ_INV:
			printf("Digite o nome do arquivo:\n");
			scanf("%s", nome);
		
			tam = leArquivo(nome, &buffer);
	
			txt = criaTextoInv(buffer, tam);
			
			printf("Feito!\n");
			break;

		case MOSTRAR_ARQ_INV:
			if     (txt != NULL)   imprimeTextoInv (txt);
			else                   printf("Nao ha texto.\n");
			break;

		case BUSCAR_NO_ARQ_INV:
			if(txt != NULL)
			{
				printf("Digite a palavra buscada: ");
				scanf("%s", nome);
				buscaImprime(nome, txt, buffer);
			}
			else printf("Nao ha texto.\n");
			break;

		case SALVAR_ARQ_INV:
			if (txt != NULL)
			{
				salvaTextoInv (txt, "arquivo-invertido.txt");
				printf ("Salvo em arquivo-invertido.txt\n");
			}
			else printf ("Nao ha texto.\n");
			break;

		case FORCA_BRUTA:
			if (buffer != NULL)
			{
				scanf ("%s", nome);

				buscaForcaBruta (nome, strlen(nome), buffer, tam);
			}
			break;

		default: // CASE SAIR:
			if    (txt    != NULL)    destroiTextoInv  (txt);
			if    (buffer != NULL)    free             (buffer);
			break;
		}
		espera(N_ENTER);
	} while (inputMenu != SAIR);
}
