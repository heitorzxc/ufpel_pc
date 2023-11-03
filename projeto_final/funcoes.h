// Definindo uma struct
struct cel {
  char nome[50];
  char idade[4];
  char telefone[12];
  struct cel *prox;
};

// Definindo a struct cel como um tipo de variável de nome "celula"
typedef struct cel celula;

// Criando ponteiro (vetor) global para uso das funções
celula *lista;

// Protótipo das funções presentes em "funcoes.c"
celula *cria(void);
void exibirMenu(void);
void inserir(char nome[50], char idade[4], char telefone[12], celula *p);
void imprime(celula *ini);
void busca(char nome[100], celula *ini);
void remova(char nome[50], celula *ini);
void salvar(celula *ini);
void imprimirDisco(void);
void ajuda(void);
void limparDisco(void);
void importarDisco(celula *ini);
