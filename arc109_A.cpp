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
  int a, b, x, y; cin >> a >> b >> x >> y;
  if(a == b) {
    cout << x << endl;
  } else if(a < b) {
    if(y <= 2 * x) {
      cout << (b - a) * y + x << endl;
    } else if(y > 2 * x) {
      cout << (b - a) * 2 * x + x << endl;
    }
  } else if(a > b) {
    if(y <= 2 * x) {
      cout << ((a - b) - 1) * y + x << endl;
    } else if(y > 2 * x) {
      cout << (a - b) * 2 * x - x << endl;
    }
  }
}