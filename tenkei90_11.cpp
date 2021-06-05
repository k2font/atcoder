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

ll N; 
vector<ll> d, c, s;
ll rec(ll n) {
  ll current = 0;
  ll money = 0;
  REP(i, N) { // N個すべての締め切りについて間に合うかどうかを判定する
    if((n & (1 << i)) == 0) continue; // 選ぶ必要のない仕事は考えずcontinueする
    if(current + c[i] > d[i]) {
      return -1;
    } else {
      current += c[i];
      money += s[i];
    }
  }
  return money;
}

int main() {
  cin >> N;
  vector<tuple<ll, ll, ll>> t;
  REP(i, N) {
    ll D, C, S; cin >> D >> C >> S;
    t.push_back(make_tuple(D, C, S));
  }
  sort(all(t));
  d.resize(N); c.resize(N); s.resize(N);
  REP(i, N) {
    d[i] = get<0>(t[i]);
    c[i] = get<1>(t[i]);
    s[i] = get<2>(t[i]);
  }
  ll ans = 0;
  for(int i = 0; i < (1 << N); ++i) {
    ll point = rec(i);
    ans = max(ans, point);
  }
  cout << ans << endl;
}