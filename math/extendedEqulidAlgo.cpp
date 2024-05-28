#include<iostream>
using namespace std;
 void  ExtendendEquilidAlgo(int A,int B,int &d,int &x,int &y){
        if (B==0) {
            d=B;
            x=1;
            y=0;
        }
        else {
             ExtendendEquilidAlgo(B,A%B,d,x,y);
             int temp= x;
             x=y;
             y=temp- (A/B)*y;
        }
 }
int main(){
    int d,x,y; 
    int A;
    cout<<"enter the max ele : ";
    cin>>A;
    int B;
    cout<<"enter the min ele : ";
    cin>>B;
    ExtendendEquilidAlgo(A,B,d,x,y);
    cout <<"GCD ( "<<A<<" , "<<B<<") = "<<d<<endl;
    cout<<" x = "<<x<<" y = "<<y<<endl;
}