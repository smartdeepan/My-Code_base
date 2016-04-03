#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length;
int decodingscount=0;
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

        fun(a,a[0]-'0',0);

        printf("%d\n",decodingscount);
    }

    return 0;
}
