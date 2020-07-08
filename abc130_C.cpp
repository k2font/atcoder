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
    double W, H; cin >> W >> H;
    ll x, y; cin >> x >> y;

    ll cnt = H * W;
    double ans = cnt / 2.0;
    string str = "0";

    if(x == W / 2 && y == H / 2) str = "1";
    cout << fixed << setprecision(10) << ans;
    cout << " " << str << endl;
}