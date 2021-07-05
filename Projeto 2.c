/*
2º projeto da turma do 1º periodo de Analise e Desenvolvimento de Sistemas

Alunos: Daniel Gomes Januario Junior.
        Everton Alves Da Silva.
        Gustavo Mateus Machado Dornelas.
        Italo Junior Rodrigues Trindade.
        João Vítor Resende Bastos.
        Victor gabriel Santos de Oliveira.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct sMusicas{ //variaveis do tipo musica

    int codMusica, votos, codBanda;
    char nome[20], compositor[20];
    float nota, notaTotal;

}MUSICAS;

typedef struct sBandas{ //variaveis do tipo banda

    char nome[20], genero[20];
    int ano, codBanda;

}BANDAS;

void ZeraCodigos (BANDAS b[], MUSICAS m[], int tamB, int tamM){ //zerar todos os valores de codigo de musica e de banda

    int i, j;

    for (i=0; i<=tamB; i++){
        b[i].codBanda=0;
    }

    for (j=0; j<=tamM; j++){
            m[j].codMusica=0;
    }
}

int verificadorMusicas (MUSICAS m[], int tamM){ //verifica se existe musicas cadastradas

    int verificador=0, j;

    for (j=0; j<=tamM; j++){
        if (m[j].codMusica!=0){
            verificador=1;
            break;
        }
    }

    if (verificador==0){
        system ("cls");
        printf ("Não existe músicas cadastradas no sistema!\n");
        system ("pause");
    }

    return verificador;
}

void CadastrarBanda (BANDAS b[], int tamB){

    int i, verificador=0;

    system ("cls");

    for (i=0; i<=tamB; i++){
        if (b[i].codBanda==0){ //verifica se tem algum espaço no vetor banda em branco

            do{ //impedir o sistema de receber variavel em branco
                system ("cls");
                fflush(stdin);
                printf ("Digite o nome da banda: ");
                gets (b[i].nome);
                strupr(b[i].nome);
                fflush(stdin);
            }while (strlen (b[i].nome)==0);

            do{
                system ("cls");//impedir o sistema de receber variavel em branco
                printf ("Digite o nome da banda: %s\n", b[i].nome);
                printf ("Digite o genero da banda: ");
                gets (b[i].genero);
                strupr(b[i].genero);
                fflush(stdin);
            }while (strlen (b[i].genero)==0);

            system ("cls");//repetir informações digitadas e mostrar variaveis em caixa alta
            printf ("Digite o nome da banda: %s\n", b[i].nome);
            printf ("Digite o genero da banda: %s\n", b[i].genero);

            printf ("Digite o ano de criação da banda: ");
            scanf ("%d", &b[i].ano);

            b[i].codBanda=i+1; //o codigo da banda sempre sera i+1, para que o primeiro codigo nunca seja igual a 0

            verificador=0;

            break;

        }else{ //maximo de espaços no vetor banda preenchidos
            verificador=1;
        }
    }

    if (verificador==1){
        printf ("Numero Máximo de bandas Atingidos!\n");
        system ("pause");
    }
}

void CadastrarMusica (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    int codBanda=0, i, j, verificador=0;
    char nomeBanda[20];

    system ("cls");

    for (j=0; j<=tamM; j++){ //verificar se tem espaço para cadastrar mais musicas
        if (m[j].codBanda==0){
            verificador=1;
            break;
        }
    }

    if (verificador==0){
        printf ("Numero máximo de músicas atingido!\n\n");
        system ("pause");
    }else{

        verificador=0; //aproveitar a variavel para verificar se tem banda cadastrada

        for(i=0; i<=tamB; i++){ //verifica se tem bandas cadastradas
            if (b[i].codBanda!=0){
                verificador=1; //verificador será 1 se existir alguma banda cadastrada.
                continue; //parar a repetição ao achar cadastro de banda
            }
        }

        if (verificador==0){ //caso verificador seja 0, significa que não tem banda cadastrada no sistema ainda.
            printf ("Nenhuma Banda cadastrada!!");
            system ("pause");
        }else{ //caso exista banda cadastrada o sistema ira continuar rodando

            do{//perguntar o usuario o nome da banda desejada e armazenar o cod da banda na variavel codBanda
                do{ //impedir o sistema de receber variavel em branco
                    system ("cls");
                    fflush (stdin);
                    printf ("Digite o nome da Banda: ");
                    gets (nomeBanda);
                    strupr (nomeBanda);
                    fflush(stdin);
                }while (strlen (nomeBanda)==0);

                for (i=0; i<=tamB; i++){
                    if (strcmp(nomeBanda,b[i].nome)==0){
                        for (j=0;j<=tamM;j++){
                            if (m[j].codMusica==0){
                                codBanda=b[i].codBanda; //salva o codigo da banda escolhida em uma variavel temporaria
                                break;
                            }
                        }
                    }
                }

                if (codBanda==0){
                    printf ("banda não cadastrada!\n");
                    system ("pause");
                    system ("cls");
                }

            }while (codBanda==0);


            for (j=0; j<=tamM; j++){

                if (m[j].codMusica==0){

                    do{ //impedir o sistema de receber variavel em branco
                        system ("cls");
                        printf ("Digite o nome da Banda: %s\n", nomeBanda);//repetir informação digitada pelo usuario
                        printf ("Digite o nome da música: ");
                        gets (m[j].nome);
                        strupr (m[j].nome);
                        fflush(stdin);
                    }while (strlen (m[j].nome)==0);

                    do{//impedir o sistema de receber variavel em branco
                        system ("cls");
                        printf ("Digite o nome da Banda: %s\n", nomeBanda);//repetir informação digitada pelo usuario
                        printf ("Digite o nome da música: %s\n", m[j].nome);//repetir informação digitada pelo usuario
                        printf ("Digite o compositor da música: ");
                        gets (m[j].compositor);
                        strupr (m[j].compositor);
                        fflush(stdin);
                    }while (strlen (m[j].compositor)==0);

                    m[j].codMusica=j+1; //o codigo da musica sempre sera j+1, para que o primeiro valor nunca seja igual a 0
                    m[j].votos=0;
                    m[j].nota=0;
                    m[j].codBanda=codBanda;
                    break;
                }
            }
        }
    }
}

void ListarBandas (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    int i,j;

    system ("cls");
    printf ("  Listando Bandas!\n\n");
    printf ("----------------------------------------------------------------------------\n");


    for(i=0; i<=tamB; i++){

        if (b[i].codBanda!=0){
            printf ("Banda: %d, %s\n",b[i].codBanda, b[i].nome); //imprime o nome da banda

            for (j=0; j<=tamM; j++){
                if (b[i].codBanda==m[j].codBanda){
                    printf ("    %s, compositor: %s\n", m[j].nome, m[j].compositor); //imprime as musicas da banda
                }
            }
            printf ("\nGenero: %s, Ano de criação da banda: %d\n", b[i].genero, b[i].ano); //imprime dos dados da banda
            printf ("----------------------------------------------------------------------------\n");
        }
    }
    system ("pause");
}

void ListarMusicas (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    int i,j;

    system ("cls");
    printf ("Listando Musicas!\n");

    for (j=0; j<=tamM; j++){
        if (m[j].codMusica!=0){

            printf ("\n%d -> ", m[j].codMusica); //imprimir codigo da musica

            for (i=0; i<=tamB; i++){
                if (m[j].codBanda==b[i].codBanda){
                    printf ("%s ", b[i].nome); //pesquisa o nome da banda e imprime

                }
            }
            printf ("- %s\nNota atual: %.2f, votos: %d\n", m[j].nome, m[j].nota, m[j].votos); //imprime os dados da musica
            printf ("----------------------------------------------------------------------------\n");
        }
    }

    printf ("\n\n");
}

void AvaliarMusicas (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    float avaliacao, verificador=0;
    int i, j, codigo;

    if (verificadorMusicas(m, tamM)!=0){ //verifica se tem musicas cadastradas

        do{
            ListarMusicas(b, m, tamB, tamM);
            printf ("Digite o código da musica: ");
            scanf ("%d", &codigo);

            if (codigo!=0){
                for (j=0; j<=tamM; j++){
                    if (codigo==m[j].codMusica){ //verifica se o cod digitado esta cadastrado, caso exista o for para com "j" na posição da musica.
                        verificador=1;
                        break;
                    }
                }
            }

            if (verificador==0 || codigo==0){ //informa que o cod digitado esta errado
                system ("cls");
                printf ("Digite um código valido!\n");
                system ("pause");
                system ("cls");
            }

        }while (verificador==0 || codigo==0); //repete ate digitar um cod valido

        do{ //repete ate digitar um valor entre 0 e 5
            system ("cls");
            printf ("Musica: %s\n", m[j].nome);
            printf ("Digite a nota para a musica (Mínimo 0, Máximo 5): ");
            scanf ("%f", &avaliacao);

            if (avaliacao<0 || avaliacao>5){ //informa caso a nota n seja valida
                system ("cls");
                printf ("Digite uma nota valida!\n");
                system ("pause");
            }

        }while (avaliacao<0 || avaliacao>5);

        //calcula a media e armazena todos os valores
        m[j].votos++;
        m[j].notaTotal=m[j].notaTotal+avaliacao;
        m[j].nota=m[j].notaTotal/m[j].votos;
    }
}

void BandasPorGenero (BANDAS b[], int tamB){

    int i, verificador=0;
    char genero[20];

    system ("cls");
    fflush (stdin);
    printf ("Digite o gênero desejado: ");
    gets (genero);
    strupr (genero);
    fflush(stdin);

    for (i=0; i<=tamB; i++){
        if (strcmp(genero, b[i].genero)==0){ //verificar se o genero existe
            printf ("\nBanda: %d, %s\nGenero: %s, Ano de criação da banda: %d\n\n",b[i].codBanda, b[i].nome, b[i].genero, b[i].ano);
            printf ("----------------------------------------------------------------------------\n");
            verificador=1;
        }
    }

    if (verificador==0){
        printf ("Não existe nenhuma banda do gênero %s cadastrada!\n", genero);
    }

    system ("pause");

}

void NotaAlta (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    int posicao, maisVotos=0, i, j;
    float notaAlta=0;

    if (verificadorMusicas(m, tamM)!=0){

        notaAlta=m[0].nota;
        maisVotos=m[0].votos;

        for (j=0; j<=tamM; j++){
            if (m[j].codMusica!=0){

                if (m[j].nota>notaAlta){ //caso a nota seja maior posicao recebe j
                    posicao=j;
                    notaAlta=m[j].nota;
                    maisVotos=m[j].votos;
                }

                if(m[j].nota==notaAlta){ //caso a nota seja igual a maior, verifica o criterio de desempate quantidade de fotos.
                    if (m[j].votos>=maisVotos){
                        posicao=j;
                        notaAlta=m[j].nota;
                        maisVotos=m[j].votos;
                    }
                }
            }
        }

        system ("cls");
        printf ("Música com nota mais alta: ");

        for (i=0; i<=tamB; i++){
            if (m[posicao].codBanda==b[i].codBanda){
                printf ("%s - ", b[i].nome);
            }
        }

        printf ("%s com a nota %.2f\n\n", m[posicao].nome, m[posicao].nota);
        system ("pause");
    }

}

void NotaBaixa (BANDAS b[], MUSICAS m[], int tamB, int tamM){

    int posicao, maisVotos, i, j;
    float notaAlta;

    if (verificadorMusicas(m, tamM)!=0){ //funcao que verifica se existe musica cadastrada

        notaAlta=m[0].nota;
        maisVotos=m[0].votos;

        for (j=0; j<=tamM; j++){
            if (m[j].codMusica!=0){


                if (m[j].nota<notaAlta){ //caso a nota seja maior posicao recebe j
                    posicao=j;
                    notaAlta=m[j].nota;
                    maisVotos=m[j].votos;
                }

                if(m[j].nota==notaAlta){ //caso a nota seja igual a maior, verifica o criterio de desempate quantidade de fotos.
                    if (m[j].votos<=maisVotos){
                        posicao=j;
                        notaAlta=m[j].nota;
                        maisVotos=m[j].votos;
                    }
                }
            }
        }

        system ("cls");
        printf ("Música com nota mais baixa:");

        for (i=0; i<=tamB; i++){
            if (m[posicao].codBanda==b[i].codBanda){
                printf ("%s - ", b[i].nome);
            }
        }

        printf ("%s com a nota %.2f\n\n", m[posicao].nome, m[posicao].nota);
        system ("pause");
    }
}

void encerramento (){
    system ("cls");
    printf ("Sistema desenvolvido por: Daniel Gomes Januario Junior.");
    printf ("\n                          Everton Alves Da Silva.");
    printf ("\n                          Gustavo Mateus Machado Dornelas.");
    printf ("\n                          Italo Junior Rodrigues Trindade.");
    printf ("\n                          João Vítor Resende Bastos.");
    printf ("\n                          Victor gabriel Santos de Oliveira.");
    printf ("\n\nAnálise e Desenvolvimento de Sistemas - Turma 1º Périodo © 2021\n");
    printf ("----------------------------------------------------------------------------\n");
    printf ("\nEncerrando sistema...\n\n");
}

void menu (BANDAS banda[], MUSICAS musica[], int b, int m){

    int menu;

    do{
        system ("cls");
        fflush (stdin);

        printf ("                                          ====== MUSIC STAR ver. 1.0 ==================\n");
        printf ("                                             1 - Cadastrar Banda\n");
        printf ("                                             2 - Cadastrar Música\n");
        printf ("                                             3 - Listar Bandas\n");
        printf ("                                             4 - Listar Músicas\n");
        printf ("                                             5 - Avaliar Música\n");
        printf ("                                             6 - Pesquisar bandas por gênero\n");
        printf ("                                             7 - Ver a música com nota mais alta\n");
        printf ("                                             8 - Ver a música com nota mais baixa\n");
        printf ("                                             0 - Sair do sistema\n");
        printf ("                                          ============================================\n");
        printf ("                                                 Opção: ");
        scanf ("%d", &menu);

        switch (menu) {

        case 1:
            CadastrarBanda (banda, b);
            break;
        case 2:
            CadastrarMusica(banda, musica, b, m);
            break;
        case 3:
            ListarBandas(banda, musica, b, m);
            break;
        case 4:
            ListarMusicas(banda, musica, b, m);
            system ("pause");
            break;
        case 5:
            AvaliarMusicas(banda, musica, b, m);
            break;
        case 6:
            BandasPorGenero(banda, b);
            break;
        case 7:
            NotaAlta(banda, musica, b, m);
            break;
        case 8:
            NotaBaixa(banda, musica, b, m);
            break;
        case 0:
            encerramento ();
            break;
        }
    }while (menu!=0);
}

int main (){

    setlocale(LC_ALL,"Portuguese");

    BANDAS banda[9];
    MUSICAS musica[9];

    ZeraCodigos (banda, musica, 9, 9); //struct, quantidades de bandas, quantidade de musicas
    menu (banda, musica, 9, 9);

    return 0;
}
