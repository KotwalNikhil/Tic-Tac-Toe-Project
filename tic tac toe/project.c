#include<stdio.h>
//#include<conio.h>   //uncomment this if you are on  code blocks.Dont worry it wont effect the code if you dont do it.
#include<stdlib.h>
#include<string.h>

void introduction()
{
printf("					    WELCOME TO TIC TAC TOE / ZERO KATA \n This a single player game ,in which your numeric key of your keyboard is your box \n  example-\n7 |8 |9\n--|--|--\n4 |5 |6\n--|--|--\n1 |2 |3\n the above numbers represent the respective positions on ZERO KATA box.\n So you have to enter the respective number to put your character in the respective position of box.\n NOTE-This game is totally unexpected as the programme is not made with the intention to win the every game \nSo  You may observe that the computer could have easily won the game if he would have put his character at right place ,but the computer move is unexpected  and he may not do that .\n TRY TO DRAW THE MATCH IT WILL BE FUN \n HOPE YOU LIKE THE GAME .\n");
}

int  check(char arr[3][3],char c1,char c)
{
int i,j,flag=0;
for(i=0;i<3;i++){//colomn
if(arr[0][i]==c1 && arr[1][i]==c1 && arr[2][i]==c1){printf(" !!! Congrats you won !!!");flag=1;break;}
else if(arr[0][i]==c && arr[1][i]==c && arr[2][i]==c){printf(" OHH,you lost ,Try Again");break;flag=1;break;}
}
for(j=0;j<3;j++){//rows
if(arr[j][0]==c1 && arr[j][1]==c1 && arr[j][2]==c1){printf(" !!! Congrats you won !!!");flag=1;break;}
else if(arr[j][0]==c && arr[j][1]==c && arr[j][2]==c){printf(" OHH,you lost ,Try Again");flag=1;break;}
}
//diagonal
if(arr[0][0]==c1 && arr[1][1]==c1 && arr[2][2]==c1){printf(" !!! Congrats you won !!!");flag=1;}
else if(arr[0][0]==c && arr[1][1]==c && arr[2][2]==c){printf(" OHH,you lost ,Try Again");flag=1;}
else if(arr[0][2]==c1 && arr[1][1]==c1 && arr[2][0]==c1){printf(" !!! Congrats you won !!!");flag=1;}
else if(arr[0][2]==c && arr[1][1]==c && arr[2][0]==c){printf(" OHH,you lost ,Try Again");flag=1;}

return flag;
}

void display(char arr[3][3])
{
    int t;
    for(t=0;t<3;t++)
    {

     printf("%c  | %c | %c ",arr[t][0],arr[t][1],arr[t][2]);
    if(t!=2)
        printf("\n --|---|--\n");
}
printf("\n");
}
char character()
{
    printf("\nPlease select your character\n1)Enter 1 for 'x' \n2) Enter 2 for 'o'\n");
    char c1;
    int a;
    scanf("%d",&a);
    if(a==1){
printf("\nYou chossed 'x'");
            c1='x';
        return c1;}
    else if(a==2){printf("You chossed 'o'");c1='o';return c1;}
}
int  toss()
{
    printf("\n\nTOSS\n");
    int flag=0;
    srand(time(0));
    int x,y,z;
    printf("\nChoose any one 1)HEADS 2)TAILS\n");
    scanf("%d",&x);
    y=rand()%2+1;
    if(y==x){
        printf("\nYou Won the toss,Now decide what you want \n 1) I want to start First 2) I don't want to start\n");
    scanf("%d",&z);
    if(z==1)
        return(1);}
    else if(y!=x)
        printf("\nSorry you lost the toss\n");

    if(y!=x || z==2)
        return -1;
}
void fill(int p,char arr[3][3],char c)
{
    switch(p)
    {
    case 1:
        arr[2][0]=c; // c is the character to be putt  in an array.
        break;
    case 2:
        arr[2][1]=c;
        break;
    case 3:
        arr[2][2]=c;
        break;
    case 4:
        arr[1][0]=c;
        break;
    case 5:
        arr[1][1]=c;
        break;
    case 6:
        arr[1][2]=c;
        break;
    case 7:
        arr[0][0]=c;
        break;
    case 8:
        arr[0][1]=c;
        break;
    case 9:
        arr[0][2]=c;
        break;
    default:
        1;
    }
}
int loose(char c,char c1)
{
int z=0,chance=0;
    int a[4]={0};
    srand(time(0));
    char arr[3][3]={0};
    int temp[5];
    int x,p,i=0,r;
    while(i<5)
    {
     r=rand()%9+1;
    for(x=0;x<i;x++)
    {
        if(temp[x]==r || r==a[x])
            break;
    }
    if(x==i){
    temp[i]=r;
    p=temp[i];

    printf("\nNikhil's turn --Press any key\n");
    //_getch();      Remove this comment if you are on code blocks ,it won't effect anything in this game if you dont remove this.
    fill(p,arr,c);
    display(arr);
    int checky=check(arr,c1,c);if(checky==1)return 1;chance++;if(chance==9){printf("\nOyeaahh This is a Draw\n"); return 1;}
    printf("\nNow its your turn\n");
    scanf("%d",&a[z]);printf("\n");
    fill(a[z],arr,c1);
     display(arr);  checky=check(arr,c1,c);if(checky==1)return 1;chance++;if(chance==9){printf("\nOyeaahh This is a Draw\n"); return 1;}
     ++i;++z;//if((z==4 || z==5) && i==5){printf("\nOyeaahh This is a Draw\n"); return 1;}
    }}}

int win(char c,char c1)
{
int z=0,chance=0;
int a[5]={0};
srand(time(0));
char arr[3][3]={0};
int temp[4];
int x,r,i=0,p;printf("SAMPLE");
 display(arr);
while(i<4)
{

 /*for(x=0;x<i;x++)
    {
        if(temp[x]==r || r==a[x])
            break;
    }
if(x==i){ */

printf("\n Its your turn enter the position no.\n");
scanf("%d",&a[z]);printf("\n");
fill(a[z],arr,c1);
display(arr); int checky=check(arr,c1,c);if(checky==1)return 1;chance++;if(chance==9){printf("\nOyeaahh This is a Draw\n"); return 1;}

again: ;
r=rand()%9+1;
for(x=0;x<=i;x++)
    {
        if(temp[x]==r || r==a[x])
         goto again; //  break;
    }
 temp[i]=r;
    p=temp[i];
    printf("\nNikhil's turn --Press any key\n");
  //_getch();       //uncomment this if you are on  code blocks.Dont worry it wont effect the code if you dont do it.
    fill(p,arr,c);
    display(arr);
    checky=check(arr,c1,c);if(checky==1)return 1;chance++;if(chance==9){printf("\nOyeaahh This is a Draw\n"); return 1;}
++i;++z;if(z==4 && i!=3){printf("\nOyeaahh This is a Draw\n"); return 1;}
}

}

char mrzi(){
 printf("\n Want to play again ?   Y/N \n");
      char marzi;
        scanf(" %c",&marzi);
        return marzi;

}
void main()
{
introduction();
    char c1=character();
    char c=c1=='x'?'o':'x';
  again: ;
  int result=toss();
   if(result==-1)
      loose(c,c1);
   else if(result==1)
      win(c,c1);

     char marzi= mrzi();
if(marzi=='Y')goto again;
         else printf("\nTHANK YOU ON BEHALF OF NIKHIL  \n");



}

