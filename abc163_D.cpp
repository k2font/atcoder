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

int main() {
  ll N, K; cin >> N >> K;
  ll INF = pow(10, 9) + 7;

  ll min_num = 0;
  ll max_num = 0;
  ll cnt = 0;
  for(int i = 0; i < K; ++i) {
    min_num += i;
    max_num += (N - i);
  }

  cnt += max_num - min_num + 1;

  for(int i = K; i <= N; ++i) {
    min_num += i;
    max_num += (N - i);

    cnt += max_num - min_num + 1;
    cnt = cnt % INF;
  }

  cout << cnt << endl;
}