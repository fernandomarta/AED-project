//inserir nó no início
void inserir_inicio(int num_aluno, char nome_aluno, float nota_frequencia, float nota_trabalho) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->num_aluno = num_aluno;
   link->nome_aluno = nome_aluno;
   //*link->apelido_aluno = apelido_aluno;
   link->nota_frequencia = nota_frequencia;
   link->nota_trabalho = nota_trabalho;
	
   if(isEmpty()) {
      last = link;
   } else {
      head->ant = link;
   }

   link->seg = head;
	
   head = link;
   head->ant = NULL;
}