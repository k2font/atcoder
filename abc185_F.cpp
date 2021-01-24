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

// 1-indexed
template <typename T=int>
struct BIT {
    const int n;
    vector<T> v;
 
    BIT(int n): n(n), v(n+1,0) {}
 
    void add(int i, int x) {
        ++i;
        while (i <= n) {
            v[i] ^= x;
            i += i & -i;
        }
    }
    T sum(int i) {
        ++i;
        T ret = 0;
        while (i > 0) {
            ret ^= v[i];
            i -= i & -i;
        }
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) ^ sum(l-1);
    }
};

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  BIT<int> bit(N + 10);
  REP(i, N) bit.add(i + 1, A[i]);
  REP(i, Q) {
    ll T, X, Y; cin >> T >> X >> Y;
    if(T == 1) {
      bit.add(X, Y);
    } else if(T == 2) {
      cout << bit.sum(X, Y) << endl;
    }
  }
}
