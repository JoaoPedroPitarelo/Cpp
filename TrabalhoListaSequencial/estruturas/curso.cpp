// curso.cpp
#define T_CURSO 5

struct curso {
    int codigo;
    string descricao;
    float valor_por_aula;
};

// Funções de curso
void incluir_curso(curso lista_cursos_S[T_CURSO],
                   curso lista_cursos_T[T_CURSO],
                   curso lista_cursos_A[T_CURSO],
                   int &contS,
                   int &contT,
                   int &contA) {

    int i = 0, j = 0, k = 0;

    while (i < contS && j < contT) {
        
        if (lista_cursos_S[i].codigo < lista_cursos_T[j].codigo) {

            lista_cursos_A[k] = lista_cursos_S[i];
            i++;
        }
        else {

            lista_cursos_A[k] = lista_cursos_T[j];
            j++;
        }

        k++;
    }

    while (i < contS) {
    
        lista_cursos_A[k] = lista_cursos_S[i];
        i++;
        k++;
    }

    while (j < contT) {

        lista_cursos_A[k] = lista_cursos_T[j];
        j++;
        k++;
    }

    contA = k;
}

// Ordenar lista - bubblesort
void ordenar_arquivo(curso lista_cursos[], int cont) {
    for (int i = cont; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (lista_cursos[j].codigo > lista_cursos[j + 1].codigo) {
                curso aux = lista_cursos[j+1];
                lista_cursos[j+1] = lista_cursos[j];
                lista_cursos[j] = aux;
            }
        }
    }
}

void listar_cursos(curso lista_cursos[], int contA_curso) {

    if (contA_curso == 0) {
        cout << "\n NÃO há cursos adicionados!\n";
    }
    else {

        cout << "Cursos adicionados: " << contA_curso;
        cout << "\nCursos restantes  : " << (T_CURSO - contA_curso) << "\n";

        for (int i = 0; i < contA_curso; i++) {
            cout << "\nCódigo: " << lista_cursos[i].codigo;
            cout << "\n Descrição: " <<  lista_cursos[i].descricao;
            cout << "\n  Valor p/aula: "<<lista_cursos[i].valor_por_aula << "\n"; 
        }
    }
}

// Primeira leitura
void ler_curso_S(curso lista_cursos_S[], int &contS) {

    int controle = 0;

    for (int i = 0; i < T_CURSO;) {

        curso curso_controle;
        bool codigo_duplicado = false;

        cout << "\n-----Leitura Curso primeira leitura-----";

        cout << "\nDigite o código: ";
        cin >> curso_controle.codigo;
        cin.ignore();

        // Verifição para ver se o usuário não está digitando um mesmo código já adicionado
        if (i != 0) {

            for (int j = 0; j < T_CURSO; j++) {

                if (curso_controle.codigo == lista_cursos_S[j].codigo) {
                    
                    cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                    codigo_duplicado = true;
                    break;
                }
            }
        }

        if (codigo_duplicado) {
            continue;
        }

        cout << " Digite a descrição do curso: ";
        getline(cin, curso_controle.descricao);

        cout << "  Digite o valor por aula: ";
        cin >> curso_controle.valor_por_aula;

        lista_cursos_S[contS] = curso_controle;

        cout << "\nDeseja adicionar mais um curso? (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS++;

        cout << "cont S dentro de ler: " << contS << "\n";

        i++;

        if (controle == 0) break;
    }

    // Ordenação do arquivoS - BubbleSort
    ordenar_arquivo(lista_cursos_S, (contS - 1));
}

// Demais leituras
void ler_curso_T(curso lista_cursos_S[],
                 curso lista_cursos_T[],
                 int &contT) {

    int i = 0;
    contT = 0;
    int controle = 0;

    for (; i < T_CURSO;) {

        curso curso_controle;
        bool codigo_duplicado = false;

        cout << "\n-----Leitura Curso-----";

        cout << "\nDigite o código: ";
        cin >> curso_controle.codigo;
        cin.ignore();

        // Verifição para ver se o usuário não está digitando um mesmo código já adicionado

        for (int j = 0; j < T_CURSO; j++) {

            if (curso_controle.codigo == lista_cursos_S[j].codigo ||
                curso_controle.codigo == lista_cursos_T[j].codigo) {
                
                cout << "\nCÓDIGO DUPLICADO! Digite um código diferente!\n";
                codigo_duplicado = true;
                break;
            }
        }

        if (codigo_duplicado) continue;

        cout << " Digite a descrição do curso: ";
        getline(cin, curso_controle.descricao);

        cout << "  Digite o valor por aula: ";
        cin >> curso_controle.valor_por_aula;

        lista_cursos_T[contT] = curso_controle;

        cout << "\nlista T dentro da função: " << "\n";
        for (int i = 0; i < T_CURSO; i++) {
            cout << "Codigo: " << lista_cursos_T[i].codigo;
            cout << "\n Descrição: " << lista_cursos_T[i].descricao << "\n";
        }
        
        cout << "\nDeseja adicionar mais um curso? (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contT++;
        i++;

        if (controle == 0) break;
    }

    // Ordenação do arquivoS - BubbleSort
    ordenar_arquivo(lista_cursos_T, (contT - 1));
}

void arquivoA_passa_arquivoS_curso(curso lista_cursos_A[T_CURSO],
                                   curso lista_cursos_S[T_CURSO],
                                   int &contS,
                                   int contA) {

    for (int i = 0; i < contA; i++) {
        lista_cursos_S[i] = lista_cursos_A[i];
    }

    contS = contA;
}