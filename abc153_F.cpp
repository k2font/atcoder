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
  ll N, D, A; cin >> N >> D >> A;
  vector<ll> X(N), H(N); REP(i, N) cin >> X[i] >> H[i];
  vector<int> ids(N);
  for (int i = 0; i < N; ++i) ids[i] = i;
  sort(ids.begin(), ids.end(), [&](int i, int j) {
    return X[i] < X[j];
  });
  vector<long long> nX(N), nH(N);
  for (int i = 0; i < N; ++i) nX[i] = X[ids[i]], nH[i] = H[ids[i]];
  X = nX, H = nH;

  BIT<ll> bit(N + 10);
  for(int i = 0; i < N; ++i) {
    bit.add(i + 1, i + 2, H[i]); // 区間を初期化
  }
  ll ans = 0;
  for(int i = 0; i < N; ++i) {
    ll cur = bit.sum(i + 1, i + 2); // その地点での体力
    if(cur <= 0) continue; // すでに0なら次のindexへ行く

    ll need = (cur + A - 1) / A; // モンスターiを倒すのに必要な必要な攻撃回数

    // X[i]を左端としたときに爆発が届く範囲を求める
    ll right = X[i] + D * 2;
    int id = upper_bound(X.begin(), X.end(), right) - X.begin();

    // 爆発させる
    bit.add(i + 1, id + 1, -need * A);
    ans += need;
  }
  cout << ans << endl;
}