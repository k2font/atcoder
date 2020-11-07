#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  int ans = -100000000;
  REP(i, N) {
    int tak_res = -10000000;
    int aoki_res = -10000000;
    REP(k, N) {
      if(i == k) continue;
      int tmp = 0; int aoki = 0;
      if(i < k) {
        for(int m = i; m <= k; ++m) {
          if((m - i) % 2 == 0) tmp += a[m];
          else aoki += a[m];
        }
      } else {
        for(int m = k; m <= i; ++m) {
          if((m - k) % 2 == 0) tmp += a[m];
          else aoki += a[m];
        }
      }
      if(aoki_res < aoki) {
        aoki_res = aoki;
        tak_res = tmp;
        // cout << i << " " << k << " " << tak_res << " " << aoki_res << endl;
      }
    }
    ans = max(ans, tak_res);
  }
  cout << ans << endl;
}
