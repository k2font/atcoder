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

int M = 10;
void dfs(vector<int> &A) {
  // 終端条件(10重ループまで回したら処理を打ち切る)
  if(A.size() == 10) {
    for(int i = 0; i < 10; ++i) cout << A[i];
    cout << endl;
    return;
  }

  int prev_last = (A.empty() ? 0 : A.back()); // こうすると、ある桁より前の桁は、ある桁の数値を下回ることはない。
  for(int v = prev_last; v < M; ++v) {
    A.push_back(v);
    dfs(A);
    A.pop_back(); // これがポイント
  }
}

int main() {
  vector<int> A;
  dfs(A);
}