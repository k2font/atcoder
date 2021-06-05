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

int N, K;
vector<double> w, p; 
bool solve(double pp) {
  vector<double> v;
  REP(i, N) v.push_back((p[i] - pp) * w[i]);
  sort(all(v), greater<double>());
  double m = 0.0;
  REP(i, K) m += v[i];
  // cout << m << endl;
  return m >= 0.0;
}

int main() {
  cin >> N >> K;
  w.resize(N); p.resize(N); REP(i, N) cin >> w[i] >> p[i];
  // ngとokを答えの範囲外に設定するとよい
  double ng = -1;
	double ok = 100;
	while(abs(ok - ng) > 0.00000000001) {
		double mid = (ok + ng) / 2;
		if(solve(mid)) ng = mid;
		else ok = mid;
	}
  cout << fixed << setprecision(15) << ok << endl;
}