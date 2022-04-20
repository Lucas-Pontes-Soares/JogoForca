#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

/* Jogo da Forca
   Monke Games
   Representantes:
   Arhur Henrique Rolli
   Lucas Pontes Soares
   Pedro Henrique Botelho
   Pedro Ramos de Lima
*/

void mostra_forca (char corpo[20]) {                              //funções
    printf ("         _ _ \n");                                  //exibição da forca
    printf ("        |   |\n");
    printf ("        |   %c\n", corpo[5]); 
    printf ("        |  %c", corpo[3]); 
    printf ("%c", corpo[4]); 
    printf ("%c \n", corpo[2]); 
    printf ("        |  %c", corpo[1]); 
    printf (" %c \n", corpo[0]); 
    printf ("       _|_   \n");     
} 

void palavrasecreta(int caracteres, char descobrir[]){   //funções
	for (int x=0; x < caracteres; x++){                 //colocar "_" de acordo com o número de caracteres
    printf("_  ");
    descobrir[x] = '_';
  	}
}

void exibir(char descobrir[]){                          //funções
	for (int x=0; x < strlen(descobrir); x++){          //trocar "_" pela letra
    printf("%c ", descobrir[x]);
  	}
}

void infortema(char tema[20]){                         //funções
	printf("\nTema = %s", tema);                      //tema da palavra secreta
}  

int letras_usadas (char arquivo[20], int i_arquivo) {     //funções
   int i;                                                 //conferir se a letra já foi digitada
   for (i=0; i< i_arquivo; i++) {
      if (arquivo[i_arquivo]==arquivo[i]) {
         return 1;
      }       
   }
   return 0;
}
 

int main() {
	char secreta[20], tema[20];
	int acertos=0, ganhou=0, erros=0, confirmacao=1, flag = 0, key = 0;
	char letra, letraUp, descobrir[20], corpo[20];
	char letraUsada[256];            // 256 é a quantidade de símbolos ASCII

    // Inicializa letraUsada.
    for (int i = 0; i < 256; i++) {
        letraUsada[i] = 0;
    }
    
	setlocale(LC_ALL, "Portuguese");  //caracteres especiais
	for (int i=0; i<6; i++) {
       corpo[i]=' ';                  //mostrar forca
    }
    
	printf("               Olá, seja bem-vindo ao jogo da forca!");
	printf("\n\n                      Jogador número 1:");
	printf("\n              Informe o tema da palavra secreta: ");
	scanf("%s", &tema);            //ler o tema da palavra
	
	printf("                  Digite a palavra secreta: "); 
  	scanf("%s", &secreta);         //ler a palavra secreta
  	system("clear||cls");          //limpar tela
  	
  	printf("\n                      Outro Jogador:");
  	printf("\n             Tente adivinhar a palavra secreta!");
	printf("\n                   Limite de erros = 6");
	Sleep(2000);                 //pausar por 2 segundos
	system("clear||cls");       //limpar tema
	
	int caracteres = strlen(secreta);  //contar a quantidade de caracteres da palavra secreta
	
	infortema(tema);                       //informar tema da palavra
	printf("\n");              
	palavrasecreta(caracteres, descobrir); //chama a função para escrever "_ _ _ _ _" por exemplo, carro.
	printf("\n");
	mostra_forca(corpo);                   //mostrar forca
	
	for(int x=0; acertos <= caracteres; x++ ){
		for (int k=0; k <= 26; k++){	
			while(key == 0){
				if (ganhou == 0){
					printf("\nDigite uma letra: ");
			        fflush(stdin);  
					scanf("%c", &letra);    //ler a letra digitada
					system("clear||cls");   //limpar tela
					infortema(tema);       //informar tema da palavra
					printf("\n");
					exibir(descobrir);     //exibir a substituição de cada letra da palavra por "_"
					printf("\n");
					mostra_forca(corpo);    //mostrar forca
				}
				
				if (!letraUsada[toupper(letra)]) {        //conferir letra usada
		        	letraUsada[toupper(letra)] = 1;
		        	
		        	confirmacao = 1;  
		        	for (int y=0; y < caracteres; y++){
			        	if( toupper(secreta[y]) == toupper(letra)){ //conferir se a letra existe em alguma pocisão da palavra secreta
					        acertos++;                     //adicionar acertos
					        descobrir[y] = letra;         //substituir "_" pela posição correta da palavra
					        system("clear||cls");         //limpar tela
					        infortema(tema);              //informar tema da palavra
					        printf("\n");
					        exibir(descobrir);            //exibir a substituição pela palavara
					        printf("\n");
					        mostra_forca(corpo);          //mostrar forca
					        confirmacao = 0;              //confirmar que acertou
	  
					        if (acertos == caracteres){
				        		printf("\nVocê ganhou!"); //caso todas as letras foram descobertas, jogador ganha
				        		printf("\nCom %i erro(s)", erros);  //exibir quantidade de erros
				        		printf("\nParabéns!!!");
				        		ganhou = 1;
				        		exit(0);
				        		break;
					  		}	
					    }
	  
				    }
		        	if(confirmacao == 1){ 
				    	erros++;            //caso a letra não foi encontrada em nenhuma posição, adiciona erro
				    	switch (erros) {    //caso erre, a cada erro desenha uma parte do personagem
				            case 6: corpo[0]='\\'; break;
				            case 5: corpo[1]='/'; break;
				            case 4: corpo[2]='-'; break;
				            case 3: corpo[3]='-'; break;
				            case 2: corpo[4]='|'; break; 
				            case 1: corpo[5]='O'; break;  
		          		}
		          		
					    system("clear||cls");     //limpar tela
					    infortema(tema);          //informar tema da palavra
					    printf("\n");
						exibir(descobrir);        //exibir o "_"
					    printf("\n");
					    mostra_forca(corpo);      //mostrar forca
				  
				    	if (erros == 6){                           //caso erros = 6, o jogador perde
					    	printf("\nVocê perdeu!");
					    	printf("\nCom %i acerto(s)", acertos);   //mostra a quantidade de acertos
					    	printf("\nA palavra correta era: %s", secreta); //mostra a palavra secreta
					    	printf("\nTente novamente!");
					    	exit(0);
					    	break;                                  //encerrar, break
						}
				    }  
		        	
		        }else{       //se a letra já foi usada ele retorna, pedindo outra letra
		        	key = 0;
				}
			}  	
		}
    } 
 }
