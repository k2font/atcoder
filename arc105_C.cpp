#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
  int N; cin >> N;
  ll M; cin >> M;
  vector<ll> w(N); REP(i, N) cin >> w[i];
  vector<ll> l(M), v(M); REP(i, M) cin >> l[i] >> v[i];
  sort(all(w));
  ll ans = pow(10, 18) + 7;
  ll v_min = *min_element(all(v)); // 耐荷重の最小値
  ll w_max = *max_element(all(w)); // ラクダの重さの最大値
  ll l_max = *max_element(all(l));
  ll l_max_2 = 0;
  REP(i, M) {
    if(v_min == v[i]) {
      if(l_max_2 < l[i]) l_max_2 = l[i]; // 15が複数あった場合は?
    }
  }
  // cout << v_min << " " << w_max << " " << l_max << endl;
  // 橋のパーツの耐荷重の最小値がラクダの重さの最大値を下回ったら-1を出力しbreak;
  if(v_min < w_max) {
    ans = -1;
    cout << ans << endl;
    return 0;
  }
  // 8!通りを全部試して、あり得る方法を出力する
  do {
    ll tmp = 0; ll res = 0;
    for(int i = 0; i < N; i++){
      // 橋を渡らせることができるか？
      if(res + w[i] <= v_min) res += w[i];
      else {
        res = w[i];
        tmp += l_max;
      }
      if(i == N - 1) {
        tmp -= l_max;
        tmp += l_max_2;
      }
    }
    if(tmp < ans) {
      ans = tmp;
      // REP(i, N) {
      //   cout << w[i] << endl;
      // }
    }
  } while(next_permutation(all(w)));
  cout << ans << endl;
}