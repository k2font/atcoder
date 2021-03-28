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
  string S; cin >> S;
  // 全探索する
  int ans = 1000000;
  REP(i, S.size()) {
    string tmp = S; int res = 0;
    while(true) {
      bool f = false;
      REP(i, tmp.size() - 1) {
        if(tmp[i] != tmp[i + 1]) {
          break;
        } else {
          if(i == tmp.size() - 2) {
            f = true;
          }
        }
      }
      if(f == true) break;
      string cnt = "";
      REP(k, tmp.size() - 1) {
        if(S[i] == tmp[k] || S[i] == tmp[k + 1]) {
          cnt += S[i];
        } else {
          cnt += tmp[k];
        }
      }
      tmp = cnt; cnt = "";
      if(tmp.size() == 0) break;
      res++;
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}