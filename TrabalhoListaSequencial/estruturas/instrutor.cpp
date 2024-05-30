//instrutor.cpp
#define T_INSTRUTOR 5

struct instrutor {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

// Funções de instrutor
void incluir_instrutor(instrutor lista_instrutores_S[],
                       instrutor lista_instrutores_T[],
                       instrutor lista_instrutores_A[],
                       int &contS,
                       int &contT,
                       int &contA) {

    int i = 0, j = 0, k = 0;

    while(i < contS && j < contT) {

        if (lista_instrutores_S[i].codigo < lista_instrutores_T[j].codigo) {

            lista_instrutores_A[k] = lista_instrutores_S[i];
            i++;
        }
        else {

            lista_instrutores_A[k] = lista_instrutores_T[j];
            j++; 
        }

        k++;
    }

    while (i < contS) {
        
        lista_instrutores_A[k] = lista_instrutores_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_instrutores_A[k] = lista_instrutores_T[j];
        j++;
        k++;
    }

    contA = k;
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

void listar_instrutores(instrutor lista_instrutores[], int contA_instrutor) {

    if (contA_instrutor == 0) {
        cout << "NÃO há instrutores adicionados!\n";
    }
    else {

        cout << "Instrutores adicionados : " << contA_instrutor;
        cout << "\nIstrutores restantes    : " << (T_INSTRUTOR - contA_instrutor) << "\n";

        for (int i = 0; i < contA_instrutor; i++) {
            cout << "\nCódigo          : " << lista_instrutores[i].codigo;
            cout << "\nNome            : " << lista_instrutores[i].nome;
            cout << "\nEndereço        : " << lista_instrutores[i].endereco;
            cout << "\nCódigo da cidade: " << lista_instrutores[i].codigo_cidade << "\n";
        }
    }
}

// Primeira leitura
void ler_instrutor_S(instrutor lista_instrutores_S[],
                     int &contS_instrutor,
                     cidade lista_cidades_S[],
                     int contA_cidade) {

    int controle = 0;

    for (int i = 0; i < T_INSTRUTOR;) {

        // Caso não haja cidades adicionadas
        if (!contA_cidade) {

            string pause = " ";
            cout << " É necessário ADICIONAR cidades PRIMEIRO!";
            cout << "\n\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        instrutor instrutor_controle;
        bool codigo_duplicado = false;
        bool cidade_valida = false;

        cout << "---- Ler Instrutor ----\n";

        cout << "Digite o código do instrutor: ";
        cin >> instrutor_controle.codigo;
        cin.ignore();

        // Verificação para ver se o usuário não está digitando um mesmo código já digitado
        if (i != 0) {

            for (int j = 0; j < contS_instrutor; j++) {

                if (instrutor_controle.codigo == lista_instrutores_S[j].codigo) {

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o nome do instrutor  : ";
        getline(cin, instrutor_controle.nome);

        cout << "Digite seu endereço         : ";
        getline(cin, instrutor_controle.endereco);
     
        // listar_cidades(lista_cidades_S, contA_cidade);
        cout << "Digite o código da cidade   : ";
        cin >> instrutor_controle.codigo_cidade;
        cin.ignore();

        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, instrutor_controle.codigo_cidade);

        if (indice_cidade == -1) {
            
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }

        cout << "\nCódigo da cidade: " << lista_cidades_S[indice_cidade].codigo; 
        cout << "\nNome da cidade  : " << lista_cidades_S[indice_cidade].nome;
        cout << "\nEstado da cidade: " << lista_cidades_S[indice_cidade].estado;
       
        lista_instrutores_S[contS_instrutor] = instrutor_controle;
        contS_instrutor++;
        i++;

        cout << "\n\nDeseja adicionar mais um instrutor: (0 = NAO) (1 = SIM)\n";
        cin >> controle;
        
        if (controle == 0) break;
    }
}

// Demais leituras
void ler_instrutor_T(instrutor lista_instrutores_S[],
                     instrutor lista_instrutores_T[],
                     int &contT_instrutor,
                     int contS_instrutor,
                     cidade lista_cidades_S[],
                     int contA_cidade) {

    int i = 0;
    contT_instrutor = 0;
    int controle = 0;
    bool cidade_valida = false;

    for (; i < T_INSTRUTOR;) {

        if (contS_instrutor == T_INSTRUTOR) {
            
            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais instrutores!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        instrutor instrutor_controle;
        bool codigo_duplicado = false;

        cout << "----Ler instrutor----\n";

        cout << "Digite o código da instrutor: ";
        cin >> instrutor_controle.codigo;
        cin.ignore();

        // Verificação para ver se o usuário não está digitando um código já digitado
        for (int j = 0; j < (contT_instrutor + contS_instrutor); j++) {
            
            if (instrutor_controle.codigo == lista_instrutores_S[j].codigo ||
                instrutor_controle.codigo == lista_instrutores_T[j].codigo) {

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o nome do instrutor  : ";
        getline(cin, instrutor_controle.nome);

        cout << "Digite seu endereço         : ";
        getline(cin, instrutor_controle.endereco);
    
        cout << "Digite o código da cidade   : ";
        cin >> instrutor_controle.codigo_cidade;
        cin.ignore();

        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, instrutor_controle.codigo_cidade);

        if (indice_cidade == -1) {

            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }
        
        cout << "\nCódigo da cidade: " << lista_cidades_S[indice_cidade].codigo; 
        cout << "\nNome da cidade  : " << lista_cidades_S[indice_cidade].nome;
        cout << "\nEstado da cidade: " << lista_cidades_S[indice_cidade].estado;
       
        lista_instrutores_T[i] = instrutor_controle;

        cout << "\n\nDeseja adicionar mais um instrutor: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS_instrutor++;
        contT_instrutor++;
        i++;

        if (controle == 0) break;
    }
}

void arquivoA_passa_arquivoS_instrutor(instrutor lista_instrutores_A[],
                                       instrutor lista_instrutores_S[],
                                       int &contS,
                                       int contA) {

    for (int i = 0; i < contA; i++) {
        lista_instrutores_S[i] = lista_instrutores_A[i];
    }

    contS = contA;
}