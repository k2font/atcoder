#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
  double N, K; cin >> N >> K;
  vector<int> A(N); REP(i, N) cin >> A[i];

  double a = (N - 1) / (K - 1);
  cout << ceil(a) << endl;
}
