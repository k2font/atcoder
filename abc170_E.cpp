#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N), B(N);
  REP(i, N) {
    cin >> A[i] >> B[i]; --B[i];
  }
  // 幼稚園ごとのレートの集合 st
  // 配列のmultiset
  const int M = 200010;
  vector<multiset<int>> st(M);
  // 最強園児最強園児の集合 maxes
  multiset<int> maxes; // 逐次pushしていく

  // 前処理
  REP(i, N) {
    st[B[i]].insert(A[i]);
  }

  REP(i, M) {
    if(st[i].size() > 0) {
      maxes.insert(*st[i].rbegin()); // それぞれの幼稚園の最強園児を取得する(rbeginは最大値を取る)
    }
  }

  // maxesからst[i]の最大値を探して削除するラムダ式
  auto del_max = [&](int i) {
    if(st[i].size() > 0) maxes.erase(maxes.find(*st[i].rbegin())); // st[i]の最大値を取得し、maxesからその値を検索する
  };

  // maxesにst[i]の最大値を挿入するラムダ式
  auto add_max = [&](int i) {
    if(st[i].size() > 0) maxes.insert(*st[i].rbegin());
  };

  // st[i]から値aを削除してmaxesを更新するラムダ式
  auto del = [&](int i, int a) {
    del_max(i); // 現在のmaxesからst[i]の最大値だけを削除する
    st[i].erase(st[i].find(a));
    add_max(i); // maxesに新しい値を突っ込む
  };

  // st[i]に値aを追加してmaxesを更新するラムダ式
  auto add = [&](int i, int a) {
    del_max(i);
    st[i].insert(a);
    add_max(i);
  };

  REP(i, Q) {
    int C, D;
    cin >> C >> D;
    C--; D--;
    int bef = B[C]; // その時所属している幼稚園のインデックス
    B[C] = D; // 移動先幼稚園のインデックスをB[i]に入れる(これで転園が完了する!)

    del(bef, A[C]);
    add(D, A[C]);

    int ans = *maxes.begin();
    cout << ans << endl;
  }
}