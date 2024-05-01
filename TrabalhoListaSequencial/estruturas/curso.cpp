// curso.cpp
#define T_CURSO 5

struct curso {
    int codigo;
    string descricao;
    float valor_por_aula;
};

// Funções de curso
void ler_curso(curso lista_cursos[T_CURSO]) {

    int controle = 0;

    cout << "\n-----Leitura Curso-----";

    for (int i = 0; i < T_CURSO; i++) {
    
        cout << "\nDigite o código: ";
        cin >> lista_cursos[i].codigo;
        cin.ignore();

        cout << " Digite a descrição do curso: ";
        getline(cin, lista_cursos[i].descricao);

        cout << "  Digite o valor por aula: ";
        cin >> lista_cursos[i].valor_por_aula;

        cout << "\nDeseja adicionar mais um curso? [" << i+1 << "] restantes\n(0 = N) (1 = S)";
        cin >> controle;

        if (controle == 0) {
            break;
        }
        
    }
}