#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());

    if(n==2 && arr[1]-arr[0]>1){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
    
    

  }



  return 0;
}