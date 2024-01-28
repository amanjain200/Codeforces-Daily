#include<iostream>
using namespace std;


int main(){

  int m=3, n=6;
  cin>>m>>n;

  int brr[m][n];
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin>>brr[i][j];
    }
  }

  int arr[m][n];
  for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
          arr[i][j] = -1;
      }
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(brr[i][j]==0){
        //make row and column i & j of arr as 0
        for(int k=0; k<n; k++){
          arr[i][k]=0;
        }
        for(int k=0; k<m; k++){
          arr[k][j]=0;
        }
      }
    }
  }


  //now for the 1s in brr
  bool fail = false;
  for(int i=0; i<m; i++){
    bool nonzero = true;
    for(int j=0; j<n; j++){
      if(brr[i][j]==1){
        nonzero=false;
        for(int k=0; k<n; k++){
          if(arr[i][k]!=0){
            nonzero=true;
            arr[i][k] = 1;
          }
        }
        for(int k=0; k<m; k++){
          if(arr[k][j]!=0){
            nonzero=true;
            arr[k][j] = 1;
          }
        }
      }
      if(nonzero != true){
        fail = true;
        break;
      }
    }
    if(nonzero != true){
        fail = true;
        break;
      }
  }

  if(fail){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  

  return 0;
}