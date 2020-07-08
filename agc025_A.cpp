#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 各桁の和の計算
int digit_sum(int n){
   if(n < 10)  return n;
   return digit_sum(n/10) + n%10;
}

int main(){
    int N; cin >> N;

    int res = 100000007;
    int cnt = 0;
    REP(i, N / 2 + 1) {
        if(i == 0) continue;
        int A = i;
        int B = N - A;

        cnt = digit_sum(A) + digit_sum(B);

        if(res > cnt) {
            res = cnt;
        }
        cnt = 0;
    }

    cout << res << endl;
}