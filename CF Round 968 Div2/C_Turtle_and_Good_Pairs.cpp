#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string str;
    cin>>str;

    // sort(str.begin(), str.end());
    // int s=1, e=n-1;
    // while(s < e){
    //   if(str[s]==str[s-1]){
    //     swap(str[s], str[e]);
    //     s++; e--;
    //   }
    //   else{
    //     s++;
    //   }
    // }
    vector<int> freq(26, 0);
    priority_queue<pair<int,int>> pq; //max heap sort on basis of freq
    for(auto &it : str) freq[it-'a']++;
    for(int i=0; i<26; i++){
      if(freq[i]> 0)
        pq.push({freq[i], i});
    }

    string ans = "";
    while(!pq.empty()){
      int p1_f = pq.top().first;
      int p1_c = pq.top().second;
      pq.pop();
      ans+=(p1_c + 'a');
      p1_f--;

      if(!pq.empty()){
        int p2_f = pq.top().first;
        int p2_c = pq.top().second;
        pq.pop();
        ans+=(p2_c + 'a');
        p2_f--;
        if(p2_f > 0) pq.push({p2_f, p2_c});
      }
      if(p1_f > 0) pq.push({p1_f, p1_c});

    }


    cout<<ans<<endl;
    
  }

  return 0;
}