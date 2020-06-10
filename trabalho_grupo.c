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
setlocale(LC_ALL,"pl_PL.UTF-8");

int opcao=0;
char nome_a;
float nota_f, nota_t ;
char certeza = 'n';
int num_eliminar;



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
        if (certeza== 's')
          registar( &head , nome_a, nota_f, nota_t );

        else
        {
          printf("\n dados nao gravados");
          sleep (5);
          break;
        }
        break;

      case 2:
        printf("\n escolheu n 2");
        break;

      case 3:
        printf( "Indique o num a eliminar");
        scanf("%d", &num_eliminar);
        eliminar (&head , num_eliminar);
        break;

      case 4:
        printf("\n escolheu n 4");
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
          printf("\n prima <enter> para continuar");
          getchar();
    }

 }
return(0);
}
