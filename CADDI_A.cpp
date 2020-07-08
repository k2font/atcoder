#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  string N; cin >> N;

  int cnt = 0;
  if(N[0] == '2') {
    cnt++;
  }

  if(N[1] == '2') {
    cnt++;
  }

  if(N[2] == '2') {
    cnt++;
  }

  if(N[3] == '2') {
    cnt++;
  }

  cout << cnt << endl;
}