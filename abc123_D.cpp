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
  ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
  vector<ll> A(X); REP(i, X) cin >> A[i]; sort(all(A), greater<ll>());
  vector<ll> B(Y); REP(i, Y) cin >> B[i]; sort(all(B), greater<ll>());
  vector<ll> C(Z); REP(i, Z) cin >> C[i]; sort(all(C), greater<ll>());
  using data = pair<ll, vector<ll>>;
  priority_queue<data> q;
  map<vector<ll>, int> f;
  q.push(make_pair(A[0] + B[0] + C[0], vector<ll>({0, 0, 0})));
  q.push(make_pair(A[1] + B[0] + C[0], vector<ll>({1, 0, 0})));
  q.push(make_pair(A[0] + B[1] + C[0], vector<ll>({0, 1, 0})));
  q.push(make_pair(A[0] + B[0] + C[1], vector<ll>({0, 0, 1})));
  f[vector<ll>({0, 0, 0})]++;
  f[vector<ll>({1, 0, 0})]++;
  f[vector<ll>({0, 1, 0})]++;
  f[vector<ll>({0, 0, 1})]++;
  REP(i, K) {
    auto x = q.top(); q.pop();
    cout << x.first << endl;
    int a = x.second[0]; int b = x.second[1]; int c = x.second[2];
    if(f[vector<ll>({a + 1, b, c})] == 0 && a + 1 < X) {
      q.push(make_pair(A[a + 1] + B[b] + C[c], vector<ll>({a + 1, b, c})));
      f[vector<ll>({a + 1, b, c})]++;
    }
    if(f[vector<ll>({a, b + 1, c})] == 0 && b + 1 < Y) {
      q.push(make_pair(A[a] + B[b + 1] + C[c], vector<ll>({a, b + 1, c})));
      f[vector<ll>({a, b + 1, c})]++;
    }
    if(f[vector<ll>({a, b, c + 1})] == 0 && c + 1 < Z) {
      q.push(make_pair(A[a] + B[b] + C[c + 1], vector<ll>({a, b, c + 1})));
      f[vector<ll>({a, b, c + 1})]++;
    }
  }
} 