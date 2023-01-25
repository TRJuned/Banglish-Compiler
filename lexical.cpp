#include<string.h>
#include<ctype.h>
#include<stdio.h>
void keyword(char str[10])
{
    if(strcmp("jonno", str)==0 || strcmp("jokhon", str)==0 || strcmp("hok",str)==0 || strcmp("purnoshongkha", str)==0 || strcmp("vognangsho", str)==0 || strcmp("borno", str)==0 || strcmp("oporibortonio",str)==0 || strcmp("shiddhanto_nao",str)==0 || strcmp("shiddhanto_check", str)==0 || strcmp("jodi", str)==0 || strcmp("nahoy", str)==0)
        printf("\n%s is a keyword", str);
    else
        printf("\n%s is an identifier", str);
}

void lexical()
{
    FILE *f1,*f2,*f3;
    char c,str[10],st1[10];
    int num[100], lineno=0, tokenvalue=0,i=0,j=0,k=0;
    printf("\nEnter the c program (Don't forget to end with 'Ctrl+z'!)\n\n");/*gets(st1);*/
    f1=fopen("input.txt", "w");
    while((c=getchar())!= EOF)
        fputc(c,f1);
    fclose(f1);
    f1=fopen("input.txt","r");
    f2=fopen("identifier.txt","w");
    f3=fopen("specialchar.txt","w");
    while((c=getc(f1))!= EOF) {
        if(isdigit(c))
        {
            tokenvalue=c-'0';
            c=getc(f1);
            while(isdigit(c)) {
            tokenvalue*=10+c-'0';
            c=getc(f1);
            }
        num[i++]=tokenvalue;
        ungetc(c,f1);
        }
        else if(isalpha(c))
        {
            putc(c,f2);
            c=getc(f1);
            while(isdigit(c)||isalpha(c)||c=='-'||c=='$')
            {
                putc(c,f2);
                c=getc(f1);
            }
            putc(' ',f2);
            ungetc(c,f1);
        }
        else if(c==' ' || c=='\t')
            printf(" ");
        else if(c=='\n')
            lineno++;
        else
            putc(c,f3);
    }
    fclose(f2);
    fclose(f3);
    fclose(f1);
    printf("\nThe numbers in the program are\n");
    for(j=0;j<i;j++)
    {
        printf("%d",num[j]);
        printf("\n");
    }
    f2=fopen("identifier.txt","r");
    k=0;
    printf("\nThe keywords and identifiers are:\n");
    while((c=getc(f2))!=EOF) {
    if(c!=' ')
        str[k++]=c;
    else
    {
        str[k]='\0';
        keyword(str);
        k=0;}
    }
    fclose(f2);
    f3=fopen("specialchar.txt","r");
    printf("\n\nSpecial characters are");
    while((c=getc(f3))!= EOF)
        printf("%c",c);
        printf("\n");
    fclose(f3);
    printf("\nTotal no. of lines are:%d\n\n",lineno);
}
