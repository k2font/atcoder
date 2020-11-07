#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  vector<int> ans(N + 1, 0);
  for(int i = N - 1; i >= 0; --i) {
    int tmp = i + 1; int res = 0;
    for(int k = tmp; k <= N; k += tmp) {
      // cout << res << endl;
      res += ans[k];
    }
    if(res % 2 != a[i]) ans[tmp] = 1;
  }

  int b = 0;
  REP(i, N + 1) {
    if(i == 0) continue;
    if(ans[i] > 0) b++;
  }
  cout << b << endl;
  for(int i = 1; i <= N; ++i) {
    if(ans[i] == 1) cout << i << " ";
  }
  cout << endl;
}