#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	
	//Exercicio 1
	
	/*
	char string[100];
	char *p_s = string; 
	
	printf("Digite uma frase: ");
	gets(string);
	
	int comp = strlen(string);
	
	for (p_s = string + comp - 1; p_s >= string; p_s--) {
	printf("%c", *p_s);
	}
	*/
	
	//Exercicio 2
	
	/*
	char string[100];
	char auxiliar[100];
	char *p_s;
	char *p_a; 
	
	printf("Digite uma frase: ");
	gets(string);
	
	int comp = strlen(string);
	
	p_a = auxiliar;
	
	for (p_s = string + comp - 1; p_s >= string; p_s--) {
		*p_a = *p_s;
		p_a++;
	}
		
	printf("Frase invertida: %s", auxiliar);
	*/
	
	//Exercicio 3
	
	/*
	char string[100];
	char auxiliar[100];
	char *p_fim; 
    char *p_inicio;
	char *p_a;
	char letra_atual;
	
	printf("Digite uma frase: ");
	gets(string);
	
	int comp = strlen(string);
	
	p_a = auxiliar;
	p_inicio = string;
	
	for (p_fim = string + comp - 1; p_fim >= string; p_fim--) {
		char letra_atual = *p_fim;
		
	if (isupper(*p_inicio)) {
            *p_a = toupper(letra_atual);	
        }
        
    else if (islower(*p_inicio)) {
            *p_a = tolower(letra_atual); 
        } 
    
    else {
            *p_a = letra_atual;
        } 
    
    p_a++;
    p_inicio++;
	}
    
	printf("Frase invertida: %s", auxiliar);
	*/
	
	//Exercicio 5
	
	/*
	char string[100];
    char letra_procurada;
    char *ptr;
    int encontrado = 0;
	
	printf("Digite uma frase: ");
	gets(string);
	
	printf("Digite a letra que quer buscar: ");
	scanf("%c", &letra_procurada);
	
	ptr = string;
	
	while (*ptr != '\0')  {
		if (*ptr == letra_procurada) {
			encontrado = 1;
			break;
		}
		ptr++;
	}
	
	if (encontrado == 1) {
        printf("Resultado : O caracter %c foi encontrado.\n", letra_procurada);
    } else {
        printf("Resultado : O caracter %c nao foi encontrado.\n", letra_procurada);
    }
    */
    
    //Exercicio 6
    
    /*
    char string[100];
    char letra_procurada;
    char *ptr;
    int encontrado = 0;
    int count = 0;
	
	printf("Digite uma frase: ");
	gets(string);
	
	printf("Digite a letra que quer buscar: ");
	scanf("%c", &letra_procurada);
	
	ptr = string;
	
	while (*ptr != '\0')  {
		if (*ptr == letra_procurada) {
			encontrado = 1;
			count++;
		}
		ptr++;
	}
	
	if (encontrado == 1) {
        printf("Resultado : O caracter %c foi encontrado %i vezes.\n", letra_procurada, count);
    } else {
        printf("Resultado : O caracter %c nao foi encontrado.\n", letra_procurada);
    }
    */
    
    //Exercicio 7
    
    char string[100];
    char letra_procurada;
    char *ptr;
    int encontrado = 0;
    int count = 0;
	
	printf("Digite uma frase: ");
	gets(string);
	
	printf("Digite a letra que quer buscar: ");
	scanf("%c", &letra_procurada);
	
	ptr = string;
	
	while (*ptr != '\0')  {
		if (*ptr == letra_procurada) {
			encontrado = 1;
			count++;
			
			int posicao = ptr - string;
            printf("Encontrado na posicao: %i\n", posicao);
		}
		ptr++;
	}
	
	if (encontrado == 1) {
        printf("Resultado : O caracter %c foi encontrado %i vezes.\n", letra_procurada, count);
    } else {
        printf("Resultado : O caracter %c nao foi encontrado.\n", letra_procurada);
    }
    
    
	return 0;
	}