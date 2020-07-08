#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    vector<int> a(N); REP(i,N) cin >> a[i];

    int max_n = *max_element(all(a));
    int min_n = *min_element(all(a));

    cout << max_n - min_n << endl;
}