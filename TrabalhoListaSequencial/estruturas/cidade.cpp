// cidade.cpp
#define T_CIDADE 20

struct cidade {
    int codigo;
    string nome;
    char estado[2];
};

// Funções de cidade

void incluir_cidade(cidade lista_cidades_S[T_CIDADE], cidade lista_cidades_T[T_CIDADE], cidade lista_cidades_A[T_CIDADE]) {

    int i = 0, j = 0, k = 0;
    //  S      T      A

    while (i < T_CIDADE && j < T_CIDADE) {
        
        if (lista_cidades_S[i].codigo < lista_cidades_T[j].codigo) {
            lista_cidades_A[k] = lista_cidades_S[i];
            i++;
        }
        else {
            lista_cidades_A[k] = lista_cidades_T[j];
            j++;
        }

        k++;
    }

    while (i < T_CIDADE) {
        lista_cidades_A[k] = lista_cidades_S[i];
        k++;
        i++;
    }

    while (j < T_CIDADE) {
        cout << "eu tenteii\n";
        lista_cidades_A[k] = lista_cidades_T[j];
        j++;
        k++;
    }
}

void ler_cidade(cidade lista_cidades_S[T_CIDADE], cidade lista_cidades_T[T_CIDADE], cidade lista_cidades_A[T_CIDADE], int &cont) {
    
    int controle = 0;
    int i = cont;
    
    cout << "\n-----Leitura Cidade-----";

    for (; i < T_CIDADE; i++) {
       
        cout << "\nDigite o código: ";
        cin >> lista_cidades_T[i].codigo;
        cin.ignore();

        cout << " Digite o nome: ";
        getline(cin, lista_cidades_T[i].nome);

        cout << "  Digite o UF: ";
        cin >> lista_cidades_T[i].estado;

        cout << "\nDeseja adicionar mais uma cidade?\n(0 = N) (1 = S)\n";
        cin >> controle;

        cont++;

        if (controle == 0)
            break;
    }


    incluir_cidade(lista_cidades_S, lista_cidades_T, lista_cidades_A);
}

void imprimir(cidade lista_cidades[T_CIDADE]) {

    for (int i = 0; i < T_CIDADE; i++) {
        cout << lista_cidades[i].codigo << " \n";
    }
}