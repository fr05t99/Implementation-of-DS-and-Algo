#include<iostream>
using namespace std;
int main(){
    int a[30],n;
    cout<<"Enter no. of elements in array ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;){
            if(a[i]==a[j]){
                for(int k=j;k<n-1;k++){
                    a[k]=a[k+1];
                }
                n--;}
             else{
                j++;
             }

        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
