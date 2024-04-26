#include "../defines.cpp"
// cidade.cpp
struct cidade {
    int codigo;
    string nome;
    char estado[2];
    bool cont = false; // Para testar se já foi lido a cidade | caso sim pule | caso não leia 
};

// Funções de cidade
void ler_cidade(cidade lista_cidades[]) {
    cout << "-----Leitura Cidade-----";

    for (int i = sizeof lista_cidades; i < t_cidade; i++) {
       
       
        cout << "\nDigite o código: ";
        cin >> lista_cidades.codigo;
        cin.ignore();

        cout << " Digite o nome: ";
        getline(cin, lista_cidades.nome);

        cout << "  Digite o UF: ";
        cin >> lista_cidades.estado;
    }
}