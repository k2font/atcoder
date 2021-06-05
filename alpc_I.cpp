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

struct SuffixArray{
    vector<int> array, rank, lcp;
    int k, N;
    vector<int> S;
 
    SuffixArray(vector<int>& S){ initialize(S); }
    SuffixArray(string S=""){ initialize(S); }
 
    bool cmp(int i, int j){
        if(rank[i] != rank[j]) return (rank[i] < rank[j]);
        int ri = (i+k < N ? rank[i+k] : -1);
        int rj = (j+k < N ? rank[j+k] : -1);
        return ri < rj;
    }
    
    void initialize(vector<int>& Sin){
        S = Sin;
        N = S.size();
        array.resize(N);
        for(int i=0; i<N; i++) array[i] = i;
        rank = S;
        vector<int> tmp(N);
 
        for(k=1; k<N; k*=2){
            sort(array.begin(), array.end(), [&](int i, int j){ return cmp(i, j); });
 
            tmp[array[0]] = 0;
            for(int i=1; i<N; i++){
                tmp[array[i]] = tmp[array[i-1]] + cmp(array[i-1], array[i]);
            }
            for(int i=0; i<N; i++) rank[i] = tmp[i];
        }
    }
 
    void initialize(string& S){
        vector<int> s;
        for(int i=0; i<int(S.size()); i++) s.push_back(S[i]);
        initialize(s);
    }
 
    void calc_lcp(){
        lcp.resize(N-1);
        int h = 0;
        for(int i=0; i<N; i++){
            if(h > 0) h--;
            if(rank[i] == 0) continue;
            int j = array[rank[i]-1];
            for(; j+h<N && i+h<N; h++){
                if(S[j+h] != S[i+h]) break;
            }
            lcp[rank[i]-1] = h;
        }
    }
};

int main() {
  string S; cin >> S;
  ll ans = S.size() * (S.size() + 1) / 2;

  SuffixArray sa(S); // suffix arrayの構築
  sa.calc_lcp();
  for(int a : sa.lcp) {
    ans -= a;
  }
  cout << ans << endl;
}