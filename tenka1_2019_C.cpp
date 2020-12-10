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
  ll N; cin >> N;
  vector<ll> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  vector<P> t(N);
  REP(i, N) t[i] = P(A[i], B[i]);
  sort(all(t), greater<pair<ll, ll>>());
  ll a = 0; ll b = 0;
  REP(i, N) {
    if(i % 2 == 0) a += t[i].first;
    else b += t[i].second;
  }
  cout << a - b << endl;
}