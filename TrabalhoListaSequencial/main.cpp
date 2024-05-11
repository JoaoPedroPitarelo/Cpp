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
        cout << "        [2] Adicionar Curso\n";
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
            arquivoA_passa_arquivoS(lista_cidades_A, lista_cidades_S, contS_cidade, contA_cidade);
            break;

        case 11:
            system("clear");
            listar_cidades(lista_cidades_S, contA_cidade);

            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;

        case 111:
            system("clear");
            int codigo_cidade_procurada = 0;

            cout << "\n Digite o código da cidade procurada: ";
            cin >> codigo_cidade_procurada;

            int resultado_busca = buscar_cidade(lista_cidades_S, codigo_cidade_procurada, contA_cidade);

            if (resultado_busca != -1) {
                
                cout << "\nENCONTRADA!\n";

                cout << "\nCódigo: " << lista_cidades_S[resultado_busca].codigo;
                cout << "\n Nome: " << lista_cidades_S[resultado_busca].nome;
                cout << "\n  Estado: " << lista_cidades_S[resultado_busca].estado << "\n";

                cout << "\n Pressione qualquer tecla para continuar: \n";
                cin.ignore();
            getline(cin, pause);
            } else {

                cout << "\n Cidade NÃO ENCONTRADA!\n";
                cout << "\n Pressione qualquer tecla para continuar: \n";
                cin.ignore();
                getline(cin, pause);
            }
            break;
        }
    }
}