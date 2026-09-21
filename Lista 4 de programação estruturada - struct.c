#include <stdio.h>

#define MAX 3

//EXERCICIO 1

/*
struct Aluno {
    char nome[MAX];
    int idade;
    float nota;
};

void imprime_aluno(struct Aluno a);

int main () {
	
	struct Aluno estudante;
	
	printf("\nDigite seu nome: ");
	scanf("%s", estudante.nome);
	
	printf("\nDigite sua idade: ");
	scanf("%d", &estudante.idade);
	
	printf("\nDigite sua nota: ");
	scanf("%f", &estudante.nota);
	
	imprime_aluno(estudante);
	
	return 0;
}

void imprime_aluno(struct Aluno a) {
	printf("\nNome: %s", a.nome);
	printf("\nIdade: %d", a.idade);
	printf("\nNota: %.1f", a.nota);	
}
*/

//EXERCICIO 2

/*struct Aluno {
    char nome[MAX];
    int idade;
    float nota;
};

void le_turma(struct Aluno turma[], int n);
	
void imprime_turma(struct Aluno turma[], int n);

int main () {
	
	struct Aluno estudante[MAX];
	
	le_turma(estudante, MAX);
	
	imprime_turma(estudante, MAX); 
	
	return 0;
}

void le_turma(struct Aluno turma[], int n) {
	int i;
	
	for(i = 0; i < TAM; i++) {
	printf("\nDigite seu nome: ");
	scanf("%s", turma[i].nome);
	
	printf("Digite sua idade: ");
	scanf("%d", &turma[i].idade);
	
	printf("Digite sua nota: ");
	scanf("%f", &turma[i].nota);
	}
}
void imprime_turma(struct Aluno turma[], int n) {
	int i;
	
	for(i = 0; i < MAX; i++) {
	printf("\n\nNome: %s", turma[i].nome);
	printf("\nIdade: %d", turma[i].idade);
	printf("\nNota: %.1f", turma[i].nota);
	}
}
*/

//EXERCICIO 3

struct Aluno {
    char nome[MAX];
    float nota;
};

float media_turma(struct Aluno turma[], int n);

int main () {
	int i;
	
	struct Aluno estudante[MAX];
	
	for(i = 0; i < MAX; i++) {
	printf("\nDigite seu nome: ");
	scanf("%s", estudante[i].nome);
		
	printf("Digite sua nota: ");
	scanf("%f", &estudante[i].nota);
	}
	
	media_turma(estudante, MAX);
	
	printf("Media: %.1f", media);
	return 0;
}

float media_turma(struct Aluno turma[], int n) {
	float soma = 0;
	int i;
	
	soma += turma[i].nota;
	media = soma / MAX;
	
    return 0.0f;
}