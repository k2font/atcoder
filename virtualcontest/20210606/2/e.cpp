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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

const ll INF = INT_MAX;

struct SegmentTree {
  private: 
    int n;
    vector<int> node; // セグメントツリー用配列

  public:
    // 元配列 v をセグメントツリーで表現する
    SegmentTree(vector<int> v) { // vは元となる配列を表す
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
      for(int i = n - 2; i >= 0; --i) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, int val) {
      // セグメントツリーの最下段のノードにアクセスする
      x += (n - 1);
      // 最下段のノードを更新したら、あとは親に上って更新していく
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = max(node[2 * x + 1], node[2 * x + 2]);
      }
    }

		int getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
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
      int vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
      int vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
      return max(vl, vr);
    }
};

ll N, K;
ll solve(ll n, ll k) {
  const ll MAX = 510000;
  SegmentTree seg(vector<int>(5000000, 0));
  REP(i, N) {
    ll a; cin >> a;
    ll left = max(0ll, a - K);
    ll right = min(MAX, a + K + 1);
    ll val = seg.getmax(left, right);
    seg.update(a, val + 1);
  }
  return seg.getmax(0, MAX);
}

int main() {
  cin >> N >> K;
  cout << solve(N, K) << endl;
}