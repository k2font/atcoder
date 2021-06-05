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

ll N, K;
vector<ll> A, F;
bool solve(ll n) {
  ll sum = 0; // 削減コストの合計
  REP(i, N) {
    ll ma = n / F[i];
    if(ma < A[i]) sum += A[i] - ma;
    if(sum > K) return false;
  }
  return true;
}

int main() {
  cin >> N >> K;
  A.resize(N); REP(i, N) cin >> A[i];
  F.resize(N); REP(i, N) cin >> F[i];
  sort(all(A));
  sort(all(F), greater<ll>());
  ll ans = 0;
  // チーム全体の成績で二分探索
  ll ng = -1;
	ll ok = 2e18 + 1;	
	while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if(solve(mid)) ok = mid; // 条件を満たす = trueならば
    else ng = mid; // 条件を満たさない = falseならば
	}
  ans = ok;
  cout << ans << endl;
}