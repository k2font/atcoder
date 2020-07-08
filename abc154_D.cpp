#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for(int i = 0; i < N; ++i) cin >> p[i];

    // 期待値の和は和の期待値
    // E[X + Y] = E[X] + E[Y]を用いる

    // 計算量がO(N^2)でもまだ間に合わない。
    // O(N)にする方法は？

    double cnt = 0.0;
    double result = 0.0;
    for(int i = 0; i < N - K + 1; ++i) {

        if(i == 0) {
            for(int k = 0; k < K; ++k) {
                result += (double)(0.5 * p[k] * (p[k] + 1)) / (double)p[k];
            }
        } else {
            result -= (double)(0.5 * p[i - 1] * (p[i - 1] + 1)) / (double)p[i - 1];
            result += (double)(0.5 * p[i + K - 1] * (p[i + K - 1] + 1)) / (double)p[i + K - 1];
        }

        if(cnt < result) {
            cnt = result;
        }
    }

    cout << fixed << setprecision(10) << cnt << endl;
}