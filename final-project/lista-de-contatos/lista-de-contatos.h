
typedef struct {
    int cod;
    char nome[60];
    char empresa[60];
    char departamento[30];
    char telefone[20]; //+55 (11) 9999-9999
    char celular[21]; //+55 (11) 99999-9999
    char email[60];
}CLIENTE;

typedef struct contato *LISTA;
LISTA *criar_lista();

int lista_existe(LISTA *li);
int tamanho_lista(LISTA *li);
int lista_vazia(LISTA *li);

int verificar_cliente_cadastrado(LISTA *li, CLIENTE cliente);

CLIENTE coletar_cliente();
CLIENTE coletar_atualizacao_cliente();
int coletar_codigo();
void coletar_nome(char *nome[60]);

int inserir_contato(LISTA *li, CLIENTE cliente);

void exibir_contato(CLIENTE cliente);
int buscar_codigo(LISTA *li, int cod, LISTA *contato);
int buscar_nome(LISTA *li, char nome[], LISTA *contatos_encontrados);
void listar_contatos(LISTA *li);
void listar_contatos_codigo(LISTA *li, int cod);
void listar_contatos_nome(LISTA *li, char nome[]);

void editar_contato_processo(LISTA *li);
void remover_contato_processo(LISTA *li);

int remover_contato(LISTA *li, int cod);

int confirmar_operacao(LISTA *li, char operacao[], LISTA *contato);

// Metodo para salvar lista atual em arquivo binario
void backup_contatos(LISTA *li);

// Metodo para ler CLIENTEs do arquivo binario e aloca-los na lista atual
void restore_contatos(LISTA *li);

void apagar_lista(LISTA *li); // Para apagar toda a memoria alocada pela lista na memoria do dispositivo

char *strlwr(char *str);
