#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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

int gcd(int a, int b) {
  if (a % b == 0) {
    return(b);
  } else {
    return(gcd(b, a % b));
  }
}

int main() {
  ll N; cin >> N;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  ll gcd_n = a[0];
  for(int i = 1; i < N; ++i) {
    gcd_n = gcd(a[i], gcd_n);
  }
  cout << gcd_n << endl; 
}