#include <bits/stdc++.h>
using namespace std;

int main(){
    int s; cin >> s;

    vector<int> res;
    map<int, int> m;

    for(int i = 0; i < 1000007; ++i) {
        if(i == 0) {
            res.push_back(s);
            m.insert(make_pair(res[i], 1));
        } else {
            if(res[i - 1] % 2 == 0) {
                res.push_back(res[i - 1] / 2);
            } else {
                res.push_back(3 * res[i - 1] + 1);
            }

            if(m.count(res[i]) == 0) {
                m.insert(make_pair(res[i], 1));
            } else {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}