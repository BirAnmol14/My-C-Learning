#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    puts("Starting");
    FILE * fp1,*fp2,*fp3;
    fp1=fopen("1.txt","r");
    fp2=fopen("2.txt","r");
    fp3=fopen("3.txt","w");
   char ch1[5],ch2[5];
    while(((fscanf(fp1,"%s",ch1))!=EOF)&&((fscanf(fp2,"%s",ch2))!=EOF))
    {
        fprintf(fp3,"%s\n%s\n",ch1,ch2);fgetc(fp1);fgetc(fp2);//eating '\n'
    }
    while(((fscanf(fp1,"%s",ch1))==EOF)&&((fscanf(fp2,"%s",ch2))!=EOF))
    {
        fprintf(fp3,"%s\n",ch2);fgetc(fp2);//eating '\n'
    }
    while(((fscanf(fp1,"%s",ch1))!=EOF)&&((fscanf(fp2,"%s",ch2))==EOF))
    {
        fprintf(fp3,"%s\n",ch1);fgetc(fp1);//eating '\n'
    }
    puts("Loop ended successfully");
    fclose(fp1);fclose(fp2);fclose(fp3);
    return 0;
}
