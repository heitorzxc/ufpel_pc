/* Comece por 90052.txt.
Boa sorte! */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(void)
{
	char nextNothingIs[] = "Next nothing is ";
	char nomeNext[] = "Next nothing is ";
	char nomeArquivo[] = "90052.txt";
	char nomeTxt[] = ".txt";
	char c;
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "r");
	for (;;)
	{
		fgets(nomeNext, 17, arquivo);
		if (strcmp(nomeNext, nextNothingIs))
		{
			break;
		}
		else
		{
			fgets(nomeArquivo, 256, arquivo);
			strcat(nomeArquivo, nomeTxt);
			fclose(arquivo);
			arquivo = fopen(nomeArquivo, "r");
		}
	}
	rewind(arquivo);
	c = fgetc(arquivo);
	while (!feof(arquivo))
	{
		putchar(c);
		c = fgetc(arquivo);
	}
	fclose(arquivo);
	return 0;
}
