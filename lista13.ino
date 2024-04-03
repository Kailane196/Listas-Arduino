#include <stdio.h>

#define ex5

#ifdef ex1
/*Escreva um programa que receba via teclado 2 numeros inteiros e imprima-os no video com o resultado das 4 operacoes aritmeticas.*/

float div(int a, int b);
int mult(int a,int b);
int soma(int a,int b);
int sub(int a,int b);

main()
{
    int continuar;
    do
    {
        int num1=0,num2=0;

        printf("Digite um numero:\n");
        scanf("%d",&num1);

        printf("Digite outro numero:\n");
        scanf("%d",&num2);

        printf("Soma: %d\n", soma(num1,num2));
        printf("Subtracao: %d\n", sub(num1,num2));
        printf("Divisao: %.2f\n", div(num1,num2));
        printf("Multiplicacao: %d\n", mult(num1,num2));

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
        system("cls");
    }
    while(continuar==1);
}

int soma(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

float div(int a, int b)
{
    return (float) a/b;
}

int mult(int a, int b)
{
    return a*b;
}
#endif // ex1

#ifdef ex2
/*Reescreva o exercicio anterior utilizando operadores de atribuicao composta.*/

float div(int a, int b);
int mult(int a,int b);
int soma(int a,int b);
int sub(int a,int b);

main()
{
    int continuar;

    do
    {
        int num1=0,num2=0;

        printf("Digite um numero:\n");
        scanf("%d",&num1);

        printf("Digite outro numero:\n");
        scanf("%d",&num2);

        printf("Soma: %d\n", soma(num1,num2));
        printf("Subtracao: %d\n", sub(num1,num2));
        printf("Divisao: %.2f\n", div(num1,num2));
        printf("Multiplicacao: %d\n", mult(num1,num2));

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
        system("cls");
    }
    while(continuar==1);
}

int soma(int a, int b)
{
    a+=b;
    return a;
}

int sub(int a, int b)
{
    a-=b;
    return a;
}

float div(int a, int b)
{
    float aux;
    aux=(float) a/b;
    return (float) aux;
}

int mult(int a, int b)
{
    a*=b;
    return a;
}
#endif // ex2

#ifdef ex3
/*Escreva um programa para determinar a idade de uma pessoa, em anos, meses e dias.
Recebendo via teclado a data (dia, mes e ano) do seu nascimento e a data (dia, mes e ano) atual.*/

int main()
{
    int dn,mn,an,da,ma,aa,ano,mes,dia;

    printf("Digite a data de nascimento (DD MM AAAA):\n");
    scanf("%d %d %d", &dn,&mn,&an);

    printf("Digite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &da,&ma,&aa);

    ano=aa-an;
    mes=ma-mn;
    dia=da-dn;

    if (mes<0)
    {
        ano--;
        mes+=12;
    }

    if (dia<0)
    {
        if (ma== 1 || ma== 3 || ma== 5 || ma== 7 || ma== 8 || ma== 10 || ma== 12)
        {
            dia += 31;
        }
        else if (ma== 4 || ma== 6 || ma== 9 || ma== 11)
        {
            dia += 30;
        }
        else
        {
            if ((aa % 4 == 0 && aa % 100 != 0) || aa % 400 == 0)
            {
                dia += 29;
            }
            else
            {
                dia += 28;
            }
        }
        mes--;
    }

    printf("Sua idade é %d anos, %d meses e %d dias.\n", ano,mes,dia);

    return 0;
}
/*
int anos(aa,an)
{
    return aa-an;
}*/
#endif // ex3

#ifdef ex4
/*Escreva um programa que receba via teclado 2 numeros inteiros e execute as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO.
Imprima-os no video no formato decimal e hexadecimal.*/

main()
{
    int continuar;
    do
    {
        int num1=0,num2=0;

        printf("Digite um numero:\n");
        scanf("%d",&num1);
        printf("Digite outro numero:\n");
        scanf("%d",&num2);

        printf("AND Dec: %3d  Hex: 0x%x\n",num1 & num2,num1 & num2);
        printf("OU Dec: %3d  Hex: 0x%x\n",num1 | num2,num1 | num2);
        printf("OU EXCLUSIVO Dec: %3d  Hex: 0x%x\n",num1 ^ num2,num1 ^ num2);

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
        system("cls");
    }
    while(continuar==1);
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba via teclado uma data (dia, mes, e ano). Determine o dia da semana desta data.*/

#include <stdio.h>

int main()
{
    int continuar;
    do
    {
        int dia, mes, ano, total;

        printf("Digite uma data (DD MM AAAA):\n");
        scanf("%d %d %d", &dia, &mes, &ano);

        int a = (14 - mes) / 12;
        int y = ano - a;
        int m = mes + 12 * a - 2;
        int d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;

        switch (d)
        {
        case 0:
            printf("Domingo");
            break;
        case 1:
            printf("Segunda");
            break;
        case 2:
            printf("Terca");
            break;
        case 3:
            printf("Quarta");
            break;
        case 4:
            printf("Quinta");
            break;
        case 5:
            printf("Sexta");
            break;
        case 6:
            printf("Sabado");
            break;
        }

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);
        system("cls");
    }
    while(continuar==1);
}

#endif // ex5
