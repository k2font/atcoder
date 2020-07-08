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
  double N, M; cin >> N >> M;

  double cnt = (1900 * M + 100 * (N - M)) * pow(2, M);

  cout << cnt << endl;
}