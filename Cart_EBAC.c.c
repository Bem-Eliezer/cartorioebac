#include <stdio.h> //biblioteca de  comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca�oes de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string

int registro()//Fun��o responsavel por cadastrar o usuario no sistema
{	
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	
	printf("Digite seu CPF a ser cadastrado:\n "); //coletando informa��es do usuario
	scanf("%s",cpf);//"%s" refere-se a salvar em uma string
		
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string	
		
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo eo "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//o "a" atualiza o arquivo com a entrada de novos dados 
	fprintf(file,",");//insere novos dados 
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando novas informa��es
	scanf("%s",nome);//salvando as informa��es em uma string
	
	file = fopen(arquivo, "a");//atualiza��o do arquivo
	fprintf(file,nome);//inserindo novos dados no arquivo
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//atualiza��o do arquivo
	fprintf(file,",");//inserindo novos dados no arquivo
	fclose(file);//fechando arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando novas inform�a��es
	scanf("%s", sobrenome);//salvando novas informa��es em uma string
	
	file = fopen(arquivo,"a");//atua�oza��o do arquivo
	fprintf(file,sobrenome);//inserindo novos dados
	fclose(file);//fechandp arquivo
	
	file = fopen(arquivo,"a");//atualiza��o do arquivo
	fprintf(file,",");//inserindo dados para o arquivo
	fclose(file);//fechando arquivo
	
	printf("digite o cargo a ser cadastrado:");//coletando novas informa��es 
	scanf("%s", cargo);//salvando novas informa�oes
	
	file = fopen(arquivo,"a");//atualizando os arquivos
	fprintf(file,cargo);//inserindo novo dados
	fclose(file);//fechando arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	//incio da cria��o das variaveis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das variaveis
	
	printf("Digite o cpf a ser consultado: ");//colentando novas informa��es
	scanf("%s",cpf);//salvando novas informa��es
	
	FILE *file; //abrindo arquivo
	file = fopen(cpf,"r");//abre o arquivo, "r" � para ler
	
	if(file == NULL)// condi��o "se"
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)// la�o de repeti��o "enquanto" "fgets"busca o arquivo
	{
		printf("\nEssas s�o as informa��es do usuario: ");//mostra as informa��es que forma salvas 
		printf("%s", conteudo);//salvando informa��es no arquivo
		printf("\n\n");//pulando linhas
	}
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	//inicio da variavel
	char cpf[40];
	//fim da variavel
	
	printf("Digite o CPF do usuario a ser deletado");//coletando dados para o arquivo
	scanf("%S",cpf);//salvando o arquivo
	
	remove(cpf);//remove o arquivo
	
	FILE *file;//abrindo o arquivo da biblioteca
	file = fopen(cpf,"r");//abrindo o arquivo e inserindo o mesmo, "r" leia
	
	if(file == NULL)// condi��o "se"
	{
		printf("O usuario foi deletado no sistem e n�o se encontra no sistema.\n");
		system("pause");
	}
}
	

int main()
{
	int opcao=0; // definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");// limpa tela
	
		setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:"); // fim do menu
	
		scanf("%d", &opcao); // armazenando escolha do usuario
	
		system("cls");// limpa tela
		
		switch(opcao)// escolha uma das op��es,"switch" significa troca
		{
			case 1:// caso escolha a op��o 1, sera de inserir dados
			registro();// fun�ao que sera execultada
			break;//fechamento caso
			
			case 2:// caso escolha a op��o 2. sera de consultar os dados armazenados
			consulta();// fun�ao que sera execultada
	 		break;//fechamento caso
			
			case 3:// caso escolha a op�ao 3, sera que deletar os dados armazenados 
			deletar();// fun�ao que sera execultada
			break;//fechamento caso
				
			default:// caso escolha a op��o diferente das 3
			printf("op��o invalida\n");//informa��o mostrada ne tela
			system("pause");
			break;//fechamento caso
				
			}
		}
				
	}
