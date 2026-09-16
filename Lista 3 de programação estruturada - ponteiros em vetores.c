#include <stdio.h>
#include <stdlib.h>

//Exercicio 1

/*void inc (int *x);

int main () {
	
	int a = 10;
	inc(&a);
	printf("a = %d", a);
	return 0;
}

void inc (int *x) {
	(*x)++;
}*/

//Exercicio 4

/*void troca_ref (int *x, int *y);

int main () {
	int a = 10, b = 7;
	troca_ref(&a,&b);
	printf("a = %d, b = %d", a, b);
	return 0;
}

void troca_ref (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
*/

//Exercicio 5

/*void inc_ref(int *p);

int main () {
	int	p = 10;
	inc_ref(&p);
	printf("P = %d",p);
	return 0;
}

void inc_ref(int *p) {
	(*p)++;
}*/

//Exercicio 6

/*
int troca_se_maior(int *a, int *b);

int main () {
	int a = 10, b = 7;
	troca_se_maior(&a,&b);
	printf("a = %d, b = %d", a,b);
	return 0;
}

int troca_se_maior(int *a, int *b) {
	if (*a > *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return 1;
	}
	return 0;
}*/

//Exercicio 7

/*void normaliza_trio(float *x, float *y, float *z);

int main () {
	float num1 = 8.0, num2 = 5.0, num3 = 5.0;
	normaliza_trio(&num1,&num2,&num3);
	printf("num1 media = %2.f\nnum2 media = %.2f\nnum3 media = %.2f", num1,num2,num3);
	return 0;
}

void normaliza_trio(float *x, float *y, float *z) {
	float media = (*x + *y + *z) / 3;
	*x = *x - media;
	*y = *y - media;
	*z = *z - media;
}*/

//Exercicio 8

/*void zera(int *v, int n);

int main () {
	int v1[5] = {1,2,3,4,5};
	zera(v1,5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", v1[i]);
	}
	return 0;
}

void zera(int *v, int n) {
	for (int i = 0; i < n; i++) {
		*(v + i) = 0;
	}
}*/

//Exercicio 9

/*int soma(const int *v, int n);
float media_int(const int *v, int n);

int main () {
	int v1[5] = {1,2,3,4,5};
	soma(v1,5);
	media_int(v1,5);
	printf("Soma = %d, media = %.2f",soma(v1,5),media_int(v1,5));
}

int soma(const int *v, int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += v[i];
	}
	return total;
}

float media_int(const int *v, int n) {
	return soma(v,n) / (float)n;
}*/

//Exercicio 10

/*void escala(float *v, int n, float k);

int main () {
	float v1[5] = {1,2,3,4,5};
	int k = 2;
	escala(v1,5,k);
	for (int i = 0; i < 5; i++) {
		printf("%.f ", v1[i]);
	}
	return 0;
}

void escala(float *v, int n, float k) {
	for (int i = 0; i < n; i++) {
		v[i] *= k; 
	}
}*/

//Exercicio 11

/*void troca_extremos(int *v, int n);

int main () {
	int v1[5] = {1,2,3,4,5};
	troca_extremos(v1,5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", v1[i]);
	}
	return 0;
}

void troca_extremos(int *v, int n) {
		int temp = v[0];
		v[0] = v[n-1];
		v[n-1] = temp;
}*/

//Exercicio 12

/*int filtra_faixa(const float *origem, int n, float *destino, float L, float U);

int main () {
	float o[5] = {1,10,5,20,7};
    float dest[5];
    float L = 1, U = 5;
    int k = filtra_faixa(o,5,dest,1,5);
    for (int i = 0; i < k; i++) {
    	printf("%.f ", dest[i]);
	}
	printf("Numeros encontrados: %d", k);
	return 0;
}

int filtra_faixa(const float *origem, int n, float *destino, float L, float U) {
int k = 0;
	for (int i = 0; i < n; i++) {
		if (origem[i] >= L && origem[i] <= U) {
		destino[k] = origem[i];
		k++;
		}
	}
	return k;
}*/

//Exercicio 13

/*int indice_min(const float *v, int n);
int indice_max(const float *v, int n);

int main () {
	int min, max;
	float v1[5] = {1,2,3,4,5};
	min = indice_min(v1,5);
	max = indice_max(v1,5);
	printf("indice min=%d, indice max=%d ", min, max); 
}

int indice_min(const float *v, int n) {
		int menor = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < menor) {
			menor = i;
		}
	}
    return menor;
}

int indice_max(const float *v, int n) {
		int maior = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] > maior) {
			maior = i;
		}
	}
    return maior;
}*/

//Exercicio 14

/*void remove_primeiro(int *v, int *n, int alvo);

int main () {
	int v1[5] = {1,2,3,4,5};
	int alvo = 3;
	int n = 5;
	remove_primeiro(v1,&n,3);
	for (int i = 0; i < n; i++) {
		printf("%d ", v1[i]);
	}
	return 0;
}

void remove_primeiro(int *v, int *n, int alvo) {
	for (int i = 0; i < *n; i++) {
		if (v[i] == alvo) {
			v[i] = v[i + 1];
		for (int j = i; j < *n - 1; j++) {
    		v[j] = v[j + 1];
		}
			(*n)--;
			break;
		}
	}
}*/

//Exercicio 15

/*void inverte(int *v, int n);

int main () {
	int v1[5] = {1,2,3,4,5};
	inverte(v1,5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", v1[i]);
	}
	return 0;
}

void inverte(int *v, int n) {
	int i = 0;
	int j = n - 1;
	
	while (i < j) {
		int temp = v[i];
		v[i] = v[j];
		v[j] = v[i];
		i++;
		j--;
	}
}*/
	
	



