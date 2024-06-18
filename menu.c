#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "textoInvertido.h"
#include "menu.h"

#ifdef LINUX
void limpaTela (void)
{
	system("clear");
}
#endif

#ifndef LINUX
void limpaTela (void)
{
	system("cls");
}
#endif

void espera (int n)
{
	printf("\n----------------------------");
	printf("\n--- ENTER PARA CONTINUAR ---");
	printf("\n----------------------------\n");

	for(int i = 0; i < n; i ++) 
		getchar();
}

void menuPrincipal (void)
{
	int input;
	char nome[127];
	
	int tam;
	char *buffer = NULL;
	textoInv *txt = NULL;

	do
	{
		limpaTela();

		printf("Escolha:\n");
		printf("[1] Ler arquivo e fazer arquivo invertido.\n");
		printf("[2] Mostrar arquivo invertido.\n");
		printf("[3] Buscar palavra no arquivo invertido.\n");
		printf("[4] Salvar arquivo invertido em txt.\n");
		printf("[5] Buscar palavra por forca bruta.\n");
		printf("[6] Sair.\n");

		do scanf("%d", &input);
		while (input < 1 || input > 6);

		switch (input)
		{
		case 1:
			printf("Digite o nome do arquivo:\n");
			scanf("%s", nome);
		
			tam = leArquivo(nome, &buffer);
	
			txt = criaTextoInv(buffer, tam);
			
			printf("Feito!\n");
			break;

		case 2:
			if(txt != NULL)
				imprimeTextoInv (txt);
			else
				printf("Nao ha texto.\n");
			break;

		case 3:
			if(txt != NULL)
			{
				printf("Digite a palavra buscada: ");
				scanf("%s", nome);
				buscaImprime(nome, txt, buffer);
			}
			else printf("Nao ha texto.\n");
			break;

		case 4:
			if(txt != NULL)
			{
				salvaTextoInv(txt, "arquivo-invertido.txt");
				printf("Salvo em arquivo-invertido.txt\n");
			}
			else printf("Nao ha texto.\n");
			break;

		case 5:
			if(buffer != NULL)
			{
				scanf("%s", nome);

				buscaForcaBruta(nome, strlen(nome), buffer, tam);
			}
			break;

		default:
			if    (txt    != NULL)    destroiTextoInv (txt);
			if    (buffer != NULL)    free (buffer);
			break;
		}
		espera(N_ENTER);
	} while (input != 6);
}
