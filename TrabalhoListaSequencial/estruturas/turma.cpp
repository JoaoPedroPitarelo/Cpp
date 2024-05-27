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

void listar_turmas(turma lista_turmas_S[], int contA_turma) {

    if (contA_turma == 0) {
        cout << "\n NÃO há turmas adicionadas!\n";
    }
    else {

        cout << "\n\nTurmas adicionadas : " << contA_turma;
        cout << "\nTurmas restantes   : " << (T_TURMA - contA_turma) << "\n";

        for (int i = 0; i < contA_turma; i++) {
            cout << "\n\nCódigo da turma: " << lista_turmas_S[i].codigo;
            cout << "\n Código do curso: " <<  lista_turmas_S[i].codigo_curso;
            cout << "\n  Código do instrutor: " << lista_turmas_S[i].codigo_instrutor;
            cout << "\n   Total de participantes: " << lista_turmas_S[i].total_participantes;
            cout << "\n    Quantidade máxima de participantes: " << lista_turmas_S[i].qtd_max_participantes;
        }
    }
}

void ler_turma_S(turma lista_turmas_S[],
                 curso lista_cursos_S[],
                 instrutor lista_instrutores_S[],
                 int &contS_turma,
                 int contA_curso,
                 int contA_instrutor) {

    int controle = 0;

    for (int i = 0; i < T_TURMA;) {

        // Caso não haja cursos adicionados
        if (!contA_curso || !contA_instrutor) {

            string pause = " ";
            cout << "\n É necessário ADICIONAR CURSOS E INSTRUTORES PRIMEIRO!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;  
        }

        // // Caso não haja cursos adicionados
        // if (!contA_instrutor) {

        //     string pause = " ";
        //     cout << "\n É necessário ADICIONAR instrutores PRIMEIRO!";
        //     cout << "\n Pressione qualquer tecla para continuar: \n";
        //     cin.ignore();
        //     getline(cin, pause);
        //     break; 
        // }

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

        listar_cursos(lista_cursos_S, contA_curso);
        cout << "\n Digite o código do curso: ";
        cin >> turma_controle.codigo_curso;

        // Verificar se o código da curso digitado é valido
        for (int j = 0; j < contA_curso; j++) {

            if (turma_controle.codigo_curso == lista_cursos_S[j].codigo) {
                
                curso_valido = true;
                break;
            }
        }

        if (!curso_valido) {
            cout << "\n Código do curso INVÁLIDO!\n\n";
            continue;
        }

        listar_instrutores(lista_instrutores_S, contA_instrutor);
        cout << "\n  Digite o código do instrutor: ";
        cin >> turma_controle.codigo_instrutor;

        // Verificar se o código do instrutor digitado é valido
        for (int j = 0; j < contA_instrutor; j++) {
            if (turma_controle.codigo_instrutor == lista_instrutores_S[j].codigo) {
                instrutor_valido = true;
                break;
            }
        }

        if(!instrutor_valido) {
            cout << "\n Código do instrutor INVÁLIDO\n\n";
            continue;
        }

        cout << "   Digite a quantidade máxima de participantes da turma: ";
        cin >> turma_controle.qtd_max_participantes;

        turma_controle.total_participantes = 0;

        lista_turmas_S[contS_turma] = turma_controle;
        contS_turma++;
        i++;

        cout << "Deseja adicionar mais uma turma? (0 = NÃO) (1 = SIM)\n";

        if (controle == 0) break;
    }
}

void ler_turma_T(turma lista_turmas_S[],
                 turma lista_turmas_T[],
                 curso lista_cursos_S[],
                 instrutor lista_instrutores_S[],
                 int &contT_turma,
                 int contS_turma,
                 int contA_curso,
                 int contA_instrutor) {

    int i = 0;
    contT_turma = 0;
    int controle = 0;
    bool cidade_valida = false;

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

        listar_cursos(lista_cursos_S, contA_curso);
        cout << " Digite o código do curso: ";
        cin >> turma_controle.codigo_curso;

        // Verificar se o código da curso digitado é valido
        for (int j = 0; j < contA_curso; j++) {
            if (turma_controle.codigo_curso == lista_cursos_S[j].codigo) {
                curso_valido = true;
                break;
            }
        }

        if (!curso_valido) {
            cout << "\n Código do curso INVÁLIDO!\n\n";
            continue;
        }

        listar_instrutores(lista_instrutores_S, contA_instrutor);
        cout << "  Digite o código do instrutor: ";
        cin >> turma_controle.codigo_instrutor;

        // Verificar se o código do instrutor digitado é valido
        for (int j = 0; j < contA_instrutor; j++) {
            if (turma_controle.codigo_instrutor == lista_instrutores_S[j].codigo) {
                instrutor_valido = true;
                break;
            }
        }

        if (!instrutor_valido) {
            cout << "\n Código do instrutor INVÁLIDO\n\n";
            continue;
        }

        cout << "   Digite a quantidade máxima de participantes da turma: ";
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

