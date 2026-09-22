#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int opcao;
    int totalProdutos = 0;
    produto *produtos = NULL;
    Tpedido pedidos[50] = {0}; //zera "numero" de todas as posições, marcando como livres

    do{
        printf("\n========================================\n");
        printf(" SISTEMA DO RESTAURANTE\n");
        printf("========================================\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Listar cardápio\n");
        printf("3 - Cadastrar pedidos\n");
        printf("4 - Calcular pedido\n");
        printf("5 - Consultar pedido\n");
        printf("6 - Alteração/Cancelamento\n");
        printf("7 - Fechamento de conta\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\n===========CADASTRO DE PRODUTOS=============\n");
                printf("Quantas opções de produto terá no restaurante?\n");
                scanf("%d", &totalProdutos);
                getchar(); 
                free(produtos); // libera o bloco anterior, se existir antes de realocar
                produtos = (produto *) malloc(totalProdutos * sizeof(produto));
                Cadastrar(totalProdutos, produtos);
            break;
            case 2:
                listarCardapio(produtos, totalProdutos);
            break;
            case 3:
                cadastrarPedido(pedidos, produtos, totalProdutos);
            break;
            case 4:
            printf("\n===========CALCULO DO PRODUTO=============\n");
            int nPedido; // Variável que receberá o número do pedido
            printf("Número do pedido que se deseja calcular:");
            scanf("%i", &nPedido);
            calculoPedido(pedidos, nPedido);
            break;
            case 5:
                consultar_pedido(pedidos);
            break;
            case 6:
                alterar_pedido(pedidos, produtos, totalProdutos);
            break;
            case 7:
            break;
            default:
            printf("Opção Inválida!");
        }
    } while (opcao != 0);

    free(produtos);
    return 0;
}
