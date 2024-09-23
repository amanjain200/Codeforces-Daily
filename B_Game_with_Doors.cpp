#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int l1, r1, l2, r2;
    cin>>l1>>r1;
    cin>>l2>>r2;
    
    if(l2<l1){
      //swap
      int t1 = l1, t2=r1;
      l1=l2; r1=r2;
      l2=t1; r2=t2;
    }

    if(l2>l1 && l2<r1 && r1==r2){
      //same at rigt end
      cout<<r2-l2+1<<endl;
    }else if(l1==l2 && r2<r1){
      //same at left end
      cout<<r2-l2+1<<endl;
    }else if(l2>l1 && r2<r1){
      //fully inside
      cout<<2+r2-l2<<endl;
    }else if(r1<l2){
      //fully diff
      cout<<1<<endl;
    }else if(l1==l2 && r1==r2){
      cout<<r1-l1<<endl;
    }else if(r1==l2 && r2>=r1){
      cout<<2<<endl;
    }
    else{
      cout<<r1-l2+1<<endl;
    }

  }



  return 0;
}