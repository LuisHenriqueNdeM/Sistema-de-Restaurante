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

void consultar_pedido(PPedido pedido){
    
    /*variaveis
    num_mesa: guarda o número da mesa para comparar
    qtde_pedi: guarda o número total de pedidos
    pedido: struct com os dados dos pedidos de cada mesa
    */
    int num_mesa, qtde_pedi = 50, j = 0;

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
