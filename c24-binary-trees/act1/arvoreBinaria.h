typedef struct NO *ArvBin;

//Criando a arvore
ArvBin *cria_arvBin();

//Destruindo a arvore
void liberar_arvBin(ArvBin *raiz);

//Coletando info
int vazia_arvBin(ArvBin *raiz);
int altura_arvBin(ArvBin *raiz);
int totalNO_arvBin(ArvBin *raiz);

//Percorrendo a arvore
int preOrdem_arvBin(ArvBin *raiz);
int emOrdem_arvBin(ArvBin *raiz);
int posOrdem_arvBin(ArvBin *raiz);

//Operacoes na arvore
int insere_arvBin(ArvBin *raiz, int valor);

