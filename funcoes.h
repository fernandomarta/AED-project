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
}node_t;

struct node *head = NULL;
struct node *current = NULL;

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
   if (head == NULL)   /* Registo em caso de não existir nós */
   {
      current = (node_t *) malloc(sizeof (node_t));
         
      current->num_aluno = num_aluno;
      strcpy(current->nome_aluno, nome_aluno);
      current->nota_frequencia = nota_frequencia;
      current->nota_trabalho = nota_trabalho;

      current->next = NULL;
      head = current;    
   }
   else              /*acrescentar novo registo */
   {
      node_t * new_node;
      new_node = (node_t *) malloc(sizeof(node_t));

      new_node->num_aluno = num_aluno;
      strcpy(new_node->nome_aluno, nome_aluno);
      new_node->nota_frequencia = nota_frequencia;
      new_node->nota_trabalho = nota_trabalho;
            
      new_node->next = head;  /* Apontar o next do novo nó para o início da lista */ 
      head = new_node; /* Apontar o início da lista para o novo nó */ 
   }
}
      


// FUNÇÃO EDITAR (2) =========================================================================================

//void editar (node_t * head , int num_aluno)
void editar (int num_aluno)
{
   int num_a;
   char nome_a[30];
   float nota_f;
   float nota_t;

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

// Função ordenar - BubbleSort  =================================================================== 
void bubbleSort(struct node *head) 
{ 
    int trocarped, i; 
    struct node *inicio; 
    struct node *final = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        return; 
  
    do
    { 
        trocarped = 0; 
        inicio = head; 
  
        while (inicio->next != final) 
        { 
            if (inicio->num_aluno > inicio->next->num_aluno) 
            {  
                trocar(inicio, inicio->next); 
                trocarped = 1; 
            } 
            inicio = inicio->next; 
        } 
        final = inicio; 
    } 
    while (trocarped); 
} 

// Função trocar registos  ===============================================================================
void trocar(struct node *a, struct node *b) 
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

   node_t * node_import;
   node_import = (node_t *) malloc(sizeof (node_t));

   ficheiro_alunos_input = fopen("BDalunosAED.dat","a+");  // !!  r ??
   if(!ficheiro_alunos_input)
   {  
      puts("erro ao abrir ficheiro");
      exit(1);
   } 
   rewind(ficheiro_alunos_input);

   while(!feof(ficheiro_alunos_input)) 
   {
      fread(&node_import, sizeof(node_t),1,ficheiro_alunos_input);
      
      if (head == NULL)
      {
         head = node_import;
         current = head;
         current->next = NULL;
      }
      else
      {
         //current->next = (node_t *) malloc(sizeof (node_t));
         current->next = node_import;
         node_import->next = NULL;
      }
      
      //current=current->next;
      
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

   // gravar a estrutura para i disco
   current = head;
   while (current->next != NULL)
   {
      fwrite (&current, sizeof(node_t), 1, ficheiro_alunos_output); 
      current = current->next;
   }

   fclose(ficheiro_alunos_output);

}

