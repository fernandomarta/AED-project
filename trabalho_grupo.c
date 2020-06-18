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

alunos = fopen("BDalunosAED.db","a+b");
if(!alunos)
  {  puts("erro ao abrir ficheiro");
    exit(1);
  }

int opcao=0;
char nome_a[30];
float nota_f, nota_t ;
char certeza = 'n';
int num_selecionado;

while (1)
{
  opcao = menu();
  getchar();

    switch (opcao)
    {
      case 1: //Registar novo Aluno ==============================================================
        printf("Indique o Nome do Aluno: ");
        scanf("%s", nome_a);
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
        printf("Tem a certeza dos valores inseridos? (s/n): ");
        getchar();
        scanf("%c", &certeza);
        if (certeza == 's')
          registar( head , nome_a, nota_f, nota_t );

        else if (certeza == 'n')
        {
          printf("\n Dados nao gravados \n");
          espera();
          break;
        }
        break;

      case 2:  //Editar Aluno ======================================================================
          num_selecionado = perguntar();
          pesquisar(head , num_selecionado);
          printf("Registo a editar. Tem a certeza? (s/n): ");
          getchar();
          scanf("%c", &certeza);
          if (certeza == 's')
          {
            editar(head , num_selecionado);
          }
          else
          {
            system("cls");
          }

        break;

      case 3:  //Eliminar registo de Aluno ==============================================================
            num_selecionado = perguntar();
            pesquisar(head , num_selecionado);
            printf("Registo a eliminar. Tem a certeza? (s/n): ");
            getchar();
            scanf("%c", &certeza);
            if (certeza == 's')
            {
              eliminar(head , num_selecionado);
            }
            else
            {
              system("cls");
            }
        
        break;

      case 4:  //Pesquisar registo de Aluno ==============================================================
        num_selecionado = perguntar();
        pesquisar(head, num_selecionado);
        getchar();
        espera();
        break;

      case 5:  //Listar todos os registos dos Alunos =====================================================
        listar (head);
        espera();
        break;

      case 0:  // Terminar o programa ====================================================================
        printf("\n\n     Seleciou a Opcao:\n >>> Terminar Programa <<<\n\n");
        printf(" Pretende sair do programa (s/n)? ");
        if(getchar()=='s')
            { printf("\n Adeus! Ate a vista!\n");
              
              exit(0);
            }
        break;

      default:  // Check para escolha do numero correto das opções do Menu ===============================
          printf("\n !!! A opcao escolhida nao e valida !!!\n");
          puts(" Por favor escolha uma opcao indicada");
          espera();
    }

 }

fclose(alunos);

return(0);
}
