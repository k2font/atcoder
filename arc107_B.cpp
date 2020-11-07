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
  ll N, K; cin >> N >> K;
  ll res = 0;
  // 各和の作り方の場合の数を求める
  vector<ll> ans(N + N + 1); int a = 2 * N + 1;
  ans[0] = 0; ans[1] = 0;
  REP(i, a) {
    if(i == 0) continue;
    if(i == 1) continue;
    ans[i] = i - 1;
    // いらない数を取り除く
    if(i - 1 - N >= 0) {
      ans[i] -= (i - 1 - N) * 2;
    }
  }
  if(K >= 0) {
    for(int i = 2; i < a; ++i) {
      if(i + K > N + N) continue;
      res += (ans[i] * ans[i + K]);
    }
  } else {
    for(int i = 2; i < a; ++i) {
      if(i - K > N + N) continue;
      res += (ans[i] * ans[i - K]);
    }
  }
  cout << res << endl;
}