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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  string tmp = ""; string res = "";
  REP(p, k) {
    res = "";
    REP(i, 2 * n) {
      tmp += s[i % n];
    }
    REP(i, 2 * n) {
      if(i % 2 == 1) continue;
      if((tmp[i + 1] == 'R' && tmp[i] == 'P') || (tmp[i + 1] == 'P' && tmp[i] == 'R')) {
        res += 'P';
      } else if((tmp[i + 1] == 'S' && tmp[i] == 'P') || (tmp[i + 1] == 'P' && tmp[i] == 'S')) {
        res += 'S';
      } else if((tmp[i + 1] == 'R' && tmp[i] == 'S') || (tmp[i + 1] == 'S' && tmp[i] == 'R')) {
        res += 'R';
      } else {
        res += tmp[i];
      }
    }
    s = res;
    tmp = "";
  }
  cout << res[0] << endl;
}