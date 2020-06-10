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


//FUNÇÃO ESPERA

void espera ()
{
   printf("Prima a tecla <ENTER> para avançar");
   getchar();
}

// FUNÇAO REGISTAR

 void registar (node_t * head , char nome_aluno, float nota_frequencia, float nota_trabalho ) 
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

void listar (node_t * head )
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

void eliminar (node_t * head , int num_aluno )
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