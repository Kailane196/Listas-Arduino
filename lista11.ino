#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define ex6

#ifdef ex1
/*Receba 2 string de ate 10 caracteres via teclado na funcao main().
Faça uma funcao para compara-las usando ponteiros e retorne como resultado se sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
Imprima o resultado na funcao main(). Declare os vetores como variavel global.*/

char s1[10];
char s2[10];

int compara(char *s1, char *s2)
{
    if (strcmp(s1, s2)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int res;

    do
    {
        printf("Digite a primeira string: ");
        scanf("%10s", s1);

        printf("Digite a segunda string: ");
        scanf("%10s", s2);

        int r = compara(s1, s2);

        if (r)
        {
            printf("Iguais\n");
        }
        else
        {
            printf("Diferentes\n");
        }

        printf("\n Deseja continuar? (1-Sim / 0-Não)");
        scanf("%d", &res);
        system("cls");

        getchar();
        if (res == 0)
            break;

    }
    while (res!=0);

    return 0;
}
#endif

#ifdef ex2
/*Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao para a funcao a letra digitada usando ponteiros.(utilize o comando return).
O vetor deve ser declarado como variavel global.
Vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

char v[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int pesquisa(char *l)
{
    int i;
    for (i = 0; i < sizeof(v); i++)
    {
        if (*l == v[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int res;
    do
    {
        setlocale(LC_ALL, "Portuguese");
        char l;
        printf("Digite uma letra: ");
        scanf("%c", &l);

        if (pesquisa(&l))
        {
            printf("A letra existe no vetor\n");
        }
        else
        {
            printf("A letra não existe no vetor\n");
        }

        printf("\n Deseja continuar? (1-Sim / 0-Não)");
        scanf("%d", &res);
        system("cls");

        getchar();
        if (res == 0)
            break;

    }
    while (res!=0);

    return 0;
}
#endif

#ifdef ex3
/*Escreva um programa que receba via teclado usando ponteiros um char, int, long, unsigned, float, double, unsigned long e unsigned char, e imprima-os no video utilizando ponteiros no seguinte formato:

           10        20        30        40        50        60
   123456789012345678901234567890123456789012345678901234567890
       int                 long                unsigned
                 float               double              char
            unsigned long       unsigned char*/

struct variaveis
{
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};
struct variaveis v;

void scan(struct variaveis *pv);
void print(struct variaveis *pv);

int main()
{
    int continuar;
    struct variaveis *pv;
    pv = &v;

    do
    {
        scan(pv);
        print(pv);

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

void scan(struct variaveis *pv)
{
    printf("Digite um caractere:");
    scanf(" %c", &pv->c);

    printf("Digite um numero inteiro:");
    scanf("%d", &pv->i);

    printf("Digite um numero long:");
    scanf("%ld", &pv->l);

    printf("Digite um numero decimal:");
    scanf("%f", &pv->f);

    printf("Digite um decimal longo:");
    scanf("%lf", &pv->d);

    printf("Digite um caractere unsigned:");
    scanf(" %c", &pv->uc);

    printf("Digite um numero inteiro unsigned:");
    scanf("%u", &pv->ui);

    printf("Digite um numero longo unsigned:");
    scanf("%lu", &pv->ul);
}

void print(struct variaveis *pv)
{
    printf("\n10        20        30        40        50        60");
    printf("\n12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%5c", pv->c);
    printf("%10d", pv->i);
    printf("%10ld", pv->l);
    printf("%20.2lf", pv->f);
    printf("%20.7f", pv->d);
    printf("\n%11c", pv->uc);
    printf("%20u", pv->ui);
    printf("%20lu", pv->ul);
}
#endif
#ifdef ex4
/*Escreva um programa que receba via teclado numeros inteiros positivos usando ponteiros.
Quando o numero digitado for negativo o programa deve parar e calcula a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser feitos usando ponteiro*/

int main()
{
    int res;

    do
    {
        setlocale(LC_ALL, "Portuguese");
        int n,soma=0,c=0;
        int *pn = &n;

        printf("Digite números positivos (digite um número negativo para parar):\n");

        while (1)
        {
            scanf("%d", pn);

            if (*pn < 0)
                break;

            soma += *pn;
            c++;
        }

        if (c>0)
        {
            float media=(float)soma/c;
            printf("Média:%.2f\n", media);
        }
        else
        {
            printf("Número inválido\n");
        }

        printf("\n Deseja continuar? (1-Sim / 0-Não) ");
        scanf("%d", &res);
        system("cls");

        getchar();
        if (res == 0)
            break;

    }
    while (res!=0);

    return 0;
}
#endif

#ifdef ex5
/*Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado usando ponteiros.
Calcule e exiba o numero de dias entre as duas datas usando ponteiros. Utilize um vetor de estruturas.
Estrutura: dia, mes e ano*/

#include <stdio.h>

int diasnomes(int mes, int ano);
int diferenca(struct data1 *d1, struct data2 *d2);
int bi(int ano);

struct data1
{
    int dia1;
    int mes1;
    int ano1;
};

struct data2
{
    int dia2;
    int mes2;
    int ano2;
};

int main()
{
    struct data1 d1;
    struct data2 d2;
    int continuar;

    do
    {
        printf("Digite a primeira data: ");
        scanf("%d %d %d", &d1.dia1, &d1.mes1, &d1.ano1);

        printf("Digite a segunda data: ");
        scanf("%d %d %d", &d2.dia2, &d2.mes2, &d2.ano2);

        int dif = diferenca(&d1, &d2);

        printf("Diferenca de dias: %d\n", dif);

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

int bi(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    else
        return 0;
}

int diasnomes(int mes, int ano)
{
    if (mes == 2)
    {
        if (bi(ano))
            return 29;
        else
            return 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

int diferenca(struct data1 *d1, struct data2 *d2)
{
    int total = 0;

    for (int i = d1->mes1; i <= 12; i++)
    {
        if (i == d1->mes1)
            total += diasnomes(d1->mes1, d1->ano1) - d1->dia1;
        else
            total += diasnomes(i, d1->ano1);
    }

    for (int i = d1->ano1 + 1; i < d2->ano2; i++)
    {
        if (bi(i))
            total += 366;
        else
            total += 365;
    }

    for (int i = 1; i <= d2->mes2; i++)
    {
        if (i == d2->mes2)
            total += d2->dia2;
        else
            total += diasnomes(i, d2->ano2);
    }

    return total;
}
#endif

#ifdef ex6
/*Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos. Receba os dados via teclado numa funcao usando ponteiros.
Imprima os dados recebidos no video numa usando ponteiros. Utilize um comando de loop.
O vetor de estruturas de ser declarado como variavel global.
Estrutura: nome, end, cidade, estado, cep*/

struct dados
{
    char nome[30];
    char endereco[50];
    char cidade[20];
    char estado[20];
    char cep[10];
};
struct dados v[4];

void scan(struct dados *ptr)
{
    printf("Digite o nome: ");
    scanf(" %s", ptr->nome);

    printf("Digite o endereco: ");
    scanf(" %s", ptr->endereco);

    printf("Digite a cidade: ");
    scanf(" %s", ptr->cidade);

    printf("Digite o estado: ");
    scanf(" %s", ptr->estado);

    printf("Digite o CEP: ");
    scanf(" %s", ptr->cep);
}

void print(struct dados *ptr)
{
    printf("Nome: %s\n", ptr->nome);
    printf("Endereco: %s\n", ptr->endereco);
    printf("Cidade: %s\n", ptr->cidade);
    printf("Estado: %s\n", ptr->estado);
    printf("CEP: %s\n", ptr->cep);
}

int main()
{
    int continuar;

    do
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            printf("%d usuario: \n", i+1);
            scan(&v[i]);
        }

        for (i = 0; i < 4; i++)
        {
            printf("%d usuario: \n", i+1);
            print(&v[i]);
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
