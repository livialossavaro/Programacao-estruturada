/*
 * Lista 6 – Estruturas com Ponteiros (SEM malloc)
 * Disciplina: Programação Estruturada
 *
 * Conteudo trabalhado:
 *  - Ponteiros para struct
 *  - Operador ->
 *  - Passagem de struct por referência
 *  - Vetores de struct acessados por ponteiros
 *  - Structs aninhadas com ponteiros
 *
 * RESTRIÇOES:
 *  - NÃO usar malloc, calloc ou realloc
 *  - NÃO retornar ponteiros alocados dinamicamente
 *  - Usar apenas vetores estáticos
 *
 * Profa. Dra. Tiemi Christine Sakata
 */

#include <stdio.h>
#include <string.h>

#define MAX 50
#define TAM 3

/* ============================================================
   EXERCÍCIO 1 — Impressao usando ponteiro para struct
   ============================================================ */

typedef struct {
    char nome[MAX];
    int idade;
    float nota;
} Aluno;

void imprime_aluno_ptr(Aluno *a) {
	printf("\n\nNome: %s", a->nome);
	printf("\nIdade: %i", a->idade);
	printf("\nNota: %.2f", a->nota);
}

/* ============================================================
   EXERCÍCIO 2 — Leitura por referencia
   ============================================================ */

void le_aluno_ptr(Aluno *a) {
	printf("\nNome: ");
	scanf("%s", a->nome);
	
	printf("\nIdade: ");
	scanf("%d", &a->idade);
	
	printf("\nNota: ");
	scanf("%f", &a->nota);
}

/* ============================================================
   EXERCÍCIO 3 — Vetor de struct acessado por ponteiro
   ============================================================ */

void le_turma_ptr(Aluno *v, int n) {
	
	int i;
	
	for (i = 0; i < n; i++) {
		printf("\n--- Aluno %d ---\n", i + 1);
		le_aluno_ptr(v++);
	}
}

void imprime_turma_ptr(Aluno *v, int n) {
	
	int i;
	
	for (i = 0; i < n; i++) {
		imprime_aluno_ptr(v++);
	}
}

/* ============================================================
   EXERCÍCIO 4 — Calculo usando ponteiros
   ============================================================ */

float media_turma_ptr(Aluno *v, int n) {
	
	float soma = 0, media;
	int i;
	
	for (i = 0; i < n; i++) {
	soma += v->nota;
	v++;
	}
	media = soma/n;
	
	return media;
}

/* ============================================================
   EXERCÍCIO 5 — Contagem condicional usando ponteiros
   ============================================================ */

int conta_aprovados_ptr(Aluno *v, int n) {
	
	int i;
	int aprovados = 0;
	
	for (i = 0; i < n; i++, v++) {
	
		if(v->nota >= 6) {
			aprovados++;
		} 
	}
    return aprovados;
}

/* ============================================================
   EXERCÍCIO 6 — Busca usando ponteiros
   ============================================================ */

Aluno* busca_aluno_ptr(Aluno *v, int n, char nome[]) {
	
	int i;
	
	for (i = 0; i < n; i++) {
		if(strcmp(v->nome, nome)== 0) {
			return v;
		}
		v++;
	}
    return NULL;
}

/* ============================================================
   EXERCÍCIO 7 — Struct aninhada com ponteiro
   ============================================================ */

typedef struct {
    char rua[MAX];
    int numero;
} Endereco;

typedef struct {
    char nome[MAX];
    Endereco end;
} Pessoa;

void imprime_pessoa_ptr(Pessoa *p) {
    /* TODO: imprimir nome e endereço usando ponteiros */
}

void le_pessoa_ptr(Pessoa *p) {
    /* TODO: ler os dados da pessoa usando ponteiros */
}

/* ============================================================
   EXERCÍCIO 8 — Vetor de struct aninhada com ponteiro
   ============================================================ */

void le_pessoas_ptr(Pessoa *v, int n) {
    /* TODO: ler pessoas usando ponteiros */
}

void imprime_pessoas_ptr(Pessoa *v, int n) {
    /* TODO: imprimir pessoas usando ponteiros */
}

/* ============================================================
   PROGRAMA PRINCIPAL
   ============================================================ */

int main(void) {

    Aluno turma[TAM];
    Pessoa pessoas[2];
    Aluno *a;
    
    printf("\n--- LEITURA DA TURMA ---\n");
    le_turma_ptr(turma, TAM);

    printf("\n--- DADOS DA TURMA ---\n");
    imprime_turma_ptr(turma, TAM);

    printf("\n\nMedia da turma: %.2f\n", media_turma_ptr(turma, TAM));
    printf("Aprovados: %d\n", conta_aprovados_ptr(turma, TAM));

    printf("\nBuscar aluno por nome: ");
    char nome_busca[MAX];
    fflush(stdin);
    fgets(nome_busca, MAX, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    a = busca_aluno_ptr(turma, TAM, nome_busca);
    if (a != NULL) {
        imprime_aluno_ptr(a);
    } else {
        printf("Aluno nao encontrado.\n");
    }

    printf("\n\n--- DADOS DE PESSOAS ---\n");
    le_pessoas_ptr(pessoas, 2);
    imprime_pessoas_ptr(pessoas, 2);

    return 0;
}
