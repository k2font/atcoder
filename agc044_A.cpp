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

unordered_map<ll, ll> memo;
ll N, A, B, C, D; 
ll dfs(ll n) {
  if(n == 0) return 0; // もし数字が0ならこたえは0
  if(n == 1) return D; // もし数字が1なら答えはd(-1すれば0にできるためコインをd枚支払う)
  if(memo.count(n)) return memo[n]; // すでにその数字で試行していたらメモしていた値をreturnする

  ll res = LLONG_MAX / D > n ? n * D : LLONG_MAX;
  ll rate, pay;

  rate = 2; pay = A;
  // 引いてから割る場合
  res = min(res, pay + n % rate * D + dfs(n / rate));
  // 足してから割る場合
  res = min(res, pay + abs(rate - n % rate) * D + dfs((n + rate - 1) / rate));

  rate = 3; pay = B;
  // 引いてから割る場合
  res = min(res, pay + n % rate * D + dfs(n / rate));
  // 足してから割る場合
  res = min(res, pay + abs(rate - n % rate) * D + dfs((n + rate - 1) / rate));

  rate = 5; pay = C;
  // 引いてから割る場合
  res = min(res, pay + n % rate * D + dfs(n / rate));
  // 足してから割る場合
  res = min(res, pay + abs(rate - n % rate) * D + dfs((n + rate - 1) / rate));

  return memo[n] = res;
}

int main() {
  int T; cin >> T;
  REP(i, T) {
    cin >> N >> A >> B >> C >> D;
    memo.clear();
    cout << dfs(N) << endl;
  }
}