#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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

// 半分全列挙のお勉強
int main() {
  int N; cin >> N;
  ll T; cin >> T;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  int n = min(N, 20);
  int m = N - n;
  vector<ll> v1, v2;
  v1.push_back(0); v2.push_back(0);
  int k1 = 1 << n; int k2 = 1 << m;
  for(int i = 1; i < k1; ++i) {
    ll t = 0;
    for(int j = 0; j < n; ++j) {
      if(((1 << j) & i) != 0) {
        t += A[j]; // 前からn個だけ走査して条件を満たした項目だけ足し込む
      }
    }

    if(t <= T) v1.push_back(t);
  }

  for(int i = 1; i < k2; ++i) {
    ll t = 0;
    for(int j = n; j < N; ++j) {
      if(((1 << (j - n)) & i) != 0) {
        t += A[j]; // 前からn個だけ走査して条件を満たした項目だけ足し込む
      }
    }

    if(t <= T) v2.push_back(t);
  }

  sort(all(v2));
  ll ans = 0;
  for(ll i : v1) {
    int l = -1;
    int r = v2.size();
    while(r - l > 1) {
      int mid = l + (r - l) / 2;
      if(i + v2[mid] <= T) l = mid;
      else r = mid;
    }
    ll res = i + v2[l];
    ans = max(ans, res);
  }
  cout << ans << endl;
}