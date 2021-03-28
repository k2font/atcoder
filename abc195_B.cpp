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
  int A, B, W; cin >> A >> B >> W;
  W *= 1000;
  ll ans_min = 100000000; ll ans_max = 0;
  
  for(ll i = 0; i <= 100000000; ++i) {
    if(A * i <= W && W <= B * i) {
      ans_min = min(ans_min, i);
      ans_max = max(ans_max, i);
    }
  }

  if(ans_min == 100000000 || ans_max == 0) cout << "UNSATISFIABLE" << endl;
  else cout << ans_min << " " << ans_max << endl;
}