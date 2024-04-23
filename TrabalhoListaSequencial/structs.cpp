// structs.cpp
struct cidade {
    int codigo;
    string nome;
    char estado[2];
};

struct curso {
    int codigo;
    string descricao;
    double valor_por_aula;
};

struct instrutor {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct aluno {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct turmas {
    int codigo;
    int codigo_curso;
    int codigo_instrutor;
    int total_participantes;
    int qtd_max_participantes;
};

struct matriculas {
    int codigo;
    int codigo_aluno;
    int codigo_turma;
    int qtd_aula;
    double valor_total;
};