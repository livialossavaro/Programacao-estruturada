/*
 * Lista 7 – Estruturas com Ponteiros e Alocação Dinâmica
 * Disciplina: Programação Estruturada
 *
 * Conteúdo trabalhado:
 *  - struct + ponteiros
 *  - malloc e realloc
 *  - ponteiro para ponteiro (**)
 *  - vetores dinâmicos de struct
 *  - busca, cálculo e remoção lógica em memória
 *
 * Profa. Dra. Tiemi Christine Sakata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

/* ============================================================
   EXERCÍCIO 1 — Definição da estrutura
   ============================================================ */

typedef struct {
    char nome[MAX];
    int idade;
    float nota;
    char status;   // 'A' = ativo | 'I' = inativo
} Aluno;

/* ============================================================
   EXERCÍCIO 2 — Alocação dinâmica inicial
   ============================================================ */

void aloca_alunos(Aluno **v, int n) {
	Aluno *aux;
	aux = (Aluno*) realloc (*v, n * sizeof(Aluno));
	if (aux == NULL)
		exit(1);
	*v = aux;
}

/* ============================================================
   EXERCÍCIO 3 — Leitura de aluno por referência
   ============================================================ */

void le_aluno_ptr(Aluno *a) {
    printf("\nNome: ");
    scanf("%s", a->nome);
    
    printf("Idade: ");
    scanf("%d", &a->idade);
    
    printf("Nota: ");
    scanf("%f", &a->nota);
    
    printf("Status: ");
    scanf(" %c", &a->status);
}

/* ============================================================
   EXERCÍCIO 4 — Inserção dinâmica de aluno
   ============================================================ */

void insere_aluno(Aluno **v, int *n) {
    aloca_alunos(v, *n) ;
	le_aluno_ptr (*v + *n);
	(*n)++;
}

/* ============================================================
   EXERCÍCIO 5 — Impressão de alunos ativos
   ============================================================ */

void imprime_alunos(Aluno *v, int n) {
	
	int i;
	
    for (i = 0; i < n; i++, v++) {

        if (v->status == 'A') {

            printf("\nNome: %s\n", v->nome);
            printf("Idade: %d\n", v->idade);
            printf("Nota: %.2f\n", v->nota);
        }
    }
}

/* ============================================================
   EXERCÍCIO 6 — Cálculo da média
   ============================================================ */

float media_alunos(Aluno *v, int n) {
	int cont = 0 , i;
	float soma = 0;
	
	for (i = 0; i < n; i++, v++) 
		if (v->status == 'A') {
			soma += v->nota;
			cont++;
		}
    return soma / cont;
}

/* ============================================================
   EXERCÍCIO 7 — Busca por nome
   ============================================================ */

Aluno* busca_aluno(Aluno *v, int n, char nome[]) {
	
	int i;
	
	for (i = 0; i < n; i++, v++) {
    if(strcmp(v->nome,nome) == 0)
    	return v;
	}
	return NULL;
	}

/* ============================================================
   EXERCÍCIO 8 — Remoção lógica
   ============================================================ */

void remove_aluno(Aluno *v, int n, char nome[]) {
    /* TODO: marcar o aluno como inativo */
}

/* ============================================================
   PROGRAMA PRINCIPAL
   ============================================================ */

int main(void) {

    Aluno *turma = NULL;   // vetor dinâmico
    int qtd = 0;           // quantidade de alunos
    int op;
    char nome[MAX];
    Aluno *a;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Media da turma\n");
        printf("4 - Buscar aluno\n");
        printf("5 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                insere_aluno(&turma, &qtd);
                break;

            case 2:
                imprime_alunos(turma, qtd);
                break;

            case 3:
                if (qtd > 0)
                    printf("Media: %.2f\n", media_alunos(turma, qtd));
                break;

            case 4:
                printf("Nome para busca: ");
                fgets(nome, MAX, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                a = busca_aluno(turma, qtd, nome);
                if (a != NULL) {
                    printf("Aluno encontrado: %s (nota %.2f)\n",
                           a->nome, a->nota);
                } else {
                    printf("Aluno nao encontrado.\n");
                }
                break;

            case 5:
                printf("Nome do aluno a remover: ");
                fgets(nome, MAX, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remove_aluno(turma, qtd, nome);
                break;
        }

    } while (op != 0);

    /* ======================================================
       Liberação da memória
       ====================================================== */

    free(turma);
    turma = NULL;

    return 0;
}
