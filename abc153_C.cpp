#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    vector<long long> H(N);
    for(int i = 0; i < N; ++i) cin >> H.at(i);

    sort(H.begin(), H.end());

    long long cnt = 0;

    for(int i = 0; i < N - K; ++i) {
        cnt += H.at(i);
    }

    cout << cnt << endl;
}
