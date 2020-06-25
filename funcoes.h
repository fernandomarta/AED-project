#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>





typedef struct node {
  int num_aluno;
  char nome_aluno[30];
  float nota_frequencia;
  float nota_trabalho;
 
  struct node *next;
  struct node *current;
  struct node *head;
}node_t;

struct node *head = 0;
//struct node *last = NULL;
struct node *current = 0;

int num_selecionado;


/*bool isEmpty () {
    return head == NULL;
    printf("lista vazia");
    getchar();
}*/

// FUNÇÃO MENU ===========================================================================================
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


//FUNÇÃO ESPERA  =========================================================================================
void espera ()
{
   printf("Prima a tecla <ENTER> para avancar ");
   getchar();
}


// FUNÇÃO PERGUNTAR  ======================================================================================
int perguntar ()
{
   int num_selecionado;

   printf("Indique o numero do aluno: ");
   scanf("%d", &num_selecionado);

   return(num_selecionado);
}



// FUNÇAO REGISTAR (1) ====================================================================================

 //void registar (node_t *head , int num_aluno, char nome_aluno[], float nota_frequencia, float nota_trabalho ) 

void registar (int num_aluno, char nome_aluno[], float nota_frequencia, float nota_trabalho ) 
{

   //int num_aluno = 0;
   //float media_aluno = 0;
   //registar o primeiro no
      
   /* Posicionar no nó inicial */

   //Registo em caso de não existir nós =================================================
      //isEmpty();

      //node_t *current = head;
      printf ("antes de verificar o head");
      espera();
   
   if (head == NULL)
   {
          printf("head NULL"); getchar();
        // struct node * current = head ;
         
         current = (node_t *) malloc(sizeof (node_t));
          
         current->num_aluno = num_aluno;
         strcpy(current->nome_aluno, nome_aluno);
         //current->nome_aluno = nome_aluno;
         current->nota_frequencia = nota_frequencia;
         current->nota_trabalho = nota_trabalho;

         current->next = NULL;
         head = current;    
   }
   else 
   {

      
   //Registo em caso de um só nó  ========================================================
      
      if (head->next == NULL)
      {
         printf("1 nó existente "); getchar();
         current = head;
            
            if ( current->num_aluno > num_aluno) //gravar o novo em primeiro
            {
               node_t * new_node;
               new_node = (node_t *) malloc(sizeof(node_t));

               new_node->num_aluno = num_aluno;
               // strlen (const char*)
               strcpy(new_node->nome_aluno , nome_aluno);
               //current->nome_aluno = nome_aluno;
               new_node->nota_frequencia = nota_frequencia;
               new_node->nota_trabalho = nota_trabalho;

               new_node->next = head;
               head = new_node;
            }  
               else if (current->num_aluno < num_aluno) // gravar o novo depois
                     {  
                     current->next = (node_t *) malloc (sizeof (node_t));
                     
                     current->next->num_aluno = num_aluno;
                     strcpy(current->next->nome_aluno , nome_aluno);
                     //current->nome_aluno = nome_aluno;
                     current->next->nota_frequencia = nota_frequencia;
                     current->next->nota_trabalho = nota_trabalho;

                     current->next->next = NULL;
                     }
                     else
                        {
                           printf("Numero já existente");
                           getchar();
                        }    


      }  
      else  
      {                 

   //Registo em caso de multiplos nós ====================================================
         printf("antes de encontrar posicao correta");

         int registo_ultimo = 0;
         current = head;
      // Criar novo nó 
         node_t * new_node;
         new_node = (node_t *) malloc(sizeof(node_t));

      // Encontrar a posição correta de inserção
         while (current->num_aluno < num_aluno)
         {
            if (current->next == NULL)  // adicionar no fim
             {  new_node->num_aluno = num_aluno;
               // strlen (const char*)
               strcpy(new_node->nome_aluno , nome_aluno);
               //current->nome_aluno = nome_aluno;
               new_node->nota_frequencia = nota_frequencia;
               new_node->nota_trabalho = nota_trabalho;

               new_node->next = NULL;
               current->next = new_node;
               registo_ultimo = 1;
               break;
             }

            current = current->next;
         }

         if (registo_ultimo = 0)
         {
            new_node->num_aluno = num_aluno;
            // strlen (const char*)
            strcpy(new_node->nome_aluno , nome_aluno);
            //current->nome_aluno = nome_aluno;
            new_node->nota_frequencia = nota_frequencia;
            new_node->nota_trabalho = nota_trabalho;

            new_node->next = current->next;
            current->next = new_node;
         }
      }
   }   
}

// FUNÇÃO EDITAR (2) =========================================================================================

//void editar (node_t * head , int num_aluno)
void editar (int num_aluno)
{
   int num_a;
   char nome_a;
   float nota_f;
   float nota_t;

   //node_t *current = head->next;
   current = head;

   // Percorrer a lista até encontrar 

   while (current->num_aluno != num_aluno)
   {
   /* if(current->next == NULL)
         printf("registo não encontrado");
         break; */

      current = current->next;
   }

   getchar();
   printf("Indique o Numero do Aluno: ");
   scanf("%d",  num_a);

   printf("Indique o Nome do Aluno: ");
   scanf("%s",  nome_a);

   while (1)
   {
   printf("Indique a nota da frequencia: ");
   scanf("%f",  &nota_f);
   if( nota_f < 0 || nota_f > 20)
      printf("valor invalido");
   else 
      break;
   }
   getchar();

   while(1)
   {
   printf("Indique a nota do trabalho: ");
   scanf("%f",  &nota_f);
   if( nota_t<0 || nota_t> 20)
      printf("valor invalido");
   else 
      break;
   }

   current->num_aluno = num_a;
   strcpy(current->nome_aluno , nome_a);
   //current->nome_aluno = nome_a;
   current->nota_frequencia = nota_f;
   current->nota_trabalho = nota_t;

}



// FUNÇÃO ELIMINAR (3) =======================================================================================

void eliminar (node_t *head , int num_aluno )
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


// FUNÇÃO PESQUISAR (4) ======================================================================================

void pesquisar (node_t *head , int num_aluno )
{
   node_t *current = head;

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
   printf("%s \t", current->nome_aluno);
   printf("%.1f \t\t", current->nota_frequencia);
   printf("%.1f \t\t", current->nota_trabalho);
   printf("%.1f \n", (current->nota_frequencia + current->nota_trabalho)/2);
   current = current->next;
}

// FUNÇÃO LISTAR (5) ========================================================================================

void listar (node_t * head)
{
node_t * current = head;

printf ( "Num \t NOME \t\t Frequencia \t Trabalho \t Media \n");

while (current != NULL)
{
printf("%d \t", current->num_aluno);
printf("%s \t", current->nome_aluno);
printf("%.1f \t\t", current->nota_frequencia);
printf("%.1f \t\t", current->nota_trabalho);
printf("%.1f \n", (current->nota_frequencia + current->nota_trabalho)/2);
current = current->next;
}
}




// FUNÇÃO INDICAR DADOS  ===================================================================================

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