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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

ll sum(ll A, ll B) {
  ll child = 1; ll moth = 1;
  int a = A; int b = B;
  for(int i = A + B; i >= 1; --i) {
    child *= i;
    if(a > 0) {
      moth *= a; a--;
    } else if(b > 0) {
      moth *= b; b--;
    }

    ll t = gcd(child, moth);
    if(child % t == 0 && moth % t == 0) {
      child /= t; moth /= t;
    }
  }
  return child;
}

int main() {
  ll A, B; cin >> A >> B;
  ll K; cin >> K;

  // 愚直解は無理
  // 前から順番に決定していきたいよね
  // A + B個の文字列の総数は？

  // まずは総数を計算する
  ll s = sum(A, B);

  // childに総数が入っている

  // 末尾からKまでどう文字列を操作する？
  string ans = "";
  ll a = A - 1; ll b = B;
  while(a >= 0 && b >= 0) {
    ll tmp = sum(a, b);
    if(tmp < K) {
      ans.push_back('b');
      b--; K -= tmp;
    }
    else if(tmp >= K) {
      ans.push_back('a');
      a--;
    }
  }

  // cout << a << " " << b << endl;

  REP(i, a) ans.push_back('a');
  REP(i, b) ans.push_back('b');
  cout << ans << endl;
}