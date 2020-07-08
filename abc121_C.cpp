#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(N);
    vector<pair<long long, long long>> p(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        p[i] = make_pair(A[i], B[i]);
    }

    sort(p.begin(), p.end());

    long long cnt = 0;
    long long mon = 0;
    for(int i = 0; i < N; ++i) {
        if(cnt + p[i].second <= M) {
            mon += p[i].first * p[i].second;
            cnt += p[i].second;
        } else if(cnt + p[i].second > M) {
            while(cnt < M) {
                cnt++;
                mon += p[i].first;
            }
        }

        if(cnt == M) {
            break;
        }
    }

    cout << mon << endl;
}