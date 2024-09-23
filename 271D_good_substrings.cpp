#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

  string str;
  string goodbad;
  int k;
  cin >> str >> goodbad >> k;

  // sliding window approach
  int ans = 0;
  int left = 0;
  int right = 0;
  int siz = str.size();
  int badtillnow = 0;
  unordered_map<string, int> mp;

  while (right < siz)
  {
    if (k!=0 && goodbad[str[right] - 'a'] == '0' && badtillnow == k)
    {
      while (badtillnow >= k)
      {
        if (goodbad[str[left] - 'a'] == '0')
        {
          badtillnow--;
        }
        left++;
      }
    }
    else if(badtillnow >k){
      while (badtillnow > k)
      {
        if (goodbad[str[left] - 'a'] == '0')
        {
          badtillnow--;
        }
        left++;
      }
    }

    right = max(right, left);
    if (goodbad[str[right] - 'a'] == '0')
    {
      badtillnow++;
    }
    right++;
    //mp[str.substr(left, right - left )]++;
    if(badtillnow <= k){
      for(int i=left; i<right; i++){
      mp[str.substr(i, right - i )]++;
    }}
  }



  if (badtillnow > k)
    {
      while (badtillnow > k)
      {
        if (goodbad[str[left] - 'a'] == '0')
        {
          badtillnow--;
        }
        left++;
      }
    }

    while(badtillnow < k && left != right){
      mp[str.substr(left, right - left )]++;
      left++;
    }



  cout << mp.size() << endl;
  for (auto &it : mp)
  {
    cout << it.first << endl;
  }

  return 0;
}