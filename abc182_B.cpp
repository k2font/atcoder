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

// 最大公約数(ゼロ除算対策済みバージョン)
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  int ans = 0; int a = 0;
  for(int i = 2; i <= 1000; ++i) {
    int res = 0;
    REP(k, N) {
      if(A[k] % i == 0) res++;
    }
    if(ans <= res) {
      a = i;
      ans = res;
    }
  }
  cout << a << endl;
}