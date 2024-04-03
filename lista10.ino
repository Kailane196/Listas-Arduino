#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex3

#ifdef ex1
/*Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
Receba via teclado diversos caracteres (um por vezes) e escreva-os nesse arquivo. O caracter '0' finaliza a entrada de dados.
Abra o arquivo "arq.txt", leia e imprima na tela todos os caracteres armazenados no arquivo (um por vezes)*/

int main()
{
    FILE *arquivo;
    char caractere;

    arquivo = fopen("arq.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo.");
        return 1;
    }

    printf("Digite os caracteres (0 para sair):\n");

    while (1)
    {
        scanf(" %c", &caractere);

        if (caractere == '0')
        {
            break;
        }

        fputc(caractere, arquivo);
    }

    fclose(arquivo);

    arquivo = fopen("arq.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("\nConteúdo do arquivo:\n");

    while ((caractere = fgetc(arquivo)) != EOF)
    {
        printf("%c\n", caractere);
    }

    fclose(arquivo);

    return 0;
}
#endif
#ifdef ex2
/*Escreva um programa para gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de dados.
Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na funcao main().
Utilize ponteiros para passar o vetor de estrutura para as funcoes.
Sempre que o programa for encerrado, os contatos devem ser escritos no arquivo e quando o programa iniciar os contatos devem ser lidos do arquivo.
O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida*/

void scan();
void print();
int cmp();
void lista();
void inicial();
void listaniver();
void altera();
void exclui();
void sair();

typedef struct
{
    char nome[20];
    char tel[20];
    char dia[3];
    char mes[3];
} dados;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    FILE *pv;
    dados v[4];
    dados *pd = v;

    do
    {
        printf("\nMenu\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar nome\n");
        printf("4 - Pesquisar nome pela inicial\n");
        printf("5 - Aniversarios do mes\n");
        printf("6 - Alterar\n");
        printf("7 - Excluir\n");
        printf("8 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            scan();
            break;
        case 2:
            print();
            break;
        case 3:
            lista();
            break;
        case 4:
            inicial();
            break;
        case 5:
            listaniver();
            break;
        case 6:
            altera();
            break;
        case 7:
            exclui();
            break;
        case 8:
            printf("Encerrando\n");
            sair();
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
    while (op != 8);
}

int cmp(char *pv, dados *pd)
{
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(pv, pd[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void scan()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk.txt", "a");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite o %d nome: ", i + 1);
        fgets(v[i].nome, sizeof(v[i].nome), stdin);

        printf("Digite o %d telefone: ", i + 1);
        fgets(v[i].tel, sizeof(v[i].tel), stdin);

        printf("Digite o %d dia de aniversário: ", i + 1);
        fgets(v[i].dia, sizeof(v[i].dia), stdin);

        printf("Digite o %d mês de aniversário: ", i + 1);
        fgets(v[i].mes, sizeof(v[i].mes), stdin);

        fwrite(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Dados salvos com sucesso.\n");
}

void print()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk.txt", "r");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
        printf("%d contato\n", i + 1);
        printf("Nome: %s", v[i].nome);
        printf("Telefone: %s", v[i].tel);
        printf("Dia do aniversário: %s", v[i].dia);
        printf("Mês do aniversário: %s\n", v[i].mes);
    }

    fclose(pv);
}

void lista()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if(j>=0){
            printf("Nome: %s", v[j].nome);
            printf("Telefone: %s", v[j].tel);
            printf("Dia do aniversário: %s", v[j].dia);
            printf("Mês do aniversário: %s", v[j].mes);
            j++;
        }
 else
        printf("Não encontrado\n");
}

void inicial()
{
    FILE *pv;
    dados v[4];
    char r;

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite a inicial do nome: ");
    scanf(" %c", &r);

    int j = 0;

    for (int i = 0; i < 4; i++) {
        if (r == v[i].nome[0]) {
            printf("\n%s\n", v[i].nome);
            j++;
        }
    }

    if (j == 0)
        printf("Não encontrado\n");
}

void listaniver()
{
    FILE *pv;
    dados v[4];
    int mes;

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o número do mês: ");
    scanf("%d", &mes);

    int j = 0;

    for (int i = 0; i < 4; i++)
    {
        int mesniver = atoi(v[i].mes);
        if (mes == mesniver)
        {
            printf("Nome: %s", v[i].nome);
            printf("Telefone: %s", v[i].tel);
            printf("Dia do aniversário: %s", v[i].dia);
            printf("Mês do aniversário: %s", v[i].mes);
            j++;
        }
    }

    if (j == 0)
    {
        printf("Não encontrado\n");
    }
}

void altera()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j >= 0)
    {
        printf("Digite o novo nome: ");
        fgets(v[j].nome, sizeof(v[j].nome), stdin);
        printf("Digite o novo telefone: ");
        fgets(v[j].tel, sizeof(v[j].tel), stdin);
        printf("Digite o novo dia de aniversário: ");
        fgets(v[j].dia, sizeof(v[j].dia), stdin);
        printf("Digite o novo mês de aniversário: ");
        fgets(v[j].mes, sizeof(v[j].mes), stdin);

        pv = fopen("lk.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            fwrite(&v[i], sizeof(dados), 1, pv);
        }

        fclose(pv);

        printf("Contato alterado\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void exclui()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j >= 0)
    {
        pv = fopen("lk.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            if (i != j)
            {
                fwrite(&v[i], sizeof(dados), 1, pv);
            }
        }

        fclose(pv);

        printf("Contato excluído\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void sair()
{
    exit(0);
}
#endif
#ifdef ex3
/*Escreva um programa para controle de um cadastro de clientes.
Para cada registro sera' armazenado nome, email e celular numa estrutura de dados.
A unica estrutura de dados e' uma variavel LOCAL na funcao main().
Escreva os registros direto no arquivo. (utilize a funcao fseek quando necessario).
NAO pode usar vetor de estruturas. Utilize ponteiros para passar parametros para as funcoes.
O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/

void scan();
void print();
int cmp();
void lista();
void altera();
void exclui();
void sair();

typedef struct
{
    char nome[20];
    char email[20];
    char celular[20];
} dados;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    FILE *pv;
    dados v[4];
    dados *pd = v;

    do
    {
        printf("\nMenu\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar nome\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("6 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            scan();
            break;
        case 2:
            print();
            break;
        case 3:
            lista();
            break;
        case 4:
            altera();
            break;
        case 5:
            exclui();
            break;
        case 6:
            printf("Encerrando\n");
            sair();
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
    while (op != 6);
}

int cmp(char *pv, dados *pd)
{
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(pv, pd[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void scan()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk2.txt", "a");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite o %d nome: ", i + 1);
        fgets(v[i].nome, sizeof(v[i].nome), stdin);

        printf("Digite o %d email: ", i + 1);
        fgets(v[i].email, sizeof(v[i].email), stdin);

        printf("Digite o %d celular: ", i + 1);
        fgets(v[i].celular, sizeof(v[i].celular), stdin);

        fwrite(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Dados salvos com sucesso.\n");
}

void print()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk3.txt", "r");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
        printf("%d contato\n", i + 1);
        printf("Nome: %s", v[i].nome);
        printf("Email: %s", v[i].email);
        printf("Celular: %s\n", v[i].celular);
    }

    fclose(pv);
}

void lista()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk2.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if(j>=0){
            printf("Nome: %s", v[j].nome);
            printf("Email: %s", v[j].email);
            printf("Celular: %s", v[j].celular);
            j++;
        }
 else
        printf("Não encontrado\n");
}

void altera()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk2.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j >= 0)
    {
        printf("Digite o novo nome: ");
        fgets(v[j].nome, sizeof(v[j].nome), stdin);
        printf("Digite o novo email: ");
        fgets(v[j].email, sizeof(v[j].email), stdin);
        printf("Digite o novo celular: ");
        fgets(v[j].celular, sizeof(v[j].celular), stdin);

        pv = fopen("lk2.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            fwrite(&v[i], sizeof(dados), 1, pv);
        }

        fclose(pv);

        printf("Contato alterado\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void exclui()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j <= 0)
    {
        pv = fopen("lk2.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            if (i != j)
            {
                fwrite(&v[i], sizeof(dados), 1, pv);
            }
        }

        fclose(pv);

        printf("Contato excluído\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void sair()
{
    exit(0);
}
#endif
#ifdef ex4
/*Escreva um programa para o controle de mercadorias em uma dispensa domestica.
Para cada produto sera' armazenado um codigo numerico, nome do produto e quantidade atual numa estrutura de dados.
A unica estrutura de dados deve ser declarada como variavel LOCAL na funcao main().
Escreva os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando necessario).
NAO pode usar vetor de estruturas. Utilize ponteiros.
O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/

void scan();
void print();
int cmp();
void lista();
void inicial();
void listaniver();
void altera();
void exclui();
void sair();

typedef struct
{
    char codigo[10];
    char nome[20];
    char qtd[3];
} dados;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    FILE *pv;
    dados v[4];
    dados *pd = v;

    do
    {
        printf("\nMenu\n");
        printf("1 - Entrada de dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar nome\n");
        printf("4 - Pesquisar produtos sem estoque\n");
        printf("5 - Alterar quantidade\n");
        printf("6 - Alterar\n");
        printf("7 - Excluir\n");
        printf("8 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            scan();
            break;
        case 2:
            print();
            break;
        case 3:
            lista();
            break;
        case 4:
            inicial();
            break;
        case 5:
            //listaniver();
            break;
        case 6:
            altera();
            break;
        case 7:
            exclui();
            break;
        case 8:
            printf("Encerrando\n");
            sair();
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
    while (op != 8);
}

int cmp(char *pv, dados *pd)
{
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(pv, pd[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void scan()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk3.txt", "a");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite o %d nome: ", i + 1);
        fgets(v[i].nome, sizeof(v[i].nome), stdin);

        printf("Digite o %d codigo: ", i + 1);
        fgets(v[i].codigo, sizeof(v[i].codigo), stdin);

        printf("Digite a %d quantidade: ", i + 1);
        fgets(v[i].qtd, sizeof(v[i].qtd), stdin);

        fwrite(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Dados salvos com sucesso.\n");
}

void print()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk3.txt", "r");

    if (pv == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
        printf("%d contato\n", i + 1);
        printf("Nome: %s", v[i].nome);
        printf("Codigo: %s", v[i].codigo);
        printf("Quantidade: %s\n", v[i].qtd);
    }

    fclose(pv);
}

void lista()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk3.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if(j>=0){
            printf("Nome: %s", v[j].nome);
            printf("Codigo: %s", v[j].codigo);
            printf("Quantidade: %s", v[j].qtd);
            j++;
        }
 else
        printf("Não encontrado\n");
}

void inicial()
{
    FILE *pv;
    dados v[4];

    pv = fopen("lk3.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    int j = 0;

    for (int i = 0; i < 4; i++)
    {
        int quantidade = atoi(v[i].qtd);
        if (quantidade == 0)
        {
            printf("Nome: %s", v[i].nome);
            printf("Codigo: %s", v[i].codigo);
            printf("Quantidade: %s", v[i].qtd);
            j++;
        }
    }

    if (j == 0)
        printf("Não encontrado\n");
}

void altera()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk3.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j >= 0)
    {
        printf("Digite o novo nome: ");
        fgets(v[j].nome, sizeof(v[j].nome), stdin);
        printf("Digite o novo codigo: ");
        fgets(v[j].codigo, sizeof(v[j].codigo), stdin);
        printf("Digite a nova quantidade: ");
        fgets(v[j].qtd, sizeof(v[j].qtd), stdin);

        pv = fopen("lk3.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            fwrite(&v[i], sizeof(dados), 1, pv);
        }

        fclose(pv);

        printf("Contato alterado\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void exclui()
{
    FILE *pv;
    dados v[4];
    char r[20];

    pv = fopen("lk3.txt", "r");

    for (int i = 0; i < 4; i++)
    {
        fread(&v[i], sizeof(dados), 1, pv);
    }

    fclose(pv);

    printf("Digite o nome: ");
    getchar();
    fgets(r, sizeof(r), stdin);

    int j = cmp(r, v);

    if (j >= 0)
    {
        pv = fopen("lk3.txt", "w");

        for (int i = 0; i < 4; i++)
        {
            if (i != j)
            {
                fwrite(&v[i], sizeof(dados), 1, pv);
            }
        }

        fclose(pv);

        printf("Contato excluído\n");
    }
    else
    {
        printf("Não encontrado\n");
    }
}

void sair()
{
    exit(0);
}
#endif
