#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n, duration, jobs;
    cin>>n>>duration>>jobs;

    vector<vector<int>> vec(jobs, vector<int>(2));

    for(int i=0; i<jobs; i++){
      cin>>vec[i][0];
      cin>>vec[i][1];
    }

    vector<int> jobsday(n+1, 0);
    for(int i=0; i<jobs; i++){
      jobsday[vec[i][0]-1]++;
      jobsday[vec[i][1]]--;
    }

    for(int i=1; i<n; i++){
      jobsday[i]+=jobsday[i-1];
    }

    int maxi=0, mini=1e9;
    int maxidx=-1, minidx=-1;
    for(int i=0; i<n-duration+1; i++){
      if(jobsday[i]>maxi){
        maxi=jobsday[i];
        maxidx=i+1;
      }
      if(jobsday[i]<mini){
        mini=jobsday[i];
        minidx = i+1;
      }
    }
    maxidx = max(1, maxidx-duration+1);
    //minidx = max(1, minidx-duration+1);
    cout<<maxidx<<" "<<minidx<<endl;
  }

  return 0;
}