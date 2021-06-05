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

bool IsPrime(ll num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  int T; cin >> T;
  REP(i, T) {
    ll Z; cin >> Z;
    ll ans = 0; int cnt = 0; vector<ll> p1(2), p2(2), p3(2);
    ll s = sqrt(Z);
    for(ll k = s; k >= 2; --k) {
      if(IsPrime(k) == true) {
        p1[cnt] = k; cnt++;
      }
      if(cnt == 2) break; 
    }

    for(ll k = s; k >= 2; --k) {
      if(IsPrime(k) == true) {
        p2[0] = k; break;
      }
    }
    for(ll k = s + 1; k <= 10000000000; ++k) {
      if(IsPrime(k) == true) {
        p2[1] = k; break;
      }
    }

    cnt = 0;
    for(ll k = s; k <= 10000000000; ++k) {
      if(IsPrime(k) == true) {
        p3[cnt] = k; cnt++;
      }
      if(cnt == 2) break; 
    }
    
    if(p1[0] * p1[1] <= Z) ans = max(ans, p1[0] * p1[1]);
    if(p2[0] * p2[1] <= Z) ans = max(ans, p2[0] * p2[1]);
    if(p3[0] * p3[1] <= Z) ans = max(ans, p3[0] * p3[1]);
    cout << "Case #" << i + 1 << ": ";
    cout << ans << endl;
  }
}