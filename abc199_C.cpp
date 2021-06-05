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
  ll N; cin >> N;
  string S; cin >> S;
  int Q; cin >> Q;

  vector<ll> T(Q), A(Q), B(Q);
  REP(i, Q) {
    cin >> T[i] >> A[i] >> B[i]; A[i]--; B[i]--;
  }

  bool f = false;
  REP(i, Q) {
    if(T[i] == 1) {
      if(f == false) { // T == 2が発動していない時 or 偶数回発動した時
        swap(S[A[i]], S[B[i]]);
      } else { // T == 2が発動した時
        ll a = 0; ll b = 0;
        if(N <= A[i]) a = A[i] - N;
        else a = A[i] + N;
        if(N <= B[i]) b = B[i] - N;
        else b = B[i] + N;
        swap(S[a], S[b]);
      }
    } else if(T[i] == 2) {
      f = !f;
    }
  }

  if(f == true) cout << S.substr(N, 2 * N) << S.substr(0, N) << endl;
  else cout << S << endl;
}