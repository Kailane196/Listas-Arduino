#include <stdio.h>

#define ex4

#ifdef ex1
/*Escreva um programa que tem uma estrutura da dados com os membros abaixo.
Receba dados via teclado em uma funcao e imprima estes conteudos no video, em outra funcao, no seguinte formato.
Estrutura: char, int, long, float, double, unsigned char, unsigned int, unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

void scan();
void print();

main()
{
    int continuar;

    do
    {
        scan();
        print();

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);
}

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

void scan()
{
    printf("Digite um caractere:");
    scanf(" %c",&v.c);

    printf("Digite um numero inteiro:");
    scanf("%d",&v.i);

    printf("Digite um numero longo:");
    scanf("%ld",&v.l);

    printf("Digite um numero decimal:");
    scanf("%f",&v.f);

    printf("Digite um numero decimal longo:");
    scanf("%lf",&v.d);

    printf("Digite um caractere unsigned:");
    scanf(" %c",&v.uc);

    printf("Digite um numero inteiro unsigned:");
    scanf("%d",&v.ui);

    printf("Digite um numero longo unsigned:");
    scanf("%lu",&v.ul);
}

void print()
{
    printf("\n        10        20        30        40        50       ");
    printf("\n1234567890123456789012345678901234567890123456789012345");
    printf("\n%5c",v.c);
    printf("%10d",v.i);
    printf("%10d",v.l);
    printf("%20.2f",v.f);
    printf("%20.7f",v.d);
    printf("\n%10c",v.uc);
    printf("%20u",v.ui);
    printf("%20lu",v.ul);
}
#endif // ex1

#ifdef ex2
/*Escreva um programa com a estrutura de dados abaixo. Defina um vetor de estruturas de 4 elementos.
Receba os dados pelo teclado em uma funcao e imprima-os no video em uma funcao.
Utilize vetor de estruturas. Faça um menu com uma opcao para saida do programa.
Estrutura: nome, end, cidade, estado, cep*/

void scan();
void print();

struct dados
{
    char nome[20];
    char end[20];
    char cid[15];
    char est[2];
    char cep[8];
};
struct dados v[4];

main()
{
    int continuar,op;

    do
    {
        printf("Menu\n1-Entrada de dados\n2-Listar dados\n3-Sair\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
        {
            scan();
        }
        break;
        case 2:
        {
            print();
        }
        break;
        case 3:
        {
            printf("\nEncerrando");
        }
        break;
        }
    }
    while(op!=3);
}

void scan()
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("Nome: ");
        scanf(" %s",v[i].nome);
        printf("Endereço: ");
        scanf(" %s",v[i].end);
        printf("Cidade: ");
        scanf(" %s",v[i].cid);
        printf("Estado: ");
        scanf(" %s",v[i].est);
        printf("CEP: ");
        scanf(" %s",v[i].cep);
    }
}

void print()
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("%d nome: %s\n",i+1,v[i].nome);
        printf("%d endereco: %s\n",i+1,v[i].end);
        printf("%d cidade: %s\n",i+1,v[i].cid);
        printf("%d estado: %s\n",i+1,v[i].est);
        printf("%d CEP: %s\n",i+1,v[i].cep);
    }
}
#endif // ex2

#ifdef ex3
/*Escreva um programa com a estrutura de dados abaixo. Defina um vetor de estrutura de 4 elementos.
Receba dados via teclado e imprima-os no video.
Faça um menu com as seguintes opcoes:
1 - receber todos os dados
2 - imprime todos os dados
3 - calcula o IMC de todas as pessoas.
4 - sair
Calculo do IMC = peso/(altura*altura).
Estrutura: nome, peso, altura*/

void print();
void scan();
void imc();

struct dados
{
    char nome[30];
    float peso;
    float alt;
};
struct dados v[4];

main()
{
    int op;

    do
    {
        printf("Menu\n1-Entrada de dados\n2-Listar dados\n3-IMC\n4-Sair\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
        {
            scan();
        }
        break;
        case 2:
        {
            print();
        }
        break;
        case 3:
        {
            imc();
        }
        break;
        case 4:
        {
            printf("\nEncerrando");
        }
        break;
        }
    }
    while(op!=4);
}

void print()
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("%d nome: %s\n",i+1,v[i].nome);
        printf("%d peso: %.2f\n",i+1,v[i].peso);
        printf("%d altura: %.2f\n",i+1,v[i].alt);
    }
}

void scan()
{
    int i;
    for(i=0; i<4; i++)
    {
        printf("Nome: ");
        scanf(" %s",v[i].nome);
        printf("Peso: ");
        scanf("%f", &v[i].peso);
        printf("Altura: ");
        scanf("%f", &v[i].alt);
    }
}

void imc()
{
    for(int i = 0; i < 4; i++)
    {
        float imc=(v[i].peso/(v[i].alt*v[i].alt));
        printf("%s IMC: %.2f\n",v[i].nome,imc);
    }
}
#endif // ex3

#ifdef ex4
/*Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via teclado na funcao main().
Faca uma funcao que calcule o numero de dias entre elas e mostre o resultado no video na funcao main().
Utilize vetor de estruturas.
Estrutura: dia, mes, ano*/

#include <stdio.h>

int diasnomes(int mes, int ano);
int diferenca(struct data1 d1, struct data2 d2);
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

        int dif = diferenca(d1, d2);

        printf("Diferenca de dias: %d\n", dif);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
    }
    while(continuar==1);
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

int diferenca(struct data1 d1, struct data2 d2)
{
    int total = 0;

    for (int i = d1.mes1; i <= 12; i++)
    {
        if (i == d1.mes1)
            total += diasnomes(d1.mes1, d1.ano1) - d1.dia1;
        else
            total += diasnomes(i, d1.ano1);
    }

    for (int i = d1.ano1 + 1; i < d2.ano2; i++)
    {
        if (bi(i))
            total += 366;
        else
            total += 365;
    }

    for (int i = 1; i <= d2.mes2; i++)
    {
        if (i == d2.mes2)
            total += d2.dia2;
        else
            total += diasnomes(i, d2.ano2);
    }

    return total;
}
#endif // ex4
