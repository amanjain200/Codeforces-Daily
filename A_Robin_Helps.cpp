#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n, threshold;
    cin>>n>>threshold;
    vector<int> people(n);

    for(int i=0;i<n; i++) cin>>people[i];

    int ans = 0;
    int currGold = 0;
    for(int i=0; i<n; i++){
      if(people[i]>=threshold){
        currGold+=people[i];
      }else if(currGold>0 && people[i]==0){
        currGold--;
        ans++;
      }
    }

    cout<<ans<<endl;
  }



  return 0;
}