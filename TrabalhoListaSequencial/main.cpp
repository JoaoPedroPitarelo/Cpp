// main.cpp
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

// Arquivo de inclusões
#include "./include.cpp"

// Protótipos de funções
void inicioPrograma();

int main() {

    inicioPrograma();
}


void inicioPrograma() {

    int contS_cidade = 0, contT_cidade = 0, contA_cidade = 0;
    int contS_curso = 0, contT_curso = 0, contA_curso = 0;

    cidade lista_cidades_S[T_CIDADE];
    curso lista_cursos_S[T_CURSO];
    turma lista_turmas_S[T_TURMA];
    aluno lista_alunos_S[T_ALUNO]; 
    matricula lista_matriculas_S[T_CURSO * T_ALUNO];

    while (true) {
        int opcao;
        string pause = " ";

        cidade lista_cidades_T[T_CIDADE] = {}; cidade lista_cidades_A[T_CIDADE] = {};
        curso lista_cursos_T[T_CURSO] =    {}; curso lista_cursos_A[T_CURSO] =    {};
        turma lista_turmas_T[T_TURMA] =    {}; turma lista_turmas_A[T_TURMA] =    {};
        aluno lista_alunos_T[T_ALUNO] =    {}; aluno lista_alunos_A[T_ALUNO] =    {};
        matricula lista_matriculas_T[T_CURSO * T_ALUNO] = {};  matricula lista_matriculas_A[T_CURSO * T_ALUNO] = {};

        system("clear");
        cout << "OPÇÕES: [1] Adicionar cidade [11] Listar cidades\n";
        cout << "        [2] Adicionar Curso  [22] Listar cursos\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            system("clear");
            if (contS_cidade == 0) {
                ler_cidade_S(lista_cidades_S, contS_cidade);
            }
            else {
                ler_cidade_T(lista_cidades_T, lista_cidades_S, contT_cidade, contS_cidade);          
            }

            incluir_cidade(lista_cidades_S, lista_cidades_T, lista_cidades_A, contS_cidade, contT_cidade, contA_cidade);
            arquivoA_passa_arquivoS_cidade(lista_cidades_A, lista_cidades_S, contS_cidade, contA_cidade);
            break;

        case 11:
            system("clear");
            listar_cidades(lista_cidades_S, contA_cidade);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        case 2:
            system("clear");
            if (contS_curso == 0) {
                ler_curso_S(lista_cursos_S, contS_curso);
            }
            else {
                ler_curso_T(lista_cursos_S, lista_cursos_T, contT_curso, contS_curso);
            }

            incluir_curso(lista_cursos_S, lista_cursos_T, lista_cursos_A, contS_curso, contT_curso, contA_curso);
            arquivoA_passa_arquivoS_curso(lista_cursos_A, lista_cursos_S, contS_curso, contA_curso);
            break;

        case 22:
            system("clear");
            listar_cursos(lista_cursos_S, contA_curso);
                
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        }
    }
}