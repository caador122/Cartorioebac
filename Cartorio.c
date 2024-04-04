#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

	int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o seu CPF para o cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //$s referese a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo o CPF
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu nome para o cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo de nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo de nome
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu sobrenome para o cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo de sobrenome
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo de sobrenome
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu cargo para o cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar, ou seja, vai atualizar o arquivo "w", mais salvando no arquivo de cargo
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}
	
	int consultar() //Fun��o responsavel por encontrar o CPF de algum aluno, professor ou funcionario
	{
		setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o seu CPF para ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); //"r" significa que o ele vai ler o arquivo para poder consultar algum CPF cadastrado 
		
		if(file == NULL) //"NULL" significa nulo e quando um arquivo ou seja o CPF n�o e localizado  
		{
			printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	}
	
	int deletar() //Fun��o responsavel por deletar os nomes que nos colocamos por engano ou desejamos deletar
	{
		char cpf[40];
		
		printf("Digite o CPF que voc� deseja deletar: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("Este usu�rio foi deletado com sucesso! \n");
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
		 
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t Cart�rio da EBAC \t \n\n"); //inicio do menu
		printf("Escolha a opc�o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consutar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d" , &opcao); //armazenamento a escolha do usu�rio 
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
				consultar();
				break;
			
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obriagdo por utilizar o sistema\n");
				return 0;
				break;	
				
			default:
				printf("\t Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;		
		} //fim da sele��o do menu
	
	 
    }
}
