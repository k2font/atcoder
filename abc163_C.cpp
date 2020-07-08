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
  int N; cin >> N;
  vector<int> A(N - 1); REP(i, N - 1) cin >> A[i];
  map<int, int> m;

  for(int i = 0; i < N ; ++i) {
    m[i + 1] = 0;
  }

  REP(i, N - 1) {
    m[A[i]]++;
  }

  for(auto i = m.begin(); i != m.end(); ++i) {
    std::cout << i->second << std::endl;
  }
}