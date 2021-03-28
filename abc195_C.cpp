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
  string hantei = to_string(N);
  ll ans = 0;
  for(int i = 4; i <= hantei.size(); i++) {
    if(i == hantei.size()) {
      ll tmp = 1;
      REP(k, i - 1) tmp *= 10;
      if(i % 3 == 0) ans += ((i / 3) - 1) * (N - tmp + 1);
      else ans += ((i / 3)) * (N - tmp + 1);
    } else {
      ll tmp = 1;
      REP(k, i - 1) tmp *= 10;
      if(i % 3 == 0) ans += ((i / 3) - 1) * ((tmp * 10 - 1)- tmp + 1);
      else ans += ((i / 3)) * ((tmp * 10 - 1) - tmp + 1);
    }
  }
  cout << ans << endl;
}