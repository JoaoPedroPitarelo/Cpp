// cidade.cpp
#include "../define.cpp"

struct cidade {
    int codigo;
    string nome;
    char estado[2];
    bool cont = false; // Para testar se já foi lido a cidade | caso sim pule | caso não leia 
};

// Funções de cidade
void ler_cidade(cidade lista_cidades[T_CIDADE]) {
    
    int controle = 0;
    
    cout << "-----Leitura Cidade-----";

    for (int i = 0; i < T_CIDADE; i++) {
       
       if (lista_cidades[i].cont == true) {
            continue;
       }

        cout << "\nDigite o código: ";
        cin >> lista_cidades[i].codigo;
        cin.ignore();

        cout << " Digite o nome: ";
        getline(cin, lista_cidades[i].nome);

        cout << "  Digite o UF: ";
        cin >> lista_cidades[i].estado;


        cout << "\nDeseja adicionar mais uma cidade? (0 = N) (1 = S)\n";
        cin >> controle;

        if (controle == 0)
            break;
    }
}