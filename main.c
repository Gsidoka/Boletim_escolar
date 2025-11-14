/*
 * =====================================================================================
 *
 * Nome do Projeto:  Boletim Escolar
 * Autor(es):        Guilherme da Silva Rodrigues e Guilherme Vieira Lima.    
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 

/* Constantes */

// Define a média necessária para aprovação
#define MEDIA_APROVACAO 6.0

// Define o tamanho máximo para nomes
#define TAMANHO_NOME 50

/* Protótipos das Funções */

// Exibe o menu principal
void exibirMenu(void);

// Lê e retorna a opção do usuário
int obterOpcao(void);

// Inicia o cadastro e o loop de alunos
void iniciarAnalise(void);

// Coleta notas e processa a média do aluno
float processarNotasDeUmAluno(void);

// Exibe o resultado final do aluno
void exibirResultado(char nome[], float media);

// Função principal que controla o fluxo do programa
int main() {
    

    int opcao;

    printf("--- Bem-vindo ao Sistema de Boletim Escolar! ---\n");

    // Loop principal do menu
    do {
        exibirMenu();
        opcao = obterOpcao();

        switch (opcao) {
            case 1:
                printf("\n1. Iniciando Cadastro de Notas...\n");
                iniciarAnalise(); 
                break;
            case 0:
                printf("\nSaindo do programa. Obrigado!\n");
                break;
            default:
                printf("\nErro: Opcao invalida! Tente novamente.\n");
        }

      

    } while (opcao != 0);

    return 0;
}

/* Implementação das Funções */

// Exibe o menu principal
void exibirMenu(void) {
    printf("\n--- Menu Principal ---\n");
    printf("1. Iniciar Cadastro de Notas\n");
    printf("0. Sair\n");
    printf("------------------------\n");
    printf("Escolha uma opcao: ");
}

// Lê e retorna a opção do usuário
int obterOpcao(void) {
    int opcao;
    int resultadoScan;

    resultadoScan = scanf("%d", &opcao);

    // Validação de entrada (se digitou letra)
    if (resultadoScan != 1) {
        fflush(stdin); 
        return -1;
    }
    
    fflush(stdin); 
    return opcao;
}

// Inicia o cadastro de alunos
void iniciarAnalise(void) {
    int totalAlunos;
    char nomeAluno[TAMANHO_NOME];
    float mediaFinal;

    printf("Quantos alunos serao cadastrados? ");
    scanf("%d", &totalAlunos);
    fflush(stdin);

    for (int i = 1; i <= totalAlunos; i++) {
        
        printf("\nDigite o nome do aluno %d (sem espacos): ", i);
        scanf("%s", nomeAluno); 
        fflush(stdin);

        mediaFinal = processarNotasDeUmAluno();

        exibirResultado(nomeAluno, mediaFinal);
    } 
    
    printf("\nCadastro de %d alunos concluido.\n", totalAlunos);
}


// Coleta notas e processa a média do aluno
float processarNotasDeUmAluno(void) {
    int totalMaterias;
    char nomeMateria[TAMANHO_NOME]; 
    float nota, somaNotas = 0;
    
    printf("Quantas materias o aluno tem? ");
    scanf("%d", &totalMaterias);
    fflush(stdin);

    for (int j = 1; j <= totalMaterias; j++) {
        
        printf("  Digite o nome da materia %d (sem espacos): ", j);
        scanf("%s", nomeMateria); 
        fflush(stdin);

        printf("  Digite a nota em %s: ", nomeMateria);
        scanf("%f", &nota);
        fflush(stdin);

        if (nota < 0.0) nota = 0.0;
        if (nota > 10.0) nota = 10.0;

        somaNotas += nota;
    } 

    if (totalMaterias > 0) {
        return somaNotas / totalMaterias;
    } else {
        return 0.0;
    }
}

// Exibe o resultado final do aluno
void exibirResultado(char nome[], float media) {
    printf("\n------------------------------------------\n");
    printf(" Aluno:  %s\n", nome);
    printf(" Media:  %.2f\n", media); 

    if (media >= MEDIA_APROVACAO) {
        printf(" Status: Aprovado\n"); 
    } else {
        printf(" Status: Reprovado\n"); 
    }
    printf("------------------------------------------\n");
}
