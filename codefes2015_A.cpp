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

ll N, K, M, R; 
double d = 0; ll target = 0;

// index が条件を満たすかどうか
bool solve(ll index, ll key) {
  cout << (long double)(d + index) / (long double)N << endl;
  if ((long double)(d + index) / (long double)N >= key) {
		return true;
	} else {
		return false;
	}
}

ll binary_search(ll key) {
	ll ng = -1;
	ll ok = 10000000000;	

	while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if(solve(mid, key)) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
	
	return ok;
}

int main() {
  cin >> N >> K >> M >> R;
  vector<ll> S(N - 1); REP(i, N - 1) cin >> S[i];
  sort(all(S), greater<ll>());
  REP(i, K) {
    if(i != K - 1) d += S[i];
    if(i == K - 1) target = S[i];
  }
  ll ans = binary_search(R);
  if(ans > M) cout << -1 << endl;
  else if(ans > target) cout << 0 << endl;
  else cout << ans << endl;
}