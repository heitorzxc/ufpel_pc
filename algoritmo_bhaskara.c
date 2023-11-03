#include <stdio.h>  // Inicializando entrada e saída padrão
#include <math.h>   // Compilar usando o argumento -lm
#include <locale.h> // Para uso da vírgula ao invés do ponto
#include <stdlib.h> // Necessário para limpar o console

float calcDelta(float a, float b, float c);
void formato(float a);
void raizes(float a, float b, float delta);

int main(void)
{

    setlocale(LC_ALL, "Portuguese");
    // Para uso da vírgula ao invés do ponto

    float a, b, c, delta;
    // Dispenso inicialização, pois valores serão substituídos ao longo do algoritmo

    char saida = 'S';
    // Condição de saída do algoritmo

    while (!(saida == 'N' || saida == 'n'))
    {
        // Enquanto eu não informar que quero sair...
        printf("Raízes de uma parábola:\n");
        // Mensagem de inicialização

        printf("Informe a: ");
        scanf("%f", &a);
        printf("Informe b: ");
        scanf("%f", &b);
        printf("Informe c: ");
        scanf("%f", &c);
        // Obtendo os dados da equação

        delta = calcDelta(a, b, c);
        // Determinação do valor de delta
        formato(a);
        // Analisando como será o formato da parábola
        raizes(a, b, delta);
        // Verificando e determinando as raízes

        printf("Deseja analisar outra equação? (S/N)\n> ");
        scanf("%s", &saida);
        if (saida == 'S' || saida == 's')
        {
            system("clear");
            // Limpando o console para recomeçar
        }
    }

    return (0);
}

float calcDelta(float a, float b, float c)
{
    return (pow(b, 2) - 4 * a * c);
}

void formato(float a)
{
    if (a > 0)
    {
        printf("Concavidade voltada para cima (u).\n");
    }
    else
    {
        printf("Concavidade voltada para baixo (∩).\n");
    }
}

void raizes(float a, float b, float delta)
{
    if (delta > 0)
    {
        // Delta maior do que zero
        printf("Raízes: %.2f e %.2f.\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
    }
    else
    {
        // Delta menor ou igual a zero
        if (delta == 0)
        {
            // Delta igual a zero
            printf("Raíz: %.2f.\n", (-b + sqrt(delta)) / (2 * a));
        }
        else
        {
            // Delta menor que zero
            printf("Vértice: (%.2f, %.2f)\n", -(b/(2*a)), -(delta/(4*a)));
        }
    }
}