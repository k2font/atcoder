#include <iostream>
#include <vector>
using namespace std;

vector<int> buf;
int cnt = 0;

void dfs(int i, const int size, const int range_start, const int range_end) {
  if (i == size) {
      // ここで所望の作業を行う
      for(int i = 0; i < buf.size(); ++i){
        cout << buf[i] << " ";
      }
      cout << endl;
      //cnt++;
      //cout << cnt << endl;
  }
  else{
      for(int j = range_start; j <= range_end; ++j){
          buf[i] = j;
          if(buf[i - 1] > buf[i]) continue;
          dfs(i + 1, size, range_start, range_end);
      }
  }
}

int main(void)
{
    int size = 10;
    int range_start = 0;
    int range_end = 9;
    
    buf.resize(size);
    dfs(0, size, range_start, range_end);

    return 0;
}