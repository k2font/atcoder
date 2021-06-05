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
  string S1, S2, S3; cin >> S1 >> S2 >> S3;

  // Sに登場する文字種を数える
  // 10文字以上だとすべてUNSOLVABLEとなる
  map<char, int> m;
  REP(i, S1.size()) m[S1[i]]++;
  REP(i, S2.size()) m[S2[i]]++;
  REP(i, S3.size()) m[S3[i]]++;

  // つまり文字種が10文字以下の場合を考えればよい。
  // すると10^10通りを考えることと同じになり、多分5秒で収まる

  if(m.size() > 10) {
    // 必ず解けない
    cout << "UNSOLVABLE" << endl;
  } else {
    // それ以外の場合を全探索する

    // 数字のパターンを作るパート
    // next_permutation?
    bool flag = false;
    vector<int> v={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		sort(all(v)); // 必ずソートすること
    do{
      map<char, int> p;
      // mapの初期化
      for(auto x : m) {
        p[x.first] = 0;
      }
      // 数字テーブルの作成
      int k = 0;
      for(auto x : p) {
        p[x.first] = v[k];
        k++;
      }

      // 計算して判定するパート
      ll N1, N2, N3; N1 = 0; N2 = 0; N3 = 0;
      REP(n, S1.size()) {
        N1 += p[S1[n]];
        if(n != S1.size() - 1) N1 *= 10;
      }
      REP(n, S2.size()) {
        N2 += p[S2[n]];
        if(n != S2.size() - 1) N2 *= 10;
      }
      REP(n, S3.size()) {
        N3 += p[S3[n]];
        if(n != S3.size() - 1) N3 *= 10;
      }
      if(N1 + N2 == N3 && (N1 != 0 && N2 != 0 && N3 != 0) && (p[S1[0]] != 0 && p[S2[0]] != 0 && p[S3[0]] != 0)) {
        cout << N1 << endl;
        cout << N2 << endl;
        cout << N3 << endl;
        flag = true;
        break;
      }
    } while(next_permutation(all(v)));

    if(flag == false) cout << "UNSOLVABLE" << endl;
  }
}