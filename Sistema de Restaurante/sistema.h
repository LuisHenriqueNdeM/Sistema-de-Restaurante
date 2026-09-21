#ifndef SISTEMA_H
#define SISTEMA_H

typedef struct PRODUTO{
    int codigo_interno;
    char nome[50];
    char categoria[50];
   float preco;
}produto;

typedef struct Pedido{
    int numero;
    Produto produto;
    int quantidade;
}Tpedido, *Ppedido, **Mpedido;

void listarCardapio(produto cardapio[],int qtd);
void consultar_pedido(Pedido pedido);
void cadastrarPedido(Tpedido pedidos[], Produto produtos[],int totalProdutos);
void calculoPedido(Ppedido listaPedidos, int nPedido);

#endif
