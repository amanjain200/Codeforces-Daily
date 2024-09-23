

#include <bits/stdc++.h>
using namespace std;

// int countOdds(int s, int e) {
//     return ceil((e-s)/2)+(e%2);
//     // if(a==b) return (a%2==1);
//     // return (b / 2) - ((a - 1) / 2);
// }

int countOdd(int L, int R){ 
 
    int N = (R - L) / 2;
 
    // if either R or L is odd 
    if (R % 2 != 0 || L % 2 != 0) 
        N += 1;
 
    return N;
}



int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, life;
        cin >> n >> life;
        long long trees = 0;
        int odd_count = 0;
        int start = n-life+1;
        int end = n;

        // for (long long i = n - life + 1; i <= n; i++) {
        //     if(i%2==1) odd_count++;
        // }

        odd_count = countOdd(start, end);
        
        if (odd_count % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
