#ifndef __MENU_H
#define __MENU_H

#define LINUX
#define N_ENTER 2

/***************************/
/**        ENUMs          **/
/***************************/

// enum para guardar as opcoes do menu que o usuario pode escolher
typedef enum 
{
	FAZER_ARQ_INV        = 1, // As opcoes devem ser contadas desde 1, senao havera erro em < esperaEscolha() >.
	MOSTRAR_ARQ_INV      = 2,
	BUSCAR_NO_ARQ_INV    = 3,
	SALVAR_ARQ_INV       = 4,
	FORCA_BRUTA         = 5,
	SAIR                 = 6  // SAIR ha de ser sempre a ultima opcao, por igual motivo.
} OpcaoDoMenu;




/***************************/
/**        FUNCOES       **/
/***************************/

// Limpa o console.
void limpaTela (void);

// ENTRADA: int n = numero de '\n' a esperar.
// Imprime aviso e espera que o usuariopressione enter <n> vezes para continuar o programa.
// Espera-se <n> vezes porque esperar apenas 1 as vezes nao tem efeito
void espera (int n);

// Inicia o menu principal, que gerencia as chamadas de funcoes
// ate o fim do programa. A funcao ja chama imprimeMenuPrincipal().
void executaMenuPrincipal (void);

// Imprime tela do menu principal.
void imprimeMenuPrincipal (void);

// Retorna OpcaoDoMenu (def. acima) escolhida pelo usuario (pelo teminal).
OpcaoDoMenu escolhaDoUsuario (void);

#endif
