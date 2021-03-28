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

bool IsPrime(ll num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  ll n; cin >> n;
  ll tmp = 0;
  string ans = "BOWWOW";
  for(int i = 1; i <= n; ++i) {
    tmp += i;
  }
  if(IsPrime(tmp)) ans = "WANWAN";
  cout << ans << endl;
}