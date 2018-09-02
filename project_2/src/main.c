/* Projeto 2

   Nome:	Leonardo de Oliveira Lourenço
   Data:	19/09/2009

   Computação Básica, Turma C, 2/2009

 ___________________________________
|                                   |
|	Descrição do projeto:       |
|___________________________________|

	Escreva um programa em C que receba os requisitos do usuário como entrada e gere uma impressão na tela indicando os requisitos do usuário e as quantidades de cada tipo de selo que serão 
	fornecidas, a quantidade total de selos e uma mensagem de agradecimento pelo uso do sistema. O seu programa deve ser estruturado em 4 funções:
		
		1: mensagens de ajuste de tela, cabeçalho e entrada de dados;
		2: cálculo das quantidades de selos (saída 1);
		3: cálculo das quantidades de selos (saída 2); 
		4: impressão de resultados). 

	O usuário da máquina deverá indicar a cada pedido de impressão de selos qual o valor total monetário que dispõe e o número de tipos de selos que deseja (de 3 a 9).
	(Se R$354,00 entrar com 354.00, se US$34.76 entrar com 34.76, sempre com duas casas decimais)

        Há várias quantidades de selos que poderão satisfazer o pedido do usuário,  a máquina deverá emitir sempre duas (2) respostas possíveis, identificando­as:
		
		1) aquela que contém a menor quantidade possível com pelo menos um (1) selo de cada valor do conjunto escolhido;
		2) aquela que contém a menor quantidade total de selos impressos, mesmo excluindo algum tipo dentre os escolhidos. 

	*** Sempre igualando-­se ao valor monetário exato do usuário.  ***

---###---###---###---###---###---###---###---###---###---###---
			VALOR DOS SELOS
---###---###---###---###---###---###---###---###---###---###---


       Para número de selos igual a 3 (nSelos = 3)
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5

       Para número de selos igual a 4 (nSelos = 4)
		valSelo1 = 1	valSelo2 = 2 	valSelo3 = 5	valSelo4 = 10

       Para número de selos igual a 5 (nSelos = 5)
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5	valSelo4 = 10	valSelo5 = 25

       Para número de selos igual a 6 (nSelos = 6)
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5	valSelo4 = 10	valSelo5 = 25
		valSelo6 = 50

       Para número de selos igual a 7 (nSelos = 7)
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5	valSelo4 = 10	valSelo5 = 25
		valSelo6 = 50	valSelo7 = 100
       
	Para número de selos igual a 8 (nSelos = 8)
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5	valSelo4 = 10	valSelo5 = 25
		valSelo6 = 50	valSelo7 = 100	valSelo8 = 200

       Para número de selos igual a 9 (nSelos = 9) 
		valSelo1 = 1	valSelo2 = 2	valSelo3 = 5	valSelo4 = 10	valSelo5 = 25
		valSelo6 = 50	valSelo7 = 100	valSelo8 = 200	valSelo9 = 500


	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	|																|
	|		RECOMENDA-SE UTILIZAR O PROGRAMA EM UM TERMINAL ABERTO EM TELA CHEIA DADO O TAMANHO DE ALGUMAS SAIDAS		|
	|																|
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

/*Funcao que imprime os resultados
	s500,s200,... 	= quantidade de selos de cada tipo.
*/
float imprime(int s500,int s200,int s100,int s50,int s25,int s10,int s5,int s2,int s1){
	float soma=0;
	if(s500>0){
		soma+=(s500*5);
		printf("%d \tselos de 500.\t%.2f\n",s500,soma);
	}
	if(s200>0){
		soma+=(s200*2.0);
		printf("%d \tselos de 200.\t%.2f\n",s200,soma);
	}
	if(s100>0){
		soma+=(s100);
		printf("%d \tselos de 100.\t%.2f\n",s100,soma);
	}
	if(s50>0){
		soma+=(s50*0.5);
		printf("%d \tselos de 50.\t%.2f\n",s50,soma);
	}
	if(s25>0){
		soma+=(s25*0.25);
		printf("%d \tselos de 25.\t%.2f\n",s25,soma);
	}
	if(s10>0){
		soma+=(s10*0.1);
		printf("%d \tselos de 10.\t%.2f\n",s10,soma);
	}
	if(s5>0){
		soma+=(s5*0.05);
		printf("%d \tselos de 5.\t%.2f\n",s5,soma);
	}
	if(s2>0){
		soma+=(s2*0.02);
		printf("%d \tselos de 2.\t%.2f\n",s2,soma);
	}
	if(s1>0){
		soma+=(s1*0.01);
		printf("%d \tselos de 1.\t%.2f\n",s1,soma);
	}
	printf("Total:\t\t%.2f\n\n",soma);


}

//Funcao que calcula a menor quantidade possível com pelo menos um (1) selo de cada valor do conjunto escolhido;
void selos1(float valor,int n){
	int valor1;							//Variavel que armazenara o valor em numero inteiro de centavos
	int s1=0,s2=0,s5=0,s10=0,s25=0,s50=0,s100=0,s200=0,s500=0;	//Variaveis que armazenarao a quantidade de selos de cada tipo onde o numero que acompanha o "s" é o tipo do selo
	//Converte o valor em centavos
	valor*=100;
	valor1=(int) valor;
	//Estrutura que atribui pelo menos 1 a cada tipo de selo (quando é possível)
	switch(n){
		case 9:
			if(valor1>=500){
				s500=1;
				valor1-=500;
			}
			if(valor1>=200){
				s200=1;
				valor1-=200;
			}
			if(valor1>=100){
				s100=1;
				valor1-=100;
			}
			if(valor1>=50){
				s50=1;
				valor1-=50;
			}
			if(valor1>=25){
				s25=1;
				valor1-=25;
			}
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		case 8:
			if(valor1>=200){
				s200=1;
				valor1-=200;
			}
			if(valor1>=100){
				s100=1;
				valor1-=100;
			}
			if(valor1>=50){
				s50=1;
				valor1-=50;
			}
			if(valor1>=25){
				s25=1;
				valor1-=25;
			}
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		case 7:
			if(valor1>=100){
				s100=1;
				valor1-=100;
			}
			if(valor1>=50){
				s50=1;
				valor1-=50;
			}
			if(valor1>=25){
				s25=1;
				valor1-=25;
			}
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		case 6:
			if(valor1>=50){
				s50=1;
				valor1-=50;
			}
			if(valor1>=25){
				s25=1;
				valor1-=25;
			}
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		case 5:
			if(valor1>=25){
				s25=1;
				valor1-=25;
			}
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		case 4:
			if(valor1>=10){
				s10=1;
				valor1-=10;
			}
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}
			break;
		default:
			printf("teste");
			if(valor1>=5){
				s5=1;
				valor1-=5;
			}
			if(valor1>=2){
				s2=1;
				valor1-=2;
			}
			if(valor1>=1){
				s1=1;
				valor1-=1;
			}

	}
	
	switch(n){
		case 9:
			if(valor1>=500){
				s500+=valor1/500;
				valor1=valor1%500;
			}
			if(valor1>=200){
				s200+=valor1/200;
				valor1=valor1%200;
			}
			if(valor1>=100){
				s100+=valor1/100;
				valor1=valor1%100;
			}
			if(valor1>=50){
				s50+=valor1/50;
				valor1=valor1%50;
			}
			if(valor1>=25){
				s25+=valor1/25;
				valor1=valor1%25;
			}
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		case 8:
			if(valor1>=200){
				s200+=valor1/200;
				valor1=valor1%200;
			}
			if(valor1>=100){
				s100+=valor1/100;
				valor1=valor1%100;
			}
			if(valor1>=50){
				s50+=valor1/50;
				valor1=valor1%50;
			}
			if(valor1>=25){
				s25+=valor1/25;
				valor1=valor1%25;
			}
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		case 7:
			if(valor1>=100){
				s100+=valor1/100;
				valor1=valor1%100;
			}
			if(valor1>=50){
				s50+=valor1/50;
				valor1=valor1%50;
			}
			if(valor1>=25){
				s25+=valor1/25;
				valor1=valor1%25;
			}
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		case 6:
			if(valor1>=50){
				s50+=valor1/50;
				valor1=valor1%50;
			}
			if(valor1>=25){
				s25+=valor1/25;
				valor1=valor1%25;
			}
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		case 5:
			if(valor1>=25){
				s25+=valor1/25;
				valor1=valor1%25;
			}
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		case 4:
			if(valor1>=10){
				s10+=valor1/10;
				valor1=valor1%10;
			}
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}
			break;
		default:
			if(valor1>=5){
				s5+=valor1/5;
				valor1=valor1%5;
			}
			if(valor1>=2){
				s2+=valor1/2;
				valor1=valor1%2;
			}
			if(valor1==1){
				s1++;
			}

	}
	imprime(s500,s200,s100,s50,s25,s10,s5,s2,s1);

}

//Funcao que calcula a menor quantidade total de selos impressos, mesmo excluindo algum tipo dentre os escolhidos.
void selos2(float valor,int n){
	int valor2;
	int s1=0,s2=0,s5=0,s10=0,s25=0,s50=0,s100=0,s200=0,s500=0;
	valor*=100;
	valor2=(int) valor;

	switch(n){
		case 9:
			if(valor2>=500){
				s500=valor2/500;
				valor2=valor2%500;
			}
			if(valor2>=200){
				s200=valor2/200;
				valor2=valor2%200;
			}
			if(valor2>=100){
				s100=valor2/100;
				valor2=valor2%100;
			}
			if(valor2>=50){
				s50=valor2/50;
				valor2=valor2%50;
			}
			if(valor2>=25){
				s25=valor2/25;
				valor2=valor2%25;
			}
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		case 8:
			if(valor2>=200){
				s200=valor2/200;
				valor2=valor2%200;
			}
			if(valor2>=100){
				s100=valor2/100;
				valor2=valor2%100;
			}
			if(valor2>=50){
				s50=valor2/50;
				valor2=valor2%50;
			}
			if(valor2>=25){
				s25=valor2/25;
				valor2=valor2%25;
			}
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		case 7:
			if(valor2>=100){
				s100=valor2/100;
				valor2=valor2%100;
			}
			if(valor2>=50){
				s50=valor2/50;
				valor2=valor2%50;
			}
			if(valor2>=25){
				s25=valor2/25;
				valor2=valor2%25;
			}
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		case 6:
			if(valor2>=50){
				s50=valor2/50;
				valor2=valor2%50;
			}
			if(valor2>=25){
				s25=valor2/25;
				valor2=valor2%25;
			}
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		case 5:
			if(valor2>=25){
				s25=valor2/25;
				valor2=valor2%25;
			}
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		case 4:
			if(valor2>=10){
				s10=valor2/10;
				valor2=valor2%10;
			}
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}
			break;
		default:
			if(valor2>=5){
				s5=valor2/5;
				valor2=valor2%5;
			}
			if(valor2>=2){
				s2=valor2/2;
				valor2=valor2%2;
			}
			if(valor2==1){
				s1++;
			}

	}
	
	imprime(s500,s200,s100,s50,s25,s10,s5,s2,s1);

}



int main(void){

	float valor;				//Variavel que armazena o valor possuido pelo usuario
	int n;					//Variavel que armazena quantidade de selos desejada
	int val=0;				//Variavel de controle

	system("clear");			//Limpa a tela
	do{
	printf("Informe o valor a ser dividido em selos:\n(Ex:  130.45  - Cento e quarenta e cinco reais e quarenta e cinco centavos)\n");
	scanf("%f",&valor);
		//Checa validade da entrada
		if(valor<=0){			
			printf("Valor invalido! Favor informar um valor positivo!\n\n");
		}
		else{
			val=1;
		}
	}while(val==0);
	do{
	printf("\nQuantos tipos de selo deseja?\n Tipos:    1 - 2 - 5 - 10 - 25 - 50 - 100 - 200 - 500\n");
	printf("\nA escolha deve ser entre 3 e 9 tipos!\nA escolha eh cumulativa, ou seja:\n\t3 = 1 - 2 - 5\n\t4=1 - 2 - 5 - 10\nE assim por diante...\n");
	scanf("%d",&n);
		//Checa validade da entrada
		if(n<3 || n>9){
			val=0;
			system("clear");
			printf("Valor invalido! A quantidade desejada deve ser entre 3 e 9!\n");
		}
		else{
			val=1;
		}
	}while(val==0);
	
	//Limpa a tela, informa a validade das entrada e sobre o processamento das mesmas e sobre as diferentes saidas do programa
	system("clear");
	printf("Valores aceitos!\n");
	printf("Valor = %.2f\nQuantidade de selos diferentes = %d\n",valor,n);
	printf("Este programa ira fornecer duas saidas distintas, a saber:\n\n");
	printf("\t1) aquela que contém a menor quantidade possível com pelo menos um (1) selo de cada valor do conjunto escolhido;\n");
	printf("\t2) aquela que contém a menor quantidade total de selos impressos, mesmo excluindo algum tipo dentre os escolhidos.\n\n");
	printf("Processando dados...\n\n");
	printf("Saida 1:\n\n");
	selos1(valor,n);
	printf("Saida 2:\n\n");
	selos2(valor,n);
	printf("\n\nFim.\n");

	

return 0;
}


