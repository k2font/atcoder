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
  vector<int> H(N); REP(i, N) cin >> H[i];

  int ans = 1;
  REP(i, N) {
    if(i == 0) continue;

    for(int k = 0; k < i; ++k) {
      if(H[i] < H[k]) break;
      if(k == i - 1) ans++;
    }
  }

  cout << ans << endl;
}