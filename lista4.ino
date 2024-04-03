#include <stdio.h>

#define ex5

#ifdef ex1
/*Escreva um programa que receba um vetor de inteiros com tamanho 10 e o decomponha em dois outros vetores.
Um tera´ as componentes de ordem impar e o outro tera´ as componentes de ordem par.
Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/

int main()
{
    int continuar;

    do
    {
        int v[10],w[10],u[10];
        int c,p=0,i=0;

        for(c=0; c<10; c++)
        {
            printf("Digite o %d valor do vetor:\n",c+1);
            scanf("%d", &v[c]);
        }

        for(c=0; c<10; c++)
        {
            if(c % 2 == 0)
            {
                w[p] = v[c];
                p++;
            }
            else
            {
                u[i]=v[c];
                i++;
            }
        }

        printf("\nImpar:\n");
        for(c=0; c<p; c++)
        {
            printf("%d ", w[c]);
        }

        printf("\n\nPar:\n");
        for(c=0; c<i; c++)
        {
            printf("%d ", u[c]);
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
#endif // ex1

#ifdef ex2
/*Escreva um programa que receba um vetor de inteiros com tamanho 10 e o decomponha em dois outros vetores.
Um tera´ as componentes de valor impar e o outro tera´ as componentes de valor par.
Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.*/

int main()
{
    int continuar;

    do
    {
        int v[10],w[10],u[10];
        int c,p=0,i=0;

        for(c=0; c<10; c++)
        {
            printf("Digite o %d valor do vetor:\n",c+1);
            scanf("%d", &v[c]);
        }

        for(c=0; c<10; c++)
        {
            if(v[c] % 2 == 0)
            {
                w[p] = v[c];
                p++;
            }
            else
            {
                u[i]=v[c];
                i++;
            }
        }

        printf("\nPar:\n");
        for(c=0; c<p; c++)
        {
            printf("%d ", w[c]);
        }

        printf("\n\nImpar:\n");
        for(c=0; c<i; c++)
        {
            printf("%d ", u[c]);
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
#endif // ex2

#ifdef ex3
/*Defina 2 vetores bidimensionais do tipo inteiro de 2x3.
Escreva um programa que recebe os dados via teclado para esses 2 vetores.
Usando o operador adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o resultado em um 3 vetor.
Imprima na tela o indice, os valores e o resultado dos 6 elementos dos vetores.*/

main()
{
    int continuar;

    do
    {
        int v1[2][3], v2[2][3], v3[2][3];
        int c,c2;

        for(c=0; c<2; c++)
        {
            for(c2=0; c2<3; c2++)
            {
                printf("Digite o elemento da %d linha e da %d coluna do 1 vetor:\n", c+1,c2+1);
                scanf("%d", &v1[c][c2]);

                printf("Digite o elemento da %d linha e da %d coluna do 2 vetor:\n", c+1,c2+1);
                scanf("%d", &v2[c][c2]);

                v3[c][c2]=v1[c][c2]+v2[c][c2];
            }
        }

        for(c=0; c<2; c++)
        {
            for(c2=0; c2<3; c2++)
            {
                printf("%d ", v3[c][c2]);
            }
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
#endif // ex3

#ifdef ex4
/*Escreva um programa para receber via teclado em vetores 3 int, 3 long, 3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:
            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/

main()
{
    int continuar;

    do
    {
        int i[3],c;
        long int l[3];
        unsigned int u[3];
        float f[3];
        double d[3];

        for(c=0; c<3; c++)
        {
            printf("Digite um numero inteiro:");
            scanf("%d",&i[c]);
        }

        for(c=0; c<3; c++)
        {
            printf("Digite um numero inteiro longo:");
            scanf("%d",&l[c]);
        }

        for(c=0; c<3; c++)
        {
            printf("Digite um numero inteiro sem sinal:");
            scanf("%d",&u[c]);
        }

        for(c=0; c<3; c++)
        {
            printf("Digite um numero decimal:");
            scanf("%f",&f[c]);
        }

        for(c=0; c<3; c++)
        {
            printf("Digite um numero decimal longo:");
            scanf("%lf",&d[c]);
        }

        printf("        10        20        30        40        50       ");
        printf("\n1234567890123456789012345678901234567890123456789012345");
        for(c=0; c<3; c++)
        {
            printf("\n%5d",i[c]);
            printf("%20d",l[c]);
            printf("%25d",u[c]);
            printf("\n%15.1f",f[c]);
            printf("%30.7lf\n",d[c]);
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
#endif // ex4

#ifdef ex5
/*Receba via teclado 10 valores inteiros e ordene por ordem crescente assim que sao digitados. Guarde-os em um vetor.
Mostre ao final os valores ordenados.*/

main()
{
    int continuar;

    do
    {
        int v[10],num[10],aux,c,i;

        for(c=0; c<10; c++)
        {
            printf("Digite o %d numero do vetor: \n", c+1);
            scanf("%d",&num[c]);

            aux=c;
            while (aux>0 && v[aux-1]>num[c])
            {
                v[aux]=v[aux-1];
                aux--;
            }
            v[aux]=num[c];

            printf("Ordem atual: \n\n");
            for (i=0; i<=c; i++)
            {
                printf("%d ", v[i]);
            }
            printf("\n");
        }

        do
        {
            printf("\n\nSe deseja executar novamente digite 1\nSe deseja encerrar digite 0\n");
            scanf("%d", &continuar);
        }
        while(continuar!=1 && continuar!=0);

        system("cls");
    }
    while (continuar==1);
}
#endif // ex5
