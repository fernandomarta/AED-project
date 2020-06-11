#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"

//is list empty
bool isEmpty() {
   return head == NULL;
}


int main()
{
//setlocale(LC_ALL,"pl_PL.UTF-8");

FILE * alunos;

alunos = fopen("BDalunos.db","a+b");
if(!alunos)
  {  puts("erro ao abrir ficheiro");
    exit(1);
  }

int opcao=0;
char nome_a;
float nota_f, nota_t ;
char certeza = 'n';
int num_selecionado;

while (1)
{

    opcao = menu();
    getchar();


    switch (opcao)
    {
      case 1:
        printf("Indique o Nome do Aluno: ");
        scanf("%c",  &nome_a);
        while (1)
        {printf("Indique a nota da frequencia: ");
        scanf("%f",  &nota_f);
        if( nota_f<0 || nota_f> 20)
          printf("valor invalido");
        else 
          break;
        }
        getchar();
        while(1)
        {
        printf("Indique a nota do trabalho: ");
        scanf("%f",  &nota_t);
        if( nota_t<0 || nota_t> 20)
          printf("valor invalido");
        else 
          break;
        }
        printf("Tem a certeza? (s/n): ");
        getchar();
        scanf("%c", &certeza);
        if (certeza == 's')
          registar( &head , nome_a, nota_f, nota_t );

        else if (certeza == 'n')
        {
          printf("\n dados nao gravados \n");
          espera();
          break;
        }
        break;

      case 2:
          num_selecionado = perguntar();
          pesquisar(&head , num_selecionado);
          printf("Tem a certeza? (s/n): ");
          getchar();
          scanf("%c", &certeza);
          if (certeza == 's')
          {
            editar(&head , num_selecionado);
          }
          else
          {
            system("cls");
          }

        break;

      case 3:
        num_selecionado = perguntar();
        eliminar(&head , num_selecionado);
        break;

      case 4:
        num_selecionado = perguntar();
        pesquisar(&head, num_selecionado);
        getchar();
        espera();
        break;

      case 5:
        listar (&head);
        espera();
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
          espera();
    }

 }

fclose(alunos);

return(0);
}
