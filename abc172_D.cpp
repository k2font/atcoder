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

ll divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  ll a = ret.size();
  return a;
}

bool IsPrime(int num) {
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0)
      {
          // 素数ではない
          return false;
      }
  }

  // 素数である
  return true;
}

int main() {
  int N; cin >> N;
  vector<ll> tmp(N + 1, 0); tmp[1] = 1;
  for (ll i = 1; i <= N; i++) {
    for (ll j = i; j <= N; j += i){
      tmp[j] += 1;
    }
  }
  ll ans = 0;
  for(int i = 1; i <= N; ++i) {
    ans += i * tmp[i];
    cout << i << " " << tmp[i] << endl;
  }
  cout << ans - 1 << endl;
}