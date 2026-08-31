#include <stdio.h>
#include <stdlib.h>

void calcularEstatisticas(int *vetor, int tamanho, int *maior, int *menor, float *media);

int main () {
	int *vetor, tamanho, maior, menor;
	float media;
	
	printf("Digite a quantd de sensores: ");
	scanf("%d", &tamanho);
	
	vetor = (int *) malloc (tamanho * sizeof(int));
	
	if (vetor == NULL) {
		printf("Memoria nao alocada, erro!");
		return 1;
	}
	
	for (int i = 0; i < tamanho; i++ ) {
		printf("Leitura %d: ", i+1);
		scanf("%d", &*(vetor + i));
	}
	
	calcularEstatisticas(vetor, tamanho, &maior, &menor, &media);
	
	printf("\nMaior temperatura: %d\n", maior);
	printf("Menor temperatura: %d\n", menor);
	printf("Media: %.2f", media);
	
	free(vetor);
	
	return 0;
}

void calcularEstatisticas(int *vetor, int tamanho, int *maior, int *menor, float *media) {
	
	*maior = vetor[0];
	*menor = vetor[0];
	int soma = 0;
	
	for (int i = 0; i < tamanho; i++) {
		if (*(vetor + i) > *maior) {
			*maior = *(vetor + i);
		}
	}

	for (int i = 0; i < tamanho; i++) {
			if (*(vetor + i) < *menor) {
				*menor = *(vetor + i);
			}
		}
		
	for (int i = 0; i < tamanho; i++) {
			soma += *(vetor + i);
			*media = soma / tamanho;
		}
		
	}