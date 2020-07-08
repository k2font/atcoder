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
  vector<int> W(N); REP(i, N) cin >> W[i];

  int ans = pow(10, 6) + 7;
  int sum_n = accumulate(all(W), 0LL);

  REP(i, N) {
    int sum_b = 0;
    for(int k = i + 1; k < N; ++k) {
      sum_b += W[k];
    }
    int sum_a = sum_n - sum_b;
    int tmp = abs(sum_a - sum_b);
    if(tmp < ans) ans = tmp;
  }

  cout << ans << endl;
}