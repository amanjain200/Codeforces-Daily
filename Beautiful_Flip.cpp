#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n, k;
    cin>>n>>k;
    string str;
    cin>>str;

    int zeros=0, ones = 0;
    for(int i=0; i<n; i++){
      if(str[i]=='0') zeros++;
      else ones++;
    }

    int reqchanges = abs(ones-zeros)/2;

    


  }

  return 0;
}