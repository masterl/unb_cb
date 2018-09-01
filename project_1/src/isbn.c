/* Projeto 1 - ISBN

	-Receba um numero ISBN de 10, ou de 13 digitos como entrada;
	-Cheque se o numero de entrada for valido, ou nao;
	-Forneca como mensagem de saida: a confirmacao se o numero for valido, ou nao; a lingua e a localizacao geografica da publicacao daquele livro,
	mostrando em linhas centralizadas (ou justificadas) da tela as partes do codigo ISBN dado que indicam tais elementos.
	- O ISBN possui cinco (5) partes, sendo duas de tamanho fixo (1a. e 5a.) e tres de tamanho variavel.
	-Projete o programa para identificar: Brasil, Reino Unido, Franca, R�ssia, Argentina, Outros (para os restantes).

   Nome:		Leonardo de Oliveira Lourenco
   Data:		06/09/2009
   
   Computacao Basica, Turma C, 2/2009
   
*/

#include <stdio.h>

int main(void){
	//Variaveis que armazenarao os digitos do ISBN.  x = 10 para ultimo digito = X;
	int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, x=10;
	
	//Digito verificador, soma do ISBN, resto da divisao
	int verif, soma, resto;
	
	//Variavel que armazena a opcao equivalente ao numero de digitos escolhido, variavel que armazena quantidade de digitos da regiao e variavel que armazena o numero da regiao
	int opcao, regiao, numregiao;
	
	//Variavel que verifica a validade da opcao
	int val=0;
	
	//Inicio do programa e selecao de opcao
	do{
	printf("Quantos digitos tem o ISBN?\n");
	printf("1 - 10 digitos. Exemplo: 0-684-84328-5\n");
	printf("2 - 13 digitos. Exemplo: 978-0-306-40615-7\n");
	scanf("%d",&opcao);
	
	//Verifica validade da opcao
	if(opcao<=0 || opcao>2){
					system("clear");
					printf("Opcao invalida! Tente novamente!\n");
							}
	else {
		val=1;
		 }
	}while(val==0);
	
	//Coloca espaco entre as opcoes
	printf("\n\n");
	
	//Le os digitos do ISBN
	printf("Informe os digitos com espacos entre cada um. Exemplo:  1 2 3 4 5 6 ...\n");
	printf("Se o ultimo digito for X digite -1 no lugar dele!\n");
	if(opcao==1) scanf("%d %d %d %d %d %d %d %d %d %d",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10);
	
	else scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13);
	
	//Pergunta quantos digitos tem a "regiao"
	do{
		printf("Quantos digitos tem o campo regiao?\n");
		scanf("%d",&regiao);
		if(regiao<=0 || regiao>5){
			system("clear");
			printf("Opcao invalida! Tente novamente!");
							   }
		else{
			val=0;
			}
	  }while(val==1);
	
	//Calcula a soma correspondente ao tipo de ISBN e verifica a validade
	if(opcao==1){
			soma=i1+(2*i2)+(3*i3)+(4*i4)+(5*i5)+(6*i6)+(7*i7)+(8*i8)+(9*i9);
			resto=soma%11;
			if(i10==-1){
					if(resto!=x){
							printf("Numero invalido!\n");
								}
					else val=1;
					   }
				}
	else{
			soma=i1+(3*i2)+i3+(3*i4)+i5+(3*i6)+i7+(3*i8)+i9+(3*i10)+i11+(3*i12);
			resto=soma%10;
			if(resto==0 && resto==i13){
				val=1;
									  }
			else{
				resto=10-resto;
				if(resto==i13){
						val=1;
							  }
				}
			
		}
	//Verifica e informa a regiao [Brasil = 85, Reino Unido = 1, Franca = 2, R�ssia = 5, Argentina = 950, Outros (para os restantes)].
	if(val==1){
				if(regiao==1){
							 }
			  }
	
	
	return 0;
}

