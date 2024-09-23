#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n, x, y;
    cin>>n>>x>>y;

    string amoves;
    cin>>amoves;

    int ax=0, ay=0;

    for(int i=0; i<=n; i++){
      int diff = abs(x-ax) + abs(y-ay);
      if(diff<=i){
        if((i-diff)%2 == 0){
          cout<<"Yes"<<endl;
          break;
        }
      }
      if(i<n){
        if(amoves[i]=='L'){
          ax--;
        }else if(amoves[i]=='R'){
          ax++;
        }else if(amoves[i]=='U'){
          ay++;
        }else{
          ay--;
        }
      }

      if(i==n) cout<<"No"<<endl;

    }



  }

  return 0;
}