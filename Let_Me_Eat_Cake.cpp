#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    int ans = 0;
    while(a != b){
      if(a>b){
        ans+=ceil(1.0*a/2);
        a=(a/2);
      }else{
        ans+=ceil(1.0*b/2);
        b=(b/2);
      }
    }    

    cout<<ans<<endl;

  }

  return 0;
}