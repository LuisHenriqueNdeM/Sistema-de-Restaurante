#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"


void voltar_menu() {
	printf("\nPressione ENTER para voltar ao menu...");
	while (getchar() != '\n');
	getchar();
}

void Cadastrar(int totalProdutos, produto *produtos) { //Cria o cadastro dos produtos

	for(int i = 0; i < totalProdutos; i++) {
		printf("\n\tProduto número %d:\n", i + 1);

		printf("Nome do produto: ");
		fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
		produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

		printf("Código do produto: ");
		scanf("%d", &produtos[i].codigo_interno);
		getchar(); //limpar o \n deixado pelo scanf antes do próximo fgets

		printf("Categoria do produto: ");
		fgets(produtos[i].categoria, sizeof(produtos[i].categoria), stdin);
		produtos[i].categoria[strcspn(produtos[i].categoria, "\n")] = '\0';

		printf("Preço do produto: R$ ");
		scanf("%f", &produtos[i].preco);
		getchar(); //limpar o \n antes do próximo for
	}
}

void listarCardapio(produto cardapio[], int qtd) {
	printf("--------------------\n");

	if(qtd == 0) {
		printf("Nenhum produto cadastrado.\n");
	} else {
		for(int i = 0; i < qtd; i++) {
			printf("Código Interno: %d\n", cardapio[i].codigo_interno);
			printf("Nome: %s\n", cardapio[i].nome);
			printf("Categoria: %s\n", cardapio[i].categoria);
			printf("Preço: %.2f\n", cardapio[i].preco);
			printf("--------------------\n");
		}
	}
	voltar_menu();
}

void cadastrarPedido(Tpedido pedidos[], produto produtos[], int totalProdutos) {
	int codigo, quantidade;

	for(int i = 0; i < 50; i++) {
		if(pedidos[i].numero == 0) { //acha a primeira posição livre

			printf("Digite o número da mesa: ");
			scanf("%d", &pedidos[i].numero);

			printf("Digite o código do produto: ");
			scanf("%d", &codigo);

			for(int j = 0; j < totalProdutos; j++) {
				if(produtos[j].codigo_interno == codigo) {

					pedidos[i].produto = produtos[j];

					printf("Digite a quantidade: ");
					scanf("%d", &quantidade);
					pedidos[i].quantidade = quantidade;

					printf("Pedido registrado com sucesso!\n");
					return;
				}
			}

			printf("Produto não encontrado!\n");
			pedidos[i].numero = 0; //libera a posição, já que o pedido não foi concluído
			return;
		}
	}

	printf("Não há mais espaço para novos pedidos.\n");
	voltar_menu();
}

void consultar_pedido(Ppedido pedido) {

	int num_mesa, qtde_pedi = 50, j = 0;

	printf("Digite o número da mesa que deseja consultar: ");
	scanf("%d", &num_mesa);

	printf("Pedidos da mesa %d:\n", num_mesa);

	for(int i = 0; i < qtde_pedi; i++) {
		if(pedido[i].numero == num_mesa) {
			printf("Prato: %s | Quantidade: %d | Preço por unidade: %.2f.\n",
			       pedido[i].produto.nome, pedido[i].quantidade, pedido[i].produto.preco);
			j = 1;
		}
	}

	if(j != 1) {
		printf("Não tem pedidos registrados na mesa %d.\n", num_mesa);
	}
	voltar_menu();
}

void alterar_pedido(Ppedido pedido, produto cardapio[], int qtdCardapio) {

	int num_mesa, opcao, quantidade_nova, indice, encontrou = 0;
	int codigo_novo, achouProduto;

	printf("Digite o número da mesa: ");
	scanf("%d", &num_mesa);

	printf("\nPedidos encontrados:\n");
	for(int i = 0; i < 50; i++) {
		if(pedido[i].numero == num_mesa) {
			printf("[%d] Prato: %s | Quantidade: %d\n", i, pedido[i].produto.nome, pedido[i].quantidade);
			encontrou = 1;
		}
	}

	if(!encontrou) {
		printf("Não há pedidos registrados na mesa %d.\n", num_mesa);
		return;
	}

	printf("\nDigite o número do pedido que deseja alterar/cancelar: ");
	scanf("%d", &indice);

	if(indice < 0 || indice >= 50 || pedido[indice].numero != num_mesa) {
		printf("Índice inválido.\n");
		voltar_menu();
		return;
	}

	printf("\n1 - Alterar quantidade\n2 - Alterar produto\n3 - Cancelar pedido\nEscolha uma opção: ");
	scanf("%d", &opcao);

	switch(opcao) {
	case 1:
		printf("Nova quantidade: ");
		scanf("%d", &quantidade_nova);
		if(quantidade_nova <= 0) {
			printf("Quantidade inválida. Use a opção de cancelamento para remover o pedido.\n");
		} else {
			pedido[indice].quantidade = quantidade_nova;
			printf("Pedido atualizado com sucesso!\n");
		}
		break;

	case 2:
		listarCardapio(cardapio, qtdCardapio);
		printf("Digite o código interno do novo produto: ");
		scanf("%d", &codigo_novo);

		achouProduto = 0;
		for(int i = 0; i < qtdCardapio; i++) {
			if(cardapio[i].codigo_interno == codigo_novo) {
				pedido[indice].produto = cardapio[i];
				achouProduto = 1;
				printf("Produto do pedido atualizado para \"%s\" com sucesso!\n", cardapio[i].nome);
				break;
			}
		}

		if(!achouProduto) {
			printf("Código de produto não encontrado no cardápio.\n");
		}
		break;

	case 3:
		pedido[indice].numero = 0;
		pedido[indice].quantidade = 0;
		printf("Pedido cancelado com sucesso!\n");
		break;

	default:
		printf("Opção inválida.\n");
		break;
	}
	voltar_menu();
}
void calculoPedido(Tpedido pedidos[], int nPedido) {
    float total = 0.0;
    int encontrou = 0;

    // Soma o valor de todos os produtos associados ao pedido informado
    for (int i = 0; i < 50; i++) {
        if (pedidos[i].numero == nPedido) {
            total += pedidos[i].produto.preco * pedidos[i].quantidade;
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nNenhum pedido encontrado para a mesa %d!\n", nPedido);
    } else {
        printf("\nValor total da conta da mesa %d: R$ %.2f\n", nPedido, total);
    }
    
    voltar_menu();
    return;
}
