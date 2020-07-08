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

int main() {
  int N; cin >> N;
  vector<ll> H(N), S(N); REP(i, N) cin >> H[i] >> S[i];
  // この探索部分を二分探索する
  ll ng = -1;
  ll ok = pow(10, 18);
  while(abs(ng - ok) > 1) {
    ll mid = (ng + ok) / 2;
    vector<ll> res;
    bool flag = true;
    for(int i = 0; i < N; ++i) {
      res.push_back((mid - H[i]) / S[i]);
      if(mid < H[i]) flag = false;
    }
    sort(all(res));
    for(int i = 0; i < N; ++i) {
      if(res[i] < i) flag = false;
    }
    if(flag == true) ok = mid;
    else ng = mid;
  }

  vector<pair<ll, ll>> res;
  for(int i = 0; i < N; ++i) {
    ll a = (ok - H[i]) / S[i];
    res.push_back(make_pair(a, i));
  }
  sort(all(res));
  ll p = 0;
  for(int i = 0; i < N; ++i) {
    ll t = res[i].second;
    ll tmp = H[t] + S[t] * i;
    if(p < tmp) p = tmp;
  }
  cout << p << endl;
}
