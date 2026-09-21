#include <stdio.h>
#include "sistema.h"

void listarCardapio(produto cardapio[],int qtd){
    printf("--------------------\n");
    for(int i = 0; i < qtd; i++){
        printf("Código Interno: %d\n", cardapio[i].codigo_interno);
        printf("Nome: %s\n", cardapio[i].nome);
        printf("Categoria: %s\n", cardapio[i].categoria);
        printf("Preço: %.2f\n", cardapio[i].preco);
    }
    printf("--------------------\n");
}

void consultar_pedido(Pedido pedido){
    
    /*variaveis
    num_mesa: guarda o número da mesa para comparar
    qtde_pedi: guarda o número total de pedidos
    pedido: struct com os dados dos pedidos de cada mesa
    */
    int num_mesa, qtde_pedi, j;

    //registro do número da mesa
    
    printf("Digite o número da mesa que deseja consultar: ");
    scanf("%d", &num_mesa);

    //exibição de tudo que a mesa pediu
    
    printf("Pedidos da mesa %d:\n", num_mesa);
    
    for(int i = 0; i < qtde_pedi; i++){
        
        if(pedido[i].numero == num_mesa){
            
            printf("Prato: %s | Quantidade: %d | Preço por unidade: %.2f.\n", pedido[i].produto.nome, pedido[i].quantidade,pedido[i].produto.preco);
            
            j = 1;
            
        }
        
    }

    //tratamento para caso não tiver pedidoos na mesa ou ela ser inexistente
    
    if(j != 1){
        
        printf("Não tem pedidos registrados na mesa %d.", num_mesa);
        
    }
    
}


void cadastrarPedido(Tpedido pedidos[], Produto produtos[],int totalProdutos){
    int codigo;
    int quantidade;
    // Percorre a lista de pedidos
    for (int i = 0; i < 50; i++) {
        // Checa que posição esta vaga
        if (pedidos[i].numero == 0) {
            pedidos[i].numero = i + 1;
            printf("Pedido de numero %i\n", pedidos[i].numero);
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            // Percorre a lista de produtos
            for (int j = 0; j < totalProdutos; j++) {
                // Checa se o códido escaneado está na lista de produtos
                if (produtos[j].codigo == codigo) {

                    pedidos[i].produto = produtos[j];

                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade);

                    pedidos[i].quantidade = quantidade;

                    return;
                }
            }

            printf("Produto nao encontrado!\n");

            // Libera a posição caso o produto não exista
            pedidos[i].numero = 0;

            return;
        }
    }

    printf("Nao ha espaco para novos pedidos!\n");
}


void calculoPedido(Ppedido listaPedidos, int nPedido){
    float total;
    // Verifica se o pedido informado existe
    if (listaPedidos[nPedido - 1].numero == 0) {
        printf("Pedido nao encontrado!\n");
        return;
    }
    // Calcula o valor total multiplicando o preco pela quantidade
    total = listaPedidos[nPedido - 1].produto.preco *
            listaPedidos[nPedido - 1].quantidade;
    // Exibe o valor final
    printf("Valor total do pedido: R$ %.2f\n", total);
}
