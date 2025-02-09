#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
    char nome[20];
    struct no *prox;
};

struct no *criarno(char nome[])
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void adicionarNoFinal(struct no **inicio, char nome[])
{
    struct no *novo = criarno(nome);
    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        struct no *temp = *inicio;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void buscar_inserir(struct no **inicio, struct no *listaNova, char amigo[])
{
    struct no *anterior = NULL;
    struct no *p = *inicio;

    while (p != NULL && strcmp(p->nome, amigo) != 0)
    {
        anterior = p;
        p = p->prox;
    }
    if (p != NULL && listaNova != NULL)
    {
        if (anterior == NULL)
        {
            struct no *temp = listaNova;
            while (temp->prox != NULL)
            {
                temp = temp->prox;
            }
            temp->prox = p;
            *inicio = listaNova;
        }
        else
        {
            struct no *temp = listaNova;
            while (temp->prox != NULL)
            {
                temp = temp->prox;
            }
            temp->prox = p;
            anterior->prox = listaNova;
        }
    }
}

void inserir_no_fim(struct no **inicio, struct no *listaNova)
{
    struct no *p = *inicio;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = listaNova;
}

void exibirLista(struct no *inicio)
{
    struct no *p = inicio;
    while (p != NULL)
    {
        printf("%s", p->nome);
        if (p->prox != NULL)
        {
            printf(" ");
        }
        p = p->prox;
    }
    printf("\n");
}

int main()
{
    char entrada[100];
    char amigo[10];
    struct no *listaAmigos = NULL;
    struct no *listaNovosAmigos = NULL;

    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    char *nome = strtok(entrada, " ");
    while (nome != NULL)
    {
        adicionarNoFinal(&listaAmigos, nome);
        nome = strtok(NULL, " ");
    }

    memset(entrada, 0, sizeof(entrada));
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    char *novoNome = strtok(entrada, " ");
    while (novoNome != NULL)
    {
        adicionarNoFinal(&listaNovosAmigos, novoNome);
        novoNome = strtok(NULL, " ");
    }

    scanf("%s", amigo);
    if (strcmp(amigo, "nao") != 0)
    {
        buscar_inserir(&listaAmigos, listaNovosAmigos, amigo);
    }
    else
    {
        inserir_no_fim(&listaAmigos, listaNovosAmigos);
    }
    exibirLista(listaAmigos);
    return 0;
}
