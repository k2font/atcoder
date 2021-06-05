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

ll N, K; 
vector<ll> A;

// 答えがマイナスになる組み合わせの個数を求める
ll getMinus(ll n) {
  vector<ll> mi, pi;
  REP(i, N) {
    if(A[i] < 0) mi.push_back(A[i]);
    if(A[i] > 0) pi.push_back(A[i]);
  }

  ll j = 0; ll res = 0;
  for(auto m : mi) {
    while(j < pi.size() && n < m * pi[j]) ++j;
    res += (pi.size() - j);
  }
  return res;
}

//答えが0になる組み合わせの個数を求める
ll getZeros() {
  ll zero = 0;
  REP(i, N) {
    if(A[i] == 0) ++zero;
  }
  return (ll)(zero * (N - zero)) + (ll)(zero * (zero - 1) / 2);
}

// 答えがプラスになる組み合わせの個数を求める
ll getPlus(ll n) {
  vector<ll> mi, pi;
  REP(i, N) {
    if(A[i] > 0) pi.push_back(A[i]);
  }

  for(int i = N - 1; i >= 0; --i) {
    if(A[i] < 0) mi.push_back(A[i]);
  }

  ll res = 0;
  ll nn = mi.size();
  ll j = nn - 1;
  REP(i, nn) {
    while(i < j && n < mi[i] * mi[j]) --j;
    res += max(0ll, j - i);
  }

  nn = pi.size();
  j = nn - 1;
  REP(i, nn) {
    while(i < j && n < pi[i] * pi[j]) --j;
    res += max(0ll, j - i);
  }

  return res;
}

// 場合分けして計算結果を返却する
ll solve(ll n) {
  ll res = getMinus(min(n, -(ll)1LL)); // 小さい順番に数え上げる
  if(0 <= n) res += getZeros();
  if(0 < n) res += getPlus(n);
  return res; // n以下の組み合わせの個数
}

int main() {
  cin >> N >> K;
  A.resize(N); REP(i, N) cin >> A[i];
  sort(all(A));
  ll ans = 0;
  // 二分探索する
  const ll infl = 1LL << 60;
  ll ng = -infl;
	ll ok = infl;	
	while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if(K <= solve(mid)) ok = mid;
		else ng = mid;
	}
  ans = ok;
  cout << ans << endl;
}