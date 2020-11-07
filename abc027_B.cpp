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
  int tmp = accumulate(all(a), 0);
  if(tmp == 0) {
    cout << 0 << endl;
    return 0;
  }
  int mod = tmp % N;
  if(mod != 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> res(N, 0);
  REP(i, N) res[i] = a[i] - (tmp / N);
  REP(i, N - 1) res[i + 1] += res[i];
  int cnt = 0; int ans = 0;
  for(int i = 0; i < N; ++i) {
    if(res[i] == 0) {
      ans += cnt;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  cout << ans << endl;
}
