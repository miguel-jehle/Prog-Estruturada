/*Q10) Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
Contrario (TLSE *l1, TLSE *l2).*/

#include<stdio.h>
#include<stdlib.h>
#include"TLSE.c"

int contrario (TLSE *l1, TLSE *l2){
    //Como l1 e l2 não podem ser alteradas, precisaremos fazer uma copia de l1
    TLSE* copia_l1 = TLSE_copia(l1);

    //Com a copia feita basta inverte-la
    TLSE_inverte(copia_l1);

    //Então agora basta aplicar o algoritmo para verificar se ambas são iguais
    int ver = 1;
    TLSE* p1 = copia_l1;
    TLSE* p2 = l2;
    while(p1 && p2){
        if(p1->info != p2->info){
            ver = 0;
            break;
        }else{
            p1 = p1->prox;
            p2 = p2->prox;
        }
    }
    return ver;
}

int main(void){
  TLSE *l1 = TLSE_inicializa();
  TLSE *l2 = TLSE_inicializa();
  int x,y;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l1 = TLSE_insere(l1, x);
  }while(1);
  do{
    scanf("%d", &y);
    if(y < 0) break;
    l2 = TLSE_insere(l2, y);
  }while(1);
  printf("As listas originais: ");
  TLSE_imprime(l1);
  printf(" e ");
  TLSE_imprime(l2);
  printf("\n");
  

  int resp = contrario(l1,l2);
  printf("Agora o resultado da funcao criada: %d", resp);
  

  TLSE_libera(l1);
  TLSE_libera(l2);

  return 0;
}