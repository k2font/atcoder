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

ll N, A, B; 
vector<ll> h;
bool solve(ll n) {
  ll sum = 0;
  REP(i, N) {
    if(h[i] - n * B >= 0) sum += ceil((double)(h[i] - n * B) / (double)(A - B));
  }
  if(sum <= n) return true;
  else return false;
}

int main() {
  cin >> N >> A >> B;
  h.resize(N); REP(i, N) cin >> h[i];
	// ngとokを答えの範囲外に設定するとよい
  ll ng = -1;
	ll ok = 1e9 + 1;	
	while(abs(ok - ng) > 1) {
	  ll mid = (ok + ng) / 2;
		if(solve(mid) == true) ok = mid;
		else ng = mid;
	}
  cout << ok << endl;
}