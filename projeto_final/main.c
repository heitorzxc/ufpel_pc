/* Trabalho final - Programação de Computadores
Heitor Avila, Cecilia Botelho, Eduardo Schwantz */

// Bibliotecas C
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Bibliotecas Próprias
#include "funcoes.h"

int main() {
  // Exibição de mensagem de boas-vindas
  printf("Academia Flor do Dia | Sua dor, nossa alegria!\n");

  // Outras variáveis locais da função main
  char tempNome[100], tempIdade[10], tempTelefone[20];
  int opcao;

  // Lista recebe o endereço fornecido pela função cria (return)
  lista = cria();

  // Execução de repetição forçada com saída condicional
  for (;;) {
    // Exibição do menu e captura da opção
    exibirMenu();
    scanf("%d", &opcao);
    printf("\n");
    // Responsável por consumir a quebra de linha no buffer
    getchar();
    // Switch case usado pra definir as condições do menu
    switch (opcao) {
      
      case 1:
        // Obtendo e armazenando informações em variáveis locais
        printf("Nome: ");
        fgets(tempNome, 100, stdin);
        printf("Idade: ");
        fgets(tempIdade, 10, stdin);
        printf("Telefone: ");
        fgets(tempTelefone, 20, stdin);
        // Executando a função "inserir" com as variáveis como parâmetro
        inserir(tempNome, tempIdade, tempTelefone, lista);
        // Comando de saída do switch
        break;

      case 2:
        // Função "imprime" que recebe a variável "lista" como parâmetro
        imprime(lista);
        break;

      case 3:
        // Buscar cliente na RAM
        printf("Digite o nome: ");
        fgets(tempNome, 100, stdin);
        busca(tempNome, lista);
        break;
      
      case 4:
        // Remover cliente da RAM
        printf("Digite o nome do cliente: ");
        fgets(tempNome, 100, stdin);
        remova(tempNome, lista);
        printf("Verifique resultado na opção 2.\n");
        break;

      case 5:
        // Salvar no disco os clientes na RAM
        salvar(lista);
        printf("Escrita no disco efetuada.\n");
        break;

      case 6:
        // Exibe na tela os clientes no disco
        imprimirDisco();
        break;

      case 7:
        // Exibe na tela as instruções do programa
        ajuda();
        break;

      case 8:
        // Comando shell executado pela função system(); da stdlib.h
        system("clear");
        break;

      case 9:
        // Comando de saída retornando "0" para o sistema
        exit(0);

      case 10:
        // Comando para limpar o arquivo no disco
        limparDisco();
        break;
      
      case 11:
        // Comando para limpar a lista encadeada
        free(lista);
        lista = cria();
        break;
      
      case 12:
        // Comando para importar para a RAM o que está no disco
        importarDisco(lista);
        break;
      }
  }
  // return 0; em comentário pois o algoritmo não tem como avançar da linha 112 por causa das condições definidas na estrutura de repetição anterior
}
