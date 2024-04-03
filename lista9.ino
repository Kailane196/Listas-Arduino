#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex1

#ifdef ex1
/*Escreva um programa que receba n valores via teclado e receba tambem a operação a ser executada.
Quando for digitado "=" o programa deve mostrar o resultado acumulado dos n valores.
As operações aritmeticas e a entrada de dados devem ser funcoes que recebe os valores usando ponteiros.
As variaveis sao LOCAIS na funcao main()*/

void scan(int* num, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%dº número:\n", i + 1);
        scanf("%d", &num[i]);
    }
}

char digita() {
    char d;
    printf("Digite a operação desejada ou '=' para calcular o resultado:\n");
    scanf(" %c", &d);
    return d;
}

int calculo(int* num, int n, char d) {
    int total = num[0];
    int i;
    for (i = 1; i < n; i++) {
        switch (d) {
            case '+':
                total += num[i];
                break;
            case '-':
                total -= num[i];
                break;
            case '*':
                total *= num[i];
                break;
            case '/':
                total /= num[i];
                break;
            default:
                printf("Operação inválida\n");
                return 0;
        }
    }
    return total;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int continuar;

    do {
        int n;

        printf("Digite a quantidade de números:\n");
        scanf("%d", &n);

        int num[n];

        scan(num, n);

        char d = digita();

        int total;

        if (d != '=') {
            total = calculo(num, n, d);
            printf("Resultado parcial: %d\n", total);
        } else {
            total = num[0];
            printf("Resultado final: %d\n", total);
        }

        printf("\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
        scanf("%d", &continuar);
    } while (continuar == 1);

    return 0;
}
#endif
#ifdef ex2
/*Escreva um programa que receba uma letra via teclado usando ponteiro.
Escreva uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
Imprima o resultado da pesquisa no video na funcao main().
Passe como informacao para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa usando ponteiros
(utilize o comando return).
O vetor deve ser declarado como variavel LOCAL na funcao main().

vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

int pesquisa(char l, char *v)
{
    while (*v != '\0')
    {
        if (*v == l)
        {
            return 1;
        }
        v++;
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int continuar;

    do
    {
        char l;
        char v[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y', '\0'};

        printf("Digite uma letra: ");
        scanf("%c", &l);

        if (pesquisa(l,v))
        {
            printf("A letra %c foi encontrada no vetor\n", l);
        }
        else
        {
            printf("A letra %c não foi encontrada no vetor\n", l);
        }

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);

    return 0;
}
#endif

#ifdef ex3
/*Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres passando como parametro ponteiro.
Os vetores devem ser declarados como variaveis LOCAIS na função main().
Escreva uma funcao para comparar as 2 strings.
Passe como parametros para a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1 ou se DIFERENTES 0.
Mostre o resultado no video na funcao main()*/

int cmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0')
    {
        return 1;
    }

    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int continuar;

    do
    {
        char str1[11], str2[11];

        printf("Digite a primeira string: ");
        scanf("%10s", str1);

        printf("Digite a segunda string: ");
        scanf("%10s", str2);

        int result = cmp(str1, str2);

        if (result)
        {
            printf("As strings são iguais\n");
        }
        else
        {
            printf("As strings são diferentes\n");
        }

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);

    return 0;
}
#endif
#ifdef ex4
/*Escreva um programa que tem uma estrutura da dados com os membros abaixo.
A estrutura e' uma variavel LOCAL na funcao main().
Receba via teclado o conteudo de cada um dos membros numa funcao e imprima-os no video no seguinte formato(também numa função).

Estrutura: char, int, long, float, double, unsigned char, unsigned int, unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

typedef struct
{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
} dados;

void scanf_dados(dados* pv);
void print_dados(dados* pv);

int main()
{
    int continuar;
    dados v;
    dados* pv = &v;

    do
    {
        scanf_dados(pv);
        print_dados(pv);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while (continuar != 1 && continuar != 0);
    }
    while (continuar == 1);

    return 0;
}

void scanf_dados(dados* pv)
{
    printf("Digite um caractere:");
    scanf(" %c", &(pv->c));

    printf("Digite um numero inteiro:");
    scanf("%d", &(pv->i));

    printf("Digite um numero longo:");
    scanf("%ld", &(pv->l));

    printf("Digite um numero decimal:");
    scanf("%f", &(pv->f));

    printf("Digite um numero decimal longo:");
    scanf("%lf", &(pv->d));

    printf("Digite um caractere unsigned:");
    scanf(" %c", &(pv->uc));

    printf("Digite um numero inteiro unsigned:");
    scanf("%u", &(pv->ui));

    printf("Digite um numero longo unsigned:");
    scanf("%lu", &(pv->ul));
}

void print_dados(dados* pv)
{
    printf("        10        20        30        40        50       ");
    printf("\n1234567890123456789012345678901234567890123456789012345");
    printf("\n%5c", pv->c);
    printf("%10d", pv->i);
    printf("%10ld", pv->l);
    printf("%20.2f", pv->f);
    printf("%20.7f", pv->d);
    printf("\n%10c", pv->uc);
    printf("%20u", pv->ui);
    printf("%20lu", pv->ul);
}
#endif
#ifdef ex5
/*Escreva um programa com a estrutura abaixo.
Defina um vetor de estruturas de 4 elementos como variavel LOCAL na funcao main().
Receba os 4 registros sequencialmente pelo teclado numa função e imprima todos os registros no video em outra funcao.
Faça um menu. Utilize ponteiros nas funcoes.
Coloque no menu a opção de sair tambem. Utilize o comando switch. (vetor de estruturas)
Estutura: nome, end, cidade, estado, cep*/

#define MAX_REGISTROS 4

struct Registro
{
    char nome[30];
    char endereco[50];
    char cidade[20];
    char estado[2];
    char cep[10];
};

void recebe(struct Registro* registros)
{
    for (int i = 0; i < MAX_REGISTROS; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", registros[i].nome);
        printf("Endereco: ");
        scanf(" %[^\n]", registros[i].endereco);
        printf("Cidade: ");
        scanf(" %[^\n]", registros[i].cidade);
        printf("Estado: ");
        scanf(" %[^\n]", registros[i].estado);
        printf("CEP: ");
        scanf(" %[^\n]", registros[i].cep);
    }
}

void imprime(struct Registro* registros)
{
    printf("Registros:\n");
    for (int i = 0; i < MAX_REGISTROS; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Endereco: %s\n", registros[i].endereco);
        printf("Cidade: %s\n", registros[i].cidade);
        printf("Estado: %s\n", registros[i].estado);
        printf("CEP: %s\n", registros[i].cep);
    }
}

int main()
{
    struct Registro registros[MAX_REGISTROS];
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1. Receber registros\n");
        printf("2. Imprimir registros\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            getchar();
            recebe(registros);
            break;
        case 2:
            imprime(registros);
            break;
        case 3:
            printf("Encerrando\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    }
    while (opcao != 3);

    return 0;
}
#endif

#ifdef ex6
/*Acrescente ao menu do exercicio anterior as funcoes de procura, altera e exclui um registro sempre usando ponteiros*/

#define MAX_REGISTROS 4

struct Registro
{
    char nome[30];
    char endereco[50];
    char cidade[20];
    char estado[2];
    char cep[10];
};

void recebe(struct Registro* registros)
{
    for (int i = 0; i < MAX_REGISTROS; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", registros[i].nome);
        printf("Endereco: ");
        scanf(" %[^\n]", registros[i].endereco);
        printf("Cidade: ");
        scanf(" %[^\n]", registros[i].cidade);
        printf("Estado: ");
        scanf(" %[^\n]", registros[i].estado);
        printf("CEP: ");
        scanf(" %[^\n]", registros[i].cep);
    }
}

void imprime(struct Registro* registros)
{
    printf("Registros:\n");
    for (int i = 0; i < MAX_REGISTROS; i++)
    {
        printf("Registro %d:\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Endereco: %s\n", registros[i].endereco);
        printf("Cidade: %s\n", registros[i].cidade);
        printf("Estado: %s\n", registros[i].estado);
        printf("CEP: %s\n", registros[i].cep);
    }
}

int busca(struct Registro* registros, char* nome)
{
    nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha

    for (int i = 0; i < MAX_REGISTROS; i++)
    {
        if (strcmp(registros[i].nome, nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void altera(struct Registro* registros)
{
    char nome[30];
    printf("Digite o nome do registro que deseja alterar: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    int indice = busca(registros, nome);
    if (indice != -1)
    {
        printf("Digite o novo endereco: \n");
        fgets(registros[indice].endereco, sizeof(registros[indice].endereco), stdin);
        printf("Digite a nova cidade: \n");
        fgets(registros[indice].cidade, sizeof(registros[indice].cidade), stdin);
        printf("Digite o novo estado: \n");
        fgets(registros[indice].estado, sizeof(registros[indice].estado), stdin);
        printf("Digite o novo CEP: \n");
        fgets(registros[indice].cep, sizeof(registros[indice].cep), stdin);
        printf("Registro alterado\n");
    }
    else
    {
        printf("Registro nao encontrado\n");
    }
}

void exclui(struct Registro* registros)
{
    char nome[30];
    printf("Digite o nome do registro que deseja excluir: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);

    // Remove o caractere de nova linha tanto da entrada do usuário quanto dos nomes nos registros
    nome[strcspn(nome, "\n")] = '\0';

    int indice = busca(registros, nome);
    if (indice != -1)
    {
        for (int i = indice; i < MAX_REGISTROS - 1; i++)
        {
            strcpy(registros[i].nome, registros[i + 1].nome);
            strcpy(registros[i].endereco, registros[i + 1].endereco);
            strcpy(registros[i].cidade, registros[i + 1].cidade);
            strcpy(registros[i].estado, registros[i + 1].estado);
            strcpy(registros[i].cep, registros[i + 1].cep);
        }
        printf("Registro excluido\n");
    }
    else
    {
        printf("Registro nao encontrado\n");
    }
}

int main()
{
    struct Registro registros[MAX_REGISTROS];
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1. Receber registros\n");
        printf("2. Imprimir registros\n");
        printf("3. Buscar registro\n");
        printf("4. Alterar registro\n");
        printf("5. Excluir registro\n");
        printf("6. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            getchar();
            recebe(registros);
            break;
        case 2:
            imprime(registros);
            break;
        case 3:
        {
            char nome[30];
            printf("Digite o nome do registro que deseja buscar: ");
            getchar();
            fgets(nome, sizeof(nome), stdin);
            int indice = busca(registros, nome);
            if (indice != -1)
            {
                printf("Registro encontrado:\n");
                printf("Nome: %s\n", registros[indice].nome);
                printf("Endereco: %s\n", registros[indice].endereco);
                printf("Cidade: %s\n", registros[indice].cidade);
                printf("Estado: %s\n", registros[indice].estado);
                printf("CEP: %s\n", registros[indice].cep);
            }
            else
            {
                printf("Registro nao encontrado.\n");
            }
            break;
        }
        case 4:
            altera(registros);
            break;
        case 5:
            exclui(registros);
            break;
        case 6:
            printf("Encerrando\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    }
    while (opcao != 6);

    return 0;
}
#endif