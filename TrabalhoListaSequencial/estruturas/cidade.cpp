// cidade.cpp
#define T_CIDADE 20

struct cidade {
    int codigo;
    string nome;
    char estado[2];
};

// Funções de Cidade
void incluir_cidade(cidade lista_cidades_S[],
                    cidade lista_cidades_T[],
                    cidade lista_cidades_A[],
                    int &contS,
                    int &contT,
                    int &contA) {

    int i = 0, j = 0, k = 0;

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

    while (i < contS) {
    
        lista_cidades_A[k] = lista_cidades_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_cidades_A[k] = lista_cidades_T[j];
        j++;
        k++;
    }

    contA = k;
}

// Imprimir
void listar_cidades(cidade lista_cidades[], int contA_cidade) {

    if (contA_cidade == 0) {
        cout << "\n NÃO há cidades adicionadas!\n";
    }
    else {

        cout << "\n\nCidades adicionadas: " << contA_cidade;
        cout << "\nCidades restantes  : " << (T_CIDADE - contA_cidade) << "\n";

        for (int i = 0; i < contA_cidade; i++) {
            cout << "\nCódigo: " << lista_cidades[i].codigo;
            cout << "\n Nome: " << lista_cidades[i].nome;
            cout << "\n  Estado: " << lista_cidades[i].estado << "\n";
        }
    }
}

int validate_cidade(cidade lista_cidades_S[], int contA, int codigo_procurado) {
    
    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_cidades_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_cidades_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

// Buscar cidade
void buscar_cidade(cidade lista_cidades[], int contA) {

    int cidade_procurada;
    int indice_cidade;
  
    cout << "Digite o código da cidade: ";
    cin >> cidade_procurada;

    indice_cidade = validate_cidade(lista_cidades, contA, cidade_procurada);

    if (indice_cidade != -1) {

        cout << "\nCidade encontrada! \n";

        cout << "\nCódigo: " << lista_cidades[indice_cidade].codigo;
        cout << "\nNome  : " << lista_cidades[indice_cidade].nome;
        cout << "\nEstado: " << lista_cidades[indice_cidade].estado << "\n";
    }
    else {
        cout << "\nCidade NÃO encontrada!\n";
    }
}

// Primeira leitura
void ler_cidade_S(cidade lista_cidades_S[], int &contS) {
    
    int controle = 0;
   
    for (int i = 0; i < T_CIDADE;) {
        
        cidade cidade_controle;
        int is_duplicado;

        cout << "---- Ler Cidade ----\n";

        cout << "Digite o código da cidade: ";
        cin >> cidade_controle.codigo;
        cin.ignore();

        is_duplicado = validate_cidade(lista_cidades_S, contS, cidade_controle.codigo);

        if (is_duplicado != -1) {
            
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        }

        cout << "Digite o nome da cidade  : ";
        getline(cin, cidade_controle.nome);

        cout << "Digite o UF              : ";
        cin >> cidade_controle.estado;

        lista_cidades_S[contS] = cidade_controle;

        cout << "\nDeseja adicionar mais uma cidade: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS++;
        i++;

        if (controle == 0) break;
    }
}

// Demais leituras
void ler_cidade_T(cidade lista_cidades_T[],
                  cidade lista_cidades_S[],
                  int &contT,
                  int contS) {
    
    int i = 0;
    contT = 0;
    int controle = 0;

    for (; i < T_CIDADE;) {

        if (contS == T_CIDADE) {

            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais cidades!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        cidade cidade_controle;
        int is_duplicado;

        cout << "---- Ler Cidade ----\n";

        cout << "Digite o código da cidade: ";
        cin >> cidade_controle.codigo;
        cin.ignore();
   
        is_duplicado = validate_cidade(lista_cidades_S, contS, cidade_controle.codigo);
        is_duplicado += validate_cidade(lista_cidades_T, contT, cidade_controle.codigo);

        if (is_duplicado >= -1) {
            
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        }

        cout << "Digite o nome da cidade  : ";
        getline(cin, cidade_controle.nome);

        cout << "Digite o UF              : ";
        cin >> cidade_controle.estado;

        lista_cidades_T[i] = cidade_controle;

        cout << "\nDeseja adicionar mais uma cidade: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS++;
        contT++;
        i++;

        if (controle == 0) break;
    }
}

void arquivoA_passa_arquivoS_cidade(cidade lista_cidades_A[T_CIDADE],
                                    cidade lista_cidades_S[T_CIDADE],
                                    int &contS,
                                    int contA) {

    for (int i = 0; i < contA; i++) {
        lista_cidades_S[i] = lista_cidades_A[i];
    }

    contS = contA;
}