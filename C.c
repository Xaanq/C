#include <stdio.h>
#include "AListLib.c"

List readList(int n){
    int i; ElementType x; List L;
    makenullList(&L);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        L.Elements[i-1] = x;
        L.Last++;
    }
    return L;
}
void printList(List L){
    Position P = 1;
    while(P <= L.Last){
        printf("%d ", L.Elements[P-1]); P++;
    }
    printf("\n");
}
/*void sort(List *pL){
    Position i = 0, j, t;
    for(; i < pL->Last; i++)
        for(j = i + 1; j < pL->Last; j++){
            if(pL->Elements[i] > pL->Elements[j]){
                t = pL->Elements[i];
                pL->Elements[i] = pL->Elements[j];
                pL->Elements[j] = t;
            }
        }
}
int main(){
    int n; List L;
    scanf("%d", &n);
    L = readList(n);
    printList(L);
    sort(&L);
    printList(L);
}*///tang dan sách
/*void xoahet(int x, List *pL){
    Position i = 0;
    for(; i < pL->Last; i++)
        if(pL->Elements[i] == x){
            deleteList(i+1, pL); i--;
        }
}	
int main(){
    int n, x; List L;
    scanf("%d", &n);
    L = readList(n);
    scanf("%d", &x);
    printList(L);
    xoahet(x, &L);
    printList(L);
}*/ //xoa tat ca x
void insertSet(ElementType x, List *pL){
    insertList(x, pL->Last+1, L);
}
void timchanle(List L, List *chan, List *le){
    Position P = 1;
    while(P <= L.Last){
        if(L.Elements[P-1] % 2 == 0) insertSet(L.Elements[P-1], chan);
        else insertSet(L.Elements[P-1], le);
        P++;
    }
}
int main(){
    int n; List L, Chan, Le;
    makenullList(&Chan); makenullList(&Le);
    scanf("%d", &n);
    L = readList(n);
    timchanle(L, &Chan, &Le);
    printList(L); printList(Le); printList(Chan);
    return 0;
}

