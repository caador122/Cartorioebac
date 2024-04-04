#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string

	int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o seu CPF para o cadastro: "); //coletando informação do usuário
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
	
	int consultar() //Função responsavel por encontrar o CPF de algum aluno, professor ou funcionario
	{
		setlocale(LC_ALL, "Portuguese"); //Definido a linguagem
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o seu CPF para ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); //"r" significa que o ele vai ler o arquivo para poder consultar algum CPF cadastrado 
		
		if(file == NULL) //"NULL" significa nulo e quando um arquivo ou seja o CPF não e localizado  
		{
			printf("Não foi possivel abrir o arquivo, não localizado! \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	}
	
	int deletar() //Função responsavel por deletar os nomes que nos colocamos por engano ou desejamos deletar
	{
		char cpf[40];
		
		printf("Digite o CPF que você deseja deletar: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("Este usuário foi deletado com sucesso! \n");
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
		 
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t Cartório da EBAC \t \n\n"); //inicio do menu
		printf("Escolha a opcão desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consutar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d" , &opcao); //armazenamento a escolha do usuário 
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções 
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
				printf("\t Essa opção não está disponivel!\n");
				system("pause");
				break;		
		} //fim da seleção do menu
	
	 
    }
}
