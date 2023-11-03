#include <stdio.h>
int main(void) {
    int numeroDeConceitos, conceitosLidos = 0, qtdeA = 0, qtdeB = 0, qtdeC = 0, qtdeD = 0, qtdeE = 0;
    char leituraDoConceito;
    printf("Informe quantos conceitos deseja informar: \n> ");
    scanf("%d", &numeroDeConceitos);
    while (conceitosLidos < numeroDeConceitos) {
        printf("Informe o conceito: \n> ");
        // Limpeza do buffer
        setbuf(stdin,NULL);
        scanf(" %c", &leituraDoConceito);
        //fgets(leituraDoConceito, 1, stdin);
        if (leituraDoConceito == 'a' || leituraDoConceito == 'A') {qtdeA++;}
        if (leituraDoConceito == 'b' || leituraDoConceito == 'B') {qtdeB++;}
        if (leituraDoConceito == 'c' || leituraDoConceito == 'C') {qtdeC++;}
        if (leituraDoConceito == 'd' || leituraDoConceito == 'D') {qtdeD++;}
        if (leituraDoConceito == 'e' || leituraDoConceito == 'E') {qtdeE++;}
        conceitosLidos++; }
    printf("Total de conceitos:\n");
    printf("A: %d \nB: %d \nC: %d \nD: %d \nE: %d \n", qtdeA, qtdeB, qtdeC, qtdeD, qtdeE);
    return 0;
}
