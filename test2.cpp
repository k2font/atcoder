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
  vector<int> a(50001000, 0);
  a[1] = 1;
  REP(i, 10000000) {
    if(a[i] == 0) continue;
    a[2 * i] = 1; a[3 * i] = 1; a[5 * i] = 1;
  }
  REP(i, 10000000) {
    a[i + 1] += a[i];
  }
  REP(i, 30) {
    cout << a[i] << endl;
  }
  while(true) {
    int m, n; cin >> m;
    if(m == 0) {
      return 0;
    }
    cin >> n;
    cout << a[n] - a[m - 1] << endl;
  }
}