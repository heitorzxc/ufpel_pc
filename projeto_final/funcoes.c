// Funções do C
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Funções próprias
#include "funcoes.h"

// Função tipo void para imprimir menu
void exibirMenu(void) {
  // Realiza apenas a impressão do menu na tela
  printf("\n");
	printf("1: Novo cadastro    (RAM)\n");
	printf("2: Listar cadastros (RAM)\n");
	printf("3: Buscar pelo nome (RAM)\n");
	printf("4: Excluir cadastro (RAM)\n");
	printf("5: Salvar no disco\n");
	printf("6: Listar do disco\n");
  printf("7: Ajuda do programa\n");
  printf("8: Limpar tela\n");
	printf("9: Sair do programa\n");
  printf("10: Limpar cadastros\n");
  printf("11: Limpar cadastros  (RAM)\n");
  printf("12: Importar do disco (RAM)\n");
  printf("\n> ");
  // Função void não precisa de retorno
}

// Função "cria" do tipo "celula" que cria a lista encadeada 
celula *cria(void) {
  // Declara um ponteiro local do tipo "celula" com nome "start"
	celula *start;
  // Realiza a alocação de memória para armazenar a lista encadeada
	start = (celula *)malloc(sizeof(celula));
  // Define o endereço de start->prox como "NULL"
	start->prox = NULL; // (*start).prox
  // Retorna o endereço de start (primeiro elemento da lista) para onde foi chamada
	return start;
}

void inserir(char nome[100], char idade[10], char telefone[20], celula *p) {
  // Cria um novo ponteiro do tipo "celula" chamado "nova"
	celula *nova;
  // Inicializa o ponteiro alocando memória
	nova = (celula *)malloc(sizeof(celula));
  // Copia para a nova célula o conteúdo das variáveis
  strcpy(nova->nome, nome);
	strcpy(nova->idade, idade);
	strcpy(nova->telefone, telefone);
  // O endereço do próximo elemento de nova agora é o endereço de p->prox
	nova->prox = p->prox;
  // E o endereço de p->prox agora é o endereço de nova
	p->prox = nova;
}

// A função imprime recebe um ponteiro como parâmetro
void imprime(celula *ini) {
  // Declara um novo ponteiro do tipo celula localmente
  celula *p;
  // Para p = ao endereço ini->prox até p!=NULL recebendo o endereço p->prox
	for (p = ini->prox; p != NULL; p = p->prox) {
    // Imprimindo os valores das variáveis
		printf("Nome: %s", p->nome);
	  printf("Idade: %s", p->idade);
	  printf("Telefone: %s", p->telefone);
    printf("\n");
  }
}

// A função busca recebe como parâmetro a variável char e o ponteiro celula
void busca(char nome[100], celula *ini) {
  // Crio um ponteiro local tipo celula
	celula *p;
  // Como a lista tem uma cabeça então o primeiro elemento está em ini->prox
	p = ini->prox;
  // Condição de aviso de nome não encontrado
  int existencia = 0;
  // Mesma lógica usada para imprimir a lista encadeada
  for (p = ini->prox; p != NULL; p = p->prox) {
    // Se a comparação entre as strings for verdadeira (return 0)
    if (strcmp(p->nome,nome)) {
      // Retornando existência falsa
      existencia=0;
    }
    else {
      // Retornando existência verdadeira
      existencia=1;
      // Exibindo existência
      printf("Foi encontrado.\n");
      break;
    }
  }
  // Se o arquivo não existe (não foi encontrado)
  if (existencia == 0) {
    // Exibindo inexistência
    printf("Não foi encontrado.\n");
  }
}

// Função remova recebe um char e um celula como parâmetro
void remova(char nome[100], celula *ini) {
  // Declarando dois ponteiros tipo celula locais
	celula *p, *q;
  // Este ponteiro p recebe a cabeça da lista encadeada
	p = ini;
  // O segundo ponteiro recebe o primeiro elemento da lista encadeada
	q = ini->prox;
  // Enquanto o segundo for diferente de nulo e a comparação entre o nome informado e o nome presente em cada celula for diferente
	while ((q != NULL) && (strcmp(q->nome, nome) != 0)) {
    // O ponteiro p irá receber o endereço de q
		p = q;
    // O q irá avançar recebendo o endereço de q->prox
		q = q->prox;
	}
  // Quando o laço parar, p irá conter a célula anterior e q irá conter a próxima célula
  // Se o endereço de q não for nulo
	if (q != NULL) {
    // p->prox irá receber o endereço de q->prox;
		p->prox = q->prox;
    // Liberando a memória alocada no endereço de q
		free(q);
	}
}

// Função salvar recebe a lista encadeada como parâmetro
void salvar(celula *ini) {
  // Criando um ponteiro local do tipo celula
	celula *p;
  // Declarando um ponteiro do tipo FILE
	FILE *arquivo;
  // Ponteiro arquivo recebe o endereço retornado por fopen
	arquivo = fopen("clientes.txt", "a");
  // Mesma lógica usada para imprimir na tela, só que agora no disco
	for (p = ini->prox; p != NULL; p = p->prox) {
		fprintf(arquivo,"%s", p->nome);
		fprintf(arquivo,"%s", p->idade);
		fprintf(arquivo,"%s", p->telefone);
	}
  // Fechando o arquivo com a função fclose
	fclose(arquivo);
}

// Função tipo void que imprime na tela os clientes do disco
void imprimirDisco(void) {
  // Declarando ponteiro local para arquivo
	FILE *arquivo;
  // Abrindo arquivo
	arquivo = fopen("clientes.txt", "r");
  // Variável local para armazenar caractere
  char c;
  // Variável recebe o caractere na posição atual (e a posição é avançada)
	c = fgetc(arquivo);
  // Enquanto não chegar ao fim do arquivo 
	while (!feof(arquivo)) {
		putchar(c);
    // Imprimindo o caractere armazenado por c na tela
    // Variável recebe o caractere na posição atual (e a posição é avançada)
    c = fgetc(arquivo);
	}
  // Fechando o arquivo
	fclose(arquivo);
}

// Mesmo raciocínio da função imprimirDisco usado para a ajuda
void ajuda(void) {
	// Ponteiro tipo FILE local
  FILE *arquivo;
  // Carregando arquivo de ajuda
	arquivo = fopen("ajuda.txt", "r");
	// Variável char local
  char c;
  // Char recebe caractere na posição atual de arquivo (e posição avança)
	c = fgetc(arquivo);
  // Enquanto não chegar ao final do arquivo
	while (!feof(arquivo)) {
		// Imprime na tela o caractere
    putchar(c);
    // Char recebe caractere na posição atual de arquivo (e posição avança)
		c = fgetc(arquivo);
	}
  // Fechando o arquivo
	fclose(arquivo);
}

// Função para esvaziar a lista de clientes no disco
void limparDisco(void) {
  FILE *arquivo;
  // O parâmetro "w" permite substituir o conteúdo do arquivo
  arquivo = fopen("clientes.txt", "w");
  // Estamos imprimindo um conteúdo vazio no arquivo com fprintf
  fprintf(arquivo, "");
  // E fechando o arquivo com segurança
  fclose(arquivo);
}

// Essa função converte o conteúdo do arquivo em nós de lista encadeada
void importarDisco(celula *ini) {
  // Ponteiro local para o arquivo
  FILE *arquivo;
  arquivo = fopen("clientes.txt", "r");
  // Variáveis locais para captura de informações  
  char nome[100], idade[10], telefone[20];
  // Enquanto não chegar ao fim do arquivo
  while (!feof(arquivo)) {
    // Obtendo strings
    fgets(nome, 100, arquivo);
    fgets(idade, 10, arquivo);
    fgets(telefone, 20, arquivo);
    // Este comando previne que o primeiro nó seja duplicado
    if (!feof(arquivo))
      inserir(nome, idade, telefone, ini);
  }
  printf("Importado.\n");
}
