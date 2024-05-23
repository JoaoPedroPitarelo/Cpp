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

void buscar_aluno(aluno lista_alunos[], int contA, int aluno_procurado, int &codigo_aluno_encontrado) {

    int inicio = 0;
    int fim = contA;
    int meio = ((inicio + fim) / 2);
    bool aluno_encontrada = false;

    for (int i = 0; i < contA; i++) {
        
        //encontrou o aluno
        if (aluno_procurado == lista_alunos[i].codigo) {
            
            codigo_aluno_encontrado = aluno_procurado;
            aluno_encontrada = true;
            break;
        }

        // Caso não exista o código do aluno
        if (inicio == fim) {
            codigo_aluno_encontrado = -1;
            aluno_encontrada = false;
        }

        if (aluno_procurado > lista_alunos[meio].codigo) {

            inicio = meio + 1;
            meio = ((inicio + fim) / 2);
            continue;
        }

        if (aluno_procurado < lista_alunos[meio].codigo) {

            fim = meio -1; 
            meio = ((inicio + fim) / 2);
            continue;
        }
    }

    if (!aluno_procurado) {
        codigo_aluno_encontrado = -1;
    }
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
    int codigo_aluno_encontrado = 0;

    cout << "\nDigite o código do aluno a ser excluído: ";
    cin >> codigo_aluno_procurado;
    
    buscar_aluno(lista_alunos_S, contA, codigo_aluno_procurado, codigo_aluno_encontrado);

    int k = 0; // final

    for (int i = 0; k < contA; i++) {
        
        if (codigo_aluno_encontrado <= 0) break;

        if (lista_alunos_S[i].codigo == codigo_aluno_encontrado) continue;
        
        lista_alunos_A[k] = lista_alunos_S[i];
        k++;
    }

    if (k > 0) {
        contA = k -1;// 'k -1' por conta de '1 <= contA', fazendo com que k fique igual a valor anterior.
        contS = contA;

        arquivoA_passa_arquivoS_aluno(lista_alunos_A, lista_alunos_S, contS, contA);

        cout << "\n Aluno excluído com sucesso! \n";
    } 
    else {
        cout << "\n Código não encontrado! \n";
    }
}


void listar_alunos(aluno lista_alunos[], int contA_aluno) {

    if (contA_aluno == 0) {
        cout << "\n NÃO há alunos adicionados!\n";
    }
    else {

        cout << "\n\nAlunos adicionados : " << contA_aluno;
        cout << "\nAlunos restantes   : " << (T_ALUNO - contA_aluno) << "\n";

        for (int i = 0; i < contA_aluno; i++) {
            cout << "\nCódigo: " << lista_alunos[i].codigo;
            cout << "\n Nome: " << lista_alunos[i].nome;
            cout << "\n  Endereço: " << lista_alunos[i].endereco;
            cout << "\n   Código da cidade: " << lista_alunos[i].codigo_cidade << "\n";
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
        bool codigo_duplicado = false;
        bool cidade_valida = false;

        cout << "---- Ler Aluno primeira----\n";

        cout << "Digite o código do aluno: ";

        cin >> aluno_controle.codigo;
        cin.ignore();

        // Verificação para ver se o usuário não está digitando um mesmo código já digitado
        if (i != 0) {

            for (int j = 0; j < contS_aluno; j++) {

                if (aluno_controle.codigo == lista_alunos_S[j].codigo) {

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite o nome do aluno: ";
        getline(cin, aluno_controle.nome);

        cout << "  Digite seu endereço: ";
        getline(cin, aluno_controle.endereco);

        cout << "--------------------\n";

        listar_cidades(lista_cidades_S, contA_cidade);
        cout << "\n Digite o código da cidade: ";
        cin >> aluno_controle.codigo_cidade;
        cin.ignore();

        // verificar se o código da cidade digitado é válido
        for (int j = 0; j < contA_cidade; j++) {
            if (aluno_controle.codigo_cidade == lista_cidades_S[j].codigo) {
                cidade_valida = true;
                break;
            }
        }

        if (!cidade_valida) {
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }

        lista_alunos_S[contS_aluno] = aluno_controle;

        cout << "\nDeseja adicionar mais um aluno: (0 = NAO) (1 = SIM)\n";
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
    bool cidade_valida = false;

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
        bool codigo_duplicado = false;

        cout << "---- Ler aluno ----\n";

        cout << "Digite o código do aluno: ";
        cin >> aluno_controle.codigo;
        cin.ignore();

        // Verificação para ver se o usuário não está digitando um mesmo código já digitado
        for (int j = 0; j < (contT_aluno + contS_aluno); j++) {

            if (aluno_controle.codigo == lista_alunos_S[j].codigo ||
                aluno_controle.codigo == lista_alunos_T[j].codigo) {

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite o nome do aluno: ";
        getline(cin, aluno_controle.nome);

        cout << "  Digite seu endereço: ";
        getline(cin, aluno_controle.endereco);

        cout << "--------------------\n";

        listar_cidades(lista_cidades_S, contA_cidade);
        cout << "\n Digite o código da cidade: ";
        cin >> aluno_controle.codigo_cidade;
        cin.ignore();

        // verificar se o código da cidade digitado é válido
        for (int j = 0; j < contA_cidade; j++) {
            if (aluno_controle.codigo_cidade == lista_cidades_S[j].codigo) {
                cidade_valida = true;
                break;
            }
        }

        if (!cidade_valida) {
            cout << "\nCódigo da cidade INVALIDA!\n\n";
            continue;
        }

        lista_alunos_T[i] = aluno_controle;

        cout << "\nDeseja adicionar mais um aluno: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS_aluno++;
        contT_aluno++;
        i++;

        if (controle == 0) break;
    }
}