#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,char>m;
   m[".-"]='A';m[".---"]='J';m["..."]='S';m[".----"]='1';m[".-.-.-"]='.';m["---..."]=':';
   m["-..."]='B';m["-.-"]='K';m["-"]='T';m["..---"]='2';m["--..--"]=',';m["-.-.-."]=';';
   m["-.-."]='C';m[".-.."]='L';m["..-"]='U';m["...--"]='3';m["..--.."]='?';m["-...-"]='=';
   m["-.."]='D';m["--"]='M';m["...-"]='V';m["....-"]='4';m[".----."]='\'';m[".-.-."]='+';
   m["."]='E'; m["-."]='N';m[".--"]='W';m["....."]='5';m["-.-.--"]='!';m["-....-"]='-';
   m["..-."]='F';m["---"]='O';m["-..-"]='X';m["-...."]='6';m["-..-."]='/';m["..--.-"]='_';
   m["--."]='G';m[".--."]='P';m["-.--"]='Y';m["--..."]='7';m["-.--."]='('; m[".-..-."]='"';
   m["...."]='H';m["--.-"]='Q';m["--.."]='Z';m["---.."]='8';m["-.--.-"]=')'; m[".--.-."]='@';
   m[".."]='I';m[".-."]='R';m["-----"]='0';m["----."]='9';m[".-..."]='&';
   char str[5000],ch[5000];
   int kase,kas=1,j,i;
   bool flag=0;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
      j=0;
      gets(str);
      if(flag)
       printf("\n");
      else
       flag=1;
      printf("Message #%d\n",kas++);
      for(i=0;str[i]!='\0';i++)
      {
        if(str[i]==' ')
        {
          ch[j]='\0';
          if(j)
          printf("%c",m[ch]);
          if(str[i+1]==' ')
           printf(" "),i++;
           j=0;
        }
        else
         ch[j++]=str[i];
      }
      ch[j]='\0';
      if(j)
      printf("%c\n",m[ch]);
      else
       printf("\n");
    }
    return 0;
}
