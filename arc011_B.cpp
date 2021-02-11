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
  vector<string> w(N); REP(i, N) cin >> w[i];
  map<char, char> m;
  m['b'] = '1'; m['c'] = '1'; m['t'] = '3'; m['j'] = '3'; m['l'] = '5'; m['v'] = '5'; m['p'] = '7'; m['m'] = '7'; m['n'] = '9'; m['g'] = '9';
  m['d'] = '2'; m['w'] = '2'; m['f'] = '4'; m['q'] = '4'; m['s'] = '6'; m['x'] = '6'; m['h'] = '8'; m['k'] = '8'; m['z'] = '0'; m['r'] = '0';
  vector<string> ans;
  REP(i, N) {
    string tmp = "";
    REP(k, w[i].size()) {
      if(isupper(w[i][k])) w[i][k] = tolower(w[i][k]);
      if(w[i][k] == 'a' || w[i][k] == 'e' || w[i][k] == 'i' || w[i][k] == 'o' || w[i][k] == 'u' || w[i][k] == 'y' || w[i][k] == '.' || w[i][k] == ',') {
        continue;
      } else {
        tmp += m[w[i][k]];
      }
    }
    if(tmp != "") ans.push_back(tmp);
  }
  REP(i, ans.size()) {
    cout << ans[i];
    if(i != ans.size() - 1) cout << " ";
  }
  cout << endl;
} 