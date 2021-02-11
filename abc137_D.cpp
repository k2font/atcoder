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
  int N, M; cin >> N >> M;
  vector<int> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  vector<vector<ll>> tmp(M + 1);
  REP(i, N) {
    if(A[i] > M) continue;
    tmp[A[i]].push_back(B[i]);
  }
  priority_queue<ll> q;
  ll ans = 0;
  for(int i = M - 1; i >= 0; --i) {
    for(auto B : tmp[M - i]) q.push(B);
    if(q.empty()) continue;
    ans += q.top();
    q.pop(); // キューの最大要素を削除する
  }
  cout << ans << endl;
}