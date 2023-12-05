
typedef struct {
    int cod;
    char nome[60];
    char empresa[60];
    char departamento[30];
    char telefone[20]; //+55 (11) 9999-9999
    char celular[21]; //+55 (11) 99999-9999
    char email[60];
}CLIENTE;

typedef struct contato *LISTA; // Variavel para armazenar ponteiro para 1° elemento da lista
LISTA *criar_lista(); // Aloca memoria para lista

int lista_existe(LISTA *li); // Retorna 1 se a lista passada como parametro esta alocada
int tamanho_lista(LISTA *li); // Retorna o tamanho da lista
int lista_vazia(LISTA *li); // Retorna 1 se a lista nao tiver contatos

int verificar_cliente_cadastrado(LISTA *li, CLIENTE cliente); // Retorna 1 se encontrar o cliente na lista

CLIENTE coletar_cliente(); // Retorna cliente preenchido com dados informados pelo user
CLIENTE coletar_atualizacao_cliente(); // Retorna cliente 
int coletar_codigo(); // Retorna codigo informado pelo user 
void coletar_nome(char *nome[60]); // Retorna para ponteiro do parametro uma string de nome informada pelo usuario

int inserir_contato(LISTA *li, CLIENTE cliente); // Retorna 1 se conseguir inserir cliente na lista de contatos

void exibir_contato(CLIENTE cliente); // Imprime dados do cliente (CONTATO->dados == CLIENTE)
int buscar_codigo(LISTA *li, int cod, LISTA *contato); // Retorna 1 se cod dos parametros for encontrado na lista, retorna um ponteiro para contato usando contato do parametro
int buscar_nome(LISTA *li, char nome[], LISTA *contatos_encontrados); // Retorna 1 se encontrar ao menos uma vez aquele um pedaço de nome na lista, retorna ponteiro para lista de contatos encontrados nos parametros
void listar_contatos(LISTA *li); // Imprime todos contatos da lista
void listar_contatos_codigo(LISTA *li, int cod); // Imprime contato com o codigo informado nos parametros
void listar_contatos_nome(LISTA *li, char nome[]); // Imprime contatos que contenham o trecho da string passada como parametro (char nome[])

void editar_contato_processo(LISTA *li); // Gerencia a pesquisa, exibicao, confirmacao e atualizacao de dados de um contato
void remover_contato_processo(LISTA *li); // Gerencia a pesquisa, exibicao e confirmacao para deletar contato

int remover_contato(LISTA *li, int cod); // Retorna 1 se encontrar e excluir contato da lista usando codigo

int confirmar_operacao(LISTA *li, char operacao[], LISTA *contato); // Retorna 1 se usuario confirmar que deseja realizar a operacao

void backup_contatos(LISTA *li); // Salva lista em arquivo binario

void restore_contatos(LISTA *li); // Busca CLIENTEs do arquivo binario de backup e os aloca na lista

void apagar_lista(LISTA *li); // Libera toda memoria alocada pela lista na memoria do dispositivo

char *strlwr(char *str); // Metodo que recebe ponteiro para string (char[]) e transforma todos caracteres em lowercase
