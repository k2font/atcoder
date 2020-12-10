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
  ll N, K; cin >> N >> K;
  vector<vector<ll>> T(N, vector<ll>(N));
  REP(i, N) {
    REP(k, N) {
      cin >> T[i][k];
    }
  }
  vector<int> vec(N - 1);
  REP(i, N - 1) vec[i] = i;
  ll ans = 0;
  do{
    ll tmp = 0;
    for(int i = 0; i < N - 1; ++i) {
      if(i == 0) {
        tmp += T[0][vec[i] + 1];
      } else {
        tmp += T[vec[i - 1] + 1][vec[i] + 1];
      }
    }
    tmp += T[vec[N - 2] + 1][0];
    if(tmp == K) ans++;
  } while(next_permutation(all(vec)));
  cout << ans << endl;
}