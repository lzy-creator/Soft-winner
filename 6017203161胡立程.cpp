#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int q[100]= {0},cnt=0;
int n;
void init()
{
    int *p;
    for(p=q;p<q+n;++p)
    {

        *p=-1000;
    }
}
int check(int line,int lis)
{
    for(int i=0; i<n; i++)
    {
        int data=q[i];
        if(lis==data)
            return 0;
        if((i+data)==(line+lis))
            return 0;
        if((i-data)==(line-lis))
            return 0;
    }
    return 1;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(q[i]!=j)
                printf("0 ");
            else
                printf("# ");
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void Queen()
{
    int m=0;
    int i=0,j=0;
    while(i<n)
    {
        while(j<n)
        {
            if(check(i,j))
            {
                q[i]=j;
                j=0;
                break;
            }
            else {
                ++j;
            }
        }
        if(q[i]==-1000)
        {

            if(i==0)
                break;
            else
            {
                --i;
                j=q[i]+1;
                q[i]=-1000;
                continue;
            }
        }
        if(i==n-1)
        {
            ++m;
            print();
            j=q[i]+1;
            q[i]=-1000;
            continue;
        }
        ++i;
    }
    printf("answer=%d\n",m);
}
int main()
{
    scanf("%d",&n);
    init();
    Queen();
    system("pause");
    return 0;
}
