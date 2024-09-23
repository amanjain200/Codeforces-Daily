#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int len;
    cin>>len;
    vector<int> vec(len);
    for(int i=0; i<len; i++) cin>>vec[i];
    
    //turtle will find the minimum and increases it
    //piggy will find the maximum and reduce it
    vector<pair<int,int>> pairs;
    for(int i=0; i<len-1; i++){
      pairs.push_back({vec[i], i});
    }
    sort(pairs.begin(), pairs.end());
    int lastidx = 0;
    int s=0, e=len-1;
    while(s<=e){
      int sidx = pairs[s].second;
      int eidx = pairs[e].second;
      s++; e--;
      if(vec[sidx]!=-1){
        vec[sidx] = max(vec[sidx], vec[sidx+1]);
        vec[sidx+1] = -1;
        lastidx = sidx;
      }
      if(vec[eidx] != -1){
        vec[eidx] = min(vec[eidx], vec[eidx+1]);
        vec[eidx+1] = -1;
        lastidx = eidx;
      }

    }

    //for(auto it : vec) cout<<it<<" ";
    //int maxi=-1;
    // for(auto it : vec){
    //   maxi=max(maxi, it);
    // }
    cout<<vec[lastidx]<<endl;

    
  }

  return 0;
}