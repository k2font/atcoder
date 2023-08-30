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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

// これを使っていこう
// 1-indexed
template <typename T=int>
struct BIT {
    const int n;
    vector<T> v;
 
    BIT(int n): n(n), v(n+1,0) {}
 
    void add(int i, int x) {
        ++i;
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    T sum(int i) {
        ++i;
        T ret = 0;
        while (i > 0) {
            ret += v[i];
            i -= i & -i;
        }
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

int main() {
  ll N; cin >> N;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  BIT<ll> bit(N + 100); ll ans = 0;
  REP(i, N) {
    ans += i - bit.sum(1, a[i]);
    bit.add(a[i], 1);
   
  }
  cout << ans << endl;
}