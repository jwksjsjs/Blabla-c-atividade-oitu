#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 100

//===============================//
struct Livro{
int codigo;
char livro[size];
char autor[size];
int anoPubli;
};

struct Biblioteca{
int numLivros;
struct Livro livros[size];
};
//==============================//

//*****************************//
int apresentar(){
int resp;
for(int n = 0; n < 31; n ++){
printf("--");
}
printf("Oque você deseja fazer:?\n ");
printf("Digite 1 para adicionar um livro à biblioteca\n");
printf("Digite 2 para ver os livros disponíveis na biblioteca\n");
printf("Digite 3 para remover um livro da biblioteca\n");
printf("Digite 4 para buscar um livro na biblioteca\n");
printf("Digite 5 para sair\n");
scanf("%d", &resp);

if(resp > 5 || resp < 1){  
    printf("Opção inválida\n");  
    return -1;  
}  
return resp;

}

int perguntar(){

unsigned int resp = -1;  
printf("digite 1 para buscar livro por título \n");  
printf("digite 2 para buscar livro por código \n");  
  
scanf("%d", &resp);  
if(resp != 1 && resp != 2){  
    printf("Opção inválida, tentar novamente\n");  
    return -1;  
}  
  
return resp;

}
//******************************//

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//
void listar(struct Biblioteca *p_Bibl){
if(p_Bibl->numLivros == 0){
printf("Nao há livros na biblioteca para serem deletados\n");
return;
}
for(int n = 0; n < p_Bibl->numLivros; n++){
printf("Código: %d\n", p_Bibl->livros[n].codigo);
printf("Livro: %s\n", p_Bibl->livros[n].livro);
printf("Autor: %s\n", p_Bibl->livros[n].autor);
printf("Data publicação: %d\n", p_Bibl->livros[n].anoPubli);
}

}

void buscar(struct Biblioteca *livrus){

if(livrus->numLivros == 0){  
    printf("Não há livros na biblioteca\n");  
    return;  
}  
  
int resp = perguntar();  
  
if(resp == 1){  
    printf("Diggite o título que do livro que deseja buscar: \n");  
    buscar_livro_nome(livrus);  
      
}else{  
    printf("Digite o código do livro que deseja buscar: \n");  
    buscar_livro_codigo(livrus);  
}

}
//   ^
//   |
//   |
int buscar_livro_nome(struct Biblioteca *livrus){
char tit[size];
scanf(" %[^\n]", tit);

for(int i = 0; i < livrus->numLivros; i++){  
          
        int comp = strcmp(tit, livrus->livros[i].livro);  
          
        if(comp == 0){  
            printf("livro encontrado\n");  
            printf("Título: %s\n", livrus->livros[i].livro);  
            printf("Código: %d\n", livrus->livros[i].codigo);  
            printf("Autor: %s\n", livrus->livros[i].autor);  
            printf("Publicação: %d\n", livrus->livros[i].anoPubli);  
            return i;  
        }else if(i == livrus->numLivros-1){  
            printf("Livro não encontrado\n");  
            return -1;  
        }  
}

}
//    ^
//    |
//    |
int buscar_livro_codigo(struct Biblioteca *livrus){
int codigo;
scanf("%d", &codigo);
for(int i = 0; i < livrus->numLivros; i++){
if(livrus->livros[i].codigo == codigo){
printf("livros emcontrado\n");
printf("Título: %s\n", livrus->livros[i].livro);
printf("Código: %d\n", livrus->livros[i].codigo);
printf("Autor: %s\n", livrus->livros[i].autor);
printf("Publicação: %d\n", livrus->livros[i].anoPubli);

//posicao do livro  
            return i;  
        }  
}  
printf("Livro não encontrado\n");  
return -1;

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@//

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
struct Biblioteca *remover(struct Biblioteca *biblioteca){

if(biblioteca->numLivros == 0){  
    printf("Não há livros na biblioteca\n");  
    return biblioteca;  
}      
  
int resp = perguntar();  
if (resp == -1){  
    printf("Opcao inválida\n");  
    return biblioteca;  
}  
    int livr_deletar;  
  
if(resp==1){  
    printf("Digite o nome do livro que deseja deletar: \n");  
    livr_deletar = buscar_livro_nome(biblioteca);  
}else{  
    printf("Digite o código do livro que deseja deletar: \n");  
    livr_deletar = buscar_livro_codigo(biblioteca);  
}  

if(livr_deletar == -1){  
    printf("Não foi possível deletar, livro não encontrado.\n");  
    return biblioteca;  
}  

printf("Deseja realmente deletar esse livro? : \n");  
printf("1 - Para sim\n");  
printf("2 - Para cancelar\n");  
scanf("%d", &resp);  
  
if(resp == 1){  
    for(int i = 0; i < biblioteca->numLivros; i++){  
        if(i >= livr_deletar){  
            if(i < (biblioteca->numLivros-1)){  
                biblioteca->livros[i] = biblioteca->livros[i+1];  
            }  
        if(i == biblioteca->numLivros-1){  
        }    
    }  
    biblioteca->numLivros--;  
    printf("Livro deletado com sucesso\n");  
    return biblioteca;  
    }  
}else{  
    printf("Ação cancelada\n");  
}

}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//

//÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷//
struct Biblioteca *adicionar(struct Biblioteca *p_Bibl, struct Livro *p_Liv, int cont){

printf("Nome do livro:");  
scanf(" %[^\n]", p_Liv->livro);  
printf("\n");  
printf("codigo do livro: ");  
scanf("%d", &p_Liv->codigo);  
printf("\n");  
printf("autor do livro: ");  
scanf(" %[^\n]", p_Liv->autor);  
printf("\n");  
printf("ano de publicação do livro: ");  
scanf("%d", &p_Liv->anoPubli);  
getchar();  
printf("\n");  
p_Bibl->numLivros = cont+1;  
p_Bibl->livros[cont] = *p_Liv;  
  
return p_Bibl;

}
//÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷÷//
int main(){

int opcao;  
//contador muito importante   
unsigned int cont = 0;  
unsigned char continuar[4];  
unsigned int resp = 1;  
  
struct Biblioteca *p_Bibl = (struct Biblioteca*) calloc(1, sizeof(struct Biblioteca));  
struct Livro *p_Liv = (struct Livro*) calloc(1, sizeof(struct Livro));  
  
while(opcao != 5){  
    opcao = apresentar();  
      
    if(opcao > 5 && opcao<1){  
        printf("Opção inválida\n");  
        continue;  
    }  
      
    switch(opcao){  
        case 1:  
            p_Bibl = adicionar(p_Bibl, p_Liv, cont);  
            cont++;  
            break;  
        case 2:      
            listar(p_Bibl);  
            break;  
        case 3:  
            p_Bibl = remover(p_Bibl);  
            break;  
        case 4:  
            buscar(p_Bibl);  
            break;  
        case 5:  
            printf("Saindo do programa...\n");  
            break;  
        }  
          
          
  
}  
free(p_Liv);  
free(p_Bibl);  
return 0;

}