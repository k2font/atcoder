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
char int_to_char(int val) {
  return '0' + val;
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

int main() {
  vector<int> b(10); REP(i, 10) cin >> b[i];
  int N; cin >> N;
  vector<string> a(N); REP(i, N) cin >> a[i];
  vector<int> sor(N);

  map<int, int> m, m2;
  REP(i, 10) m[i] = b[i]; // 対照表を作る
  REP(i, 10) m2[b[i]] = i; // 対照表を作る
  REP(i, N) {
    REP(k, a[i].size()) {
      // cout << m[char_to_int(a[i][k])] << endl;
      a[i][k] = int_to_char(m2[char_to_int(a[i][k])]);
    }
  }

  REP(i, N) {
    sor[i] = stoi(a[i]);
  }
  sort(all(sor));
  REP(i, N) {
    a[i] = to_string(sor[i]);
  }

  REP(i, N) {
    REP(k, a[i].size()) {
      a[i][k] = int_to_char(m[char_to_int(a[i][k])]);
    }
    cout << a[i] << endl;
  }
}