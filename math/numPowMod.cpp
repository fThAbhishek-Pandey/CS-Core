#include<iostream>
using namespace std;
int main(){
    int x,n;
    cout<<"enter number : ";
    cin>>x;
    cout<<"enter pow : ";
    cin>>n;
    cout<<"enter modulo : ";
    int mod= 16;
    int res =1;
    while (n>0){
        if (n%2==1) (res*=x)%16;
        x= (x*x)%mod;
        n/=2;
    }
       cout<<res<<endl;
        return 0;
}