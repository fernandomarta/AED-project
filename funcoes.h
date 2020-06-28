#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>





typedef struct node {
  int num_aluno;
  char nome_aluno[30];
  float nota_frequencia;
  float nota_trabalho;
 
  struct node *next;
  struct node *current;
  struct node *head;
  //struct node *node;
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
   printf("\nPrima a tecla <ENTER> para avancar ");
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
       node_t * new_node;
       new_node = (node_t *) malloc(sizeof(node_t));

         new_node->num_aluno = num_aluno;
         strcpy(new_node->nome_aluno, nome_aluno);
         //current->nome_aluno = nome_aluno;
         new_node->nota_frequencia = nota_frequencia;
         new_node->nota_trabalho = nota_trabalho;
        /* Apontar o next do novo nó para o início da lista */ 
       
         new_node->next = head; /* Apontar o início da lista para o novo nó */ 
         head = new_node; 
   }
  /*    
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
      */
   }
      


// FUNÇÃO EDITAR (2) =========================================================================================

//void editar (node_t * head , int num_aluno)
void editar (int num_aluno)
{
   int num_a;
   char nome_a[30];
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
   scanf("%d", &num_a);

   getchar();
   printf("Indique o Nome do Aluno: ");
   fgets (nome_a, 30, stdin);
   nome_a[strlen(nome_a) - 1] = '\0';

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
   scanf("%f",  &nota_t);
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

node_t* eliminar (node_t *current , int num_aluno )
{
   node_t* next;

   if (current == NULL) { // Encontra a cauda
        printf("Nao encontrado\n");
        return NULL;
    } else if (current->num_aluno == num_aluno) { // Encontrou o valor a remover
        next = current->next;
        free(current);
        return next;
    } else { // Continuar
        current->next = eliminar(current->next, num_aluno);
        return current;
    }
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

printf ( "Num \tNOME \t\t\t\t  Frequencia \t Trabalho \tMedia \n");

while (current != NULL)
{
printf("%d \t", current->num_aluno);
printf("%-33s ", current->nome_aluno);
printf("%-14.1f ", current->nota_frequencia);
printf("%-14.1f ", current->nota_trabalho);
printf("%.1f \n", (current->nota_frequencia + current->nota_trabalho)/2);
current = current->next;
}
}

/* Bubble sort the given linked list */
void bubbleSort(struct node *head) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->num_aluno > ptr1->next->num_aluno) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b) 
{ 
    int temp_num = a->num_aluno; 
    a->num_aluno = b->num_aluno; 
    b->num_aluno = temp_num; 

   char temp_nome[30];
    strcpy(temp_nome, a->nome_aluno);
    strcpy(a->nome_aluno, b->nome_aluno);
    strcpy(b->nome_aluno, temp_nome);

    float temp_f = a->nota_frequencia; 
    a->nota_frequencia = b->nota_frequencia; 
    b->nota_frequencia = temp_f;

    float temp_t = a->nota_trabalho; 
    a->nota_trabalho = b->nota_trabalho; 
    b->nota_trabalho = temp_t;

    

}  


// Função importar dados do ficheiro de disco =============================================================

void importar()
{
   FILE * ficheiro_alunos_input;

   ficheiro_alunos_input = fopen("BDalunosAED.dat","rb");  // !! deveria ser o "r"  !! <<<<<<<=====
   
   if(!ficheiro_alunos_input)
   {  
      puts("erro ao abrir ficheiro");
      exit(1);
   } 
   rewind(ficheiro_alunos_input);

   while(!feof(ficheiro_alunos_input)) 
   {
      current = (node_t *) malloc(sizeof (node_t));
      fread(&current, sizeof(node_t),1,ficheiro_alunos_input);
      
      if (head == NULL)
      {
         head = current;
         current->next = NULL;
      }
      else
      {
          
         current->next = current;
         current->next->next = NULL;
      }
      
      current=current->next;  // ???
      
   }

   fclose(ficheiro_alunos_input);
}



// Função exportar dados para o ficheiro de disco =========================================================

void exportar()
{
   FILE *ficheiro_alunos_output;

   // abrir o ficheiro para escrita 

   ficheiro_alunos_output = fopen ("BDalunosAED.dat", "wb"); 

   if (ficheiro_alunos_output == NULL) 
   { 
      puts("erro ao abrir ficheiro");
      exit (1); 
   } 

   // gravar a estrutura
   current = head;
   while (current->next != NULL)
   {
      fwrite (&current, sizeof(node_t), 1, ficheiro_alunos_output); 
      current = current->next;
   }

   fclose(ficheiro_alunos_output);

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