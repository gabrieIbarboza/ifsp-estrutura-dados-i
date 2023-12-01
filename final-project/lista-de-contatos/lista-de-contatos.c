#include <stdio.h>
#include <stdlib.h>
#include "lista-de-contatos.h"

typedef struct contato{
    CLIENTE dados;
    struct contato *prox_contato;
}CONTATO;

LISTA *criar_lista()
{
    LISTA *li;
    li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL)
    {
        *li = NULL;
    }
    return li;
}

int tamanho_lista(LISTA *li)
{
    if(li == NULL)
    {
        return 0;
    }

    int total = 0;
    CONTATO *c = *li;
    while(c != NULL)
    {
        total++;
        c = c->prox_contato;
    }
    return total;
}

int lista_vazia(LISTA *li)
{
    if(tamanho_lista(li) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
