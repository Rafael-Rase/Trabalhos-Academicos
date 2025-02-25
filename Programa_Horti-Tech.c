#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//VARIAVEIS GLOBAIS DO PROGRAMA
float TotalPreco = 0;
char TotalCompra[4000];

//VARIAVEIS DA SESSAO FRUTAS
char VETcodigofruta[4][20] = {"F1","F2","F3","F4"};
char VETnomefruta[4][50] = {"Maca (1 KILO)", "Pera (1 KILO)", "Banana (12 UNIDADES)", "Melancia (1 UNIDADE)"};
float VETprecofruta[4] = {18.99,23.99,12.19,28.00};
float VETdescontofruta[4] = {0.05,0.10,0.05,0.10};
float VETquantidadefruta[4] ={1,1,1,1};

//VARIAVEIS DA SESSAO GELADEIRAS
char VETcodigogeladeira[5][20] = {"G1","G2","G3","G4","G5"};
char VETnomegeladeira[5][50] = {"Queijo Mussarela (1 KILO)", "Ovo Branco (12 UNIDADES)", "Leite Integral (1 LITRO)", "Suco de laranja (1 LITRO)","Suco verde(1 LITRO)"};
float VETprecogeladeira[5]= {45.90,12.50, 8.00, 15.99,21.99 };
float VETdescontogeladeira[5] = {0.20,0.05,0.0,0.05,0.10};
float VETquantidadegeladeira[5]={1,1,1,1,1};

//VARIAVEIS DA SESSAO VERDURAS
char VETcodigoverdura[4][20] = {"V1","V2","V3","V4"};
char VETnomeverdura[4][50] = {"Brocolis (1 KILO)", "Alface (1 KILO)", "Coentro (1 UNIDADE)", "Couve (500 GRAMAS)"};
float VETprecoverdura[4]= {32.50,22.00,5.99,20.00 };
float VETdescontoverdura[4] = {0.15,0.15,0.10,0.15};
float VETquantidadeverdura[4]={1,1,1,1};

//VARIAVEIS DA SESSAO LEGUMES
char VETcodigolegume[4][20] = {"L1","L2","L3","L4"};
char VETnomelegume[4][50] = {"Abobrinha (1 KILO)", "Berinjela (1 KILO)", "Tomate (1 KILO)", "Pepino (1 KILO)"};
float VETprecolegume[4] = {6.98, 9.98, 10.00, 6.00};
float VETdescontolegume[4] = {0.15, 0.35, 0.20, 0.60};
float VETquantidadelegume[4] = {1, 1, 1, 1};

//VARIAVEIS DA SESSAO RAIZES E TUBERCULOS
char VETcodigoraiz[4][20] = {"R1","R2","R3","R4"};
char VETnomeraiz[4][50]= {"Cenoura (1 KILO)", "Beterraba (1 KILO)", "Batata (1 KILO)", "Cebola (KILO)"};
float VETprecoraiz[4]= {6.98,7.38,12.90,7.73};
float VETdescontoraiz[4]= {0.05,0.10,0.05,0.10};
float VETquantidaderaiz[4]={1,1,1,1};

int x, resposta;
char Baixo = 'B', Medio = 'M', Alto = 'A';
int Permissao = -1;
char Usuario[15], Senha[20];

	

void UsuarioSenha() //ESSA FUNCAO SERVE PARA ENTRADA E REGISTRO DO USUARIO AO SISTEMA PARA PODER ENTRAR NO PROGRAMA
{
	int x, resposta=0;
	char Baixo = 'B', Medio = 'M', Alto = 'A';
	char Usuario[15], Senha[20] ;	
		
	int Maiusculo = 0, Simbolo = 0;
	int escolha;
	
	printf("\nOla Usuario!\n");
	
	printf("    ____                     _    ___           __                     \n");
	printf("   / __ )___  ____ ___      | |  / (_)___  ____/ /___     ____ _____   \n");
	printf("  / __  / _  / __ `__  _____| | / / / __  / __  / __     / __ `/ __    \n");
	printf(" / /_/ /  __/ / / / / /_____/ |/ / / / / / /_/ / /_/ /  / /_/ / /_/ /  \n");
	printf("/_____/ ___/_/ /_/ /_/       ___/_/_/ /_/ __,_/ ____/    __,_/ ____/   \n");

	printf("    __  __           __  _ __            __   \n");   
	printf("   / / / /___  _____/ /_(_) /____  _____/ /_  \n");    
	printf("  / /_/ / __  / ___/ __/ / __/ _  / ___/ __   \n");
	printf(" / __  / /_/ / /  / /_/ / /_/  __/ /__/ / / / \n");
	printf("/_/ /_/ ____/_/    __/_/ __/ ___/ ___/_/ /_/  \n");
	             
	printf("\n\nPrimeiro, entre com usuario e senha e assim iremos proseguir... ");

	
	while (true)
	{
		printf("\n\nDeseja entrar ou se registrar?\nEntrar [1]\nRegistrar[2] \n");
		scanf("%d", &escolha);
		getchar();
		
		if (escolha == 1) //ESCOLHA PARA ENTRADA, POREM, A PRIMEIRA VEZ QUE ENTRE NO PROGRAMA VOCE NAO POSSUI REGISTRO
		{
		
			printf("\nVejo que nao possui login ainda... Va para o registro\nVoltando...");
			
		}
		if (escolha == 2) //ESCOLHA PARA REGISTRO, PEDINDO CRIACAO DE USUARIO E SENHA
		{
			printf("\nOtimo, crie o Usuario.\nA unica letra Maiuscula do usuario devera ser a primeira, representando  o cargo da empresa ['B' BAIXO, 'M' MEDIO, 'A' ALTO].\n\n");
			
			while (1)
			{
				printf("USUARIO :");
				gets(Usuario);
			
				//VERIFICACAO DO CARGO DO USUARIO REGISTREADO
				if(strchr(Usuario,Baixo) || strchr(Usuario, Medio) ) //CASO O CARGO SEJA BAIXO 'B' OU MEDIO 'M'
				{
					printf("\n\t\t***Letra de cargo *ENCONTRADA*, prosseguimos...***\n\n");
					Permissao = 0;
					break;
				}
				if (strchr(Usuario,Alto)) //CASO O CARGO SEJA ALTO 'A'
				{
					printf("\n\t\t***Letra de cargo *ENCONTRADA*, prosseguimos...***\n\n"); 
					Permissao = 1;
					break;
				}
				else //CASO O USUARIO REGISTRADO NAO TENHA O CARGO, MANDA REFAZER
				{
					printf("\n\t\t***Letra de cargo *NAO ENCONTRADA*, tente novamente...***\n");
				}	
			}
			printf("\nOtimo, crie a Senha.\nEla devera conter MAIS que 8 caracteres, com pelo menos Uma letra Maiuscula e Um Simbolo.\n\n");
			
			while (1)
			{
				printf("SENHA :");
			
				for (int y = 0; Senha[y]; y++) //LACO DE REPETICAO PARA VERIFICAR TODOS OS CARACTERES DA SENHA
				{
					
					gets(Senha);
				
					if (isupper(Senha[y])) //CASO ALGUM CARACTERE DA SENHA SEJA MAIUSCULA
					{
						Maiusculo =1;
						
						if (ispunct(Senha[y])) //CASO ALGUM CARACTERE DA SENHA SEJA SIMBOLO OU ESPECIAL
						{
							Simbolo = 1;
						}
							if (strlen(Senha) >= 8) //CASO A SENHA APRESENTE 8 OU MAIS CARACTERES
							{
								printf("Senha criada com sucesso\n\nBem-Vindo Ao Menu De Compras Do Hortitech\n");
								printf("\n------------------------------------------------------------------------------------------------------\n\n");
								break;
							}
					}
					
					else //CASO A SENHA NAO APRESENTE MAISCULO E/OU SIMBOLO E/OU 8 OU MAIS CARACTERES
					{
						printf("\n\t\t***Senha nao foi criada...***\n\t\t***falta maiuscula, simbolo ou nao atende aos 8 caracteres...***\n\nSENHA :");
						y = 0;
					}
				
				}
				break;
			}	
			break;		
		}
		if (escolha !=1 && escolha !=2) // CASO A ENTRADA DO USUARIO NAO SEJA NENHUMA DAS OPCOES, ELE VOLTA PRO COMECO DO LACO
		{
			printf("Erro na escolha, voltando...\n");
		}
		
	}
	
	
}


void frutas()
{
	//VARIAVEIS PARA TODOS OS FUNCIONAMENTOS DO VOID FRUTAS
	char compras[2000] = "";
	float preco = 0, precototal = 0;

	float quantidade;
	int x, resposta=0;
	
	printf("\n------------------------------------------------------------------------------------------------------\n\n");

	for (x=0; x<4; x++) //LACO DE REPETICAO PARA MOSTRAR OS PRODUTOS E SEUS PRECOS, QUANTIDADES E DESCONTOS
	{
		printf("%-25s | Preco: %6.2f | Quantidade: %6.2f | Desconto: %6.2f\n", VETnomefruta[x], VETprecofruta[x], VETquantidadefruta[x], VETdescontofruta[x]);
}	
	//LACO DE REPETICAO PARA ESCOLHAS
	while (resposta != 2)
	{
		printf("\n------------------------------------------------------------------------------------------------------\n");
		printf("O que voce deseja fazer agora? \n1- Comprar produtos\n2- Voltar ao inicio: "); //ESPERANDO COMANDO PARA COMPRAR OU VOLTAR A SESSAO
		scanf("%d", &resposta);
		
		getchar();
		
		//IF DAS POSSIVEIS RESPOSTAS 
		if (resposta == 1) //CASO EM QUE O USUARIO QUER COMPRAR ALGUM/NS PRODUTO/S 
		
		{
			while(resposta == 1)//LACO DE REPETICAO PARA AS COMPRAS DO PRODUTO
			{
				printf("\n\nQual Produto Deseja Comprar? ( 0- %s | 1- %s | 2- %s | 3- %s ): ", VETnomefruta[0],VETnomefruta[1],VETnomefruta[2],VETnomefruta[3]); //ESPERANDO COMANDO PARA SELECIONAR O PRODUTO
				scanf("%d", &x);
				
				printf("\nQual a quantidade desejada? (Na Compra de 2 ou Mais Unidades, Kilos, etc o Desconto e Considerado): "); //ESPERANDO COMANDO PARA SELECIONAR A QUANTIDADE
				scanf("%f", &quantidade);
				
				getchar();
				
				//LACO PARA DETERMINAR USO DO DESCONTO OU NAO
				if (quantidade >= 2 && VETdescontofruta[x] != 0) //CASO A QUANTIDADE SEJA MAIOR QUE 1 ELE EFETUA O CALCULO DE DESCONTO DO PRODUTO
				{
					printf("\n\n\t\t\t\t\t**DESCONT0 APLICADO**\n");
					preco = VETprecofruta[x] * quantidade * (1 - VETdescontofruta[x]);
				}
				else //CASO A QUANTIDADE SEJA IGUAL OU MENOR A 1
				{
					preco = VETprecofruta[x] * quantidade;
				}
				
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
			
                sprintf(compras + strlen(compras), "\t%s %-25s\tQUANTIDADE DESEJADA: %6.2f\tVALOR UNIDADE: %6.2f\tPRECO: R$ %6.2f\n",VETcodigofruta[x], VETnomefruta[x], quantidade, VETprecofruta[x], preco); //ARMAZENA OS PRODUTOS COMPRADOS NA VARIAVEL COMPRAS
			
                
				printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n", compras); 
				
				//FORMULA PARA FAZER O PRECOTOTAL DOS PRODUTOS COMPRADOS NA SESSAO
				precototal = precototal + preco;
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n");
				printf("Deseja Continuar Comprando nessa Sessao? ( 1- Sim | 2- Nao ): "); //ESPERANDO COMANDO PARA CONTINUAR COMPRANDO OU SAIR DO LACO
				scanf("%d", &resposta);
				
				getchar();
				
				//IF ELSE DE CONTINUAR COMPRANDO OU VOLTAR AO MENU
				if (resposta == 1) // VOLTA AO LACO DE COMPRA
				{
				}
				if (resposta == 2) // MOSTRA OS PRODUTOS COMPRADOS NA SESSAO  E O PRECO TOTAL
				{
					printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
					printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", compras);
					printf("\t\t\tPreco Total da sua compra na sessao de Frutas: R$%.2f\n", precototal);
					printf("\n----------------------------------------------------------------------------------------------------------------\n");
					
					//FORMULA PARA FAZER O TOTALCOMPRA PARA O CAIXA
					TotalPreco = TotalPreco + precototal;
					sprintf(TotalCompra, "%s\n%s", TotalCompra, compras);
				}
			}
			
		}
		if (resposta == 2) //CASO PARA VOLTAR AO MENU DE SESSOES
		{
			printf("\nVoltando ao menu...\n\n"); 
		}	
		if(resposta >= 3 || resposta <=0) //CASO O USUARIO NAO DIGITE NENHUMA DAS ALTERNATIVAS
		{
			printf("\nErro na resposta...");
		}
	}	


}


void geladeira()
{
	//VARIAVEIS PARA TODOS OS FUNCIONAMENTOS DO VOID GELADEIRAS
	char compras[2000] = "";
	float preco = 0, precototal = 0;

	float quantidade;
	int x, resposta=0;
	
	printf("\n------------------------------------------------------------------------------------------------------\n\n");

	for (x=0; x<5; x++) //LACO DE REPETICAO PARA MOSTRAR OS PRODUTOS E SEUS PRECOS, QUANTIDADES E DESCONTOS
	{
		printf("%-25s | Preco: %6.2f | Quantidade: %6.2f | Desconto: %6.2f\n", VETnomegeladeira[x], VETprecogeladeira[x], VETquantidadegeladeira[x], VETdescontogeladeira[x]);
}	
	//LACO DE REPETICAO PARA ESCOLHAS
	while (resposta != 2)
	{
		printf("\n------------------------------------------------------------------------------------------------------\n");
		printf("O que voce deseja fazer agora? \n1- Comprar produtos\n2- Voltar ao inicio: "); //ESPERANDO COMANDO PARA COMPRAR OU VOLTAR A SESSAO
		scanf("%d", &resposta);
		
		getchar();
		
		//IF DAS POSSIVEIS RESPOSTAS 
		if (resposta == 1) //CASO EM QUE O USUARIO QUER COMPRAR ALGUM/NS PRODUTO/S 
		
		{
			while(resposta == 1)//LACO DE REPETICAO PARA AS COMPRAS DO PRODUTO
			{
				printf("\n\nQual Produto Deseja Comprar? ( 0- %s | 1- %s | 2- %s | 3- %s | 4- %s ): ", VETnomegeladeira[0],VETnomegeladeira[1],VETnomegeladeira[2],VETnomegeladeira[3],VETnomegeladeira[4]); //ESPERANDO COMANDO PARA SELECIONAR O PRODUTO
				scanf("%d", &x);
				
				printf("\nQual a quantidade desejada? (Na Compra de 2 ou Mais Unidades, Kilos, etc o Desconto e Considerado): "); //ESPERANDO COMANDO PARA SELECIONAR A QUANTIDADE
				scanf("%f", &quantidade);
				
				getchar();
				
				//LACO PARA DETERMINAR USO DO DESCONTO OU NAO
				if (quantidade >= 2 && VETdescontogeladeira[x]!= 0) //CASO A QUANTIDADE SEJA MAIOR QUE 1 ELE EFETUA O CALCULO DE DESCONTO DO PRODUTO
				{
					printf("\n\n\t\t\t\t\t**DESCONT0 APLICADO**\n");
					preco = VETprecogeladeira[x] * quantidade * (1 - VETdescontogeladeira[x]);
				}
				else //CASO A QUANTIDADE SEJA IGUAL OU MENOR A 1
				{
					preco = VETprecogeladeira[x] * quantidade;
				}
				
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
			
                sprintf(compras + strlen(compras), "\t%s %-25s\tQUANTIDADE DESEJADA: %6.2f\tVALOR UNIDADE: %6.2f\tPRECO: R$ %6.2f\n",VETcodigogeladeira[x], VETnomegeladeira[x], quantidade, VETprecogeladeira[x], preco); //ARMAZENA OS PRODUTOS COMPRADOS NA VARIAVEL COMPRAS
            
                
				printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n", compras); 
				
				//FORMULA PARA FAZER O PRECOTOTAL DOS PRODUTOS COMPRADOS NA SESSAO
				precototal = precototal + preco;
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n");
				printf("Deseja Continuar Comprando nessa Sessao? ( 1- Sim | 2- Nao ): "); //ESPERANDO COMANDO PARA CONTINUAR COMPRANDO OU SAIR DO LACO
				scanf("%d", &resposta);
				
				getchar();
				
				//IF ELSE DE CONTINUAR COMPRANDO OU VOLTAR AO MENU
				if (resposta == 1) // VOLTA AO LACO DE COMPRA
				{
				}
				if (resposta == 2) // MOSTRA OS PRODUTOS COMPRADOS NA SESSAO  E O PRECO TOTAL
				{
					printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
					printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", compras);
					printf("\t\t\tPreco Total da sua compra na sessao de Frutas: R$%.2f\n", precototal);
					printf("\n----------------------------------------------------------------------------------------------------------------\n");
					
					//FORMULA PARA FAZER O TOTALCOMPRA PARA O CAIXA
					TotalPreco = TotalPreco + precototal;
					sprintf(TotalCompra, "%s\n%s", TotalCompra, compras);
				}
			}
			
		}
		if (resposta == 2) //CASO PARA VOLTAR AO MENU DE SESSOES
		{
			printf("\nVoltando ao menu...\n\n"); 
		}	
		if(resposta >= 3 || resposta <=0)
		{
			printf("\nErro na resposta..."); //CASO O USUARIO NAO DIGITE NENHUMA DAS ALTERNATIVAS
		}
	}	


}


void verduras ()
{
	//VARIAVEIS PARA TODOS OS FUNCIONAMENTOS DO VOID VERDURAS
	char compras[2000] = "";
	float preco=0, precototal=0;

	float quantidade;
	int x, resposta=0;
	
	printf("\n------------------------------------------------------------------------------------------------------\n\n");

	for (x=0; x<4; x++) //LACO DE REPETICAO PARA MOSTRAR OS PRODUTOS E SEUS PRECOS, QUANTIDADES E DESCONTOS
	{
		printf("%-25s | Preco: %6.2f | Quantidade: %6.2f | Desconto: %6.2f\n", VETnomeverdura[x], VETprecoverdura[x], VETquantidadeverdura[x], VETdescontoverdura[x]); 
	}
	while (resposta != 2)
	{
	printf("\n------------------------------------------------------------------------------------------------------\n");
		printf("Oque voce deseja fazer agora? \n1- Comprar produtos\n2- Voltar ao inicio: "); //ESPERANDO COMANDO PARA COMPRAR OU VOLTAR A SESSAO
		scanf("%d", &resposta);
		
		getchar();
		
		if (resposta == 1)
		{
			while(resposta == 1)
			{
				printf("\n\nQual Produto Deseja Comprar? ( 0- %s | 1- %s | 2- %s | 3- %s ): ",VETnomeverdura[0],VETnomeverdura[1],VETnomeverdura[2],VETnomeverdura[3]);
				scanf("%d", &x);
				printf("\nQual a quantidade desejada? (Na Compra de 2 ou Mais Unidades, Kilos, etc o Desconto e Considerado): "); //ESPERANDO COMANDO PARA SELECIONAR A QUANTIDADE
				scanf("%f", &quantidade);
				
				getchar();
				
				//LACO PARA DETERMINAR USO DO DESCONTO OU NAO
				if (quantidade >= 2 && VETdescontoverdura[x]!= 0) //CASO A QUANTIDADE SEJA MAIOR QUE 1 ELE EFETUA O CALCULO DE DESCONTO DO PRODUTO
				{
					printf("\n\n\t\t\t\t\t**DESCONT0 APLICADO**\n");
					preco = VETprecoverdura[x] * quantidade * (1 - VETdescontoverdura[x]);
				}
				else //CASO A QUANTIDADE SEJA IGUAL OU MENOR A 1
				{
					preco = VETprecoverdura[x] * quantidade;
				}
		
            	
				printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
			
                sprintf(compras + strlen(compras), "\t%s %-25s\tQUANTIDADE DESEJADA: %6.2f\tVALOR UNIDADE: %6.2f\tPRECO: R$ %6.2f\n",VETcodigoverdura[x], VETnomeverdura[x], quantidade, VETprecoverdura[x], preco); //ARMAZENA OS PRODUTOS COMPRADOS NA VARIAVEL COMPRAS
            
                
				printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n", compras);
				
				//FORMULA PARA FAZER O PRECOTOTAL DOS PRODUTOS COMPRADOS NA SESSAO
				precototal = precototal + preco;
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n");
				printf("Deseja Continuar Comprando nessa Sessao? ( 1- Sim | 2- Nao ): "); //ESPERANDO COMANDO PARA CONTINUAR COMPRANDO OU SAIR DO LACO
				scanf("%d", &resposta);
				
				getchar();
				
				//IF ELSE DE CONTINUAR COMPRANDO OU VOLTAR AO MENU
				if (resposta == 1) // VOLTA AO LACO DE COMPRA
				{
				}
				if (resposta == 2) // MOSTRA OS PRODUTOS COMPRADOS NA SESSAO  E O PRECO TOTAL
				{
					printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
					printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", compras);
					printf("\t\t\tPreco Total da sua compra na sessao de Verduras: R$%.2f\n", precototal);
					printf("\n----------------------------------------------------------------------------------------------------------------\n");
					
					//FORMULA PARA FAZER O TOTALCOMPRA PARA O CAIXA
					TotalPreco = TotalPreco + precototal;
					sprintf(TotalCompra, "%s\n%s", TotalCompra, compras);
				}
			}
		}
		if (resposta == 2)
		{
			printf("\nVoltando ao menu...\n\n"); //CASO PARA VOLTAR AO MENU DE SESSOES
		}
	
		if(resposta >= 3 || resposta <=0) //CASO O USUARIO NAO DIGITE NENHUMA DAS ALTERNATIVAS
		{
			printf("\nErro na resposta...");
		}	
	}
	
}


void legumes()
{
	char compras[2000] = "";
	float preco=0, precototal=0;

	float quantidade;
	int x, resposta=0;

	 printf("\n------------------------------------------------------------------------------------------------------\n\n");

	for (x=0; x<4; x++) //LACO DE REPETICAO PARA MOSTRAR OS PRODUTOS E SEUS PRECOS, QUANTIDADES E DESCONTOS
	{
		printf("%-25s | Preco: %6.2f | Quantidade: %6.2f | Desconto: %6.2f\n", VETnomelegume[x], VETprecolegume[x], VETquantidadelegume[x], VETdescontolegume[x]);
	}
	while (resposta != 2)
	{
	printf("\n------------------------------------------------------------------------------------------------------\n");
		printf("Oque voce deseja fazer agora? \n1- Comprar produtos\n2- Voltar ao inicio: "); //ESPERANDO COMANDO PARA COMPRAR OU VOLTAR A SESSAO
		scanf("%d", &resposta);

		getchar();

		if (resposta == 1)
		{
			while(resposta == 1)
			{
				printf("\n\nQual Produto Deseja Comprar? ( 0- %s | 1- %s | 2- %s | 3- %s ): ",VETnomelegume[0],VETnomelegume[1],VETnomelegume[2],VETnomelegume[3]);
				scanf("%d", &x);
				printf("\nQual a quantidade desejada? (Na Compra de 2 ou Mais Unidades, Kilos, etc o Desconto e Considerado): "); //ESPERANDO COMANDO PARA SELECIONAR A QUANTIDADE
				scanf("%f", &quantidade);

				getchar();

				//LACO PARA DETERMINAR USO DO DESCONTO OU NAO
				if (quantidade >= 2 && VETdescontolegume[x]!= 0) //CASO A QUANTIDADE SEJA MAIOR QUE 1 ELE EFETUA O CALCULO DE DESCONTO DO PRODUTO
				{
					printf("\n\n\t\t\t\t\t*DESCONT0 APLICADO*\n");
					preco = VETprecolegume[x] * quantidade * (1 - VETdescontolegume[x]);
				}
				else //CASO A QUANTIDADE SEJA IGUAL OU MENOR A 1
				{
					preco = VETprecolegume[x] * quantidade;
				}


				printf("\n----------------------------------------------------------------------------------------------------------------\n\n");

                sprintf(compras + strlen(compras), "\t%s %-25s\tQUANTIDADE DESEJADA: %6.2f\tVALOR UNIDADE: %6.2f\tPRECO: R$ %6.2f\n",VETcodigolegume[x], VETnomelegume[x], quantidade, VETprecolegume[x], preco); //ARMAZENA OS PRODUTOS COMPRADOS NA VARIAVEL COMPRAS


				printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n", compras);

				//FORMULA PARA FAZER O PRECOTOTAL DOS PRODUTOS COMPRADOS NA SESSAO
				precototal = precototal + preco;

				printf("\n----------------------------------------------------------------------------------------------------------------\n");
				printf("Deseja Continuar Comprando nessa Sessao? ( 1- Sim | 2- Nao ): "); //ESPERANDO COMANDO PARA CONTINUAR COMPRANDO OU SAIR DO LACO
				scanf("%d", &resposta);

				getchar();

				//IF ELSE DE CONTINUAR COMPRANDO OU VOLTAR AO MENU
				if (resposta == 1) // VOLTA AO LACO DE COMPRA
				{
				}
				if (resposta == 2) // MOSTRA OS PRODUTOS COMPRADOS NA SESSAO  E O PRECO TOTAL
				{
					printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
					printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", compras);
					printf("\t\t\tPreco Total da sua compra na sessao de Legumes: R$%.2f\n", precototal);
					printf("\n----------------------------------------------------------------------------------------------------------------\n");

					//FORMULA PARA FAZER O TOTALCOMPRA PARA O CAIXA
					TotalPreco = TotalPreco + precototal;
					sprintf(TotalCompra, "%s\n%s", TotalCompra, compras);
				}
			}
		}
		if (resposta == 2)
		{
			printf("\nVoltando ao menu...\n\n"); //CASO PARA VOLTAR AO MENU DE SESSOES
		}

		if(resposta >= 3 || resposta <=0) //CASO O USUARIO NAO DIGITE NENHUMA DAS ALTERNATIVAS
		{
			printf("\nErro na resposta...");
		}
	}
}



void raizesetuberculos()
{
	//VARIAVEIS PARA TODOS OS FUNCIONAMENTOS DO VOID RAIZ E TUBERCULOS
	char compras[2000] = "";
	float preco=0, precototal=0;

	float quantidade;
	int x, resposta=0;
	
	printf("\n------------------------------------------------------------------------------------------------------\n\n");

	for (x=0; x<4; x++) //LACO DE REPETICAO PARA MOSTRAR OS PRODUTOS E SEUS PRECOS, QUANTIDADES E DESCONTOS
	{
		printf("%-25s | Preco: %6.2f | Quantidade: %6.2f | Desconto: %6.2f\n", VETnomeraiz[x], VETprecoraiz[x], VETquantidaderaiz[x], VETdescontoraiz[x]);
}	
	//LACO DE REPETICAO PARA ESCOLHAS
	while (resposta != 2)
	{
		printf("\n------------------------------------------------------------------------------------------------------\n"); 
		printf("O que voce deseja fazer agora? \n1- Comprar produtos\n2- Voltar ao inicio: "); //ESPERANDO COMANDO PARA COMPRAR OU VOLTAR A SESSAO
		scanf("%d", &resposta);
		
		getchar();
		
		//IF DAS POSSIVEIS RESPOSTAS 
		if (resposta == 1)
		
		{//LACO DE REPETICAO PARA AS COMPRAS DO PRODUTO
			while(resposta == 1)
			{
				printf("\n\nQual Produto Deseja Comprar? ( 0- %s | 1- %s | 2- %s | 3- %s ): ",VETnomeraiz[0],VETnomeraiz[1],VETnomeraiz[2],VETnomeraiz[3]);
				scanf("%d", &x);
				printf("\nQual a quantidade desejada? (Na Compra de 2 ou Mais Unidades, Kilos, etc o Desconto e Considerado): "); //ESPERANDO COMANDO PARA SELECIONAR A QUANTIDADE
				scanf("%f", &quantidade);
				
				getchar();
				
				//LACO PARA DETERMINAR USO DO DESCONTO OU NAO
				if (quantidade >= 2 && VETdescontoraiz[x]!= 0) //CASO A QUANTIDADE SEJA MAIOR QUE 1 ELE EFETUA O CALCULO DE DESCONTO DO PRODUTO
				{
					printf("\n\n\t\t\t\t\t**DESCONT0 APLICADO**\n");
					preco = VETprecoraiz[x] * quantidade * (1 - VETdescontoraiz[x]);
				}
				else //CASO A QUANTIDADE SEJA IGUAL OU MENOR A 1
				{
					preco = VETprecoverdura[x] * quantidade;
				}
				
			
				printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
			
                sprintf(compras + strlen(compras), "\t%s %-25s\tQUANTIDADE DESEJADA: %6.2f\tVALOR UNIDADE: %6.2f\tPRECO: R$ %6.2f\n",VETcodigoraiz[x], VETnomeraiz[x], quantidade, VETprecoraiz[x], preco); //ARMAZENA OS PRODUTOS COMPRADOS NA VARIAVEL COMPRAS
            
                
				printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n", compras);
				
				//FORMULA PARA FAZER O PRECOTOTAL DOS PRODUTOS COMPRADOS NA SESSAO
				precototal = precototal + preco;
				
				printf("\n----------------------------------------------------------------------------------------------------------------\n");
				printf("Deseja Continuar Comprando nessa Sessao? ( 1- Sim | 2- Nao ): "); //ESPERANDO COMANDO PARA CONTINUAR COMPRANDO OU SAIR DO LACO
				scanf("%d", &resposta);
				
				getchar();
				
				//IF ELSE DE CONTINUAR COMPRANDO OU VOLTAR AO MENU
				if (resposta == 1) // VOLTA AO LACO DE COMPRA
				{
				}
				if (resposta == 2) // MOSTRA OS PRODUTOS COMPRADOS NA SESSAO  E O PRECO TOTAL
				{
					printf("\n----------------------------------------------------------------------------------------------------------------\n\n");
					printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", compras);
					printf("\t\t\tPreco Total da sua compra na sessao de Raizes e Tuberculos: R$%.2f\n", precototal);
					printf("\n----------------------------------------------------------------------------------------------------------------\n");
					
					//FORMULA PARA FAZER O TOTALCOMPRA PARA O CAIXA
					TotalPreco = TotalPreco + precototal;
					sprintf(TotalCompra, "%s\n%s", TotalCompra, compras);
				}
			}
		}
		if (resposta == 2)
		{
			printf("\nVoltando ao menu...\n\n"); //CASO PARA VOLTAR AO MENU DE SESSOES
		}
	
		if(resposta >= 3 || resposta <=0) //CASO O USUARIO NAO DIGITE NENHUMA DAS ALTERNATIVAS
		{
			printf("\nErro na resposta...");
		}	
	}	
}


void caixa()
{
	//VARIAVEIS PARA O VOID CAIXA
	float preco, precototal, Pagamento;
	char compras[2000];
	int resposta = 0;
	
	TotalPreco = TotalPreco + precototal;
	
	
	//MOSTRA NA TELA TODAS AS COMPRAS FEITAS, JUNTANDO TODOS AS SESSOES
	printf("\n------------------------------------------------------------------------------------------------------\n\n");
	printf("\t\t\t\t\t:::LISTA DE PRODUTOS:::\n   Codigo  Produto\n%s\n\n", TotalCompra);
	printf(":::SUBTOTAL:::\n[ R$ %.2f ]", TotalPreco);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	
	while (resposta != 2) //LACO DE REPETICAO 
	{
		printf("\nO que voce vai fazer? \n1- Pagar a conta \n2- Voltar ao inicio : "); // ESPERANDO COMANDO DO USUARIO PARA PAGAR OU VOLTAR AO MENU DE SESSOES
		scanf("%d", &resposta);
		
		getchar();
		
		if(resposta == 1) //CASO PARA EFETUAR A COMPRA DOS PRODUTOS
		{	
			
			do
			{
				printf("\nQuanto Ira colocar? R$"); //COLOCAR O PRECO PRA PAGAR
				scanf("%f", &Pagamento);
				
				getchar();
			
				if (Pagamento >= TotalPreco) //SE O PAGAMENTO FOR IGUAL OU MAIOR AO PRECO TOTAL 
				{
					Pagamento = Pagamento - TotalPreco;
					
					printf("\nTchau tchau dinheiro... Seu Troco foi de R$ %.2f \n\n", Pagamento);
					
					printf("   ____  __         _                 __                       \n");
					printf("  / __  / /_  _____(_)___ _____ _____/ /___                    \n");
					printf(" / / / / __  / ___/ / __ `/ __ `/ __  / __                    \n");
					printf("/ /_/ / /_/ / /  / / /_/ / /_/ / /_/ / /_/ /                   \n");
					printf(" ____/_.___/_/  /_/ __, / __,_/ __,_/ ____/                   \n");
					printf(" _    __      ____/____/    _____       \n");
					printf("| |  / /___  / / /____     / ___/___  ____ ___  ____  ________\n");
					printf("| | / / __  / / __/ _       __  / _  / __ `__  / __  / ___/ _  \n");
					printf("| |/ / /_/ / / /_/  __/   ___/ /  __/ / / / / / /_/ / /  /  __/\n");
					printf("|___/ ____/_/ __/ ___/   /____/ ___/_/ /_/ /_/ .___/_/    ___/ \n");
					printf("                                            /_/                \n\n");
					
					system("pause");
					exit(0);
				}
				
				else //SE O PAGAMENTO FOR MENOR QUE O PRECO TOTAL
				{
					printf("\n\nNao Vai dar calote nao engracadinho, faltaria R$ %.2f para completar a compra. Coloque o dinheiro denovo...", TotalPreco - Pagamento);
					printf("\n------------------------------------------------------------------------------------------------------\n");		
				}
			}while (Pagamento >= TotalPreco);
		}
		if (resposta == 2) // CASO PARA VOLTAR AO MENU DE SESSOES
		{
			printf("\nVoltando ao inicio...\n");
			break;
		}
		if(resposta !=1 && resposta !=2) //CASO A RESPOSTA DO USUARIO NAO FOR NEHUMA DAS DEFINIDAS
		{
			printf("\nEsta opcao nao existe, voltando...");
		}
		
	}
}


void AlteraProduto()
{
	//VARIAVEIS PARA FUNCIONAMENTO DO VOID ALTERAPRODUTOS
	char AlteraNomeProduto;
	float AlteraProduto;
	int resposta, x = 0;
	char VETnome[4][50];
    float VETpreco[4], VETdesconto[4], VETquantidade[4];
    
	printf("\n------------------------------------------------------------------------------------------------------\n\n");
	printf("Qual Sessao gostaria de mudar? ( 1 - Frutas | 2 - Geladeiras | 3 - Verduras | 4 - Legumes | 5 - Raizes e Tuberculos )\n"); //ESPERANDO O USUARIO ESCOLHER A SESSAO QUE SERA MUDADA
	scanf("%d", &resposta);
	
	getchar();
	if (resposta == 1) //CASO QUE ALTERA A SESSAO FRUTAS
	{
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
		printf("Mude os 4 produtos da Sessao Frutas");
		
		printf("\nComecando pelo *NOME* dos Produtos. Coloque o nome e o tipo de pesagem\tEX. Maca (KILO)\n"); //LACO DE REPETICAO PARA ALTERAR TODOS OS NOMES DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%d] Nome do Produto: ", x);
			gets(VETnomefruta[x]);
		}
		
		printf("\n\nColoque o *PRECO* do produto"); //LACO PARA ALTERAR O PRECO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Preco do Produto: ", VETnomefruta[x]);
			scanf("%f", &VETprecofruta[x]);
			getchar();
		}
		
		printf("\n\nColoque a *QUANTIDADE* do produto"); //LACO PARA ALTERAR A QUANTIDADE DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Quantidaem do Produto: ", VETnomefruta[x]);
			scanf("%f", &VETquantidadefruta[x]);
			getchar();
		}
		
		printf("\n\nColoque o *DESCONTO* do produto"); //LACO PARA ALTERAR O DESCONTO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Desconto do Produto: ", VETnomefruta[x]);
			scanf("%f", &VETdescontofruta[x]);
			getchar();
		}
		
		printf("Produtos da Sessao alteraos com sucesso!\n");
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
		
		
	}
	if (resposta == 2) //CASO QUE ALTERA A SESSAO GELADEIRAS
	{
		printf("Mude os 5 produtos da Sessao Geladeiras");
		
		printf("\nComecando pelo *NOME* dos Produtos. Coloque o nome e o tipo de pesagem\tEX. Maca (KILO)\n");//LACO DE REPETICAO PARA ALTERAR TODOS OS NOMES DOS PRODUTOS
		for (int x = 0; x<5;x++)
		{
			printf("\n[%d] Nome do Produto: ", x);
			gets(VETnomegeladeira[x]);
		}
		
		printf("\n\nColoque o *PRECO* do produto");//LACO PARA ALTERAR O PRECO DOS PRODUTOS
		for (int x = 0; x<5;x++)
		{
			printf("\n[%s] Preco do Produto: ", VETnomegeladeira[x]);
			scanf("%f", &VETprecogeladeira[x]);
			getchar();
		}
		
		printf("\n\nColoque a *QUANTIDADE* do produto"); //LACO PARA ALTERAR A QUANTIDADE DOS PRODUTOS
		for (int x = 0; x<5;x++)
		{
			printf("\n[%s] Quantidaem do Produto: ", VETnomegeladeira[x]);
			scanf("%f", &VETquantidadegeladeira[x]);
			getchar();
		}
		
		printf("\n\nColoque o *DESCONTO* do produto");//LACO PARA ALTERAR O DESCONTO DOS PRODUTOS
		for (int x = 0; x<5;x++)
		{
			printf("\n[%s] Desconto do Produto: ", VETnomegeladeira[x]);
			scanf("%f", &VETdescontogeladeira[x]);
			getchar();
		}
		
		printf("Produtos da Sessao alteraos com sucesso!\n");
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
	}
	if (resposta == 3)//CASO QUE ALTERA A SESSAO VERDURAS
	{
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
		printf("Mude os 5 produtos da Sessao Veruras");
		
		printf("\nComecando pelo *NOME* dos Produtos. Coloque o nome e o tipo de pesagem\tEX. Maca (KILO)\n");//LACO DE REPETICAO PARA ALTERAR TODOS OS NOMES DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%d] Nome do Produto: ", x);
			gets(VETnomeverdura[x]);
			getchar();
		}
		
		printf("\n\nColoque o *PRECO* do produto");//LACO PARA ALTERAR O PRECO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Preco do Produto: ", VETnomeverdura[x]);
			scanf("%f", &VETprecoverdura[x]);
			getchar();
		}
		
		printf("\n\nColoque a *QUANTIDADE* do produto"); //LACO PARA ALTERAR A QUANTIDADE DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Quantidaem do Produto: ", VETnomeverdura[x]);
			getchar();
		}
		
		printf("\n\nColoque o *DESCONTO* do produto");//LACO PARA ALTERAR O DESCONTO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Desconto do Produto: ", VETnomeverdura[x]);
			scanf("%f", &VETdescontoverdura[x]);
			getchar();
		}
		
		printf("Produtos da Sessao alteraos com sucesso!\n");
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
	}
	if (resposta == 4)//CASO QUE ALTERA A SESSAO LEGUMES
	{
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
		printf("Mude os 5 produtos da Sessao Legumes");
		
		printf("\nComecando pelo *NOME* dos Produtos. Coloque o nome e o tipo de pesagem\tEX. Maca (KILO)\n");//LACO DE REPETICAO PARA ALTERAR TODOS OS NOMES DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%d] Nome do Produto: ", x);
			gets(VETnomelegume[x]);
			
		}
		
		printf("\n\nColoque o *PRECO* do produto");//LACO PARA ALTERAR O PRECO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Preco do Produto: ", VETnomelegume[x]);
			scanf("%f", &VETprecolegume[x]);
			getchar();
		}
		
		printf("\n\nColoque a *QUANTIDADE* do produto"); //LACO PARA ALTERAR A QUANTIDADE DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Quantidaem do Produto: ", VETnomelegume[x]);
			scanf("%f", &VETquantidadelegume[x]);
			getchar();
		}
		
		printf("\n\nColoque o *DESCONTO* do produto");//LACO PARA ALTERAR O DESCONTO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Desconto do Produto: ", VETnomelegume[x]);
			scanf("%f", &VETdescontolegume[x]);
			getchar();
		}
		
		printf("Produtos da Sessao alteraos com sucesso!\n");
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
	}
	if (resposta == 5)//CASO QUE ALTERA A SESSAO RAIZ E TUBERCULOS
	{
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
		printf("Mude os 5 produtos da Sessao Raiz e Tuberculos");
		
		printf("\nComecando pelo *NOME* dos Produtos. Coloque o nome e o tipo de pesagem\tEX. Maca (KILO)\n");//LACO DE REPETICAO PARA ALTERAR TODOS OS NOMES DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%d] Nome do Produto: ", x);
			gets(VETnomeraiz[x]);
		}
		
		printf("\n\nColoque o *PRECO* do produto");//LACO PARA ALTERAR O PRECO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Preco do Produto: ", VETnomeraiz[x]);
			scanf("%f", &VETprecoraiz[x]);
			getchar();
		}
		
		printf("\n\nColoque a *QUANTIDADE* do produto"); //LACO PARA ALTERAR A QUANTIDADE DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Quantidaem do Produto: ", VETnomeraiz[x]);
			scanf("%f", &VETquantidaderaiz[x]);
			getchar();
		}
		
		printf("\n\nColoque o *DESCONTO* do produto");//LACO PARA ALTERAR O DESCONTO DOS PRODUTOS
		for (int x = 0; x<4;x++)
		{
			printf("\n[%s] Desconto do Produto: ", VETnomeraiz[x]);
			scanf("%f", &VETdescontoraiz[x]);
			getchar();
		}
		
		printf("Produtos da Sessao alteraos com sucesso!\n");
		printf("\n------------------------------------------------------------------------------------------------------\n\n");
	}
	if (resposta >5 || resposta <1) //CASO A RESPOSTA DO USUARIO NAO FOR NENHUMA INDICADA NA TELA
	{
		printf("Erro de resposta, voltando...");
		return;
	}
}

int main()
{	
	//VARIAVEIS PARA FUNCIONAR O INT MAIN
	
	char Baixo = 'B', Medio = 'M', Alto = 'A';
	char Usuario[15] = "", Senha[20] = "";
		
	
	//EXECUTA O VOID USUARIO E SENHA
	UsuarioSenha();
	
	
	printf("    __  ___                        __        ______                ____                  \n");
	printf("   /  |/  /__  ____  __  __   ____/ /__     / ____/_____________  / / /_  ____ ______    \n");	
	printf("  / /|_/ / _  / __  / / / /  / __  / _     / __/ / ___/ ___/ __  / / __  / __ `/ ___/    \n");	
	printf(" / /  / /  __/ / / / /_/ /  / /_/ /  __/  / /___(__  ) /__/ /_/ / / / / / /_/ (__  )     \n");	
	printf("/_/  /_/ ___/_/ /_/ __,_/    __,_/ ___/  /_____/____/ ___/ ____/_/_/ /_/ __,_/____/      \n");	
	printf("\n\n");
		
	//LACO DDE REPETICAO PARA AS ALTERNATIVAS DISPONIVEIS
	while(resposta != 8)
	{
		printf("Escolha uma das opcoes: \n1- Frutas\n2- Geladeira\n3- Verduras\n4- Legumes\n5- Raizes e Tuberculos \n6- Caixa\n7- Alterar Estoque\n8- Sair\n\nResposta: ");
		scanf("%d", &resposta);
		if(resposta == 1) //ESCOLHE SESSAO FRUTA
		{
			frutas();
		}
		if(resposta == 2) //ESCOLHE SESSAO GELADEIRA
		{
			geladeira();
		}
		if(resposta == 3) //ESCOLHE SESSAO VERDURAS
		{
			verduras();
		}
		if(resposta == 4) //ESCOLHA SESSAO LEGUMES
		{
			legumes();
		}
		if(resposta == 5) //ESCOLHE SESSAO RAIZ E TUBERCULOS
		{
			raizesetuberculos();
		}
		if(resposta == 6) //ESCOLHE IR AO CAIXA
		{
			caixa();
		}
		if (resposta == 7) //ESCOLHE ALTERACAO DE PRODUTOS
		{
			
			if(Permissao == 1) //CASO O USUARIO TENHA CARGO ALTO 'A'
			{
		
				printf("\n\t\t***Voce tem permissao para entrar***\n\n");
				AlteraProduto();
	
				
			}
			else //CASO O USUARIO TENHA CARGO MEDIO 'M' OU BAIXO 'B'
			{
				printf("\n\t\t***Voce nao tem permissao para entrar***");
				printf("\nSeu cargo nao lhe permite isso.\n\nVoltando...\n\n");
			}
		}
		if (resposta == 8) //ESCOLHE SAIR DO PROGRAMA
		{
		printf("   ____  __         _                 __                       \n");
		printf("  / __  / /_  _____(_)___ _____ _____/ /___                    \n");
		printf(" / / / / __  / ___/ / __ `/ __ `/ __  / __                    \n");
		printf("/ /_/ / /_/ / /  / / /_/ / /_/ / /_/ / /_/ /                   \n");
		printf(" ____/_.___/_/  /_/ __, / __,_/ __,_/ ____/                   \n");
		printf(" _    __      ____/____/    _____       \n");
		printf("| |  / /___  / / /____     / ___/___  ____ ___  ____  ________\n");
		printf("| | / / __  / / __/ _       __  / _  / __ `__  / __  / ___/ _  \n");
		printf("| |/ / /_/ / / /_/  __/   ___/ /  __/ / / / / / /_/ / /  /  __/\n");
		printf("|___/ ____/_/ __/ ___/   /____/ ___/_/ /_/ /_/ .___/_/    ___/ \n");
		printf("                                            /_/                \n\n");
		
		printf("Fechando programa...\n\n");
		
		}
	}
	system("pause");
	return 0;
}
