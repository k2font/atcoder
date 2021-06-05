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
  vector<ll> lx(N), ly(N), rx(N), ry(N);
  REP(i, N) {
    cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
  }
  vector<vector<ll>> rect(1100, vector<ll>(1100, 0));
  REP(i, N) {
    rect[lx[i]][ly[i]]++;
    rect[rx[i]][ry[i]]++;
    rect[lx[i]][ry[i]]--;
    rect[rx[i]][ly[i]]--;
  }
  REP(i, 1010) {
    REP(k, 1010) {
      rect[i][k + 1] += rect[i][k];
    }
  }
  REP(k, 1010) {
    REP(i, 1010) {
      rect[i + 1][k] += rect[i][k];
    }
  }

  map<ll, ll> m;
  REP(i, 1010) {
    REP(k, 1010) {
      m[rect[i][k]]++;
    }
  }
  for(int i = 1; i <= N; ++i) {
    cout << m[i] << endl;
  }
}