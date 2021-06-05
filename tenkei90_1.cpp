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

ll N, L; 
ll K; 
vector<ll> A;
// 引数が条件を満たすかどうか
bool solve(ll target) {
  ll res = 0; ll tmp = 0;
  REP(i, N) {
    if(A[i] - tmp >= target && L - A[i] >= target) {
      res++; tmp = A[i];
    }
  }
  if(res >= K) return true;
  else return false;
}

int main() {
  cin >> N >> L;
  cin >> K;
  A.resize(N); REP(i, N) cin >> A[i];
  ll ans = -1;
  ll ng = -1;
	ll ok = L + 1;	
	while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if(solve(mid) == false) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
  ans = ng;
  cout << ans << endl;
}