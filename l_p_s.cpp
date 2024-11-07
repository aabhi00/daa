#include <iostream>
#include <string>
#include<vector>

using namespace std;
int lpalindromesubseq(const string &s){
      int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // All substrings of length 1 are palindromes, so initialize the diagonal
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {  
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;  // j is the end index of the substring
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];  // Include the matching characters
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);  // Excluding  one character
            }
        }
    }
    return dp[0][n - 1];
}

int main(){
    string s = "bbbab";
    cout<<"length of longest palindromic sub sequence :"<<lpalindromesubseq(s)<<endl;
}
