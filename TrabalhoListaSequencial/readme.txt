Trabalho 2 ADS - T1 - Data de entrega: 03/06/2024

Escreva um programa para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de gerenciamento para uma empresa de Treinamentos:

Cidades: código, nome, UF

Cursos: código, descrição, valor_por_aula

Instrutores: código, nome, endereço, codigo_cidade

Alunos: código, nome, endereço, codigo_cidade

Turmas: código, código_curso, código_instrutor, total_participantes, quant_max_participantes

Matrículas: código, código_aluno, código_turma, quantidade_aulas, valor_total


[x] 1) Escreva funções específicas para a leitura dos dados das estruturas: Cidades, Cursos.

[x] 2) Escreva uma função para permitir a inclusão de novos registros na tabela de Instrutores.

[x] 2.1) O programa deverá garantir que o código do instrutor a ser inserido não existe na tabela de Instrutores.

[x] 2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF.

[x] 3) Escreva uma função para permitir a inclusão de novos registros na tabela de Alunos.

[x] 3.1) O programa deverá garantir que o código do aluno a ser inserido não existe na tabela de Alunos.
 
[x] 3.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e UF.

[] 4) Escreva uma função para permitir a exclusão de registros na tabela de Alunos.

[] 5) Escreva uma função para permitir a inclusão de novos registros na tabela de Turmas.
 
[] 5.1) Quando o usuário digitar o código_curso, o programa deverá buscar este código na tabela de Cursos e exibir a descrição e o valor por aula.

[] 5.2) Quando o usuário digitar o código_instrutor, o programa deverá buscar este código na tabela de Instrutores e exibir o nome do instrutor e o nome da cidade onde mora o intrutor.
 
[] 6) Escreva uma função para permitir a inclusão de novos registros na tabela de Matrículas.

[] 6.1) Quando o usuário digitar o código_aluno, o programa deverá buscar este código na tabela de Alunos e exibir seu nome e o nome da sua cidade.
 
[] 6.2) Quando o usuário digitar o código_turma, o programa deverá buscar este código na tabela de Turmas e exibir a descrição do curso, o nome do instrutor e o valor por aula.

[] 6.3) Quando o usuário digitar quantidade_aulas, o programa deverá mostrar o valor total a ser pago, que deverá ser calculado pela multiplicação da quantidade_aulas pelo valor_por aula do curso. 
 
[] 6.4) O total_participantes deverá ser adicionado em mais um participante. 
 
[] 6.4.1) O programa não deverá permitir que o total_participantes seja maior do que quant_max_participantes.

[] 6.5) O programa deverá calcular e exibir o valor total a ser pago pelo aluno e gravar essa informação em valor_total na tabela Matrículas.

[] 7) Escreva uma função para permitir ao usuário consultar os dados de determinada turma.
 
[] 7.1) Para cada turma consultada, exibir: nome do curso, nome do instrutor, nome da cidade do instrutor, total de participantes.
 
[] 8) Escreva uma função para exibir todos as Turmas que estejam completas (total_participantes = quant_max_participantes). 
 
[] 8.1) As seguintes informações devem ser exibidas: código da turma, nome do curso, nome do instrutor, nome da cidade do instrutor, total_participantes, quant_max_participantes.
 
[] 9) Escreva uma função para exibir todos os registros da tabela Matrículas.
 
[] 9.1) As seguintes informações devem ser exibidas: código, nome do aluno, nome do curso, nome do instrutor, valor total arrecadado (quantidade_aulas * valor_por_aula do curso).

Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().

Obs: não utilizar variáveis globais.