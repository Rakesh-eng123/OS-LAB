#include<stdio.h>

int main()
{
    FILE *fp;
    fp=fopen("scaler.txt","r");
    if(!fp) 
    {
        printf("Error: File cannot be opened\n") ;
        return 0;
    }
    
    //Since the file pointer points to the starting of the file, ftell() will return 0
    printf("Position pointer in the beginning : %ld\n",ftell(fp));
    
    char ch;
    while(fread(&ch,sizeof(ch),1,fp)==1)
    {
        //Here, we traverse the entire file and print its contents until we reach its end.
        printf("%c",ch);
    }
    
    printf("\nSize of file in bytes is : %ld\n",ftell(fp));
    fclose(fp);
    return 0;
}

