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
  vector<ll> a(N); REP(i, N) cin >> a[i];
  vector<pair<int, int>> ans;
  int max_n = -1e9; int min_n = 1e9;
  int max_t = -1; int min_t = -1;
  REP(i, N) {
    if(max_n < a[i]) {
      max_n = a[i]; max_t = i;
    }
    if(min_n > a[i]) {
      min_n = a[i]; min_t = i;
    }
  }

  REP(i, N - 1) {
    if(a[i] > a[i + 1]) break;
    if(i == N - 2) {
      cout << 0 << endl;
      return 0;
    }
  }

  if(min_n < 0 && max_n > 0) { // 正と負が入り混じっている時
    if(abs(min_n) > abs(max_n)) { // min_nの絶対値のほうが大きい時
      // 全部負にする
      REP(i, N) {
        a[i] += min_n;
        ans.push_back(P(min_t, i));
      }
    } else {
      // 全部正にする
      REP(i, N) {
        a[i] += max_n;
        ans.push_back(P(max_t, i));
      }
    }
  }
  
  max_n = -1e9; min_n = 1e9;
  max_t = -1; min_t = -1;
  REP(i, N) {
    if(max_n < a[i]) {
      max_n = a[i]; max_t = i;
    }
    if(min_n > a[i]) {
      min_n = a[i]; min_t = i;
    }
  }

  if(min_n >= 0) { // すべて正のとき
    REP(i, N - 1) {
      a[i + 1] += a[i];
      ans.push_back(P(i, i + 1));
    }
  } else { // すべて負のとき
    for(int i = N - 1; i >= 1; --i) {
      a[i - 1] += a[i];
      ans.push_back(P(i, i - 1));
    }
  }

  cout << ans.size() << endl;
  REP(i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}