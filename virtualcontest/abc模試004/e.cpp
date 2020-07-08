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
    vector<double> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];

    double cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int k = i + 1; k < N; ++k) {
            double res = (x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i]);
            double result = sqrt(res);
            if(cnt < result) {
                cnt = result;
            }
        }
    }

    cout << fixed << setprecision(6) << cnt << endl;
}