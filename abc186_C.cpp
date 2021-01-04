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
  int N; cin >> N;
  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    stringstream ss;
    ss << oct << i;
    string o = ss.str();
    // 8進数の判定
    bool f = false;
    REP(k, o.size()) {
      if(o[k] == '7') {
        f = true;
        break;
      }
    }
    if(f == true) continue;
    // 10進数の判定
    f = false;
    string p = to_string(i);
    REP(k, p.size()) {
      if(p[k] == '7') {
        f = true;
        break;
      }
    }
    if(f == true) continue;
    ans++;
  }
  cout << ans << endl;
}
