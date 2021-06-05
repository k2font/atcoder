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

// 最大公約数(ゼロ除算対策済みバージョン)
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

// 最小公倍数
int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  ll A, B, C; cin >> A >> B >> C;
  ll a = gcd(A, B);
  ll b = gcd(a, C);
  cout << A / b + B / b + C / b - 3<< endl;
}