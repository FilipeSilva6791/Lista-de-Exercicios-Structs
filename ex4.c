/******************************************************************

   FUNDA��O LIBERATO SALZANO VIEIRA DA CUNHA
   AUTOR: FILIPE DA SILVA
   EXERC�CIOS DE STRUCTS

 ******************************************************************/

 /***** INCLUDES *****/

 #include<stdio.h>  //entrada e sa�da de dados
 #include<stdlib.h> //system
 #include<string.h> //manipula��o de strings
 #include<locale.h> //caracteres na lingua portuguesa
 #include<time.h>  //tempo do computador
 #include<math.h> //fun��es matem�ticas
 #include<ctype.h>
 #include<conio.h>

/*
    4. Um censo demogr�fico visa mapear a distribui��o das caracter�sticas f�sicas da popula��o
    nos bairros da cidade. Para cada entrevistado ser�o coletados os seguintes dados:
    � idade
    � sexo (M e F)
    � cor dos olhos (A � azul, V � verde, C � castanho)
    � cor do cabelo (L � loiro, C � castanho, P � preto)
    Declare um tipo de vari�vel capaz de armazenar as informa��es desejadas.
    Declare um array deste tipo de vari�veis para armazenar os resultados das pesquisas. Minimo
    de 10 elementos.
    Elabore uma rotina de entrada de dados. A quantidade de indiv�duos pesquisada s� � conhecida
    no momento da entrada de dados. Construa a entrada de dados de tal forma que seja poss�vel
    interromper e retomar o processo.
    Elabore rotinas para gerar o relat�rio final da pesquisa, contendo as seguintes informa��es :
    � Numero de indiv�duos pesquisados.
    � M�dia de idade geral e por sexo.
    � Distribui��o das caracteristicas fisicas na popula��o, em geral e por sexo.
    Sugest�o : Construa uma interface com o usu�rio atrav�s de um menu de op��es.
*/

#define var 10

int main ()
{
  typedef struct dados
  {
    int idade;
    char sexo;
    char olhos;
    char cabelo;
  };

  struct dados individuo [var];   //criando um vetor de vari�veis tipo "dados"
  int opcao;                      //armazena as opcoes do usuario
  int qtd_H=0,qtd_M=0,qtd_total;  //qtd. de homens entrevistados, de mulheres entrevistadas e qtd total de individuos
  int i=0;                        //variavel do laco
  int soma_idade_H=0;             //armazena a soma das idades dos homens
  int soma_idade_M=0;             //armazena a soma das idades das mulheres
  int soma_total;                 //soma da idade de todos os individuos

  int carac_M[6]={};              //armazena as caracteristicas digitadas para as mulheres
  int carac_H[6]={};              //armazena as caracteristicas digitadas para os homens
  int carac[6] = {};                //armazena a soma das caracteristicas digitadas para os homens e mulheres

 /*
  //indice//
  carac_x[0] -> qtd de olhos azuis
  carac_x[1] -> qtd de olhos verdes
  carac_x[2] -> qtd de olhos castanhos
  carac_x[3] -> qtd de cabelos loiros
  carac_x[4] -> qtd de cabelos castanhos
  carac_x[5] -> qtd de cabelos pretos
 */

  setlocale(LC_ALL,"");           //configurando os caracteres da lingua portuguesa


  //!ENTRADA DE DADOS

  do {
    do{
        printf("Para o cadastro digite os seguintes dados do individuo %d:\n\n", i+1);
        printf("(Caso voc� digite algo errado termine o cadastro para poder retomar o processo)\n\n");

        printf("Idade: ");
        scanf(" %d",&individuo[i].idade);

        printf("Sexo, sendo 'F' feminino e 'M' masculino: ");
        scanf(" %c",&individuo[i].sexo);

        if(individuo[i].sexo>'Z')             //se o usu�rio digitar a letra minuscula
            individuo[i].sexo-=('a'-'A');     //transforma a letra para maiuscula


        printf("Cor dos olhos, sendo 'A' azul, 'V' verde e 'C' castanho: ");
        scanf(" %c",&individuo[i].olhos);

        if(individuo[i].olhos>'Z')             //se o usu�rio digitar a letra minuscula
            individuo[i].olhos-=('a'-'A');     //transforma a letra para maiuscula

        printf("Cor dos cabelos, sendo 'L' loiro, 'C' castanho e 'P' preto: ");
        scanf(" %c",&individuo[i].cabelo);

        if(individuo[i].cabelo>'Z')             //se o usu�rio digitar a letra minuscula
            individuo[i].cabelo-=('a'-'A');     //transforma a letra para maiuscula


        if(individuo[i].sexo == 'M')             //se for homem
        {
               soma_idade_H+=individuo[i].idade;  //soma a idade do homem a variavel destinada a isso
               qtd_H++;                           //incrementa a qtd de homens

               switch(individuo[i].olhos)         //incrementa no vetor a qtd de de cada caracteristica digitada
              {
                case 'A':
                  carac_H[0]++;
                  break;

                case 'V':
                  carac_H[1]++;
                  break;

                case 'C':
                  carac_H[2]++;
                  break;

                default:
                  break;
              }

               switch(individuo[i].cabelo)         //incrementa no vetor a qtd de de cada caracteristica digitada
              {
                case 'L':
                  carac_H[3]++;
                  break;

                case 'C':
                  carac_H[4]++;
                  break;

                case 'P':
                  carac_H[5]++;
                  break;

                default:
                  break;
              }

        }

        if(individuo[i].sexo =='F')            //se for mulher
        {

               soma_idade_M+=individuo[i].idade;  //soma a idade da mulher a variavel destinada a isso
               qtd_M++;                           //incrememnta a qtd de mulheres

              switch(individuo[i].olhos)         //incrementa no vetor a qtd de de cada caracteristica digitada
              {
                case 'A':
                  carac_M[0]++;
                  break;

                case 'V':
                  carac_M[1]++;
                  break;

                case 'C':
                  carac_M[2]++;
                  break;

                default:
                  break;
              }

               switch(individuo[i].cabelo)         //incrementa no vetor a qtd de de cada caracteristica digitada
              {
                case 'L':
                  carac_M[3]++;
                  break;

                case 'C':
                  carac_M[4]++;
                  break;

                case 'P':
                  carac_M[5]++;
                  break;

                default:
                  break;
              }
        }

//        //individuo[i].sexo=1;

        printf("\n********** Confirmando dados digitados do individuo %d **********\n\n",i+1);
        printf("Idade: %d anos.\n",individuo[i].idade);
        printf("Sexo: %c.\n",individuo[i].sexo);
        printf("Cor dos olhos: %c.\n",individuo[i].olhos);
        printf("Cor do cabelo: %c.\n",individuo[i].cabelo);


        printf("\nSe os dados etiverem corretos tecle enter, se n�o estiver tecle esc.\n");
        printf("\n*******************************************************************\n");
        opcao=getch(); //pega um caractere sem o uso do enter no fim

     } while (opcao!=13); //valor do enter na ASCII


  i++;      // incrementa o indice do vetor para comecar a armazenar as caracteristicas do proximo usuario

  printf("\nDigite 1 para registrar um novo indiv�duo ou 2 para exibir os resultados: ");
  scanf(" %d", &opcao);
  printf("\n*******************************************************************\n");

  } while(opcao!=2);


  //!CALCULANDO E EXIBINDO OS RESULTADOS

  printf("\n****************** RESULTADOS ********************\n\n");

  qtd_total=qtd_H+qtd_M;

  printf("** Quantidade de pessoas entrevistadas: %d . ** Sendo:\n",qtd_total);
  printf("%d homens e %d mulheres. \n", qtd_H,qtd_M);

  soma_total=soma_idade_H+soma_idade_M;
  soma_total/=qtd_total; //calculando a media total
  soma_idade_M/=qtd_M; //calculando a media de idade das mulheres
  soma_idade_H/=qtd_H; //calculando a media de idade dos homens

  printf("\n** Media de idade entre os entrevistados ** \n");
  printf("Considerando todos os indiv�duos: %d\n",soma_total);
  printf("Considerando apenas os homens: %d\n",soma_idade_H);
  printf("Considerando apenas as mulheres: %d\n",soma_idade_M);

  printf("\n** Distribuicao das caracteristicas fisicas da populacao\n ");

  for(i=0;i<6;i++)
  carac[i]=carac_M[i]+carac_H[i;];

  printf("\nGERAL (cor dos olhos)\n");
  printf("Azul: %d\n",carac[0]);
  printf("Verde: %d\n",carac[1]);
  printf("Castanho: %d\n",carac[2]);

  printf("\nMULHERES (cor dos olhos)\n");
  printf("Azul: %d\n",carac_M[0]);
  printf("Verde: %d\n",carac_M[1]);
  printf("Castanho: %d\n",carac_M[2]);

  printf("\nHOMENS (cor dos olhos)\n");
  printf("Azul: %d\n",carac_H[0]);
  printf("Verde: %d\n",carac_H[1]);
  printf("Castanho: %d\n",carac_H[2]);

  printf("\nGERAL (cor dos cabelos)\n");
  printf("Loiro: %d\n",carac[3]);
  printf("Castanho: %d\n",carac[4]);
  printf("Preto: %d\n",carac[5]);

  printf("\nMULHERES (cor dos cabelos)\n");
  printf("Loiro: %d\n",carac_M[3]);
  printf("Castanho: %d\n",carac_M[4]);
  printf("Preto: %d\n",carac_M[5]);

  printf("\nHOMENS (cor dos cabelos)\n");
  printf("Loiro: %d\n",carac_H[3]);
  printf("Castanho: %d\n",carac_H[4]);
  printf("Preto: %d\n",carac_H[5]);

  system("pause");

}





