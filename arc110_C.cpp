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
  vector<int> P(N); REP(i, N) cin >> P[i];
  vector<int> ans; int memo = 1; // i番目 + 1の値を入れる
  REP(i, N) {
    if(P[i] == memo) {
      for(int k = i; k >= memo; --k) {
        swap(P[k], P[k - 1]); ans.push_back(k);
      }
      for(int k = i; k >= memo; --k) {
        if(P[k - 1] != k) {
          cout << -1 << endl;
          return 0;
        }
      }
      memo = i + 1;
    }
  }
  if(ans.size() != N - 1) {
    cout << -1 << endl;
    return 0;
  }
  REP(i, ans.size()) cout << ans[i] << endl;
}