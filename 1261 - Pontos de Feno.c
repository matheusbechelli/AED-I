#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char cargo[20];
	unsigned comissao;

} funcao;

typedef struct{

	char palavra[300];

} string;

bool procuraPalavra(funcao *, char *, unsigned short);
unsigned short posicao;

void main ()
{

	unsigned short numPalavras, qtsCargos;
	char texto[10000], *palavraTmp;
	unsigned long qtsSalarioTotal;
	string dicionario[10000];
	unsigned short i, j;

	scanf("%hu %hu", &numPalavras, &qtsCargos);

	funcao cargos[numPalavras];
	memset(cargos, 0, sizeof(cargos));

	for (i = 0; i < numPalavras; i++)
			scanf(" %s %u", cargos[i].cargo, &cargos[i].comissao);

	while (qtsCargos--)
	{

		qtsSalarioTotal = 0;
		while (true)
		{

			scanf(" %[^\n]", texto);

			if (strcmp(texto, ".") == 0)
				break;

			i = 0;
			palavraTmp = strtok(texto, " ");
			strcpy(dicionario[i++].palavra, palavraTmp);

			do
			{

				palavraTmp = strtok('\0', " ");

				if (palavraTmp)
					strcpy(dicionario[i++].palavra, palavraTmp);

			} while (palavraTmp);

			for (j = 0; j < i; j++)
				if (procuraPalavra(cargos, dicionario[j].palavra, numPalavras))
					qtsSalarioTotal += cargos[posicao].comissao;

		}

		printf("%lu\n", qtsSalarioTotal);

	}

}

bool procuraPalavra(funcao *cargos, char *palavra, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (strcmp(cargos[i].cargo, palavra) == 0)
		{
			posicao = i;
			return true;
		}

	return false;

}
