
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

int tamanho_lista(LISTA *li);
int lista_vazia(LISTA *li);


