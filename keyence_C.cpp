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

int main() {
  ll N, K, S; cin >> N >> K >> S;
  ll cnt = 0;
  vector<ll> A;
  while(true) {
    if(cnt == K) break;
    A.push_back(S);
    cnt++;
  }
  for(int i = 0; i < N - K; ++i) {
    if(S == 1000000000) A.push_back(S - 1);
    else A.push_back(S + 1);
  }
  REP(i, A.size()) {
    cout << A[i] << " ";
  }
  cout << endl;
}