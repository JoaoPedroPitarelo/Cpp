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

// Buscar cidade
void buscar_cidade(cidade lista_cidades[], int contA) {

    int inicio = 0;
    int fim = contA;
    int meio = ((inicio + fim) / 2);
    int cidade_procurada;
    bool cidade_encontrada = false;

    cout << "Digite o código da cidade: ";
    cin >> cidade_procurada;


    for (int i = 0; i < contA; i++) {
    
        // Encotrou a cidade
        if (cidade_procurada == lista_cidades[i].codigo) {
            cout << "\nCidade encontrada! \n";

            cout << "\nCódigo: " << lista_cidades[i].codigo;
            cout << "\nNome  : " << lista_cidades[i].nome;
            cout << "\nEstado: " << lista_cidades[i].estado << "\n";
            
            cidade_encontrada = true;
        }

        // // Caso não exista o código da cidade
        // if (inicio == fim) {
        //     cidade_encontrada = false;
        // }

        if (cidade_procurada > lista_cidades[meio].codigo) {
          
            inicio = meio + 1;
            meio = ((inicio + fim) / 2);
            continue;
        }

        if (cidade_procurada < lista_cidades[meio].codigo) {
            
            fim = meio -1;
            meio = ((inicio + fim) / 2);
            continue;
        }
    }

    if (!cidade_encontrada) 
        cout << "\nCidade NÃO encontrada!\n";
}

// Primeira leitura
void ler_cidade_S(cidade lista_cidades_S[], int &contS) {
    
    int controle = 0;
   
    for (int i = 0; i < T_CIDADE;) {
        
        cidade cidade_controle;
        bool codigo_duplicado = false;

        cout << "---- Ler Cidade ----\n";

        cout << "Digite o código da cidade: ";
        cin >> cidade_controle.codigo;
        cin.ignore();

        // Verifição para ver se o usuário não está digitando um mesmo código já adicionado
        if (i != 0) {

            for (int j = 0; j < contS; j++) {

                if (cidade_controle.codigo == lista_cidades_S[j].codigo) {
                    
                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

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
        bool codigo_duplicado = false;

        cout << "---- Ler Cidade ----\n";

        cout << "Digite o código da cidade: ";
        cin >> cidade_controle.codigo;
        cin.ignore();
   
        // Verifição para ver se o usuário não está digitando um mesmo código já adicionado
        for (int j = 0; j < (contT + contS); j++) {
            
            if (cidade_controle.codigo == lista_cidades_S[j].codigo ||
                cidade_controle.codigo == lista_cidades_T[j].codigo) {

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }
        
        if (codigo_duplicado) continue;


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