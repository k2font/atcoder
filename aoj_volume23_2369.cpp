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
  string s; cin >> s;
  string p = "";
  REP(i, s.size()) {
    p += s[i];
    if(p.size() >= 3) {
      if(p.substr(p.size() - 3, 3) == "mew") {
        p.erase(p.size() - 3);
        if(p == "" && i != s.size() - 1) {
          cout << "Rabbit" << endl;
          return 0;
        }
      }
    }
  }
  if(p.size() == 0) cout << "Cat" << endl;
  else cout << "Rabbit" << endl;
}