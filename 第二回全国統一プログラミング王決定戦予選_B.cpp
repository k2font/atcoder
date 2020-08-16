#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
struct edge {
  ll to, cost;
};

ll modpow(ll a, ll n, ll mod) {
  if(n == 0) {
    return 1;
  } else if(n % 2 == 1) {
    return modpow(a, n - 1, mod) * a % mod;
  } else {
    ll t = modpow(a, n / 2, mod);
    return t * t % mod;
  }
}

int main() {
  int N; cin >> N;
  vector<ll> D(N); REP(i, N) cin >> D[i];
  if(D[0] != 0) { // 1番目が0でなければ構築不可能
    cout << 0 << endl;
    return 0;
  }
  // それ以外の検査
  // ソートしてよい
  sort(all(D));
  vector<ll> res; ll cnt = 0;
  REP(i, N) { // 前処理
    cnt++;
    if(D[i] != D[i + 1]) {
      res.push_back(cnt);
      cnt = 0;
    }
  }
  bool flag = false;
  REP(i, N - 1) { // 連番になってなければ構築不可能。
    if(D[i + 1] - D[i] > 1) flag = true;
  }
  if(flag == true || D[1] == 0) {
    cout << 0 << endl;
    return 0;
  }

  // 判定パート
  ll ans = 1;
  const ll MOD = 998244353;
  REP(i, res.size() - 1) {
    ans *= modpow(res[i], res[i + 1], MOD);
    ans %= MOD;
  }
  cout << ans << endl;
}