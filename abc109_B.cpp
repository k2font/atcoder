#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> W(N); for(int i = 0; i < N; ++i) cin >> W[i];
    vector<string> W_copy(N);
    W_copy = W;

    bool flag = false;
    sort(W_copy.begin(), W_copy.end());
    for(int i = 1; i < W_copy.size(); ++i) {
        if(W_copy[i - 1] == W_copy[i]) {
            cout << "No" << endl;
            flag = true;
        }
    }

    if(flag != true) {
        for(int i = 1; i < N; ++i) {
            if(W[i - 1].at(W[i - 1].size() - 1) != W[i].at(0)) {
                cout << "No" << endl;
                break;
            }

            if(i == N - 1) {
                cout << "Yes" << endl;
            }
        }
    }
}