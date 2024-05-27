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
int validate_turma(turma lista_turmas_S[], int contA, int codigo_procurado) {

    // Buscando o indice em relação ao código
    int inicio = 0;
    int fim = contA;

    while (inicio < fim) {
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

void ler_matricula_S(matricula lista_matriculas_S[],
                     aluno lista_alunos_S[],
                     turma lista_turmas_S[],
                     curso lista_cursos_S[],
                     instrutor lista_instrutores_S[],
                     int &contS_matricula,
                     int contA_aluno,
                     int contA_turma,
                     int contA_curso,
                     int contA_instrutor) {

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

        cout << "---- Ler matricula primeira ----\n";
        
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

        // Listar alunos fazer uma função para isso: 
        for (int i = 0; i < contA_aluno; i++) {

            cout << "\nCódigo do aluno: " << lista_alunos_S[i].codigo;
            cout << "\nNome do aluno: " << lista_alunos_S[i].nome;
            cout << "\nEndereço: " << lista_alunos_S[i].endereco;
            cout << "\n";
        }

        cout << "\n Digite o código do aluno: ";
        cin >> matricula_controle.codigo_aluno;

        // Verificar se o aluno é válido
        for (int j = 0; j < contA_aluno; j++) {

            if (matricula_controle.codigo_aluno == lista_alunos_S[j].codigo) {

                aluno_valido = true;
                break;
            }
        }

        if (!aluno_valido) {

            cout << "\n Código do aluno INVÁLIDO\n\n";
            continue;
        }

        // Listar turma, descrição, instrutor e valor por aula - fazer uma função para isso depois
        for (int i = 0; i < contA_turma; i++) {

            cout << "\n\nTurma: " << lista_turmas_S[i].codigo;
            cout << "\nDescrição do curso: " << lista_cursos_S[lista_turmas_S[i+1].codigo_curso].descricao;
            cout << "\nInstrutor: " << lista_instrutores_S[lista_turmas_S[i+1].codigo_instrutor].nome;
            cout << "\nValor por aula: R$" << lista_cursos_S[lista_turmas_S[i+1].codigo_curso].valor_por_aula;
        }

        cout << "\n Digite o código da turma: ";
        cin >> matricula_controle.codigo_turma;

        // Verificar se a turma é válida:
        for (int j = 0; j < contA_turma; j++) {

            if (matricula_controle.codigo_turma == lista_turmas_S[j].codigo) {

                turma_valida = true;
                break;
            }
        }

        if (!turma_valida) {

            cout << "\n Código da turma INVÁLIDA\n\n";
            continue;
        }

        // Verificar se a quantidade máxima não será ultrapassada
        int indice = validate_turma(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);

        if (lista_turmas_S[indice].total_participantes == lista_turmas_S[indice].qtd_max_participantes) {

            string pause = "";
            int opcao;
            cout << "\nQuantidade máxima dessa turma atingida!!!\n";
            cout << "Deseja tentar outra turma ou ir para Menu? (1- Tentar outra turma) (0- Voltar para Menu)";
            cin >> opcao;

            if (opcao == 0) break;
            
            continue;
        }

        cout << "\n Digite a quantidade de aulas: ";
        cin >> matricula_controle.qtd_aula;

        cout << "\nTotal a ser pago ";
        cout << "R$: " << matricula_controle.qtd_aula * lista_cursos_S[lista_turmas_S[matricula_controle.codigo_turma].codigo_curso].valor_por_aula << "\n";

        matricula_controle.valor_total = matricula_controle.qtd_aula * lista_cursos_S[lista_turmas_S[matricula_controle.codigo_turma].codigo_curso].valor_por_aula;
       
        indice = validate_turma(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);

        lista_turmas_S[indice].total_participantes++;

        lista_matriculas_S[contS_matricula] = matricula_controle;
        contS_matricula++;
        i++;

        cout << "Deseja adicionar mais uma matricula? (0 = NÃO) (1 = SIM)\n";
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
                     int &contT_matricula,
                     int contS_matricula,
                     int contA_aluno,
                     int contA_turma,
                     int contA_curso,
                     int contA_instrutor) {
        
    int i = 0;
    contT_matricula = 0;
    int controle = 0;

    while (i < (T_ALUNO * T_CURSO)) {

        if (contS_matricula == (T_ALUNO * T_CURSO)) {
            
            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais turmas!";
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

        // Listar alunos fazer uma função para isso: 
        for (int i = 0; i < contA_aluno; i++) {

            cout << "\nCódigo do aluno: " << lista_alunos_S[i].codigo;
            cout << "\nNome do aluno: " << lista_alunos_S[i].nome;
            cout << "\nEndereço: " << lista_alunos_S[i].endereco;
            cout << "\n";
        }

        cout << "\n Digite o código do aluno: ";
        cin >> matricula_controle.codigo_aluno;

        // Verificar se o aluno é válido
        for (int j = 0; j < contA_aluno; j++) {

            if (matricula_controle.codigo_aluno == lista_alunos_S[j].codigo) {

                aluno_valido = true;
                break;
            }
        }

        if (!aluno_valido) {

            cout << "\n Código do aluno INVÁLIDO\n\n";
            continue;
        }

        // Listar turma, descrição, instrutor e valor por aula - fazer uma função para isso depois
        for (int i = 0; i < contA_turma; i++) {

            cout << "\n\nTurma: " << lista_turmas_S[i].codigo;
            cout << "\nDescrição do curso: " << lista_cursos_S[lista_turmas_S[i+1].codigo_curso].descricao;
            cout << "\nInstrutor: " << lista_instrutores_S[lista_turmas_S[i+1].codigo_instrutor].nome;
            cout << "\nValor por aula: R$" << lista_cursos_S[lista_turmas_S[i+1].codigo_curso].valor_por_aula;
        }

        cout << "\n Digite o código da turma: ";
        cin >> matricula_controle.codigo_turma;

        // Verificar se a turma é válida:
        for (int j = 0; j < contA_turma; j++) {

            if (matricula_controle.codigo_turma == lista_turmas_S[j].codigo) {

                turma_valida = true;
                break;
            }
        }

        if (!turma_valida) {

            cout << "\n Código da turma INVÁLIDA\n\n";
            continue;
        }

        // Verificar se a quantidade máxima não será ultrapassada
        int indice = validate_turma(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);
        if (lista_turmas_S[indice].total_participantes == lista_turmas_S[indice].qtd_max_participantes) {

            string pause = "";
            int opcao;
            cout << "\nQuantidade máxima dessa turma atingida!!!\n";
            cout << "Deseja tentar outra turma ou ir para o menu? (1- Tentar outra turma) (0- Voltar para Menu)";
            cin >> opcao;

            if (opcao == 0) break;
            
            continue;
        }


        cout << "\n Digite a quantidade de aulas: ";
        cin >> matricula_controle.qtd_aula;

        cout << "\nTotal a ser pago ";
        cout << "R$: " << matricula_controle.qtd_aula * lista_cursos_S[lista_turmas_S[matricula_controle.codigo_turma].codigo_curso].valor_por_aula << "\n";

        matricula_controle.valor_total = matricula_controle.qtd_aula * lista_cursos_S[lista_turmas_S[matricula_controle.codigo_turma].codigo_curso].valor_por_aula;
       
        indice = validate_turma(lista_turmas_S, contA_turma, matricula_controle.codigo_turma);

        lista_turmas_S[indice].total_participantes++;

        lista_matriculas_T[i] = matricula_controle;
        contS_matricula++;
        contT_matricula++;
        i++;

        cout << "\nDeseja adicionar mais uma matricula: (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        if (controle == 0) break;
    }
}

void listar_matriculas(matricula lista_matriculas[], int contA_matricula) {
    
    if (contA_matricula == 0) {
        cout << "\n NÃO há matriculas adicionadas!\n";
    }
    else {

        cout << "Matriculas adicionados: " << contA_matricula;
        cout << "\nMatriculas restantes  : " << ((T_ALUNO * T_CURSO) - contA_matricula) << "\n";

        for (int i = 0; i < contA_matricula; i++) {

            cout << "\nCódigo: " << lista_matriculas[i].codigo;
            cout << "\n Código aluno: " << lista_matriculas[i].codigo_aluno;
            cout << "\n  Código turma:  R$" << lista_matriculas[i].codigo_turma;
            cout << "\n   Quantidade de aulas: " <<  lista_matriculas[i].qtd_aula;
            cout << "\n    Valor total: R$" << lista_matriculas[i].valor_total << "\n"; 
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