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

void listar_instrutores(instrutor lista_instrutores[], int contA_instrutor) {

    if (contA_instrutor == 0) {
        cout << "\n NÃO há instrutores adicionados!\n";
    }
    else {

        cout << "\n\nInstrutores adicionados : " << contA_instrutor;
        cout << "\nIstrutores restantes  : " << (T_INSTRUTOR - contA_instrutor) << "\n";

        for (int i = 0; i < contA_instrutor; i++) {
            cout << "\nCódigo: " << lista_instrutores[i].codigo;
            cout << "\n Nome: " << lista_instrutores[i].nome;
            cout << "\n  Endereço: " << lista_instrutores[i].endereco;
            cout << "\n   Código da cidade: " << lista_instrutores[i].codigo_cidade << "\n";
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
            cout << "\n É necessário ADICIONAR cidades PRIMEIRO!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
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

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite o nome do instrutor: ";
        getline(cin, instrutor_controle.nome);

        cout << "  Digite seu endereço: ";
        getline(cin, instrutor_controle.endereco);
     
        cout << "--------------------\n";

        listar_cidades(lista_cidades_S, contA_cidade);
        cout << "\n Digite o código da cidade: ";
        cin >> instrutor_controle.codigo_cidade;
        cin.ignore();

        // verificar se o código da cidade digitado é válido
        for (int j = 0; j < contA_cidade; j++) {
            if (instrutor_controle.codigo_cidade == lista_cidades_S[j].codigo) {
                cidade_valida = true;
                break;
            }
        }

        if (!cidade_valida) {
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }
       
        lista_instrutores_S[contS_instrutor] = instrutor_controle;
        contS_instrutor++;
        i++;

        cout << "\nDeseja adicionar mais um instrutor: (0 = NAO) (1 = SIM)\n";
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

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite o nome do instrutor: ";
        getline(cin, instrutor_controle.nome);

        cout << "  Digite seu endereço: ";
        getline(cin, instrutor_controle.endereco);

        cout << "--------------------";

        listar_cidades(lista_cidades_S, contA_cidade);
        cout << "\n Digite o código da cidade: ";
        cin >> instrutor_controle.codigo_cidade;
        cin.ignore();

        // verificar se o código da cidade digitado é válido
        for (int j = 0; j < contA_cidade; j++) {
            if (instrutor_controle.codigo_cidade == lista_cidades_S[j].codigo) {
                cidade_valida = true;
                break;
            }
        }

        if (!cidade_valida) {
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }


        lista_instrutores_T[i] = instrutor_controle;

        cout << "\nDeseja adicionar mais um instrutor: (0 = NAO) (1 = SIM)\n";
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