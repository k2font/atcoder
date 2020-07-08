#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  ll N; cin >> N;
  bool flag = false;
  for(ll h = 1; h <= 10000; ++h) {
    for(ll n = 1; n <= 10000; ++n) {
      ll a = N * h * n;
      ll b = 4 * n * h - N * n - N * h;
      ll c = a / b;
      if(a > 0 && b > 0) {
        if(a % b == 0) {
          cout << h << " " << n << " " << c << endl;
          flag = true;
          break;
        }
      }
    }
    if(flag) break;
  }
}