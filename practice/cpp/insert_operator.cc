#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define ll long long int

string NumberToString (int n) {
  ostringstream ss;
  ss << n;
  return ss.str();
}

string PrintPath(int i, int j, const vector<vector<int> >& path,
                 const vector<string>& sub_paths) {
  //cout << i << " " << j << endl;

  if (i > j) {
    return "";
  }

  if (i == j) {
    return "(" + sub_paths[i] + ")";
  }

  int k = path[i][j];
  int x = k < 0 ? -k : k;
  
  string left = PrintPath(i, x - 1, path, sub_paths);
  string right = PrintPath(x, j, path, sub_paths);

  if (k < 0) {
    left = "(" + left + " + 1)";
  } else {
    right = "(1 + " + right + ")";
  }

  return left + "*" + right;
}

int main() {
  int n;

  while (cin >> n) {
    vector<int> arr(n, -1);
    cout << "Input: ";
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> dp_base_arr;
    vector<string> sub_path;

    // Preprocess for leading and trailing 1's.
    int s = 0;
    int e = n - 1;
    ll prod = 1;
    string ps = "";

    // Leading 1.
    if (n > 1 && arr[s] == 1) {
      s = 2;
    }

    // Trailing 1.
    if (n > 1 && s < e && arr[e] == 1) {
      e = n - 3;
    }

    prod = 1;
    ps = "";
    int size = 0;
    for (int i = s; i <= e; ++i) {
      if (arr[i] == 1 && size > 0) {
        dp_base_arr.push_back(prod);
        sub_path.push_back(ps);

        prod = 1;
        ps = "";
        size = 0;
      } else if (arr[i] == 0) {
        if (ps.length() > 0) {
          ps += ")+";
        }
        ps += NumberToString(arr[i]);
        ps = "(" + ps + ")";
        ++size;
      } else if (arr[i] != 1) {
        prod *= arr[i];
        if (ps.length() > 0) {
          ps += "*";
        }
        ps +=  NumberToString(arr[i]);
        ++size;
      }
    }

    if (size > 0) {
      dp_base_arr.push_back(prod);
      sub_path.push_back(ps);
    }   

    // Do MCM.
    int dp_n = dp_base_arr.size();
    vector<vector<ll> > dp(dp_n, vector<ll>(dp_n, 0));
    vector<vector<int> > path(dp_n, vector<int>(dp_n, 0));

    for (int i = 0; i < dp_n; ++i) {
      dp[i][i] = dp_base_arr[i];
    }

    for (int l = 2; l <= dp_n; ++l) {
      for (int i = 0; i <= dp_n - l; ++i) {
        int j = i + l - 1;
        
        dp[i][j] = -1;
        for (int k = i + 1; k <= j; ++k) {
          ll opt1 = (dp[i][k - 1] + 1) * dp[k][j];
          ll opt2 = dp[i][k - 1] * (1 + dp[k][j]);

          ll opt = opt1 > opt2 ? opt1 : opt2;

          if (dp[i][j] < opt) {
            dp[i][j] = opt;
            if (opt == opt1) {
              path[i][j] = -k;
            } else {
              path[i][j] = k;
            }
          }
        }
      }
    }

    string ans = PrintPath(0, dp_n - 1, path, sub_path);
    int ans_val = 0;
    
    if (dp_n > 0 ) {
      ans_val = dp[0][dp_n - 1];
    }

    // Add leading and trailing 1 parts if applicable.
    if (s > 0) {
      if (ans_val == 0) {
        ans_val = 1;
      }
      ans_val *= (1 + arr[1]);
      ans = "(1+" + NumberToString(arr[1]) + ")" + (ans.length() > 0 ? "*" : "") +  ans;
    }
    
    if (e < n - 1 && s < e) {
      if (ans_val == 0) {
         ans_val = 1;
      }
      ans_val *= (1 + arr[n - 2]);
      ans = ans +  (ans.length() > 0 ? "*" : "") + "(" + NumberToString(arr[n - 2]) + " +1)";
    }

    cout << "Answer expression: " << ans << endl;
    cout << "Value: " << ans_val << endl << endl;
  }

  return 0;
}
