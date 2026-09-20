#ifndef SISTEMA_H
#define SISTEMA_H

typedef struct PRODUTO{
    int codigo_interno;
    char nome[50];
    char categoria[50];
    float preco;
}produto;

void listarCardapio(produto cardapio[],int qtd);

#endif