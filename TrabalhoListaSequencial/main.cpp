// main.cpp
#include <iostream>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
using namespace std;

// Arquivo de inclusões
#include "./include.cpp"


// Protótipos de funções
void inicioPrograma();

int main() {

    // Definir acentuação
    setlocale(LC_ALL, "pt-br");   
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
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
    int contS_aluno = 0, contT_aluno = 0, contA_aluno = 0;
    int contS_turma = 0, contT_turma = 0, contA_turma = 0;
    int contS_matricula = 0, contT_matricula = 0, contA_matricula;

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
        system("cls");

        cout << "_______________Empresa de treinamentos_______________\n\n";

        cout << "______________________OPÇÕES_________________________\n";
        cout << "| [1] Adicionar Cidade    [12] Buscar cidade        |\n";
        cout << "| [2] Adicionar Curso     [22] Listar cursos        |\n";
        cout << "| [3] Adicionar Instrutor [32] Listar instrutores   |\n";
        cout << "| [4] Adicionar Aluno     [42] Excluir aluno        |\n";
        cout << "| [5] Adicionar Turma     [52] Listar turmas cheias |\n";
        cout << "|                         [53] Buscar turma         |\n";
        cout << "| [6] Adicionar Matricula [62] Listar matriculas    |\n";
        cout << "-----------------------------------------------------\n";

        cout << "\nEscolha: ";
        cin >> opcao;

        switch (opcao) {
        // Cidade -------------------
        case 1:
            system("cls");
            if (contS_cidade == 0) {
                ler_cidade_S(lista_cidades_S, contS_cidade);
            }
            else {
                ler_cidade_T(lista_cidades_T, lista_cidades_S, contT_cidade, contS_cidade);          
            }

            incluir_cidade(lista_cidades_S, lista_cidades_T, lista_cidades_A, contS_cidade, contT_cidade, contA_cidade);
            arquivoA_passa_arquivoS_cidade(lista_cidades_A, lista_cidades_S, contS_cidade, contA_cidade);
            break;

        case 12:
            system("cls");

            buscar_cidade(lista_cidades_S, contA_cidade);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        // Curso -------------------
        case 2:
            system("cls");
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
            system("cls");
            listar_cursos(lista_cursos_S, contA_curso);
                
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        // Instrutor -------------------
        case 3:
            system("cls");
            if (contS_instrutor == 0) {
                ler_instrutor_S(lista_instrutores_S, contS_instrutor, lista_cidades_S, contA_cidade);
            }
            else {
                ler_instrutor_T(lista_instrutores_S, lista_instrutores_T, contT_instrutor, contS_instrutor, lista_cidades_S, contA_cidade);
            }

            incluir_instrutor(lista_instrutores_S, lista_instrutores_T, lista_instrutores_A, contS_instrutor, contT_instrutor, contA_instrutor);
            arquivoA_passa_arquivoS_instrutor(lista_instrutores_A, lista_instrutores_S, contS_instrutor, contA_instrutor);
            break;

        case 32:
            system("cls");
            listar_instrutores(lista_instrutores_S, contA_instrutor);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        // Aluno -------------------
        case 4:
            system("cls");
            if(contS_aluno == 0) {
                ler_aluno_S(lista_alunos_S, contS_aluno, lista_cidades_S, contA_cidade);
            }
            else {
                ler_aluno_T(lista_alunos_S, lista_alunos_T, contT_aluno, contS_aluno, lista_cidades_S, contA_cidade);
            }

            incluir_aluno(lista_alunos_S, lista_alunos_T, lista_alunos_A, contS_aluno, contT_aluno, contA_aluno);
            arquivoA_passa_arquivoS_aluno(lista_alunos_A, lista_alunos_S, contS_aluno, contA_aluno);
            break;

        case 42:
            system("cls");

            excluir_aluno(lista_alunos_S, lista_alunos_A, contA_aluno, contS_aluno);
            listar_alunos(lista_alunos_S, contA_aluno);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);

            break;

        // Turma -------------------
        case 5:
            system("cls");
            if(contS_turma == 0) {
                ler_turma_S(lista_turmas_S, lista_cursos_S,lista_instrutores_S, lista_cidades_S, contS_turma, contA_curso, contA_instrutor, contA_cidade);
            }
            else {
                ler_turma_T(lista_turmas_S, lista_turmas_T, lista_cursos_S, lista_instrutores_S, lista_cidades_S, contT_turma, contS_turma, contA_curso, contA_instrutor, contA_cidade);
            }

            incluir_turma(lista_turmas_S, lista_turmas_T, lista_turmas_A, contS_turma, contT_turma, contA_turma);
            arquivoA_passa_arquivoS_turma(lista_turmas_A, lista_turmas_S, contS_turma, contA_turma);

            break;

        case 52: 
            system("cls");

            listar_turmas_completas(lista_turmas_S, lista_instrutores_S, lista_cursos_S, lista_cidades_S, contA_turma, contA_instrutor, contA_curso, contA_cidade);
            
            cout << "\n\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        case 53:
            system("cls");

            buscar_turma(lista_turmas_S, lista_cursos_S, lista_instrutores_S, lista_cidades_S, contA_turma, contA_curso, contA_instrutor, contA_cidade);

            cout << "\n\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);

            break;
        // Matricula --------------------
        case 6:
            system("cls");
            if (contS_matricula == 0) {
                ler_matricula_S(lista_matriculas_S, lista_alunos_S, lista_turmas_S, lista_cursos_S, lista_instrutores_S, lista_cidades_S, contS_matricula, contA_aluno, contA_turma, contA_curso, contA_instrutor, contA_cidade);
            }
            else {
                ler_matricula_T(lista_matriculas_S, lista_matriculas_T, lista_alunos_S, lista_turmas_S, lista_cursos_S, lista_instrutores_S, lista_cidades_S, contT_matricula, contS_matricula, contA_aluno, contA_turma, contA_curso, contA_instrutor, contA_cidade);
            }

            incluir_matricula(lista_matriculas_S, lista_matriculas_T, lista_matriculas_A, contS_matricula, contT_matricula, contA_matricula);
            arquivoA_passa_arquivoS_matricula(lista_matriculas_A, lista_matriculas_S, contS_matricula, contA_matricula);

            break;
        case 62:
            system("cls");

            listar_matriculas(lista_matriculas_S, lista_alunos_S, lista_cursos_S, lista_instrutores_S, lista_turmas_S, contA_matricula, contA_aluno, contA_curso, contA_instrutor, contA_turma);
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }
    }
}