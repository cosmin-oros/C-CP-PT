#include <stdio.h>

int main(void){
    FILE* fp;
    unsigned long pos;
    fp=fopen("somefile.bin","a+b");
    if (fp==NULL)
    {
        perror("fopen()");
        return -1;
    }
    
    pos=ftell(fp);
    printf("File position is %lu\n",pos);
    // fwrite(&a,sizeof(int),1,fp);
    printf("File position is %lu\n",pos);
    // fread(&a,sizeof(int),1,fp);
    printf("File position is %lu\n",pos);
    fclose(fp);
    return 1;
}