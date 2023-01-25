#include<stdio.h>
#include<conio.h>
int comment() {
char com[30];
int i=2,a=0;
getchar();
printf("\n Enter a line of comment:");
gets(com);
if(com[0]=='/') {
if(com[1]=='/')
printf("\n It is a single line comment\n\n");
else if(com[1]=='*'){
for(i=2;i<=30;i++){
if(com[i]=='*' && com[i+1]== '/'){
printf("\n It is multi line comment\n\n");
a=1;
break;
}
else{
continue;
}
}
}
else{
printf("\n It is not a comment\n\n");
}
}
else{
printf("\n It is not a comment\n\n");
}
getch();
}
