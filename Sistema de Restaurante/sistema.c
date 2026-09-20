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