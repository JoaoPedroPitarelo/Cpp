// aluno.cpp
#define T_ALUNO 150 

struct aluno {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

// Funções de aluno
void incluir_aluno(aluno lista_alunos_S[],
                   aluno lista_alunos_T[],
                   aluno lista_alunos_A[],
                   int &contS,
                   int &contT,
                   int &contA) {

    int i = 0, j = 0, k = 0;

    while(i < contS && j < contT) {

        if (lista_alunos_S[i].codigo < lista_alunos_T[j].codigo) {

            lista_alunos_A[k] = lista_alunos_S[i];
            i++;
        }
        else {

            lista_alunos_A[k] = lista_alunos_T[j];
            j++;
        }

        k++;
    }

    while (i < contS) {

        lista_alunos_A[k] = lista_alunos_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_alunos_A[k] = lista_alunos_T[j];
        j++;
        k++;
    }

    contA = k;
}


int validate_aluno(aluno lista_alunos_S[], int contA, int codigo_procurado) {

    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_alunos_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_alunos_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

void arquivoA_passa_arquivoS_aluno(aluno lista_alunos_A[],
                                   aluno lista_alunos_S[],
                                   int &contS,
                                   int contA) {
    
    for (int i = 0; i < contA; i++) {
        lista_alunos_S[i] = lista_alunos_A[i];
    }

    contS = contA;
}

void excluir_aluno(aluno lista_alunos_S[],
                   aluno lista_alunos_A[],
                    int &contA,
                    int &contS) {
    
    int codigo_aluno_procurado = 0;

    cout << "\nDigite o código do aluno a ser excluído: ";
    cin >> codigo_aluno_procurado;
    
    int indice_aluno_excluido = validate_aluno(lista_alunos_S, contA, codigo_aluno_procurado);

    int k = 0; 

    for (int i = 0; k < contA; i++) {
        
        if (indice_aluno_excluido == -1) break;

        if (i == indice_aluno_excluido) {
            
            continue;
        }

        lista_alunos_A[k] = lista_alunos_S[i];
        k++;
    }

    if (k > 0) {

        contA = k-1;
        contS = k-1;

        arquivoA_passa_arquivoS_aluno(lista_alunos_A, lista_alunos_S, contS, contA);

        cout << "\n Aluno excluído com sucesso! \n\n";
    } 
    else {
        cout << "\n Código não encontrado! \n\n";
    }
}

void listar_alunos(aluno lista_alunos[], int contA_aluno) {

    if (contA_aluno == 0) {
        cout << "\n NÃO há alunos adicionados!\n";
    }
    else {

        cout << "Alunos adicionados: " << contA_aluno;
        cout << "\nAlunos restantes  : " << (T_ALUNO - contA_aluno) << "\n";

        for (int i = 0; i < contA_aluno; i++) {

            cout << "\nCódigo          : " << lista_alunos[i].codigo;
            cout << "\nNome            : " << lista_alunos[i].nome;
            cout << "\nEndereço        : " << lista_alunos[i].endereco;
            cout << "\nCódigo da cidade: " << lista_alunos[i].codigo_cidade << "\n";
        }
    }
}

// Primeira leitura
void ler_aluno_S(aluno lista_alunos_S[],
                 int &contS_aluno,
                 cidade lista_cidades_S[],
                 int contA_cidade) {

    int controle = 0;

    for (int i = 0; i < T_ALUNO;) {
        
        // Caso não haja cidades adicionadas
        if (!contA_cidade) {

            string pause = " ";
            cout << "\n É necessário ADICIONAR cidades PRIMEIRO!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        aluno aluno_controle;
        int is_duplicado;
        bool cidade_valida = false;

        cout << "---- Ler Aluno ----\n";

        cout << "Digite o código do aluno : ";

        cin >> aluno_controle.codigo;
        cin.ignore();

        is_duplicado = validate_aluno(lista_alunos_S, contS_aluno, aluno_controle.codigo);

        if (is_duplicado != -1) {
            
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        }

        cout << "Digite o nome do aluno   : ";
        getline(cin, aluno_controle.nome);

        cout << "Digite seu endereço      : ";
        getline(cin, aluno_controle.endereco);

        cout << "Digite o código da cidade: ";
        cin >> aluno_controle.codigo_cidade;
        cin.ignore();

        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, aluno_controle.codigo_cidade);

        if (indice_cidade == -1) {
            
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }

        cout << "\nCódigo da cidade: " << lista_cidades_S[indice_cidade].codigo; 
        cout << "\nNome da cidade  : " << lista_cidades_S[indice_cidade].nome;
        cout << "\nEstado da cidade: " << lista_cidades_S[indice_cidade].estado;
       
        lista_alunos_S[contS_aluno] = aluno_controle;

        cout << "\n\nDeseja adicionar mais um aluno: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS_aluno++;
        i++;

        if (controle == 0) break;
    }
}

// Demais leituras
void ler_aluno_T(aluno lista_alunos_S[],
                 aluno lista_alunos_T[],
                 int &contT_aluno,
                 int contS_aluno,
                 cidade lista_cidades_S[],
                 int contA_cidade) {

    int i = 0;
    contT_aluno = 0;
    int controle = 0;

    for (; i < T_ALUNO;) {

        if (contS_aluno == T_ALUNO) {
            
            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais instrutores!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        aluno aluno_controle;
        int is_duplicado;

        cout << "---- Ler aluno ----\n";

        cout << "Digite o código do aluno : ";
        cin >> aluno_controle.codigo;
        cin.ignore();

        is_duplicado = validate_aluno(lista_alunos_S, contS_aluno, aluno_controle.codigo);
        is_duplicado += validate_aluno(lista_alunos_T, contT_aluno, aluno_controle.codigo);

        if (is_duplicado >= -1) {
            
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        } 

        cout << "Digite o nome do aluno   : ";
        getline(cin, aluno_controle.nome);

        cout << "Digite seu endereço      : ";
        getline(cin, aluno_controle.endereco);

        cout << "Digite o código da cidade: ";
        cin >> aluno_controle.codigo_cidade;
        cin.ignore();

        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, aluno_controle.codigo_cidade);

        if (indice_cidade == -1) {
            
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }

        cout << "\nCódigo da cidade: " << lista_cidades_S[indice_cidade].codigo; 
        cout << "\nNome da cidade  : " << lista_cidades_S[indice_cidade].nome;
        cout << "\nEstado da cidade: " << lista_cidades_S[indice_cidade].estado;
     
        lista_alunos_T[i] = aluno_controle;
        contS_aluno++;
        contT_aluno++;
        i++;

        cout << "\n\nDeseja adicionar mais um aluno: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}