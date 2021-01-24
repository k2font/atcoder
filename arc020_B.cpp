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
  int n; cin >> n; int c; cin >> c;
  vector<int> a(n); REP(i, n) cin >> a[i];
  ll ans = pow(10, 9);
  for(int i = 1; i <= 10; ++i) {
    for(int k = 1; k <= 10; ++k) {
      if(i == k) continue;
      ll tmp = 0;
      REP(m, n) {
        if(m % 2 == 0) {
          if(i != a[m]) tmp += c;
        } else if(m % 2 == 1) {
          if(k != a[m]) tmp += c;
        }
      }
      chmin(ans, tmp);
    }
  }
  cout << ans << endl;
}