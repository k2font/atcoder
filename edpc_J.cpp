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

int N; 

double dp[500][500][500];
bool flag[500][500][500];

double f(ll c1, ll c2, ll c3) {
  if(flag[c1][c2][c3] == true) return dp[c1][c2][c3];
  if(c1 + c2 + c3 == 0) return 0;
  flag[c1][c2][c3] = true;
  double res = 0.0;

  double mot = (double)(N - c1 - c2 - c3) / (double)N;
  res = (double)1 / ((double)1 - mot); // 1 - (0個の皿が選ばれる確率)
  // cout << c1 << " " << c2 << " " << c3 << " " << mot << " " << res << endl;
  if(c1 > 0) res += f(c1 - 1, c2, c3) * c1 / N / (1 - mot); // 1個の皿が選ばれる確率
  if(c2 > 0) res += f(c1 + 1, c2 - 1, c3) * c2 / N / (1 - mot); // 2個の皿が選ばれる確率
  if(c3 > 0) res += f(c1, c2 + 1, c3 - 1) * c3 / N / (1 - mot); // 3個の皿が選ばれる確率

  return dp[c1][c2][c3] = res;
}

int main() {
  cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];

  REP(i, N) {
    REP(k, N) {
      REP(m, N) {
        dp[i][k][m] = false;
      }
    }
  }

  map<ll, ll> c;
  REP(i, N) c[a[i]]++;
  double ans = f(c[1], c[2], c[3]);
  cout << fixed << setprecision(10) << ans << endl;
}