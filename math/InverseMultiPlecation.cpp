#include<iostream>
using namespace std;
// (A*B)%M=1 
/*
Time Complexity
The algorithm mentioned above runs in O(M).
*/
int inverseMultiPlycationMod(int A, int M){
    for (int B=1;B<M;B++){
        if ((A*B)%M==1) return B;
    }
    return -1;
}
/*Time complexity

                   O(log(max(A,M)))
*/
void extdEquildAlgo (int A,int B,int &x, int &y,int &d){
    if (B==0) {
        d=B;
        x=1;
        y=0;
    }
    else {
        extdEquildAlgo(B,A%B,x,y,d);
        int temp= x;
        x=y;
        y=temp- (A/B)*y;
    }
}
int main(){
    int A,B,M,x,y;
    cout<<"enter big Number : ";
    cin>>A;
    cout<<"enter mod Number : ";
    cin>>M;
    extdEquildAlgo(A,M,B,x,y);
    B = inverseMultiPlycationMod(A, M);
    cout<<"the inverse multiplication is : "<<B;
}