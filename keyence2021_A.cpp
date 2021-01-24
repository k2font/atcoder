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

int main() {
  ll N; cin >> N;
  vector<ll> a(N), b(N); REP(i, N) cin >> a[i]; REP(i, N) cin >> b[i];
  ll max_a = 0; int max_i_a = -1;
  ll max_l = 0;
  REP(i, N) {
    ll max_b = 0; int max_i_b = -1;
    // 数列aのi番目までの最大値と、その時の位置を求める
    if(max_a < a[i]) {
      max_a = a[i]; max_i_a = i;
    }

    if(max_b < b[i]) {
      max_b = b[i]; max_i_b = i;
    }

    // max_i_aからNまでの最大値を高速に求めるには?
    // if(max_i_a > max_i_b) {
    //   ll tmp = 0;
    //   for(int k = max_i_a; k <= i; ++k) {
    //     tmp = max(tmp, b[k]);
    //   }
    //   max_b = tmp;
    // }

    ll ans = max_a * max_b;
    max_l = max(ans, max_l);
    cout << max_l << endl;
  }
}
