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
  int N; cin >> N; ll k = pow(2, N);
  vector<ll> A(k); REP(i, k) cin >> A[i];
  vector<pair<ll, ll>> p(k);
  REP(i, k) {
    p[i] = make_pair(A[i], i + 1);
  }
  vector<pair<ll, ll>> q; q = p;
  vector<pair<ll, ll>> r;
  if(N == 1) {
    if(A[0] > A[1]) {
      cout << 2 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  }
  while(true) {
    for(int i = 0; i < k; i += 2) {
      if(q[i].first > q[i + 1].first) {
        r.push_back(q[i]);
      } else {
        r.push_back(q[i + 1]);
      }
    }
    if(r.size() == 2) {
      if(r[0].first > r[1].first) {
        cout << r[1].second << endl;
        break;
      } else {
        cout << r[0].second << endl;
        break;
      }
    }
    q = r;
    r.clear();
    k = q.size();
  }
}
