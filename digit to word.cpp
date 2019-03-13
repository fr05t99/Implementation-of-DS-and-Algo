#include<iostream>
using namespace std;
main()
{
int n;
cin>>n;
char c[n];
cin>>c;
int a[n];
int k=0;
for(int i=n-1;i>=0;i--)
{
a[i]=c[k]-'0';
k++;
}
for(int j=n-1;j>=0;j--)
{
if(j==0)
{
switch(a[j])
{
case 1:
cout<<"one ";
break;
case 2:
cout<<"two ";
break;
case 3:
cout<<"three ";
break;
case 4:
cout<<"four ";
break;
case 5:
cout<<"five ";
break;
case 6:
cout<<"six ";
break;
case 7:
cout<<"seven ";
break;
case 8:
cout<<"eight ";
break;
case 9:
cout<<"nine ";
break;
default:
cout<<" ";
}
}
if(j==1)
{
switch(a[j])
{
case 1:
switch(a[0])
{
case 0:
cout<<"ten ";
j--;
break;
case 1:
cout<<"eleven ";
j--;
break;
case 2:
cout<<"twelve ";
j--;
break;
case 3:
cout<<"thirteen " ;
j--;
break;
case 4:
cout<<"fourteen ";
j--;
break;
case 5:
cout<<"fifteen ";
j--;
break;
case 6:
cout<<"sixteen ";
j--;
break;
case 7:
cout<<"seventeen ";
j--;
break;
case 8:
cout<<"eighteen ";
j--;
break;
case 9:
cout<<"nineteen ";
j--;
break;
default:
cout<<" ";
}
break;
case 2:
cout<<"twenty ";
break;
case 3:
cout<<"thirty ";
break;
case 4:
cout<<"fourty ";
break;
case 5:
cout<<"fifty ";
break;
case 6:
cout<<"sixty ";
break;
case 7:
cout<<"seventy ";
break;
case 8:
cout<<"eighty ";
break;
case 9:
cout<<"ninety ";
break;
default:
cout<<" ";
}
}
if(j==2)
{
    switch(a[j])
    {
    case 0:
        cout<<" ";
        break;
    case 1:
        cout<<"One hundred ";
        break;
    case 2:
        cout<<"Two hundred ";
        break;
    case 3:
        cout<<"Three hundred ";
        break;
    case 4:
        cout<<"Four hundred ";
        break;
    case 5:
        cout<<"Five hundred ";
        break;
    case 6:
        cout<<"Six hundred ";
        break;
    case 7:
        cout<<"Seven hundred ";
        break;
    case 8:
        cout<<"Eight hundred ";
        break;
    case 9:
        cout<<"Nine Hundred ";
        break;
    default:
        cout<<" ";
    }}
    else if(j%2!=0&&j>=3)
    {
        switch(a[j])
    {
    case 0:
        cout<<" ";
        break;
    case 1:
        cout<<"One ";
        break;
    case 2:
        cout<<"Two ";
        break;
    case 3:
        cout<<"Three ";
        break;
    case 4:
        cout<<"Four ";
        break;
    case 5:
        cout<<"Five ";
        break;
    case 6:
        cout<<"Six ";
        break;
    case 7:
        cout<<"Seven ";
        break;
    case 8:
        cout<<"Eight ";
        break;
    case 9:
        cout<<"Nine ";
        break;
    default:
        cout<<" ";
    }
    }
    else if(j%2==0&&j>=3
)
    {
        switch(a[j])
    {
    case 0:
        cout<<" ";
        break;
    case 1:

switch(a[j-1])
{
case 0:
cout<<"ten ";
j--;
break;
case 1:
cout<<"eleven ";
j--;
break;
case 2:
cout<<"twelve ";
j--;
break;
case 3:
cout<<"thirteen " ;
j--;
break;
case 4:
cout<<"fourteen ";
j--;
break;
case 5:
cout<<"fifteen ";
j--;
break;
case 6:
cout<<"sixteen ";
j--;
break;
case 7:
cout<<"seventeen ";
j--;
break;
case 8:
cout<<"eighteen ";
j--;
break;
case 9:
cout<<"nineteen ";
j--;
break;
default:
cout<<" ";
}
        break;
    case 2:
        cout<<"Twenty ";
        break;
    case 3:
        cout<<"Thirty ";
        break;
    case 4:
        cout<<"Fourty ";
        break;
    case 5:
        cout<<"Fifty ";
        break;
    case 6:
        cout<<"Sixty ";
        break;
    case 7:
        cout<<"Seventy ";
        break;
    case 8:
        cout<<"Eighty ";
        break;
    case 9:
        cout<<"Ninety ";
        break;
    default:
        cout<<" ";
    }
    }
    if(j==3)
    {
        cout<<" Thousand ";
    }
    if(j==5)
    {
        cout<<" Lakh ";
    }
    if(j==7)
    {

        cout<<" Crore ";
    }
    if(j==9)
    {

        cout<<"Arab";
    }

}
}
