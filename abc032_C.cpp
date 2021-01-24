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
  vector<ll> s(N); REP(i, N) cin >> s[i];
  // 0があるかどうか判定する
  REP(i, N) {
    if(s[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }

  // それ以外
  int right = 0;
  ll sum = 1;
  ll res = 0; ll ans = 0;
  for(int left = 0; left < N; ++left) {
    // cout << "left: " << left << " right: " << right << endl;
    while(right < N && sum * s[right] <= K) {
      sum *= s[right];
      right++;
    }
    chmax(ans, (ll)right - (ll)left);

    res += (N - right);

    if(right == left) ++right;
    else {
      if(s[left] == 0) sum = 1;
      else sum /= s[left];
    }
  }
  cout << ans << endl;
}