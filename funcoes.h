#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int num_aluno;
  char nome_aluno;
   //*char apelido_aluno;
  float nota_frequencia;
  float nota_trabalho;
 
  struct node *next;
}node_t;

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

int num_selecionado;

// FUNÇÃO MENU
int menu()
{
   int opcao_f;

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
    scanf("%d", &opcao_f);

    return(opcao_f);
}

//FUNÇÃO ESPERA

void espera ()
{
   printf("Prima a tecla <ENTER> para avançar");
   getchar();
}

// FUNÇAO REGISTAR

 void registar (node_t **head , char nome_aluno, float nota_frequencia, float nota_trabalho ) 
 {

   //int num_aluno = 0;
   //float media_aluno = 0;

   /* Posicionar no nó inicial */
      node_t *current = head;

      
   /* Percorrer a lista até ao final */
   while (current->next != NULL)
   {
   current = current->next;
   }

   /* Criar novo nó e adicionar no final */
   current->next = (node_t *) malloc(sizeof (node_t));
   current->next->num_aluno = current->num_aluno + 1;
   current->next->nome_aluno = nome_aluno;
   current->next->nota_frequencia = nota_frequencia;
   current->next->nota_trabalho = nota_trabalho;
   current->next->next = NULL;

 }


// FUNÇÃO LISTAR

void listar (node_t * head)
{
node_t * current = head->next;

printf ( "Num \t NOME \t\t Frequencia \t Trabalho \t Media \n");

while (current != NULL)
{
printf("%d \t", current->num_aluno);
printf("%-20c \t", current->nome_aluno);
printf("%.1f \t\t", current->nota_frequencia);
printf("%.1f \t\t", current->nota_trabalho);
printf("%.1f \n", (current->nota_frequencia + current->nota_trabalho)/2);
current = current->next;
}
}

// FUNÇÃO ELIMINAR

void eliminar (node_t **head , int num_aluno )
{
   node_t *current = head;

   // Percorrer a lista até encontrar 

   while (current->next->num_aluno != num_aluno)
   {
   /* if(current->next == NULL)
         printf("registo não encontrado");
         break; */

      current = current->next;
   }

   // eliminar o nó

   current->next = current->next->next;

   }


// FUNÇÃO PESQUISAR

void pesquisar (node_t * head , int num_aluno )
{
node_t *current = head->next;

// Percorrer a lista até encontrar 

while (current->num_aluno != num_aluno)
{
  /* if(current->next == NULL)
      printf("registo não encontrado");
      break; */

   current = current->next;
}

printf ( "Num \t NOME \t\t Frequencia \t Trabalho \t Media \n");

printf("%d \t", current->num_aluno);
printf("%-20c \t", current->nome_aluno);
printf("%.1f \t\t", current->nota_frequencia);
printf("%.1f \t\t", current->nota_trabalho);
printf("%.1f \n", (current->nota_frequencia + current->nota_trabalho)/2);
current = current->next;
}

// FUNÇÃO EDITAR

void editar (node_t * head , int num_aluno)
{
   char nome_aluno;
   float nota_frequencia;
   float nota_trabalho;

   node_t *current = head->next;

   // Percorrer a lista até encontrar 

   while (current->num_aluno != num_aluno)
   {
   /* if(current->next == NULL)
         printf("registo não encontrado");
         break; */

      current = current->next;
   }

   getchar();
   printf("Indique o Nome do Aluno: ");
   scanf("%c",  &nome_aluno);
   while (1)
   {
   printf("Indique a nota da frequencia: ");
   scanf("%f",  &nota_frequencia);
   if( nota_frequencia<0 || nota_frequencia> 20)
      printf("valor invalido");
   else 
      break;
   }
   getchar();
   while(1)
   {
   printf("Indique a nota do trabalho: ");
   scanf("%f",  &nota_trabalho);
   if( nota_trabalho<0 || nota_trabalho> 20)
      printf("valor invalido");
   else 
      break;
   }

   current->num_aluno = num_aluno;
   current->nome_aluno = nome_aluno;
   current->nota_frequencia = nota_frequencia;
   current->nota_trabalho = nota_trabalho;

}

// FUNÇÃO PERGUNTAR
int perguntar ()
{
   int num_selecionado;

   printf("Indique o numero do aluno: ");
   scanf("%d", &num_selecionado);

   return(num_selecionado);
}

// FUNÇÃO AVANÇAR
void avancar ()
{
   printf("\n prima <enter> para continuar");
   getchar();
}

// FUNÇÃO INDICAR DADOS

/*int indicar_dados()
{
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
            avancar();
            break;
         }
}*/