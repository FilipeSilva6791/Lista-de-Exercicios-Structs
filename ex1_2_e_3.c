/******************************************************************

   FUNDAÇÃO LIBERATO SALZANO VIEIRA DA CUNHA
   AUTOR: FILIPE DA SILVA
   EXERCÍCIOS DE STRUCTS

 ******************************************************************/

 /***** INCLUDES *****/

 #include<stdio.h>  //entrada e saída de dados
 #include<stdlib.h> //system
 #include<string.h> //manipulação de strings
 #include<locale.h> //caracteres na lingua portuguesa
 #include<time.h>  //tempo do computador
 #include<math.h> //funções matemáticas
 #include<ctype.h>
 #include<conio.h>


 /****** EXERCÍCIOS ******/

#define Ex1
/*
    1. Um projeto de caderno de chamada eletrônico especifica o armazenamento das informações
       dos alunos em estruturas com os seguintes dados:
     • Matricula (inteiro sem sinal)
     • Nome do aluno (string)
     • Notas de 3 trimestrais (float)
     • Resultado anual (float)
     • Conceito (char)

     Elabore um programa que:
     a) Construa (declare) a estrutura que represente a organização proposta. Crie uma variável deste tipo.
     b) Codifique a entrada de dados para a variável.
     c) O resultado é definido como sendo a média ponderada com pesos 25, 35 e 40, respectivamente.
     O conceito é dado em função do resultado:
     Resultado Conceito >=9 A ; >=7,5 B; >=6 C; <6 R.
     Elabore as rotinas de cálculo do resultado e conceito.
     d) Exiba o resultado obtido pelo aluno.
*/

#define Ex2
/*
     2. Em um determinado sistema de informática, as datas do calendário são representadas pela  estrutura abaixo

     struct dma
     {
       int dia;          // dia do mes
       int mes;        // mes
       int ano;         // ano
       int feriado;   //  0 – não é feriado, 1 - feriado
       char efemeride[50];  // qual motivo do feriado
     };

     Desenvolva um programa que :
     a. Contenha uma variável do tipo estrutura dma

     b. Uma rotina de entrada de dados que preencha esta variável, considerando o número de dias de cada mês
        e a possibilidade do ano ser bissexto. Considere que as datas correspondem aos séculos 20 e 21. O campo
        efemeride só deve ser preenchido se necessário.

     c. Uma rotina que exiba o conteúdo da variável tipo struct dma como apresentado no exemplo abaixo:

        25/dez/2020  é feriado : Natal
*/

#define Ex3
/*
    3. Utilizando como base o código desenvolvido no exercicio 2, elabore um programa que, a
    partir de 2 datas, determine o intervalo, em dias, entre estas datas.
*/



/******************************************************************************************************/
#ifdef Ex

#define var 32

int main ()
 {
   setlocale(LC_ALL,"");

   int i; //uso geral
   int j; //uso geral
   int numeroAluno; //especifica o número do aluno que o usúario desejar ver os dados

   struct dados{

    int matricula;
    char nome[30];
    float notas [3];
    float resultado;
    char conceito;

   };

  struct dados aluno [var]; // criando uma struct para cada aluno

  printf("*********************************** CHAMADA ELETRÔNICA *************************************");

  for(i=0; i<var; i++) //entrada de dados
  {
    fflush(stdin); // limpando o buffer do teclado para não dar erro no scanf e no gets
    printf("\nDigite a matrícula do aluno %d: ", i+1);
    scanf("%d", &aluno[i].matricula);

    fflush(stdin);
    printf("Digite o nome do aluno %d: ",i+1);
    gets(aluno[i].nome);

    for (j=0; j<3; j++)
     {
       printf("Digite a nota do trimestre %d: ", j+1);
       scanf ("%f", &aluno[i].notas[j]);
     }
  }


  for(i=0; i<var; i++)
  {
    aluno[i].resultado=((aluno[i].notas[0]*25+aluno[i].notas[1]*35+aluno[i].notas[2]*40)/100); //definindo o resultado de cada aluno

    //! DEFININDO O CONCEITO
    if (aluno[i].resultado>=9)
        aluno[i].conceito='A';

    if (aluno[i].resultado>=7.5 & aluno[i].resultado<9)
        aluno[i].conceito='B';

    if (aluno[i].resultado>=6 & aluno[i].resultado<7.5)
        aluno[i].conceito='C';

    if (aluno[i].resultado<6 )
        aluno[i].conceito='R';

  }


  printf("\n*************************** DADOS DOS ALUNOS ************************************************\n");

  for(i=0; i<var; i++)
  {
    printf("Aluno %s, Nº %d\n", aluno[i].nome, i+1);
    printf("Resultado: %.2f\n", aluno[i].resultado);
    printf("Conceito: %c \n\n",aluno[i].conceito);
  }

  while(numeroAluno!=0)
  {
    printf("Busca por aluno: \nDigite seu número na chamada ou digite 0 para sair: ");
    scanf("%d",&numeroAluno);

   if(numeroAluno!=0){  //não deixa o código rodar a partir daqui se o primeiro número digitado pelo usuário for zero
    printf("\nAluno %s, Nº %d\n", aluno[numeroAluno-1].nome,numeroAluno);
    printf("Resultado: %.2f\n", aluno[numeroAluno-1].resultado);
    printf("Conceito: %c \n\n", aluno[numeroAluno-1].conceito);
   }
  }
  printf("\n");
  system("pause");
 }

#endif

/******************************************************************************************************/
#ifdef Ex

 int main ()
 {
   setlocale(LC_ALL,""); //configura os caracteres da língua portuguesa

   struct dma
  {
    int dia;             // dia do mes
    int mes;             // mes
    int ano;             // ano
    int feriado;         // 0 – não é feriado, 1 - feriado
    char efemeride[50];  // qual motivo do feriado
  }calendario;



  int bissexto=0;                               //testa se o ano digitado é bissexto
  int i;                                        //variavel dos laços
  int mes[12]={1,0,1,0,1,0,1,1,0,1,0,1};        // 1-mes é de 31 dias / 0-não é; determina qual mes é de 31 dias e qual não é
  int dia;                                      //testa se o dia digitado é válido
  char nome_mes[3];                             //armazena o nome do mes digitado


  /************************ ENTRADA DE DADOS ****************************/



 //! Inserindo o ano e testando se ele correponde ao sec XX ou XXI:

 i=0; //zerando i para usar no laço

 do
  {
   if(i>0)
    printf("\nO ano digitado não corresponde ao intervalo. Por favor, digite novamente.\n");

   printf("Digite um ano entre o sec XX e XXI: ");
   scanf("%d",&calendario.ano);

   i++;
  } while (calendario.ano<1901 || calendario.ano>2100);


 //! Descobrindo se o ano é bissexto:
 //ano bissexto =1, não bissexto =0

 if((calendario.ano%4==0 && calendario.ano%100!=0) || calendario.ano%400==0)
      bissexto=1;
    else
      bissexto=0;



//! Inserindo o mês e testando se ele correponde ao intervalo de janeiro a dezembro:

  i=0; //zerando a varivael i para ser usada no laço

 do
  {
   if(i>0)
    printf("O mês digitado não existe. Por favor, digite novamente.\n");

   printf("Digite o mês: ");
   scanf("%d",&calendario.mes);

   i++;
  } while (calendario.mes<1 || calendario.mes>12);


//! Inserindo o dia e testando se ele existe:

 i=0; //zerando i para ser usado no laço


 do //1= dia valido; 0= dia não existe
 {
   if(i>0)
     printf("O dia digitado não existe. Por favor, digite novamente.\n");

//printf("\n\n\n\n MES = %d \n\n",mes[calendario.mes-1]);

   printf("Digite o dia: ");
   scanf("%d",&calendario.dia);

   if(calendario.dia>0 && calendario.dia<32) // se o dia cumpre o intervalo do dia 1 ao 31
   {
      if(calendario.mes==2)  // se o mês digitado for fevereiro
      {
        if(bissexto==1 && (calendario.dia<30))
            dia=1;
        else if(bissexto==0 && (calendario.dia<29))
            dia=1;
        else
            dia=0;
      }
      else
      {
        if(mes[calendario.mes-1]==0 && calendario.dia>30) //se o mes é de 30 dias e o usuário digitou 31
            dia=0;
        else              //qualquer outra situação
            dia=1;
      }

   }else
       dia=0;

 i++;

 } while (dia==0);

 //! Inserindo o dia e vendo se é feriado ou não:

 i=0; //zerando i para usar no laço

 do
  {
   if(i>0)
    printf("\nO número digitado não corresponde ao solicitado. Por favor, digite novamente.\n");

   printf("Digite 1(um) se o dia for feriado e 0(zero) se não for:");
   scanf("%d",&calendario.feriado);

   if(calendario.feriado==1)
   {
     printf("Digite o motivo do feriado (páscoa, natal e etc...):");
     fflush(stdin); //limpando o buffer do teclado, deixado pelo scanf
     gets(calendario.efemeride);
   }

   i++;
  } while (calendario.feriado <0 || calendario.feriado >1);



 /******************************** EXIBINDO OS DADOS DIGITADOS *****************************************/

  printf("\nDados digitados:\n\n");

  switch (calendario.mes)
  {

    case 1:
        nome_mes[0]='j';
        nome_mes[1]='a';
        nome_mes[2]='n';
        nome_mes[3]='\0';
        break;

    case 2:
        nome_mes[0]='f';
        nome_mes[1]='e';
        nome_mes[2]='v';
        nome_mes[3]='\0';
        break;

    case 3:
        nome_mes[0]='m';
        nome_mes[1]='a';
        nome_mes[2]='r';
        nome_mes[3]='\0';
        break;

    case 4:
        nome_mes[0]='a';
        nome_mes[1]='b';
        nome_mes[2]='r';
        nome_mes[3]='\0';
        break;

    case 5:
        nome_mes[0]='m';
        nome_mes[1]='a';
        nome_mes[2]='i';
        nome_mes[3]='\0';
        break;

    case 6:
        nome_mes[0]='j';
        nome_mes[1]='u';
        nome_mes[2]='n';
        nome_mes[3]='\0';
        break;

    case 7:
        nome_mes[0]='j';
        nome_mes[1]='u';
        nome_mes[2]='l';
        nome_mes[3]='\0';
        break;

    case 8:
        nome_mes[0]='a';
        nome_mes[1]='g';
        nome_mes[2]='o';
        nome_mes[3]='\0';
        break;

    case 9:
        nome_mes[0]='s';
        nome_mes[1]='e';
        nome_mes[2]='t';
        nome_mes[3]='\0';
        break;

    case 10:
        nome_mes[0]='o';
        nome_mes[1]='u';
        nome_mes[2]='t';
        nome_mes[3]='\0';
        break;

    case 11:
        nome_mes[0]='n';
        nome_mes[1]='o';
        nome_mes[2]='v';
        nome_mes[3]='\0';
        break;

    case 12:
        nome_mes[0]='d';
        nome_mes[1]='e';
        nome_mes[2]='z';
        nome_mes[3]='\0';
        break;
  }

 if(calendario.feriado)
 printf("%d / %s / %d - é feriado. Motivo: %s", calendario.dia, nome_mes, calendario.ano, calendario.efemeride);
 else
 printf("%d / %s / %d - não é feriado.", calendario.dia, nome_mes, calendario.ano);


 printf("\n");
 system("pause");


 }

#endif

/******************************************************************************************************/
#ifdef Ex

int main ()
{

 setlocale(LC_ALL,""); //configurando os caracteres da lingua portuguesa

 struct distancia
 {
   int dia;
   int mes;
   int ano;
 }data1, data2, troca; //primeira data que for digitada, data a ser comparada e variavel para trocas

 int i;                                                        //varivael dos laços
 int dias_data1=0;                                             //qtd de dias entre a data 0/0/0 a data 1
 int dias_data2=0;                                             //qtd de dias entre a data 0/0/0 a data 2
 int qtd_dia_mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //qtd de dias de cada mes se o ano não for bissexto
 int qtd_dia_mes2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31}; //qtd de dias de cada mes se o ano for bisssexto
 int resultado;                                                //qtd de dias entre as duas datas

 printf("Programa que, a partir de 2 datas, determina o intervalo, em dias, entre estas datas.\n\n");

 printf("Digite a primeira data conforme o exemplo ao lado (25/ 5/ 2025): ");
 scanf("%d/%d/%d",&data1.dia,&data1.mes,&data1.ano);

 printf("Agora digite a segunda data, também conforme o exemplo: ");
 scanf("%d/%d/%d",&data2.dia,&data2.mes,&data2.ano);


//! Reorganizando caso o usuário digite a primeira data mais atual que a segunda
 if(data1.ano>data2.ano)
 {
   troca=data1;
   data1=data2;
   data2=troca;
 }
 else if(data1.ano==data2.ano && data1.mes>data2.mes)
 {
   troca=data1;
   data1=data2;
   data2=troca;
 }
 else if(data1.ano==data2.ano && data1.mes==data2.mes && data1.dia>data2.dia)
 {
   troca=data1;
   data1=data2;
   data2=troca;
 }



//! Fazendo os cálculos de quantos dias se passaram da data 0/0/0 a data1

 for(i=0;i<data1.ano;i++)
{
    if((i%4==0 && i%100!=0) || i%400==0) // se o ano é bissexto
      dias_data1+=366;                   // soma-se 366
    else                                 // se não
      dias_data1+=365;                   // soma-se 365
}

 if((data1.ano%4==0 && data1.ano%100!=0) || data1.ano%400==0) // se o ano é bissexto
 {
   for(i=1;i<data1.mes;i++)      //soma-se o valor de cada mês anterior ao da data (valores definidos pelo vetor)
    dias_data1+=qtd_dia_mes2[i];

 }else{                          // se não for bissexto

   for(i=1;i<data1.mes;i++)
    dias_data1+=qtd_dia_mes[i];

 }

  dias_data1+=data1.dia;         // somando a variavel data.dia a quantidade de dias da data

//! Fazendo os cálculos de quantos dias se passaram da data 0/0/0 a data2
//(processos idênticos aos anteriores)

 for(i=0;i<data2.ano;i++)
{
    if((i%4==0 && i%100!=0) || i%400==0)
      dias_data2+=366;
    else
      dias_data2+=365;
}

 if((data2.ano%4==0 && data2.ano%100!=0) || data2.ano%400==0)
 {
   for(i=1;i<data2.mes;i++)
    dias_data2+=qtd_dia_mes2[i];

 }else{

   for(i=1;i<data2.mes;i++)
    dias_data2+=qtd_dia_mes[i];

 }

  dias_data2+=data2.dia;

//!Obtendo o resultado:

 resultado=dias_data2-dias_data1;

 printf("\n\t\tRESULTADO = %d dias.\n\n",resultado);

 system("pause");
}

#endif

/******************************************************************************************************/
