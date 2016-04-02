#include <stdio.h>
#include <stdlib.h>
int n;
int a[10000000];
int globalxor=-65553636;
int initk;
int fun(int i,int k,int lxor){


	if(k==0){
        if(globalxor<lxor){
                globalxor=lxor;
                //printf("ans  ",lxor);
               //printf("\n");

        }

        k=initk;
        lxor=-65553636;

}

if(i>=n){
    return;
}






//printf("goto i=%d , k=%d , lxor=%d  ",i+1,k-1,lxor);
//printf("\n");
fun(i+1,k,lxor);

if(lxor==-65553636){
    lxor=a[i];
}
else{
    lxor=lxor^a[i];
}
//printf("goto i=%d , k=%d , lxor=%d  ",i+1,k-1,lxor);
//printf("\n");

fun(i+1,k-1,lxor);

}

int main()
{

    int i,t,k;




    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
         scanf("%d",&a[i]);
    }

    int lxor=-65553636;

 globalxor=-65553636;
    initk=k;
   fun(0,k,lxor);


	  printf("%d\n",globalxor);
    }

    return 0;
}
