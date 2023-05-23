#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int num;
    struct nodo* sig;
}nodo;
typedef nodo* Tlista;
void cargalista(Tlista *p1);
void elimina(Tlista*p1,int num);
void recorrelista(Tlista p1);
int main()
{
    Tlista lista;
    int num;
    cargalista(&lista);
    printf("num\n");scanf("%d",&num);
    elimina(&lista,num);
    recorrelista(lista);
    return 0;
}
cargalista(Tlista *p1)
{
    FILE* arch_numero=fopen("numeros.txt","rt");
    Tlista nuevo;
    nuevo=(Tlista)malloc(sizeof(nodo));
    while(fscanf(arch_numero,"%d",&nuevo->num)==1){
        nuevo->sig=*p1;
        nuevo=*p1;
        nuevo=(Tlista)malloc(sizeof(nodo));
    }
    fclose(arch_numero);
}
void elimina(Tlista*p1,int num)
{
    Tlista act,ant,elim;
    act=*p1;
    while(act!=NULL){
        if(act->num == num){
            elim=act;
            act=act->sig;
            ant->sig=act;
            free(elim);
        }else{
            ant=act;
            act=act->sig;
        }
    }

}
void recorrelista(Tlista p1)
{
    while(p1!=NULL){
        printf("%d\n",p1->num);
        p1=p1->sig;
    }
}
