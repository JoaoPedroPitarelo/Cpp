// matricula.cpp
struct matricula {
    int codigo;
    int codigo_aluno;
    int codigo_turma;
    int qtd_aula;
    double valor_total;
};

// Funções de matricula
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

            cout << "\nTurma: " << lista_turmas_S[i].codigo;
            cout << "\nDescrição do curso: " << lista_cursos_S[lista_turmas_S[i].codigo_curso].descricao;
            cout << "\nInstrutor: " << lista_instrutores_S[lista_turmas_S[i].codigo_instrutor].nome;
            cout << "\nValor por aula: " << lista_cursos_S[lista_turmas_S[i].codigo_curso].valor_por_aula;
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

        cout << "\n Digite a quantidade de aulas: ";
        cin >> matricula_controle.qtd_aula;

        cout << "\nTotal a ser pago: ";
        cout << "R$: " << matricula_controle.qtd_aula * lista_cursos_S[matricula_controle.codigo_turma].valor_por_aula;

        matricula_controle.valor_total = matricula_controle.qtd_aula * lista_cursos_S[matricula_controle.codigo_turma].valor_por_aula;
        lista_turmas_S[matricula_controle.codigo_turma].total_participantes++;

        lista_matriculas_S[contS_matricula] = matricula_controle;
        contS_matricula++;
        i++;

        cout << "Deseja adicionar mais uma turma? (0 = NÃO) (1 = SIM)\n";

        if (controle == 0) break;
    }

}
