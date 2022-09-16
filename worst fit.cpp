#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct p{
int acum[100];
int jp[100];
}st;
int main()
{
int n,m,i,count=0,j,pn[100];
int p[100],size[100];
bool flag[100];
printf("ENTER THE NO PROCESS AND MEMORY :\n ");
scanf("%d%d",&n,&m);
printf("ENTER THE SIZE OF PROCESS \n");
for(i=0;i<n;i++)
scanf("%d",&p[i]);
printf("ENTER THE SIZE OF MEMORY PARTION \n");
for(i=0;i<m;i++)
{
scanf("%d",&size[i]);
flag[i]=0;
int k;
st.acum[i]=size[i];
st.jp[i]=i;
for(k=i;k>0;k--)
{
if(st.acum[k]<=st.acum[k-1])
{
int temp=st.acum[k];
st.acum[k]=st.acum[k-1];
st.acum[k-1]=temp;
temp=st.jp[k];
st.jp[k]=st.jp[k-1];
st.jp[k-1]=temp;
}
}
}
int x=m-1;
for(i=0;i<n;i++)
{
if(p[i]<=st.acum[x]&&flag[st.jp[x]]==0)
{
flag[st.jp[x]]=true;
pn[st.jp[x]]=i;
x--;
count++;
}
}
printf("NO OF PROCESS CAN ACOMADATE :%d\n\n",count);
printf("MEMORY\tPROCESS\n");
for(i=0;i<m;i++ )
{
if(flag[i]==1)
{
printf("%d <-->%d\n",size[i],p[pn[i]]);
}
else
printf("%d\tMEMORY NOT ALLOCATED\n",size[i]);
}
return 0;
}
