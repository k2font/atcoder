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

// 区間加算にも対応した BIT
template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main() {
  int N; cin >> N;
  ll D, A; cin >> D >> A;
  vector<ll> X(N), H(N); REP(i, N) cin >> X[i] >> H[i];
  BIT<ll> bit(N + 10);
  ll ans = 0;
  
  // モンスターをXが小さい順に並び替える
  vector<pair<pair<ll, ll>, ll>> p(N);
  REP(i, N) p[i] = make_pair(make_pair(X[i], H[i]), i);
  sort(all(p));
  vector<ll> nX(N), nH(N);

  // 並び替えた結果を反映した、新しいXとHを作成する
  REP(i, N) {
    nX[i] = X[p[i].second]; nH[i] = H[p[i].second];
  }
  X = nX; H = nH;

  REP(i, N) bit.add(i + 1, i + 2, H[i]); // BITの初期化
  REP(i, N) {
    // その地点X[i]の体力を求める
    ll nokori = bit.sum(i + 1, i + 2);

    // 地点X[i]の体力が0以下であれば、次の地点を見に行く
    if(nokori <= 0) continue;

    // モンスターiを倒すのに必要な爆弾を置く回数を求める
    ll num = (nokori + A - 1) / A;

    // X[i]を左端とした爆弾が届く範囲を求める
    ll tmp = X[i] + 2 * D;
    int id = upper_bound(all(X), tmp) - X.begin();

    // 爆発させる
    bit.add(i + 1, id + 1, -num * A);
    ans += num;
  }
  cout << ans << endl;
}