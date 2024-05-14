//instrutor.cpp
#define T_INSTRUTOR 5
#include "./cidade.cpp";

struct instrutor {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

// Funções de instrutor
// Primeira leitura
void ler_instrutor_S(instrutor lista_instrutores_S, int &contS_instrutor) {

    int controle = 0;

    for (int i = 0; i < T_INSTRUTOR;) {

        instrutor instrutor_controle;
        bool codigo_duplicado = false;

        cout << "---- Ler Instrutor ----\n";

        cout << "Digite o código do instrutor: ";
        cin >> instrutor_controle.codigo;
        cin.ignore();

        // Verificação para ver se o usuário não está digitando um mesmo código já digitado
        if (i != 0) {

            for (int j = 0; j < T_INSTRUTOR; j++) {

                if (instrutor_controle.codigo == lista_instrutores_S[j].codigo) {

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite o nome do instrutor: ";
        getline(cin, instrutor_controle.nome);

        cout << " Digite seu endereço: ";
        getline(cin, instrutor_controle.endereco);

        cout << " Digite o código da cidade: ";
        

    }
}