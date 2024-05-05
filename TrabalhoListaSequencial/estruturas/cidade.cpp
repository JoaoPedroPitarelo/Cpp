// cidade.cpp
#define T_CIDADE 20

struct cidade {
    int codigo;
    string nome;
    char estado[2];
};

// Funções de Cidade

void incluir_cidade(cidade lista_cidades_S[T_CIDADE], cidade lista_cidades_T[T_CIDADE], cidade lista_cidades_A[T_CIDADE], int &contS, int &contT) {

    int i = 0, j = 0, k = 0;
    //  S      T      A

    cout << "contT = " << contT;
    cout << "contS = " << contS;
    while (i < contS && j < contT) {
        
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

    cout << "\n K = " << k;

    cout << "\n i = " << i << "\n";
    while (i < contS) {
        cout << "\n K = " << k;
        lista_cidades_A[k] = lista_cidades_S[i];
        i++;
        k++;
    }

    cout << "\n j = " << j << "\n";
    while (j < contT) {
        lista_cidades_A[k] = lista_cidades_T[j];
        j++;
        k++;
    }
}

// Ordenar arquivo
void ordenar_arquivo(cidade lista_cidades[], int cont) {
    for (int i = cont; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lista_cidades[j].codigo > lista_cidades[j + 1].codigo) {
                cidade aux = lista_cidades[j+1];
                lista_cidades[j+1] = lista_cidades[j];
                lista_cidades[j] = aux;
            }
        }
    }
}

// Imprimir
void imprimir(cidade lista_cidades[T_CIDADE]) {

    for (int i = 0; i < T_CIDADE; i++) {
        cout << lista_cidades[i].codigo << " \n";
    }
}

// Primeira leitura
void ler_cidade_S(cidade lista_cidades_S[], int &contS) {
    
    int controle = 0;

    for (int i = 0; i < T_CIDADE; i++) {
        cout << "---- Ler Cidade - Primeira Leitura ----\n";

        cout << "Digite o código da cidade: ";
        cin >> lista_cidades_S[contS].codigo;
        cin.ignore();

        cout << " Digite o nome da cidade: ";
        getline(cin, lista_cidades_S[contS].nome);

        cout << "  Digite o UF: ";
        cin >> lista_cidades_S[contS].estado;

        cout << "\nDeseja adicionar mais uma cidade: (0 = NAO) (1 = SIM)";
        cin >> controle;

        contS++;

        if (controle == 0)
            break;
    }

    // Ordenação do arquivoS - BubleSort
    ordenar_arquivo(lista_cidades_S, (contS - 1));
}

// Demais leituras
void ler_cidade_T(cidade lista_cidades_T[], int &contT) {
    
    int i = 0;
    contT = 0;
    int controle = 0;

    for (; i < T_CIDADE; i++) {
        cout << "---- Ler Cidade ----\n";

        cout << "Digite o código da cidade: ";
        cin >> lista_cidades_T[i].codigo;
        cin.ignore();

        cout << " Digite o nome da cidade: ";
        getline(cin, lista_cidades_T[i].nome);

        cout << "  Digite o UF: ";
        cin >> lista_cidades_T[i].estado;

        cout << "\nDeseja adicionar mais uma cidade: (0 = NAO) (1 = SIM)";
        cin >> controle;

        contT++;

        if (controle == 0)
            break;
    }

    // Ordenação do arquivoT - BubleSort
    ordenar_arquivo(lista_cidades_T, (contT - 1));
}

void arquivoA_passa_arquivoS(cidade lista_cidades_A[T_CIDADE], cidade lista_cidades_S[T_CIDADE]) {
    
    for (int i = 0; i < T_CIDADE; i++) {
        cout << "\nLista s :" << i << " = " << lista_cidades_S[i].codigo;
        lista_cidades_S[i] = lista_cidades_A[i];

        cout << "\nLista s :" << i << " = " << lista_cidades_S[i].codigo << "\n";
    }
}