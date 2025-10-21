#include <stdio.h>

int main(void) {
    int totalAlunos, totalMaterias;
    char nomeAluno[50], nomeMateria[50];
    float nota, somaNotas, media;

    printf("Quantos alunos serao cadastrados? ");
    scanf("%d", &totalAlunos);

    for (int i = 1; i <= totalAlunos; i++) {
        printf("\nDigite o nome do aluno %d (sem espacos): ", i);
        scanf("%s", nomeAluno);

        printf("Quantas materias o aluno tem? ");
        scanf("%d", &totalMaterias);

        somaNotas = 0;

        for (int j = 1; j <= totalMaterias; j++) {
            printf("\nDigite o nome da materia %d (sem espacos): ", j);
            scanf("%s", nomeMateria);

            printf("Digite a nota em %s: ", nomeMateria);
            scanf("%f", &nota);

            somaNotas += nota;
        }

        media = somaNotas / totalMaterias;

        printf("\n------------------------------------------\n");
        printf("Aluno: %s\n", nomeAluno);
        printf("Media: %.2f\n", media);

        if (media >= 6.0) {
            printf("Status: Aprovado\n");
        } else {
            printf("Status: Reprovado\n");
        }
        printf("------------------------------------------\n");
    }

    return 0;
}