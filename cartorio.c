#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string 

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
		//In�cio cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrato: "); //Coletando informa��es do usu�rio
		scanf("%s", cpf); //%refere-se a string
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
		
		FILE *file; //Cria o arquivo 
		file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever
		fprintf(file,cpf); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //Salvo o valor da variavel
		
		printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s", nome); //%refere-se a string
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file,nome); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s", sobrenome); //%refere-se a string
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file,sobrenome); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s", cargo); //%refere-se a string
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file,cargo); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, "."); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		system("pause");
		
}

int consulta()
{
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
		
		//In�cio cria��o de vari�veis/string
		char cpf[40];
		char conteudo[200];
		//Final da cria��o de vari�veis/string
		
		printf("Digite o CPF a ser consultado: "); //Consultando informa��es do usu�rio
		scanf("%s",cpf); //%refere-se a string
		
		FILE *file; //Cria o arquivo 
		file = fopen(cpf, "r"); // Cria o arquivo e o "R" significa ler
		
		if(file == NULL) //Se o arquivo n�o for encontrado
		{
			printf("ARQUIVO N�O LOCALIZDO! \n"); //resposta de n�o localizado
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("Essas s�o informa��es do usu�rio:\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("CPF N�O LOCALIZDO! . \n");
			system("pause");
		}
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t 1 - Registrar Nomes \n");
		printf("\t 2 - Consultar Nomes \n");
		printf("\t 3 - Deletar Nomes \n\n\n"); 
		printf("\t 4 - Sair do Sistema \n\n"); 
		printf("Op��o:");//Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		
		switch(opcao) //In�co da sele��o do menu
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2: 
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Tchau, at� a pr�xima! \n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o est� disponivel! \n");
			system("pause");
			break;
			//Fim da sele��o
				
		}
	
	}	
}
