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

    cidade lista_cidades_A[T_CIDADE], lista_cidades_S[T_CIDADE], lista_cidades_T[T_CIDADE];
    curso lista_cursos_A[T_CURSO], lista_cursos_S[T_CURSO],lista_cursos_T[T_CURSO];
    turma lista_turmas_A[T_TURMA], lista_turmas_S[T_TURMA],lista_turmas_T[T_TURMA];
    aluno lista_alunos_A[T_ALUNO], lista_alunos_S[T_ALUNO],lista_alunos_T[T_ALUNO]; 
    matricula lista_matriculas_A[T_CURSO * T_ALUNO], lista_matriculas_S[T_CURSO * T_ALUNO], lista_matriculas_T[T_CURSO * T_ALUNO];

    int contS = 0, contT = 0, contA = 0;

    while (true) {
        int opcao = 0;

        //system("clear");
        cout << "OPÇÕES: [1] Adicionar cidade\n";
        cout << "        [2] Adicionar Curso\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            //system("clear")
            if (contS == 0) {
                ler_cidade_S(lista_cidades_S, contS);
            }
            else {
                ler_cidade_T(lista_cidades_T, contT);            
            }

            // cout << "lista S:\n";
            // imprimir(lista_cidades_S); cout << "\n\n";

            // cout << "Lista T:\n";
            // imprimir(lista_cidades_T); cout << "\n\n";

            incluir_cidade(lista_cidades_S, lista_cidades_T, lista_cidades_A, contS, contT);

            cout << "lista A:\n";
            imprimir(lista_cidades_A);
        
            break;
        case 2:
            system("clear");
            //ler_curso(lista_cursos_A, lista_cursos_T, lista_cursos_S);
        default:
            break;
         }
    }
}