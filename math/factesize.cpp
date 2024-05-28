#include<iostream>
#include<vector>
using namespace std;
void collectPrime (vector<int> &vec,int n){
       for (int i=2;i*i<=n;i++){
        if (vec[i]==0){
            for(int j=i*i;j<=n;j+=i){
                vec[j]=i;
            }
        }
       }
}
    int main (){
    int n;
    cout<<"enter the max number range : ";
    cin>>n;
    vector<int> vec (n+1,0);
    collectPrime (vec,n);
    for (int i=0;i< vec.size ();i++){
        if (vec[i]==0)
        cout<<i<<" ";
    }


}