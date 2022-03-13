#include <stdio.h>
#include <string.h>
int main(){
    char name[10],tname[10],temp[8];
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    printf("\nEnter %d names: \n",n);
    for(int i=0;i<n;i++){
        scanf("%s",&name[i]);
        strcpy(tname[i],name[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(name[i],name[j])>0){
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
            }
        }
    }
    printf("Input names|Sorted names: \n");
    for(int i=0;i<n;i++){
        printf("%s|%s\n",tname[i],name[i]);
    }
    return 0;
}