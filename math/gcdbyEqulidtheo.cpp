#include <iostream>
using namespace std;
int gcd (int x,int y){
    if (y==0) return x;
    else return gcd(y,x%y);
}

int main (){
    int x,y;
    cout<<"enter x : ";
    cin>>x;
    cout<<"enter y : ";
    cin>>y;
    cout<<gcd(max(x,y),min(x,y))<<endl;
}