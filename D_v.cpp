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
  int N; cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];

  ll all_num = 0;
  REP(k, N) {
    if(k == 0) {
      all_num += abs(A[0]);
      all_num += abs(A[0] - A[1]);
    } else if(k == N - 1) {
      all_num += abs(A[k]);
    } else {
      all_num += abs(A[k + 1] - A[k]);
    }
  }

  ll tmp = all_num;

  REP(i, N) {
    if(i == 0) {
      all_num = all_num - abs(A[i]) - abs(A[i + 1] - A[i]) + abs(A[i + 1]);
    } else if(i == N - 1) {
      all_num = all_num + abs(A[i - 1]) - abs(A[i] - A[i - 1]) - abs(A[i]);
    } else {
      all_num = all_num - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]);
    }

    // cout << A[i] << " " << all_num << endl;
    cout << all_num << endl;
    all_num = tmp;
  }
}