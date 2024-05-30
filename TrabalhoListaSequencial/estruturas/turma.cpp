// turma.cpp
#define T_TURMA 10

struct turma {
    int codigo;
    int codigo_curso;
    int codigo_instrutor;
    int total_participantes;
    int qtd_max_participantes;
};

// Funções de turma
void incluir_turma(turma lista_turmas_S[],
                   turma lista_turmas_T[],
                   turma lista_turmas_A[],
                   int contS,
                   int contT,
                   int &contA) {

    int i = 0, j = 0, k = 0;

    while (i < contS && j < contT) {

        if (lista_turmas_S[i].codigo < lista_turmas_T[j].codigo) {

            lista_turmas_A[k] = lista_turmas_S[i];
            i++;
        }
        else {

            lista_turmas_A[k] = lista_turmas_T[j];
            j++;
        }

        k++;
    }

    while (i < contS) {

        lista_turmas_A[k] = lista_turmas_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_turmas_A[k] = lista_turmas_T[j];
        j++;
        k++;
    }

    contA = k;
}

// Funções interna
int validate_curso(curso lista_cursos_S[], int contA, int codigo_procurado) {

    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_cursos_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_cursos_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int validate_instrutor(instrutor lista_instrutores_S[], int contA, int codigo_procurado) {

    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_instrutores_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_instrutores_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

void listar_turmas_completas(turma lista_turmas_S[],
                  instrutor lista_instrutores_S[],
                  curso lista_cursos_S[],
                  cidade lista_cidades_S[],
                  int contA_turma,
                  int contA_instrutor,
                  int contA_curso,
                  int contA_cidade) {

    if (contA_turma == 0) {
        cout << "NÃO há turmas adicionadas!";
    }
    else {

        cout << "\nTurmas completas: \n";

        for (int i = 0; i < contA_turma; i++) {

            if (lista_turmas_S[i].total_participantes == lista_turmas_S[i].qtd_max_participantes) {

                int indice_curso = validate_curso(lista_cursos_S, contA_curso, lista_turmas_S[i].codigo_curso);
                int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, lista_turmas_S[i].codigo_instrutor);
                int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, lista_instrutores_S[indice_instrutor].codigo_cidade);

                cout << "\nCódigo da turma    : " << lista_turmas_S[i].codigo;
                cout << "\nNome do curso      : " << lista_cursos_S[indice_curso].descricao;
                cout << "\nNome do instrutor  : " << lista_instrutores_S[indice_instrutor].nome;
                cout << "\nCidade do instrutor: " << lista_cidades_S[indice_cidade].nome;
                cout << "\nTotal participantes: " << lista_turmas_S[i].total_participantes;
                cout << "\nQuantidade máxima  : " << lista_turmas_S[i].qtd_max_participantes;
            }
        }
    }
}

void buscar_turma(turma lista_turmas_S[],
                  curso lista_cursos_S[],
                  instrutor lista_instrutores_S[],
                  cidade lista_cidades_S[],
                  int contA_turma,
                  int contA_curso,
                  int contA_instrutor,
                  int contA_cidade) {

    if (contA_turma < 1) {

        cout << "\n NÃO há turmas adicionadas!\n";
    }
    else {

        int codigo_procurado;
        int codigo_resultado = -1;

        cout << "\n Digite o código da turma: ";
        cin >> codigo_procurado;

        // Buscar binária
        int inicio = 0;
        int fim = contA_turma;

        while (inicio <= fim) {

            int meio = (inicio + fim) / 2;

            if (lista_turmas_S[meio].codigo == codigo_procurado) {
                codigo_resultado = meio;
            }
            
            if (lista_turmas_S[meio].codigo < codigo_procurado) {
                inicio = meio + 1;
            }
            else {
                fim = meio - 1;
            }
        }

        if (codigo_resultado != -1) {
            
            // Usando indíce de turma para achar o indice de curso, instrutor e cidade
            int indice_curso     = validate_curso(lista_cursos_S, contA_curso, lista_turmas_S[codigo_resultado].codigo_curso);
            int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, lista_turmas_S[codigo_resultado].codigo_instrutor);
            int indice_cidade    = validate_cidade(lista_cidades_S, contA_cidade, lista_instrutores_S[indice_instrutor].codigo_cidade);

            cout << "\n Turma encontrada!\n";

            cout << "\nNome do curso         : " << lista_cursos_S[indice_curso].descricao;
            cout << "\nNome do instrutor     : " << lista_instrutores_S[indice_instrutor].nome;
            cout << "\nCidade do instrutor   : " << lista_cidades_S[indice_cidade].nome;
            cout << "\nTotal de participantes: " << lista_turmas_S[codigo_resultado].total_participantes;
        }
        else {

            cout << "\nTurma não encontrada!!!";
        }
    }
}

void ler_turma_S(turma lista_turmas_S[],
                 curso lista_cursos_S[],
                 instrutor lista_instrutores_S[],
                 cidade lista_cidades_S[],
                 int &contS_turma,
                 int contA_curso,
                 int contA_instrutor,
                 int contA_cidade) {

    int controle = 0;

    for (int i = 0; i < T_TURMA;) {

        // Caso não haja cursos adicionados
        if (!contA_curso || !contA_instrutor) {

            string pause = " ";
            cout << "\n É necessário ADICIONAR CURSOS E INSTRUTORES PRIMEIRO!";
            cout << "\n\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;  
        }

        turma turma_controle;
        bool codigo_duplicado = false;
        bool curso_valido = false;
        bool instrutor_valido = false;

        cout << "---- Ler Turma primeira ----\n";

        cout << "Digite o código da turma: ";
        cin >> turma_controle.codigo;

        // Verificação para ver se o usuário não está digitando um mesmo código já digitado
        if (i != 0) {

            for (int j = 0; j < contS_turma; j++) {

                if (turma_controle.codigo == lista_turmas_S[j].codigo) {

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o código do curso: ";
        cin >> turma_controle.codigo_curso;

        int indice_curso = validate_curso(lista_cursos_S, contA_curso, turma_controle.codigo_curso);

        if (indice_curso == -1) {

            cout << "\n Código do curso INVÁLIDO!\n\n";
            continue;
        }

        // Listando curso selecionado
        cout << "\nDescrição     : " << lista_cursos_S[indice_curso].descricao;
        cout << "\nValor por aula: R$" << lista_cursos_S[indice_curso].valor_por_aula;

        cout << "\n\nDigite o código do instrutor: ";
        cin >> turma_controle.codigo_instrutor;

        int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, turma_controle.codigo_instrutor);
        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, lista_instrutores_S[indice_instrutor].codigo_cidade);

        if(indice_instrutor == -1) {

            cout << "\n Código do instrutor INVÁLIDO\n\n";
            continue;
        }

        // Listandno instrutor
        cout << "\nNome do instrutor: " << lista_instrutores_S[indice_instrutor].nome;
        cout << "\nNome da cidade   : " << lista_cidades_S[indice_cidade].nome;

        cout << "\n\nDigite a quantidade máxima de participantes da turma: ";
        cin >> turma_controle.qtd_max_participantes;

        turma_controle.total_participantes = 0;

        lista_turmas_S[contS_turma] = turma_controle;
        contS_turma++;
        i++;

        cout << "\nDeseja adicionar mais uma turma? (0 = NÃO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}

void ler_turma_T(turma lista_turmas_S[],
                 turma lista_turmas_T[],
                 curso lista_cursos_S[],
                 instrutor lista_instrutores_S[],
                 cidade lista_cidades_S[],
                 int &contT_turma,
                 int contS_turma,
                 int contA_curso,
                 int contA_instrutor,
                 int contA_cidade) {

    int i = 0;
    contT_turma = 0;
    int controle = 0;

    while (i < T_TURMA) {

        if (contS_turma == T_TURMA) {
            
            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais turmas!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        turma turma_controle;
        bool codigo_duplicado = false;
        bool curso_valido = false;
        bool instrutor_valido = false;

        cout << "---- Ler Turma -----\n";

        cout << "Digite o código da turma: ";
        cin >> turma_controle.codigo;

        for (int j = 0; j < (contT_turma + contS_turma); j++) {

            if (turma_controle.codigo == lista_turmas_S[j].codigo ||
                turma_controle.codigo == lista_turmas_T[j].codigo) {

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o código do curso: ";
        cin >> turma_controle.codigo_curso;

        int indice_curso  = validate_curso(lista_cursos_S, contA_curso, turma_controle.codigo_curso);

        if (indice_curso == -1) {

            cout << "\n Código do curso INVÁLIDO!\n\n";
            continue;
        }

        // Listando curso selecionado
        cout << "\nDescrição     : " << lista_cursos_S[indice_curso].descricao;
        cout << "\nValor por aula: R$" << lista_cursos_S[indice_curso].valor_por_aula;

        cout << "\n\nDigite o código do instrutor: ";
        cin >> turma_controle.codigo_instrutor;

        int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, turma_controle.codigo_instrutor);
        int indice_cidade    = validate_cidade(lista_cidades_S, contA_cidade, lista_instrutores_S[indice_instrutor].codigo_cidade);

        if (indice_instrutor == -1) {

            cout << "\n Código do instrutor INVÁLIDO\n\n";
            continue;
        }

        // Listando instrutor
        cout << "\nNome do instrutor: " << lista_instrutores_S[indice_instrutor].nome;
        cout << "\nNome da cidade   : " << lista_cidades_S[indice_cidade].nome;

        cout << "\n\nDigite a quantidade máxima de participantes da turma: ";
        cin >> turma_controle.qtd_max_participantes;

        turma_controle.total_participantes = 0;

        lista_turmas_T[i] = turma_controle;
        contS_turma++;
        contT_turma++;
        i++;

        cout << "\nDeseja adicionar mais uma turma: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}

void arquivoA_passa_arquivoS_turma(turma lista_turmas_A[T_TURMA],
                                    turma lista_turmas_S[T_TURMA],
                                    int &contS,
                                    int contA) {

    for (int i = 0; i < contA; i++) {
        lista_turmas_S[i] = lista_turmas_A[i];
    }

    contS = contA;
}

