#include <iostream>
#include <locale.h>
using namespace std;

#include "./define.cpp"
#include "./estruturas/cidade.cpp"
#include "./estruturas/turma.cpp"
#include "./estruturas/curso.cpp"





// Protótipos de funções
void inicioPrograma();



int main() {

    

}


void inicioPrograma() {

    cidade lista_cidades[T_CIDADE];
    turma lista_turmas[T_TURMAS];


    while (true) {
        int opcao = 0;

        cout << "OPÇÕES: [1] - Adicionar cidade [2] - Adicionar Turma\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            ler_cidade(lista_cidades);
            break;
        case 2:
            // ler_turmas(lista_turmas)
        default:
            break;
         }
    }

}