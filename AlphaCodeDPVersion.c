#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length;
unsigned long long decodingscount=0;
int isValid(int a){

if(a>=1&&a<=26){
    return 1;
}
return 0;
}

int isValidfor2(int a){

if(a>9&&a<=26){
    return 1;
}
return 0;
}

void fun(char a[],int value,int i)
{


    if(value>26)
    {
        return;
    }
    if(value<26&&i==length)
    {
        // spl case
        decodingscount++;
        return;
    }

    if(i==length-1)
    {
        decodingscount++;
        return;
    }

    if(i+1<length)
    {
        int tempvalue=(a[i]-'0')*10;


        tempvalue+=a[i+1]-'0';

        fun(a,tempvalue,i+2);
    }

    fun(a,a[i]-'0',i+1);



}
void fundp(char a[]){
    unsigned long long dp[length+1];
    int i,j;
    dp[0]=1;
    for(i=1; i<=length; i++)
    {
        dp[i]=0;
    }
    int onedigit,twodigit;
    int index=1;
    for(i=0; i<length; i++)
    {
        onedigit=a[i]-'0';

        if(i>=1){
        twodigit=a[i-1]-'0';
        twodigit=twodigit*10+(a[i]-'0');
//printf("values---- %d- -- %d \n ",i,twodigit);
        }

        if(isValid(onedigit)==1)
        {
            dp[index]=dp[index-1];
        }
        if(isValidfor2(twodigit)==1)
        {
            dp[index]+=dp[index-2];
        }



    index++;
    }




    decodingscount = dp[length];


}
int main()
{
    int t;
    char a[5001];

    while(1)
    {
        scanf("%s",&a);

        if(a[0]-'0'==0)
        {
            break;
        }
        decodingscount=0;

        length=strlen(a);

        //fun(a,a[0]-'0',0);

        fundp(a);
        printf("%llu\n",decodingscount);
    }

    return 0;
}
