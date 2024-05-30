// matricula.cpp
struct matricula {
    int codigo;
    int codigo_aluno;
    int codigo_turma;
    int qtd_aula;
    double valor_total;
};

// Funções de matricula
void incluir_matricula(matricula lista_matriculas_S[],
                       matricula lista_matriculas_T[],
                       matricula lista_matriculas_A[],
                       int contS,
                       int contT,
                       int &contA) {
                        
    int i = 0, j = 0, k = 0;

    while (i < contS && j < contT) {

        if (lista_matriculas_S[i].codigo < lista_matriculas_T[j].codigo) {
            
            lista_matriculas_A[k] = lista_matriculas_S[i];
            i++;
        }
        else {

            lista_matriculas_A[k] = lista_matriculas_T[j];
            j++;
        }

        k++;
    }

    while (i < contS) {

        lista_matriculas_A[k] = lista_matriculas_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_matriculas_A[k] = lista_matriculas_T[j];
        j++;
        k++;
    }    

    contA = k;
    
}

// Funções "internas"

// Buscar indice dentro da lista de acordo com o código
int validate_turma_matricula(turma lista_turmas_S[], int contA, int codigo_procurado) {

    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_turmas_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_turmas_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int validate_matricula(matricula lista_matricula_S[], int contA, int codigo_procurado) {

    int inicio = 0;
    int fim = contA;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista_matricula_S[meio].codigo == codigo_procurado) {
            return meio;
        }
        
        if (lista_matricula_S[meio].codigo < codigo_procurado) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
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

void ler_matricula_S(matricula lista_matriculas_S[],
                     aluno lista_alunos_S[],
                     turma lista_turmas_S[],
                     curso lista_cursos_S[],
                     instrutor lista_instrutores_S[],
                     cidade lista_cidades_S[],
                     int &contS_matricula,
                     int contA_aluno,
                     int contA_turma,
                     int contA_curso,
                     int contA_instrutor,
                     int contA_cidade) {

    int controle = 0;

    for (int i = 0; i < (T_CURSO * T_ALUNO);) {
        
        // Caso não haja alunos nem turmas nem cursos adicionados
        if(!contA_aluno || !contA_turma || !contA_curso) {

            string pause = " ";
            cout << "\n É necessário ADICIONAR ALUNOS, TURMAS E CURSOS antes de adicionar uma matricula!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break; 
        }

        matricula matricula_controle;
        bool codigo_duplicado = false;
        bool aluno_valido = false;
        bool turma_valida = false;
        bool curso_valido = false;

        cout << "---- Ler matricula ----\n";
        
        cout << "Digite o código da matricula: ";
        cin >> matricula_controle.codigo;

        // Verificar se o usuário não entrou um código já digitado
        if (i != 0) {

            for (int j = 0; j < contS_matricula; j++) {

                if (matricula_controle.codigo == lista_matriculas_S[j].codigo) {

                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o código do aluno    : ";
        cin >> matricula_controle.codigo_aluno;

        int indice_aluno = validate_aluno(lista_alunos_S, contA_aluno, matricula_controle.codigo_aluno);
        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, lista_alunos_S[indice_aluno].codigo_cidade);

        if (indice_aluno == -1) {

            cout << "\n Código do aluno INVÁLIDO\n\n";
            continue;
        }

        // Listando aluno selecionado
        cout << "\nNome do aluno  : " << lista_alunos_S[indice_aluno].nome;
        cout << "\nCidade do aluno: " << lista_cidades_S[indice_cidade].nome;

        cout << "\n\nDigite o código da turma: ";
        cin >> matricula_controle.codigo_turma;

        // Usando o indice de turma para achar os indíces de curso e de instrutor
        int indice_turma     = validate_turma_matricula(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);
        int indice_curso     = validate_curso(lista_cursos_S, contA_curso, lista_turmas_S[indice_turma].codigo_curso);
        int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, lista_turmas_S[indice_turma].codigo_instrutor);

        if (indice_turma == -1) {

            cout << "\n Código da turma INVÁLIDA\n\n";
            continue;
        }

        // Listar turma, descrição, instrutor e valor por aula - fazer uma função para isso depois
        cout << "\nTurma             : " << lista_turmas_S[indice_turma].codigo;
        cout << "\nDescrição do curso: " << lista_cursos_S[indice_curso].descricao;
        cout << "\nInstrutor         : " << lista_instrutores_S[indice_instrutor].nome;
        cout << "\nValor por aula    : R$" << lista_cursos_S[indice_curso].valor_por_aula;
    
        if (lista_turmas_S[indice_turma].total_participantes == lista_turmas_S[indice_turma].qtd_max_participantes) {

            string pause = "";
            int opcao;
            cout << "\n\nQuantidade máxima dessa turma atingida!!!\n";
            cout << "\nDeseja tentar outra turma ou ir para Menu? (1- Tentar outra turma) (0- Voltar para Menu)";
            cin >> opcao;

            if (opcao == 0) break;
            
            continue;
        }

        cout << "\n\nDigite a quantidade de aulas: ";
        cin >> matricula_controle.qtd_aula;

        cout << "\nTotal a ser pago ";
        cout << "R$: " << matricula_controle.qtd_aula * lista_cursos_S[indice_curso].valor_por_aula << "\n";

        matricula_controle.valor_total = matricula_controle.qtd_aula * lista_cursos_S[indice_curso].valor_por_aula;
        lista_turmas_S[indice_turma].total_participantes++;
        lista_matriculas_S[contS_matricula] = matricula_controle;
        contS_matricula++;
        i++;

        cout << "\nDeseja adicionar mais uma matricula? (0 = NÃO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}

void ler_matricula_T(matricula lista_matriculas_S[],
                     matricula lista_matriculas_T[],
                     aluno lista_alunos_S[],
                     turma lista_turmas_S[],
                     curso lista_cursos_S[],
                     instrutor lista_instrutores_S[],
                     cidade lista_cidades_S[],
                     int &contT_matricula,
                     int contS_matricula,
                     int contA_aluno,
                     int contA_turma,
                     int contA_curso,
                     int contA_instrutor,
                     int contA_cidade) {
        
    int i = 0;
    contT_matricula = 0;
    int controle = 0;

    while (i < (T_ALUNO * T_CURSO)) {

        if (contS_matricula == (T_ALUNO * T_CURSO)) {
            
            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais matriculas!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        matricula matricula_controle;
        bool codigo_duplicado = false;
        bool aluno_valido = false;
        bool turma_valida = false;
        bool curso_valido = false;
        bool instrutor_valido = false;

        cout << "---- Ler matricula ----\n";

        cout << "Digite o código da matricula: ";
        cin >> matricula_controle.codigo;

        // Verificar se o usuário não entrou um código ja digitado
        for (int j = 0; j < (contS_matricula + contT_matricula); j++) {

            if (matricula_controle.codigo == lista_matriculas_S[j].codigo ||
                matricula_controle.codigo == lista_matriculas_T[j].codigo) {

                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << "Digite o código do aluno    : ";
        cin >> matricula_controle.codigo_aluno;

        int indice_aluno = validate_aluno(lista_alunos_S, contA_aluno, matricula_controle.codigo_aluno);
        int indice_cidade = validate_cidade(lista_cidades_S, contA_cidade, lista_alunos_S[indice_aluno].codigo_cidade);

        if (indice_aluno == -1) {

            cout << "\n Código do aluno INVÁLIDO\n\n";
            continue;
        }

        // Listando aluno selecionado
        cout << "\nNome do aluno  : " << lista_alunos_S[indice_aluno].nome;
        cout << "\nCidade do aluno: " << lista_cidades_S[indice_cidade].nome;

        cout << "\n\nDigite o código da turma: ";
        cin >> matricula_controle.codigo_turma;

        // Usando o indíce de turma para achar os indices de curso e instrutor
        int indice_turma = validate_turma_matricula(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);
        int indice_curso = validate_curso(lista_cursos_S, contA_curso, lista_turmas_S[indice_turma].codigo_curso);
        int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, lista_turmas_S[indice_turma].codigo_instrutor);

        if (indice_turma == -1) {

            cout << "\n Código da turma INVÁLIDA\n\n";
            continue;
        }

        // Listar turma, descrição, instrutor e valor por aula - fazer uma função para isso depois    
        cout << "\nTurma             : " << lista_turmas_S[indice_turma].codigo;
        cout << "\nDescrição do curso: " << lista_cursos_S[indice_curso].descricao;
        cout << "\nInstrutor         : " << lista_instrutores_S[indice_instrutor].nome;
        cout << "\nValor por aula    : R$" << lista_cursos_S[indice_curso].valor_por_aula;
    
        if (lista_turmas_S[indice_turma].total_participantes == lista_turmas_S[indice_turma].qtd_max_participantes) {

            string pause = "";
            int opcao;
            cout << "\n\nQuantidade máxima dessa turma atingida!!!\n";
            cout << "\nDeseja tentar outra turma ou ir para o menu? (1- Tentar outra turma) (0- Voltar para Menu)";
            cin >> opcao;

            if (opcao == 0) break;
            
            continue;
        }

        cout << "\n\nDigite a quantidade de aulas: ";
        cin >> matricula_controle.qtd_aula;

        cout << "\nTotal a ser pago ";
        cout << "R$: " << matricula_controle.qtd_aula * lista_cursos_S[indice_curso].valor_por_aula << "\n";

        matricula_controle.valor_total = matricula_controle.qtd_aula * lista_cursos_S[indice_curso].valor_por_aula;
        lista_turmas_S[indice_turma].total_participantes++;
        lista_matriculas_T[i] = matricula_controle;
        contS_matricula++;
        contT_matricula++;
        i++;

        cout << "\nDeseja adicionar mais uma matricula: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}

void listar_matriculas(matricula lista_matriculas_S[],
                       aluno     lista_alunos_S[],
                       curso     lista_cursos_S[],
                       instrutor lista_instrutores_S[],
                       turma     lista_turmas_S[],
                       int contA_matricula,
                       int contA_aluno,
                       int contA_curso,
                       int contA_instrutor,
                       int contA_turma) {
    
    if (contA_matricula == 0) {
        cout << "\n NÃO há matriculas adicionadas!\n";
    }
    else {

        cout << "Matriculas adicionados: " << contA_matricula;
        cout << "\nMatriculas restantes  : " << ((T_ALUNO * T_CURSO) - contA_matricula) << "\n";

        for (int i = 0; i < contA_matricula; i++) {

            int indice_aluno     = validate_aluno(lista_alunos_S, contA_aluno, lista_matriculas_S[i].codigo_aluno);
            int indice_turma     = validate_turma_matricula(lista_turmas_S, contA_turma, lista_matriculas_S[i].codigo_turma);
            int indice_curso     = validate_curso(lista_cursos_S, contA_curso, lista_turmas_S[indice_turma].codigo_curso);
            int indice_instrutor = validate_instrutor(lista_instrutores_S, contA_instrutor, lista_turmas_S[indice_turma].codigo_instrutor);

            cout << "\nCódigo             :   "   << lista_matriculas_S[i].codigo;
            cout << "\nNome do aluno      :   "   << lista_alunos_S[indice_aluno].nome;
            cout << "\nNome curso         :   "   << lista_cursos_S[indice_curso].descricao;
            cout << "\nNome do instrutor  :   "   << lista_instrutores_S[indice_instrutor].nome; 
            cout << "\nValor total        :   R$" << lista_matriculas_S[i].valor_total << "\n"; 
        }
    }
}

void arquivoA_passa_arquivoS_matricula(matricula lista_matriculas_A[],
                                        matricula lista_matriculas_S[],
                                        int &contS,
                                        int contA) {

    for (int i = 0; i < contA; i++) {
        lista_matriculas_S[i] = lista_matriculas_A[i];
    }

    contS = contA;
}