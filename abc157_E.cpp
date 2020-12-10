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

int INF = 1e9+7;
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
  int N, Q; string S; cin >> N >> S >> Q;
  // BIT使ったほうがわかりやすく簡単に書ける？
  // BITを26本持つ
  vector<BIT<int>> a(26, BIT<int>(N + 10));
  REP(i, N) a[S[i] - 'a'].add(i + 1, i + 2, 1);
  REP(i, Q) {
    int q; cin >> q;
    if(q == 1) {
      int idx; char nc; cin >> idx >> nc; --idx;
      char pc = S[idx];
      S[idx] = nc;
      a[pc - 'a'].add(idx + 1, idx + 2, -1);
      a[nc - 'a'].add(idx + 1, idx + 2, 1);
    } else {
      int l, r; cin >> l >> r;
      --l;
      int res = 0;
      REP(i, 26) {
        if(a[i].sum(l + 1, r + 1)) ++res;
      }
      cout << res << endl;
    }
  }
}