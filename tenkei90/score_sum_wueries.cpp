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

int main() {
  ll N; cin >> N;
  vector<ll> C(N), P(N);
  REP(i, N) {
    cin >> C[i] >> P[i];
  }
  ll Q; cin >> Q;
  vector<ll> L(Q), R(Q);
  REP(i, Q) {
    cin >> L[i] >> R[i];
  }
  vector<ll> ruia(N + 1, 0), ruib(N + 1, 0);
  REP(i, N) {
    if(C[i] == 1) {
      ruia[i + 1] += P[i];
    } else {
      ruib[i + 1] += P[i];
    }
  }
  REP(i, N) {
    ruia[i + 1] += ruia[i];
    ruib[i + 1] += ruib[i]; 
  }
  REP(i, Q) {
    cout << (ruia[R[i]] - ruia[L[i] - 1]) << " " << (ruib[R[i]] - ruib[L[i] - 1]) << endl;
  }
}