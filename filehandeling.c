#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp, *fp1;
    int ft, i=0, ch;
	fp = fopen("myfile.txt","w");
	fputs("MY CAPTAIN", fp);
	fclose(fp);
	fp = fopen("myfile.txt","r");
	if(fp==NULL)
	{
		printf("ERROR");
		return 0;
	}
	fseek(fp,0,SEEK_END);
	ft=ftell(fp);
	while(i<ft)	
	{
		i++;
		fseek(fp,-i,SEEK_END);
		printf("%c",fgetc(fp));	
	}
	fclose(fp);
	
	fp = fopen("myfile.txt","w");
	fp1 = fopen("copy.txt","r");
	while((ch==fgetc(fp))!=EOF)
	{
		fputc(ch,fp1);
	}
	printf("File copied");
	fclose(fp);
	fclose(fp1);
	
	return 0;
}


