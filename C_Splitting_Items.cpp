#include<bits/stdc++.h>
using namespace std;

//total increase less than k
//can't decrease
//

int main(){

  int t;
  cin>>t;

  while(t--){
    int n, k;
    cin>>n>>k;

    vector<int> vec(n);
    for(int i=0; i<n; i++) cin>>vec[i];

    sort(vec.rbegin(), vec.rend());

    for(int i=1; i<vec.size(); i+=2){
      int change = min(k, vec[i-1]-vec[i]);
      vec[i] += change;
      k-=change;
    }

    int alice=0, bob=0;
    for(int i=0; i<vec.size(); i++){
      if(i%2==0) alice+=vec[i];
      else bob+=vec[i];
    }

    cout<<alice-bob<<endl;

  }

  return 0;
}