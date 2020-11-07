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
  ll n; cin >> n;
  ll a = 0; ll b = pow(10, 9) + 1000000;
  for(ll i = 1; i <= 100000; ++i) {
    ll _a = i * i;
    // cout << _a << " " << i << endl;
    if(n % _a == 0) {
      if((n / _a) <= b) {
        a = i;
        b = n / _a;
      }
    }
  }
  cout << a << " " << b << endl;
}