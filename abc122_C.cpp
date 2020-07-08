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
  int Q; cin >> Q;
  string S; cin >> S;

  vector<int> l(Q), r(Q);
  REP(i, Q) {
    cin >> l[i] >> r[i];
  }

  vector<int> ans(S.size());
  REP(i, S.size()) {
    ans[i] = 0;
  }

  REP(i, S.size()) {
    if(i == 0) continue;
    if(S[i - 1] == 'A' && S[i] == 'C') ans[i]++;
    ans[i] += ans[i - 1];
  }

  REP(i, Q) {
    cout << ans[r[i] - 1] - ans[l[i] - 1] << endl;
  }
}