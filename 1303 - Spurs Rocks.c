#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int identificador;
    int pontuacao;
    int pontos_feitos;
    int pontos_recebidos;
} Equipe;

int comparar(const void *a, const void *b)
{
    Equipe *e1 = (Equipe *)a;
    Equipe *e2 = (Equipe *)b;

    if (e1->pontuacao != e2->pontuacao)
        return e2->pontuacao - e1->pontuacao;

    double media_cestas1 = (e1->pontos_recebidos == 0) ? e1->pontos_feitos : (double)e1->pontos_feitos / e1->pontos_recebidos;
    double media_cestas2 = (e2->pontos_recebidos == 0) ? e2->pontos_feitos : (double)e2->pontos_feitos / e2->pontos_recebidos;

    if (media_cestas1 != media_cestas2)
        return (media_cestas1 > media_cestas2) ? -1 : 1;

    if (e1->pontos_feitos != e2->pontos_feitos)
        return e2->pontos_feitos - e1->pontos_feitos;

    return e1->identificador - e2->identificador;
}

int main()
{
    int num_equipes, instancia = 0;
    while (scanf("%d", &num_equipes) == 1 && num_equipes)
    {
        Equipe equipes[100];
        for (int i = 0; i < num_equipes; i++)
        {
            equipes[i].identificador = i + 1;
            equipes[i].pontuacao = 0;
            equipes[i].pontos_feitos = 0;
            equipes[i].pontos_recebidos = 0;
        }

        int num_jogos = (num_equipes * (num_equipes - 1)) / 2;
        for (int i = 0; i < num_jogos; i++)
        {
            int equipe1, pontos1, equipe2, pontos2;
            scanf("%d %d %d %d", &equipe1, &pontos1, &equipe2, &pontos2);

            equipes[equipe1 - 1].pontos_feitos += pontos1;
            equipes[equipe1 - 1].pontos_recebidos += pontos2;
            equipes[equipe2 - 1].pontos_feitos += pontos2;
            equipes[equipe2 - 1].pontos_recebidos += pontos1;

            if (pontos1 > pontos2)
            {
                equipes[equipe1 - 1].pontuacao += 2;
                equipes[equipe2 - 1].pontuacao += 1;
            }
            else
            {
                equipes[equipe2 - 1].pontuacao += 2;
                equipes[equipe1 - 1].pontuacao += 1;
            }
        }

        qsort(equipes, num_equipes, sizeof(Equipe), comparar);

        if (instancia)
            printf("\n");
        printf("Instancia %d\n", ++instancia);

        for (int i = 0; i < num_equipes; i++)
        {
            if (i)
                printf(" ");
            printf("%d", equipes[i].identificador);
        }
        printf("\n");
    }
    return 0;
}
