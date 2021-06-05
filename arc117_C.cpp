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

vector<ll> f, g;

ll ncr_mod3(ll n, ll r) {
  if (f[n] != f[r] + f[n - r]) return 0;
	if (g[n] == 1 && g[r] * g[n - r] == 1) return 1;
	if (g[n] == 1 && g[r] * g[n - r] == 2) return 2;
	if (g[n] == 1 && g[r] * g[n - r] == 4) return 1;
	if (g[n] == 2 && g[r] * g[n - r] == 1) return 2;
	if (g[n] == 2 && g[r] * g[n - r] == 2) return 1;
	if (g[n] == 2 && g[r] * g[n - r] == 4) return 2;
	return -1;
}

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  f.resize(400010); g.resize(400010);
  for(int i = 1; i <= 400000; ++i) {
    ll pos = i;
    while(pos % 3 == 0) {
      pos /= 3; f[i] += 1;
    }
    g[i] = pos % 3;
  }
  g[0] = 1;
  REP(i, 400001) {
    if(i == 0) continue;
    f[i] += f[i - 1];
  }
  REP(i, 400001) {
    if(i == 0) continue;
    g[i] = (g[i] * g[i - 1]) % 3;
  }

  ll res = 0;
  REP(i, N) {
    ll p1 = 0; ll p2 = ncr_mod3(N - 1, i);
    if(S[i] == 'B') p1 = 0;
    if(S[i] == 'W') p1 = 1;
    if(S[i] == 'R') p1 = 2;
    res += p1 * p2; res %= 3;
  }

  if(N % 2 == 0) {
    res = (3 - res) % 3;
  }

  if(res == 0) cout << "B" << endl;
  else if(res == 1) cout << "W" << endl;
  else cout << "R" << endl;
}