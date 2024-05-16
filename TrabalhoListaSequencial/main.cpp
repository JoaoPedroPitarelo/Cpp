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

    cidade lista_cidades_S[T_CIDADE];
    curso lista_cursos_S[T_CURSO];
    turma lista_turmas_S[T_TURMA];
    instrutor lista_instrutores_S[T_INSTRUTOR];
    aluno lista_alunos_S[T_ALUNO]; 
    matricula lista_matriculas_S[T_CURSO * T_ALUNO];

    int contS_cidade = 0, contT_cidade = 0, contA_cidade = 0;
    int contS_curso = 0, contT_curso = 0, contA_curso = 0;
    int contS_instrutor = 0, contT_instrutor = 0, contA_instrutor = 0; 

    while (true) {

        cidade lista_cidades_T[T_CIDADE] = {}; cidade lista_cidades_A[T_CIDADE] = {};
        curso lista_cursos_T[T_CURSO] =    {}; curso lista_cursos_A[T_CURSO] =    {};
        turma lista_turmas_T[T_TURMA] =    {}; turma lista_turmas_A[T_TURMA] =    {};
        instrutor lista_instrutores_T[T_INSTRUTOR] = {}; instrutor lista_instrutores_A[T_INSTRUTOR] = {}; 
        aluno lista_alunos_T[T_ALUNO] =    {}; aluno lista_alunos_A[T_ALUNO] =    {};
        matricula lista_matriculas_T[T_CURSO * T_ALUNO] = {};  matricula lista_matriculas_A[T_CURSO * T_ALUNO] = {};

        int opcao;
        string pause = " ";

        // "Interface"
        system("clear");
        cout << "OPÇÕES: [1] Adicionar cidade    [11] Buscar cidade\n";
        cout << "        [2] Adicionar Curso     [22] Listar cursos\n";
        cout << "        [3] Adicionar Instrutor [33] Listar instrutor\n";
        

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
        
        case 3:
            system("clear");
            if (contS_instrutor == 0) {
                ler_instrutor_S(lista_instrutores_S, contS_instrutor, lista_cidades_S, contA_cidade);
            }
            else {
                ler_instrutor_T(lista_instrutores_S, lista_instrutores_T, contT_instrutor, contS_instrutor, lista_cidades_S, contA_cidade);
            }

            incluir_instrutor(lista_instrutores_S, lista_instrutores_T, lista_instrutores_A, contS_instrutor, contT_instrutor, contA_instrutor);
            arquivoA_passa_arquivoS_instrutor(lista_instrutores_A, lista_instrutores_S, contS_instrutor, contA_instrutor);
            break;

        case 33:
            system("clear");
            listar_instrutores(lista_instrutores_S, contA_instrutor);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

       
    }
}