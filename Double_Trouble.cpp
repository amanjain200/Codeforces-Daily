#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long n, k;
    cin>>n>>k;
    vector<long long> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=0; i<n; i++) pq.push(arr[i]);

    while(k--){
      long long temp = pq.top();
      //cout<<temp<<"-"<<endl; 
      pq.pop();
      pq.push((temp+temp));
    }

    long long ans = 0;
    while(!pq.empty()){
      long long temp = pq.top();
      pq.pop();

      ans = (ans+temp)%mod;
    }

    cout<<ans<<endl;

  }

  return 0;
}