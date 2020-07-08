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

// 最大公約数
ll gcd(ll a, ll b) {
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }

  sort(begin(ret), end(ret));
  return (ret);
}

bool IsPrime(ll num) {
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2)
  {
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
  ll A, B; cin >> A >> B;
  ll gc = gcd(A, B);
  auto d = divisor(gc);
  ll ans = 0;
  for(int i = 0; i < d.size(); ++i) {
    if(IsPrime(d[i])) ans++;

  }
  cout << ans + 1 << endl;
}