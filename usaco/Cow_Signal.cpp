/* Input Format
*  5 4 2
*  XXX.
*  X..X
*  XXX.
*  X..X
*  XXX.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int M, N, K; //M is y_dim, N is x_dim, K is dilation_val
  cin >> M >> N >> K;
  string lines = "";
  for (int i = 0; i < M; i++){
    string new_line = "";
    for (int j = 0; j < N; j++){
      char z;
      cin >> z;
        for (int l = 0; l < K; l++){
          new_line += z;
        }
  }
    if (i == M-1){
      for (int l = 0; l < K - 1; l++){
        lines += new_line;
        lines += "\n";
      }
      lines += new_line;
    }
    else{
      for (int l = 0; l < K; l++){
        lines += new_line;
        lines += "\n";
      }
    }
}
  cout << lines;
}

