# Lista-de-Exercicios-Structs
Lista de exercícios sobre structs - Cadeira de introdução a linguagem C - Fundação Liberato

1. Um projeto de caderno de chamada eletrônico especifica o armazenamento das informações dos alunos em estruturas com os seguintes dados:
* Matricula (inteiro sem sinal)
* Nome do aluno (string)
* Notas de 3 trimestrais (float)
* Resultado anual (float)
* Conceito (char)

Elabore um programa que:
* a) Construa (declare) a estrutura que represente a organização proposta. Crie uma variável deste tipo.
* b) Codifique a entrada de dados para a variável.
* c) O resultado é definido como sendo a média ponderada com pesos 25, 35 e 40, respectivamente.

O conceito é dado em função do resultado: </br>
\>= 9   -> A </br>
\>= 7,5 -> B </br>
\>= 6   -> C </br>
<6     -> R

Elabore as rotinas de cálculo do resultado e conceito.

* d) Exiba o resultado obtido pelo aluno.

2. Em um determinado sistema de informática, as datas do calendário são representadas
pela estrutura abaixo </br>
struct dma </br>
{ </br>
int dia; // dia do mes </br>
int mes; // mes </br>
int ano; // ano </br>
int feriado; // 0 – não é feriado, 1 - feriado </br>
char efemeride[50]; // qual motivo do feriado </br>
}; </br>
Desenvolva um programa que :
* a. Contenha uma variável do tipo estrutura dma
* b. Uma rotina de entrada de dados que preencha esta variável, considerando o número de dias de cada mês e a possibilidade do ano ser bissexto. Considere que as datas correspondem aos séculos 20 e 21. O campo efemeride só deve ser preenchido se necessário.
* c. Uma rotina que exiba o conteúdo da variável tipo struct dma como apresentado no exemplo abaixo:

25/dez/2020 é feriado : Natal

3. Utilizando como base o código desenvolvido no exercicio 2, elabore um programa que, a
partir de 2 datas, determine o intervalo, em dias, entre estas datas.

4. Um censo demográfico visa mapear a distribuição das características físicas da população
nos bairros da cidade. Para cada entrevistado serão coletados os seguintes dados:
* idade
* sexo (M e F)
* cor dos olhos (A – azul, V – verde, C – castanho)
* cor do cabelo (L – loiro, C – castanho, P – preto)

Declare um tipo de variável capaz de armazenar as informações desejadas.
Declare um array deste tipo de variáveis para armazenar os resultados das pesquisas. Minimo
de 10 elementos.
Elabore uma rotina de entrada de dados. A quantidade de indivíduos pesquisada só é conhecida
no momento da entrada de dados. Construa a entrada de dados de tal forma que seja possível
interromper e retomar o processo.
Elabore rotinas para gerar o relatório final da pesquisa, contendo as seguintes informações :
* Numero de indivíduos pesquisados.
* Média de idade geral e por sexo.
* Distribuição das caracteristicas fisicas na população, em geral e por sexo.

Sugestão : Construa uma interface com o usuário através de um menu de opções.
