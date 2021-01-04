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
const int INF = 0;
struct SegmentTree {
  private: 
    int n;
    vector<ll> node; // セグメントツリー用配列

  public:
    // 元配列 v をセグメントツリーで表現する
    SegmentTree(vector<ll> v) { // vは元となる配列を表す
      // 最下段のノード数は元配列のサイズ以上になる最小の2冪 -> これをnとおく。
      // たとえばvのサイズが6なら、上記を満たす最小の2冪は8となる。
      // セグメントツリー全体で必要なノード数は 2n-1 個ある。
      int sz = v.size();
      n = 1;
      while(n < sz) n *= 2;
      node.resize(2 * n - 1, INF);

      // 最下段に値を入れたあとに、下の段から順番に値を入れる。これは値の更新。
      // 値を入れるには、自分の子の2値を参照すればいい
      for(int i = 0; i < sz; ++i) node[i + n - 1] = v[i]; // 最下段に値を入れる
      for(int i = n - 2; i >= 0; --i) node[i] = node[2 * i + 1] ^ node[2 * i + 2];
    }

    void show() {
      int i, j, h = ceil(log2(n));
      for(i=0 ; i<=h ; ++i)
        {
          for(j=0 ; j<pow(2, i) ; ++j)
            cout<<node[int(pow(2, i)-1 + j)]<<' ';
          cout<<endl;
        }
    }

    void update(ll x, ll val) {
      // セグメントツリーの最下段のノードにアクセスする
      x += (n - 1);
      // 最下段のノードを更新したら、あとは親に上って更新していく
      node[x] ^= val; // 加算していく必要があるので、末端のノードの値も加算する
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = (node[2 * x + 1] ^ node[2 * x + 2]);
      }
    }

    // 要求区間[a, b)中の要素の合計を答える
    // k = 自分がいるノードのインデックス
    // 対象区間は[l. r)にあたる
    ll getsum(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
      // 最初に呼び出されたときの対象区間は[0, n)
      if(r < 0) r = n;

      // 要求区間と対象区間が交わらない -> 適当に返す
      // [l, r)である点に注意。つまり、(l <=)r <= [a, b)か[a, b) <= l(<= r)のどちらか、を指している
      if(r <= a || b <= l) return 0;

      // 要求区間が対象区間を完全に被覆 -> 対象区間の答えを計算に使う
      if(a <= l && r <= b) return node[k];

      // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
      // 左側の子をvl、右側の子をvrとしている
      // 新しい対象区間は、現在の対象区間を半分に割ったもの
      ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
      ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
      return (vl ^ vr);
    }
};

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  SegmentTree seg(A);
  REP(i, Q) {
    ll c, x, y; cin >> c >> x >> y;
    if(c == 1) {
      --x;
      seg.update(x, y); // 半開区間ではなく、普通の区間で考える
    } else if(c == 2) {
      --x;
      cout << seg.getsum(x, y) << endl;
    }
    // seg.show();
  }
}
