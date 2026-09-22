#ifndef SISTEMA_H
#define SISTEMA_H

typedef struct PRODUTO{
    int codigo_interno;
    char nome[50];
    char categoria[50];
    float preco;
} produto;

typedef struct PEDIDO{
    int numero;       // número da mesa (0 = posição livre) 
    produto produto;  // produto pedido
    int quantidade;
} Tpedido, *Ppedido, **Mpedido;

void Cadastrar(int totalProdutos, produto *produtos);
void listarCardapio(produto cardapio[], int qtd);
void cadastrarPedido(Tpedido pedidos[], produto produtos[], int totalProdutos);
void consultar_pedido(Ppedido pedido);
void alterar_pedido(Ppedido pedido, produto cardapio[], int qtdCardapio);
void calculoPedido(Tpedido pedidos[], int nPedido);
void voltar_menu();

#endif#ifndef SISTEMA_H
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
