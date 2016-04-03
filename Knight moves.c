#include <iostream>
#include <limits.h>
using namespace std;

int x[9] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y[9] = { 1, 2, 2, 1, -1, -2, -2, -1 };




int isSafe(int x1,int y1)
{
    if(x1>=0&&y1>=0&&x1<8&&y1<8)
    {
        return 1;
    }
    return 0;
}

void bfs(int sx,int sy,int dx,int dy)
{


    int queue1[64];
    int start =0,end1=0;
    queue1[end1++]=sx*9+sy;

    int count1=0, i, j;
    int visited[9][9];
    int ans[9][9];

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            visited[i][j]=0;
            ans[i][j]=INT_MAX;
        }
    }

    int currx,curry;

    ans[sx][sy]=0;
    visited[sx][sy]=1;

    while(start<=end1)
    {

        int popdele=queue1[start++];

        currx=popdele/9;
        curry=popdele%9;



        count1=ans[currx][curry];

        if(count1>64)
        {

            break;
        }


        if(currx==dx&&curry==dy)
        {

            cout<<count1<<"\n";
            break;
        }


        for(int k=0; k<8; k++)
        {
            int nextx=currx+x[k];
            int nexty=curry+y[k];

            if(isSafe(nextx,nexty)==1)
            {

                if(visited[nextx][nexty]==1)
                {
                    if(ans[nextx][nexty]>ans[currx][curry]+1)
                    {

                        ans[nextx][nexty]=ans[currx][curry]+1;
                    }
                }
                else
                {
                    visited[nextx][nexty]=1;
                    ans[nextx][nexty]=ans[currx][curry]+1;
                    queue1[end1++]=nextx*9+nexty;

                }
            }

        }

    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[3],b[3];
        int sx,sy,dx,dy;

        cin>>a;
        cin>>b;


        sy=a[0]-'a';
        sx=a[1]-'0';
        dy=b[0]-'a';
        dx=b[1]-'0';



        //sy=(int)a-'a';
        //dy=(int)b-'a';
        bfs(sx-1,sy,dx-1,dy);

    }

    return 0;
}

