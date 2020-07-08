#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, M; cin >> A >> B >> M;
    vector<int> a(A), b(B);
    for(int i = 0; i < A; ++i) {
        cin >> a[i];
    }

    for(int i = 0; i < B; ++i) {
        cin >> b[i];
    }

    vector<int> x(M), y(M), c(M);
    for(int i = 0; i < M; ++i) {
        cin >> x[i] >> y[i] >> c[i];
    }

    int min_res = 10000007;
    for(int i = 0; i < M; ++i) {
        int comp = a[x[i] - 1] + b[y[i] - 1] - c[i];
        if(min_res > comp) {
            min_res = comp;
        }

        if(i == M - 1) {
            int min_ele = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
            if(min_res > min_ele) {
                min_res = min_ele;
            }
        }
    }

    cout << min_res << endl;
}