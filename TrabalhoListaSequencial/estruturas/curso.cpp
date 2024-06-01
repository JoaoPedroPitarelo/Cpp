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

// Validar indíce
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

// Listar cursos
void listar_cursos(curso lista_cursos[], int contA_curso) {

    if (contA_curso == 0) {
        cout << "\n NÃO há cursos adicionados!\n";
    }
    else {

        cout << "Cursos adicionados: " << contA_curso;
        cout << "\nCursos restantes  : " << (T_CURSO - contA_curso) << "\n";

        for (int i = 0; i < contA_curso; i++) {
            cout << "\nCódigo        : " << lista_cursos[i].codigo;
            cout << "\nDescrição     : " << lista_cursos[i].descricao;
            cout << "\nValor p/aula  : R$"<< lista_cursos[i].valor_por_aula << "\n"; 
        }
    }
}

// Primeira leitura
void ler_curso_S(curso lista_cursos_S[], int &contS) {

    int controle = 0;

    for (int i = 0; i < T_CURSO;) {
        
        curso curso_controle;
        int is_duplicado;

        cout << "-----Leitura Curso-----";

        cout << "\nDigite o código            : ";
        cin >> curso_controle.codigo;
        cin.ignore();

        is_duplicado = validate_curso(lista_cursos_S, contS, curso_controle.codigo);

        if (is_duplicado != -1) {
                    
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        }

        cout << "Digite a descrição do curso: ";
        getline(cin, curso_controle.descricao);

        cout << "Digite o valor por aula    : ";
        cin >> curso_controle.valor_por_aula;

        lista_cursos_S[contS] = curso_controle;

        cout << "\nDeseja adicionar mais um curso? (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contS++;
        i++;

        if (controle == 0) break;
    }
}

// Demais leituras
void ler_curso_T(curso lista_cursos_S[],
                 curso lista_cursos_T[],
                 int &contT,
                 int contS) {

    int i = 0;
    contT = 0;
    int controle = 0;

    for (; i < T_CURSO;) {

        if (contS == T_CURSO) {

            string pause = " ";
            cout << "\n Limite alcançado! Você NÃO pode adicionar mais cursos!";
            cout << "\n Pressione qualquer tecla para continuar: \n";
            cin.ignore();
            getline(cin, pause);
            break;
        }

        curso curso_controle;
        int is_duplicado;

        cout << "-----Leitura Curso-----";

        cout << "\nDigite o código            : ";
        cin >> curso_controle.codigo;
        cin.ignore();

        is_duplicado = validate_curso(lista_cursos_S, contS, curso_controle.codigo);
        is_duplicado += validate_curso(lista_cursos_T, contT, curso_controle.codigo);

        if (is_duplicado >= -1) {
                
            cout << "\nCódigo duplicado!!!";
            cout << "\nDigite um código diferente\n\n";
            continue;
        }

        cout << "Digite a descrição do curso: ";
        getline(cin, curso_controle.descricao);

        cout << "Digite o valor por aula    : ";
        cin >> curso_controle.valor_por_aula;

        lista_cursos_T[contT] = curso_controle;

        cout << "\nDeseja adicionar mais um curso? (0 = NAO) (1 = SIM)\n";
        cin >> controle;

        contT++;
        contS++;
        i++;

        if (controle == 0) break;
    }
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