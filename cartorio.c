#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string 

int registro() //Função responsável por cadastrar os usuários no sistema 
{
		//Início criação de variáveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da criação de variáveis/string
		
		printf("Digite o CPF a ser cadastrato: "); //Coletando informações do usuário
		scanf("%s", cpf); //%refere-se a string
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das string
		
		FILE *file; //Cria o arquivo 
		file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever
		fprintf(file,cpf); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //Salvo o valor da variavel
		
		printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
		scanf("%s", nome); //%refere-se a string
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file,nome); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
		scanf("%s", sobrenome); //%refere-se a string
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file,sobrenome); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); // Cria o arquivo
		fprintf(file, ","); //Salvo o valor da variavel
		fclose(file); //fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coletando informações do usuário
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
		
		//Início criação de variáveis/string
		char cpf[40];
		char conteudo[200];
		//Final da criação de variáveis/string
		
		printf("Digite o CPF a ser consultado: "); //Consultando informações do usuário
		scanf("%s",cpf); //%refere-se a string
		
		FILE *file; //Cria o arquivo 
		file = fopen(cpf, "r"); // Cria o arquivo e o "R" significa ler
		
		if(file == NULL) //Se o arquivo não for encontrado
		{
			printf("ARQUIVO NÃO LOCALIZDO! \n"); //resposta de não localizado
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("Essas são informações do usuário:\n");
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
			printf("CPF NÃO LOCALIZDO! . \n");
			system("pause");
		}
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem 
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t 1 - Registrar Nomes \n");
		printf("\t 2 - Consultar Nomes \n");
		printf("\t 3 - Deletar Nomes \n\n\n"); 
		printf("\t 4 - Sair do Sistema \n\n"); 
		printf("Opção:");//Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		
		switch(opcao) //Iníco da seleção do menu
		{
			case 1: 
			registro(); //chamada de funções
			break;
			
			case 2: 
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Tchau, até a próxima! \n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponivel! \n");
			system("pause");
			break;
			//Fim da seleção
				
		}
	
	}	
}
