#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>

void dispscore()
{
float s,sc1,sc2,sc3,tsc;
char name[20],n1[20],n2[20],n3[20],tn[20];
FILE *f;
clrscr();
f=fopen("score.txt","r");
//fscanf(f,"%s%f",&name,&s);
fscanf(f,"%s%f",&n1,&sc1);
fscanf(f,"%s%f",&n2,&sc2);
fscanf(f,"%s%f",&n3,&sc3);

printf("%s\tscored\t%f top\n",n1,sc1);
printf("%s\tscored\t%f second\n",n2,sc2);
printf("%s\tscored\t%f third\n",n3,sc3);
getch();

fclose(f);
getch();
}

void help()
{
 clrscr();
 printf(" \n\tThis is a quiz game with multiple choice questions.\n\t");
 printf("\n\tYou will be asked some questions which tests your general knowledge.\n\t");
 printf("\n\tfour options are provided.\n\t");
 printf("\n\tYour score will be calculated at the end.\n\t");
 printf("\n\tThe more quicker you answer more will be your score.\n\t");
 printf("\n\tYour score will be calculated and displayed at the end.\n\t");
 printf("\n\tIf you score the highest it will be recorded.\n\t");
 printf("\n\t\t\t\t ALL THE BEST \n\t");
 }
void wrscore(float s,char pname[20])
{
float sc1,sc2,sc3,tsc;
char n1[20],n2[20],n3[20],tn[20];
FILE *f;
clrscr();

f=fopen("score.txt","r");

fscanf(f,"%s%f",&n1,&sc1);
fscanf(f,"%s%f",&n2,&sc2);
fscanf(f,"%s%f",&n3,&sc3);

fclose(f);

f=fopen("score.txt","w");
if(s>=sc1)
{
tsc=s;s=sc1;sc1=tsc;
strcpy(tn,pname);
strcpy(pname,n1);
strcpy(n1,tn);
}

if (s>=sc2)
{
tsc=s;s=sc2;sc2=tsc;
strcpy(tn,pname);
strcpy(pname,n2);
strcpy(n2,tn);
}

if (s>=sc3)
{
tsc=s;s=sc3;sc3=tsc;
strcpy(tn,pname);
strcpy(pname,n3);
strcpy(n3,tn);
}

fprintf(f,"%s\t%.2f\n",n1,sc1);
fprintf(f,"%s\t%.2f\n",n2,sc2);
fprintf(f,"%s\t%.2f\n",n3,sc3);

printf("%s\tscored\t%f top\n",n1,sc1);
printf("%s\tscored\t%f second\n",n2,sc2);
printf("%s\tscored\t%f third\n",n3,sc3);
getch();

fclose(f);
}

int main()
{
int n, k, m,j;
char buf[120]="\0";
int qcount,rcount;
int pa,nq[6],w,r,i,dtime;
float s;
FILE *fp1;
char choice, field, *ans2;
char pname[20], *fname, *ans1="Ans:", ans[10]="\0";
time_t itime,ftime;
clrscr();
mainmenu:
clrscr();
puts("\n\tWelcome to the quiz game");
puts("\n\t****                   ****");
puts("\n\t press S to start the game");
puts("\n\t press V to display/view the highest score");
puts("\n\t press H for help menu");
puts("\n\t press Q to quit the game");
choice=toupper(getch());
if(choice=='V')
{
dispscore();
goto mainmenu;
}
else if(choice=='Q')
exit(0);
else if(choice=='H')
{
help();
getch();
goto mainmenu;
}
else if(choice=='S')
{
clrscr();
printf("enter your name(one word only)......");
gets(pname);
// Include here the choice of fileds for quiz
fieldmenu:
clrscr();
puts("\n\t Welcome to choose the filed of your choice");
puts("\n\t A. Sports    \t\t B. General Knowledge");
puts("\n\t C. Movies     \t\t D. Model Qp");
field=toupper(getch());
if (field=='A')
fname="sportsqz1.txt";
else if (field == 'B')
fname="GKqz1.txt";
else if (field == 'C')
fname="movqz1.txt";
else if (field=='D')
fname="modelqz1.txt";
else
{
printf("enter the right option");
sound(2000);
delay(2);
nosound();
goto fieldmenu;
}
if ((fp1 = fopen(fname,"r")) == NULL)
{
       printf("Error! opening file choice of fields");
       sound(200);
       delay(1000);
       nosound();
       getch();

// Program exits if the file pointer returns NULL.
exit(1);
}


menu:
clrscr();
itime=time(NULL);
qcount=rcount=0;
i=1;
start:
srand(time(NULL));
r=rand()%6+1;   //limiting total questions no to 6 at present//
nq[i]=r;
for(w=0;w<i;w++)
if(nq[w]==r)
goto start;
fseek(fp1, 0, SEEK_SET);
// Six lines are used for each question. so the line
// number to be skipped is (r-1)*6
k=(r-1)*6+1;
for (m=1;m<k;m++)
{
  fgets(buf, 100, fp1);
}
// for (i=1; i<6; i++)
{
//fread(buf, 25, 1, fptr);
//  fgets(buf, 60, fptr);
//  strncpy(qvar, buf, 12);
//  printf("read %s and cut %s \n",buf,qvar);
    fgets(buf, 100, fp1);
    printf("\t %s\n",buf);
    fgets(buf, 100, fp1);
    printf("\t %s\n",buf);
    fgets(buf, 100, fp1);
    printf("\t %s\n",buf);
    fgets(buf, 100, fp1);
    printf("\t %s\n",buf);
    fgets(buf, 100, fp1);
//    printf("\t %s\n",buf);
    *ans2=toupper(getch());
    strcpy(ans,ans1);
    strcat(ans,ans2);
    if(strncmpi(ans,buf,5)==0)
    {
    printf("\n \t %s \t Your answer is correct\n",ans);
    rcount++;
    }
    else
    {
    printf("\n \t %s \t Your answer is wrong!!!\n",ans);
     sound(500);
     delay(500);
     nosound();
    }
    printf("\tThe correct answer is  \t%s\n",buf);
    qcount++;
    fgets(buf, 100, fp1);
    printf("\t %s\n",buf);
  getch();
  clrscr();
}
//return 0;


i++;
if (i<= 3) goto start;
fclose(fp1);

ftime = time(NULL);
dtime = difftime(ftime,itime);
if (dtime > (i-1)*5) dtime = dtime -(i-1)*5;
else dtime =0;
s= (float)rcount/qcount*100 - dtime/5;
if (s<0) s=0;
printf("\n\n\t Your Score: %.2f\n",s);
if (s==100) printf("\n\n Excellent U R Genius");
else if (s >=80 && s<100) printf("\n\t Outstanding ");
else if (s >=60 && s<80) printf("\n\t Very Good ");
else if (s >=40 && s<60) printf("\n\t Can do better ");
else  printf("\n\t Work hard and do better next time ");
getch();
wrscore(s,pname);
goto mainmenu;
}
else
sound(2000);
delay(200);
nosound();
{printf("\n\n\t\t Enter the Right Option \n\n");
sleep(2);
goto mainmenu;
}
}








