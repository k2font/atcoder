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
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

const ll INF = 8888888888;

int main() {
  int H, W, K; cin >> H >> W >> K;
  vector<string> S(H); REP(i, H) cin >> S[i];
  ll ans = INF;
  for(int bit = 0; bit < (1 << (H - 1)); ++bit) {
    vector<int> id(H);
    int g = 0;
    for(int i = 0; i < H; ++i) {
      id[i] = g; // グループ分け
      if(bit >> i & 1) g++; // 線引ラインが来たらグループ番号をインクリメントする
    }
    g++; // グループ数を表すので、もう一回インクリメントしておく

    vector<vector<ll>> c(g, vector<ll>(W, 0));
    REP(i, H) {
      REP(j, W) {
        c[id[i]][j] += char_to_int(S[i][j]); // 1であるホワイトチョコレートを配列cに足し込んでいく。これは天才の書き方!
        // 僕ならif文書いてS[i][j] == '1'ならインクリメント... とかやってしまうけど冗長だな。
      }
    }

    ll num = g - 1; // 答え(横に切った回数を入れておく)
    vector<ll> now(g);
    auto add = [&](ll j) { // [&]とすると、スコープの外の変数を参照できるようになる
      REP(i, g) now[i] += c[i][j];
      REP(i, g) {
        if(now[i] > K) return false; // 加算した値がKを超えてしまったらfalse
      }
      return true; // Kを超えなかったらまだOK
    };
    REP(j, W) {
      if(!add(j)) {
        num++; // 縦に切った回数をインクリメント
        now = vector<ll>(g); // 真っ白な配列で初期化する
        if(!add(j)) {
          num = INF;
          break;
        }
      }
    }
    ans = min(ans, num);
  }
  cout << ans << endl;
}
