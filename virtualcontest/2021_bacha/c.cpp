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
  int N, A, B; cin >> N >> A >> B;
  vector<string> s(N); vector<int> d(N); REP(i, N) cin >> s[i] >> d[i];
  int ans = 0;
  REP(i, N) {
    if(s[i] == "East") {
      if(d[i] > B) ans += B;
      else if(A <= d[i] && d[i] <= B) ans += d[i];
      else ans += A;
    } else if(s[i] == "West") {
      if(d[i] > B) ans -= B;
      else if(A <= d[i] && d[i] <= B) ans -= d[i];
      else ans -= A;
    }
  }
  if(ans < 0) cout << "West" << " " << -ans << endl;
  else if(ans == 0) cout << "0" << endl;
  else cout << "East" << " " << ans << endl;
}