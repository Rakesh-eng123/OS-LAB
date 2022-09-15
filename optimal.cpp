
#include<stdio.h>
int optimalframe(int w[],int m);
int main()
{
int i,j,n,m,r,pagef,l,h,p;
int a[100],b[100],w[10];
pagef=0;
printf("enter the number of pages\n");
scanf("%d",&n);
printf("enter the number of frames in main memory\n");
scanf("%d",&m);
for(i=0;i<m;i++)
b[i]=-1;
for(i=0;i<n;i++)
{
printf("enter the element %d\n",i);
scanf("%d",&a[i]);
}
for(i=0;i<m;i++)
{
b[i]=a[i];
 for(r=0;r<m;r++)
printf("%d ",b[r]);
printf("\n");
pagef++;
}
for(i=m;i<n;i++)
{
for(j=0;j<m;j++)
{
if(b[j]==a[i])
{
printf("the page %d is already present in main memory\n",a[i]);
break;
}
}
if(j==m)
{
for(l=0;l<m;l++)
{
for(p=i+1;p<n;p++)
{

if(b[l]==a[p])
{
w[l]=p;
break;
}
}
if(p==n)
{
b[l]=a[i];
break;
}}
if(l==m)
{
h=optimalframe(w,m);
b[h]=a[i];
}
for(r=0;r<m;r++)
printf("%d ",b[r]);
printf("\n");
pagef++;
}
}
printf("number of page faults: %d",pagef);
}
int optimalframe(int w[],int m)
{
int max,k,h=0;
max=w[0];
for(k=1;k<m;k++)
if(w[k]>max)
{
max=w[k];
h=k;
}
return h;
}
 
