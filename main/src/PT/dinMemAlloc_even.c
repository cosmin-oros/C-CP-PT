#include <stdio.h>
#include <stdlib.h>

int* readIntegers(int* v){
    int numar;
    int i=0;
    int* aux;    //v2 la tn si asta trebuie sa fie pointer la int
    scanf("%d",&numar);
    if(numar==0){
        return v;
    }
    else{
        aux=realloc(v,sizeof(int)); //nu mai trebuie sa scrii (int*) inainte    pt ca e deja deci nu traba sa i dai type cast 
        if(!aux){
            free(v);
            return NULL;    //daca nu poti sa aloci memorie
        }
        v=aux;
        if(numar%2==0){
            v[i]=numar;
        }
        else{
            return NULL;    //daca nu e par n are rost sa continui
        }
        while(numar){
            scanf("%d",&numar);
            i++;
            aux=realloc(v,(i+1)*sizeof(int));
            if(!aux){
                free(v);
                return NULL;
            }
            v=aux;
            if(numar%2==0){     //puteai sa faci ifu asta fix dupa ce dadeai scanf ca sa nu mai aloce aiurea nuj dc l am facut aici
                v[i]=numar;
            }
            else{
                return NULL;
            }
        }
    }
    return v;
}

int main(){
    int *v=NULL;
    v=readIntegers(v);
    if(v!=NULL){
        for(int i=0;v[i];i++){
            printf("%d ",v[i]); // asta ca sa vezi ca ti o pus in vector ce trebe
        }
        printf("\n");
        printf("All numbers are even\n");
    }
    else{
        printf("Not all numbers are even\n");
    }
    return 0;
}