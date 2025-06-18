#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- DEFINIÇÕES DE CORES ANSI ---
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_ORANGE  "\x1b[33m" 


// Definição da estrutura para o aluno
struct Aluno {
    char nomeCompleto[100];
    char dataNascimento[11]; // DD/MM/AAAA
    char matricula[11];      // Máximo 10 dígitos + '\0'
    int idade;
};

#define MAX_ALUNOS 100 // Capacidade máxima de alunos

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunosCadastrados = 0;
    int opcao;
    char continuarMenu = 'S';

    // Limpa a tela no início
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Título inicial (não faz parte do loop)
    printf(ANSI_COLOR_YELLOW "===================================\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN  "        CADASTRO DE ALUNOS         \n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "===================================\n" ANSI_COLOR_RESET);

    while (continuarMenu == 'S' || continuarMenu == 's') {
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // Cabeçalho e Menu Principal com cores
        printf(ANSI_COLOR_YELLOW "========================================\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN  "          CADASTRO DE ALUNOS            \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "========================================\n" ANSI_COLOR_RESET);

        printf(ANSI_COLOR_YELLOW "  --------- Menu Principal ---------\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE   "     1.    Adicionar Novo Aluno  \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN  "     2. Verificar Alunos Cadastrados\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_ORANGE "     3.      Remover Aluno        \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "     4.        Creditos           \n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED    "     0.          Sair             \n" ANSI_COLOR_RESET);
        printf("Escolha uma opcao: ");
 
        // Validação da entrada do menu (recria o menu colorido em caso de erro)
        while (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 4) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            printf(ANSI_COLOR_YELLOW "=================================\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_GREEN  "       CADASTRO DE ALUNOS        \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_YELLOW "=================================\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_YELLOW "\n   --------- Menu Principal ---------\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_BLUE   "     1.    Adicionar Novo Aluno  \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_GREEN  "     2. Verificar Alunos Cadastrados\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_ORANGE "     3.      Remover Aluno        \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_YELLOW "     4.        Creditos           \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_RED    "     0.          Sair             \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_RED "Opcao invalida." ANSI_COLOR_RESET " Por favor, digite um numero entre 0 e 4: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        switch (opcao) {
            case 1: { // Adicionar Novo Aluno
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                if (numAlunosCadastrados < MAX_ALUNOS) {
                    struct Aluno novoAluno;
                    char confirmacao;
                    int erroEdicao = 1;

                    while (erroEdicao) {
                        #ifdef _WIN32
                            system("cls");
                        #else
                            system("clear");
                        #endif
                        memset(&novoAluno, 0, sizeof(struct Aluno));

                        // 1. Nome Completo
                        int nomeValido = 0;
                        while (!nomeValido) {
                            printf(ANSI_COLOR_BLUE "--- Adicionar Novo Aluno ---\n" ANSI_COLOR_RESET);
                            printf("Digite o nome completo do aluno: ");
                            fgets(novoAluno.nomeCompleto, sizeof(novoAluno.nomeCompleto), stdin);
                            novoAluno.nomeCompleto[strcspn(novoAluno.nomeCompleto, "\n")] = '\0';

                            nomeValido = 1;
                            for (int i = 0; i < strlen(novoAluno.nomeCompleto); i++) {
                                char c = novoAluno.nomeCompleto[i];
                                if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && c != ' ') {
                                    nomeValido = 0;
                                    printf(ANSI_COLOR_RED "Nome invalido. Digite apenas caracteres. Tente novamente.\n" ANSI_COLOR_RESET);
                                    printf("Pressione ENTER para continuar...");
                                    while(getchar() != '\n');
                                    break;
                                }
                            }
                        }
                        
                        
                        
                        // Confirmação final
                        printf(ANSI_COLOR_GREEN "Aluno cadastrado com sucesso!\n" ANSI_COLOR_RESET);
                        printf("Pressione ENTER para voltar ao menu principal...");
                        while(getchar() != '\n');
                    }
                } else {
                    printf(ANSI_COLOR_RED "Limite maximo de alunos atingido.\n" ANSI_COLOR_RESET);
                    printf("Pressione ENTER para voltar ao menu principal...");
                    while(getchar() != '\n');
                }
                break;
            }
            case 2: { // Verificar Alunos Cadastrados
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                if (numAlunosCadastrados == 0) {
                    printf("Nenhum aluno cadastrado ainda.\n");
                } else {
                    printf(ANSI_COLOR_GREEN "\n--- Alunos Cadastrados ---\n" ANSI_COLOR_RESET);
                    for (int i = 0; i < numAlunosCadastrados; i++) {
                        printf("Aluno %d:\n", i + 1);
                        printf("  Nome: %s\n", alunos[i].nomeCompleto);
                        printf("  Matricula: %s\n", alunos[i].matricula);
                        printf("  Data de Nascimento: %s\n", alunos[i].dataNascimento);
                        printf("  Idade: %d anos\n", alunos[i].idade);
                        printf(ANSI_COLOR_GREEN "------------------------\n" ANSI_COLOR_RESET);
                    }
                }
                printf("\nPressione ENTER para voltar ao menu principal...");
                while(getchar() != '\n');
                break;
            }
            case 3: { // Remover Aluno
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                if (numAlunosCadastrados == 0) {
                    printf("Nenhum aluno para remover.\n");
                } else {
                    // ... Lógica de remoção ...
                }
                printf("Pressione ENTER para voltar ao menu principal...");
                while(getchar() != '\n');
                break;
            }
            case 4: { // Créditos
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                printf("\n");
                printf(ANSI_COLOR_YELLOW "==========================================\n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_YELLOW "        ARTHUR DE OLIVEIRA BORGES         \n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_YELLOW "               2512130009                 \n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_YELLOW "==========================================\n" ANSI_COLOR_RESET);
                printf("\n");
                printf("Pressione ENTER para voltar ao menu principal...");
                while(getchar() != '\n');
                break;
            }
            case 0: { // Sair
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                printf(ANSI_COLOR_RED "Saindo do sistema de cadastro. Ate mais!\n" ANSI_COLOR_RESET);
                continuarMenu = 'N'; 
                break;
            }
            default: {
                printf(ANSI_COLOR_RED "Opcao invalida. Pressione ENTER para tentar novamente." ANSI_COLOR_RESET);
                while(getchar() != '\n');
                break;
            }
        }
    }

    return 0;
}