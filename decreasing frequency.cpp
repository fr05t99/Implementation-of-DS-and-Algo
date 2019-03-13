#include<iostream>
using namespace std;
int main(){
    int a[30],n,b[30],counti=1,l=0,maxi,in=0,temp;
    cout<<"Enter no. of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;){
            if(a[i]==a[j]){
                counti++;
                for(int k=j;k<n-1;k++){
                    a[k]=a[k+1];
                }
                n--;
            }
            else{
                j++;
            }
        }
        b[l]=(a[i]*100)+counti;
        l++;
        counti=1;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l-i-1;j++){
            if((b[j]%100)>=(b[j+1]%100)){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for(int k=l-1;k>=0;k--){
        cout<<b[k]/100<<" occured "<<b[k]%100<<" times.\n";
    }
}
