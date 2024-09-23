#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;

    vector<long long> vec(n);
    long long sum = 0;
    for(int i=0; i<n; i++){
      cin>>vec[i];
      sum+=vec[i];
    } 
    if(n<3){
      cout<<-1<<endl;
      continue;
    }

    sort(vec.begin(), vec.end());

    int halfidx;

    halfidx = n/2;

    double currAvg = (1.0*sum)/n;

    // cout<<sum<<endl;
    // cout<<currAvg<<endl;
    // cout<<vec[halfidx]<<endl;
    // cout<<(1.0*vec[halfidx])*2<<endl;
    if(currAvg > double(vec[halfidx])*2){
      cout<<0<<endl;
      continue;
    }
    long long reqAvg = 2*(vec[halfidx]);

    long long x = n*reqAvg - sum;
    x+=1;
    cout<<x<<endl;

  }



  return 0;
}