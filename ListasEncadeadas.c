#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMESIZE 50
#define true 1
#define false 0

// Structs usadas

typedef struct Smateria {
  char titulo[NAMESIZE];
  char status; // A ou R
  float notas[4]; // notas[0] e a media das notas
  /*
    notas[1] = 6.0
    notas[2] = 5.0
    notas[0] = (notas[1] + notas[2]) / 2 # 5.5
    notas[3] = 6.5
    notas[0] = (notas[0] + notas[3]) / 2 # 6.0
  */
  struct Smateria * proximo; // NULL
} materia;

typedef struct Saluno {
  char nome[NAMESIZE];
  unsigned int matricula; // 151047000
  //Direcionais da struct Saluno
  void * anterior;
  void * proximo;
  struct Smateria * turma;
} aluno;

typedef struct Sheader {
  unsigned int quantidade;
  unsigned int maiorMatricula;
  unsigned int menorMatricula;
  struct Saluno * proximo;
  struct Saluno * anterior;
} head;

head * cabeca = NULL;
aluno * lista = NULL;

int main() {
  void iniciar_head(); // Completa
  void inserir_aluno(); // Imcompleta
  void mostrar_todos(); // Imcompleta

  iniciar_head();

  int choice;

  while(true) {
    printf("\nDiga o que deseja fazer:");
    printf("\n  1 - Inserir Aluno");
    printf("\n  5 - Mostrar todos");
    printf("\n  0 - Sair");
    printf("\n>>");
    scanf("%i", &choice);

    if(choice == 1) {
      inserir_aluno();
    }
    else if(choice == 5) {
      mostrar_todos();
    }
    else if(choice == 0) {
      break;
    }

  }

  printf("\nHello World\n");

  return 0;
}

void iniciar_head() {
  cabeca = malloc(sizeof(head));
  /*
  [<|cabeca|>]
  */
  cabeca->quantidade=0;
  cabeca->proximo = NULL;
  cabeca->anterior = NULL;
  cabeca->maiorMatricula = 0;
  cabeca->menorMatricula = 151048000;
  printf("\nCabeca criada");
  printf("\nEspaco - Maior - Menor - Quantidade");
  printf("\n%p - %i - %i - %i", cabeca, cabeca->maiorMatricula, cabeca->menorMatricula, cabeca->quantidade);
}

void inserir_aluno() {
  aluno * aux, * criador, * seguraLista;
  /*
    aux = auxiliar da lista, podendo percorrer e salvar
    criador = ponteiro de alocacao, nele esta salvo os dados das novas instancias, para ser trabalhado
    seguraLista = Como o nome diz, ele ira gravar a posicao da lista quando necessario
      para que a mesma nao se perca
  */
  char name[NAMESIZE];
  unsigned int mat;

  printf("\n\nInserindo aluno:");
  printf("\nDiga o nome do aluno: ");
  scanf(" %[^\n]s%*c", name);
  printf("Diga os tres ultimos numeros da matricula: ");
  scanf("%i", &mat);
  mat = 151047000 + (mat%1000);

  if(lista == NULL) {
    aux = malloc(sizeof(aluno));
    /*
    [<|_aux_|>]
    */
    aux->proximo = (struct Sheader *) malloc(sizeof(head));
    aux->proximo = cabeca; // Aux -> cabeca
    aux->matricula = mat;
    strcpy(aux->nome, name);
    aux->anterior = (struct Sheader *) malloc(sizeof(head));
    aux->anterior = cabeca; // Cabeca <- Aux
    aux->turma = malloc(sizeof(materia));
    aux->turma = NULL;

    cabeca->proximo = aux; // Cabeca -> Aux
    cabeca->anterior = aux; // Aux <- cabeca
    cabeca->menorMatricula = mat;
    cabeca->maiorMatricula = mat;
    cabeca->quantidade += 1;
    lista = aux;
  }
  else {
    aux = lista;

    criador = malloc(sizeof(aluno));
    strcpy(criador->nome, name);
    criador->matricula = mat;

    while(aux->proximo != cabeca) {
      aux = aux->proximo;
      /*
       Auxiliar ira percorrer a lista ate chegar o ultimo elemento, que é o elemento
      que retornaria para o cabeca
      */
    }

    aux->proximo = criador; // Aux -> criador
    criador->anterior = aux; // Aux <- criador
    criador->proximo = cabeca; // Criador -> cabeca
    cabeca->anterior = criador; // Criador <- cabeca
    criador->turma = NULL;
    cabeca->quantidade += 1;
  }
}

void mostrar_todos() {
  aluno * auxAluno = NULL; // Auxiliar que ira percorrer a lista

  if(lista != NULL) {
    printf("\nHEAD");
    printf("\n    Quantidade: %i - Maior: %i - Menor: %i", cabeca->quantidade, cabeca->maiorMatricula, cabeca->menorMatricula);
    printf("\n  Alunos");
    auxAluno = lista;
    while(auxAluno != cabeca) {
      //Percorre a lista até que ela retorne a cabeca
      printf("\n      Matricula: %i - Nome %s", auxAluno->matricula, auxAluno->nome);
      auxAluno=auxAluno->proximo;
    }
  }
  else {
    printf("\nA lista esta vazia!");
  }
}
