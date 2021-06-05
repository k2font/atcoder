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
  string S; cin >> S;
  deque<char> T; bool f = false;
  REP(i, S.size()) {
    if(S[i] == 'R') {
      f = !f; continue;
    }
    if(f == false) {
      T.push_back(S[i]);
      if(T.size() >= 2 && T[T.size() - 1] == T[T.size() - 2]) {
        T.pop_back(); T.pop_back();
      }
    } else {
      T.push_front(S[i]);
      if(T.size() >= 2 && T[0] == T[1]) {
        T.pop_front(); T.pop_front();
      }
    }
  }
  if(f == false) {
    REP(i, T.size()) {
      cout << T[i];
    }
    cout << endl;
  } else {
    for(int i = T.size() - 1; i >= 0; --i) {
      cout << T[i];
    }
    cout << endl;
  }
}