#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int M, N, K; cin >> M >> N >> K;
    vector<int> a(K); for(int i = 0; i < K; ++i) cin >> a[i];

    vector<int> res(M); for(int i = 0; i < M; ++i) res[i] = 0;
    int rem = N;
    for(int i = 0; i < K; ++i) {
        for(int m = 0; m < M; ++m) {
            if(a[i] != (m + 1)) {
                if(res[m] > 0) {
                    res[m]--;
                    res[a[i] - 1]++;
                }
            }
        }

        if(rem > 0) {
            rem--;
            res[a[i] - 1]++;
        }
    }
    
    int max_n = 0;
    for(int i = 0; i < M; ++i) {
        if(res[i] > max_n) {
            max_n = res[i];
        }
    }
    
    for(int i = 0; i < M; ++i) {
        if(max_n == res[i]) {
            cout << i + 1 << endl;
        }
    }
    
    return 0;
}