#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"


struct node {
  int num_aluno;
  char nome_aluno;
  //*char apelido_aluno;
  float nota_frequencia;
  float nota_trabalho;
 

  struct node *seg;
  struct node *ant;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

//is list empty
bool isEmpty() {
   return head == NULL;
}

int main()
{
int opcao=0;

while (1)
{

    system("cls");
    printf(" =============================================================================\n");
    printf("                            Avaliacao de Alunos\n");
    printf(" =============================================================================\n\n");
    printf("                          <<<  Menu Principal >>>\n\n");
    printf("                            1) Registar aluno \n");
    printf("                            2) Editar registo\n");
    printf("                            3) Eliminar registo\n");
    printf("                            4) Pesquisar registo\n");
    printf("                            5) Listar registos\n");
    printf("                            0) Terminar Programa\n\n");
    printf(" =============================================================================\n");
    printf(" =============================================================================\n\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);
    getchar();


    switch (opcao)
    {
      case 1:
        inserir_inicio (1,'m', 15,14);
        printf("\n escolheu n 1");
        break;

      case 2:
        printf("\n escolheu n 2");
        break;

      case 3:
        printf("\n escolheu n 3");
        break;

      case 4:
        printf("\n escolheu n 4");
        break;

      case 5:
        printf("\n escolheu n 5");
        break;

      case 0:
        printf("\n\n     Seleciou a Opcao:\n >>> Terminar Programa <<<\n\n");
        printf(" Tem a certeza (s/n)? ");
        if(getchar()=='s')
            { printf("\n Adeus! Ate a vista!\n");
              
              exit(0);
            }
        break;

      default:
          printf("\n !!! A opcao escolhida nao e valida !!!\n");
          puts(" Por favor escolha uma opcao indicada");
          printf("\n prima <enter> para continuar");
          getchar();
    }

 }
return(0);
}
