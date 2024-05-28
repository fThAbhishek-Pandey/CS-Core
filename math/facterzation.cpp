#include<iostream>
#include<vector> 
using namespace std;
vector<int> factor (int n){
      vector<int > res;
      for (int i=2;i*i<=n;i++){
        while (n%i==0){
            res.push_back(i);
            n/=2;
        }
      }
      if (n!=1) res.push_back(n);
      return res;
}
int main (){
    int n;
    cin>>n;
    vector<int> ans= factor( n);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}