#include<bits/stdc++.h>
using namespace std;

// bool func(int idx, string &str, string &taken, bool onedone, int lastidx){
//   if(idx==str.size()-1){
//     if(taken[str[idx]-'a'] == '1') return false;
//     return onedone;
//   }
//   bool nottake = func(idx+1, str, taken, onedone, lastidx);
//   bool take = false;
//   if(taken[str[idx]-'a'] == '0'){
//     taken[str[lastidx+1]-'a'] = '1';
//     bool take = func(idx+1, str, taken, true, idx);
//     taken[str[lastidx+1]-'a'] = '0';
//   }

//   return (take||nottake);
// }

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    string str;
    cin>>str;

    // string taken(26,'0');

    // if(func(0, str, taken, false, -1)){
    //   cout<<"YES"<<endl;
    // }else{
    //   cout<<"NO"<<endl;
    // }
    if(str[0] != str[n-1]){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }


  }

  return 0;
}