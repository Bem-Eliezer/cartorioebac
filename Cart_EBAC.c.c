#include <stdio.h> //biblioteca de  comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocaçoes de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro()//Função responsavel por cadastrar o usuario no sistema
{	
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	
	printf("Digite seu CPF a ser cadastrado:\n "); //coletando informações do usuario
	scanf("%s",cpf);//"%s" refere-se a salvar em uma string
		
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string	
		
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo eo "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//o "a" atualiza o arquivo com a entrada de novos dados 
	fprintf(file,",");//insere novos dados 
	fclose(file);//fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando novas informações
	scanf("%s",nome);//salvando as informações em uma string
	
	file = fopen(arquivo, "a");//atualização do arquivo
	fprintf(file,nome);//inserindo novos dados no arquivo
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//atualização do arquivo
	fprintf(file,",");//inserindo novos dados no arquivo
	fclose(file);//fechando arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando novas informçações
	scanf("%s", sobrenome);//salvando novas informações em uma string
	
	file = fopen(arquivo,"a");//atuaçozação do arquivo
	fprintf(file,sobrenome);//inserindo novos dados
	fclose(file);//fechandp arquivo
	
	file = fopen(arquivo,"a");//atualização do arquivo
	fprintf(file,",");//inserindo dados para o arquivo
	fclose(file);//fechando arquivo
	
	printf("digite o cargo a ser cadastrado:");//coletando novas informações 
	scanf("%s", cargo);//salvando novas informaçoes
	
	file = fopen(arquivo,"a");//atualizando os arquivos
	fprintf(file,cargo);//inserindo novo dados
	fclose(file);//fechando arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	//incio da criação das variaveis
	char cpf[40];
	char conteudo[200];
	//fim da criação das variaveis
	
	printf("Digite o cpf a ser consultado: ");//colentando novas informações
	scanf("%s",cpf);//salvando novas informações
	
	FILE *file; //abrindo arquivo
	file = fopen(cpf,"r");//abre o arquivo, "r" é para ler
	
	if(file == NULL)// condição "se"
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)// laço de repetição "enquanto" "fgets"busca o arquivo
	{
		printf("\nEssas são as informações do usuario: ");//mostra as informações que forma salvas 
		printf("%s", conteudo);//salvando informações no arquivo
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
	
	if(file == NULL)// condição "se"
	{
		printf("O usuario foi deletado no sistem e não se encontra no sistema.\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:"); // fim do menu
	
		scanf("%d", &opcao); // armazenando escolha do usuario
	
		system("cls");// limpa tela
		
		switch(opcao)// escolha uma das opções,"switch" significa troca
		{
			case 1:// caso escolha a opção 1, sera de inserir dados
			registro();// funçao que sera execultada
			break;//fechamento caso
			
			case 2:// caso escolha a opção 2. sera de consultar os dados armazenados
			consulta();// funçao que sera execultada
	 		break;//fechamento caso
			
			case 3:// caso escolha a opçao 3, sera que deletar os dados armazenados 
			deletar();// funçao que sera execultada
			break;//fechamento caso
				
			default:// caso escolha a opção diferente das 3
			printf("opção invalida\n");//informação mostrada ne tela
			system("pause");
			break;//fechamento caso
				
			}
		}
				
	}
