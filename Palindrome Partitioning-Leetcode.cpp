class Solution {
public:
  bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
      if(s[start++] != s[end--])
        return false;
    }
    return true;
  }
    void partitionHelper(int index, string s, vector<string> &path,
vector<vector<string>> &res) 
  {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }
    vector<vector<string>> partition(string s) {
        //TC=O(2^n)*n   i.e.O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome . SC=O(2^n*n)
        vector<vector<string>> res;
        vector<string> path;
        partitionHelper(0,s, path, res);
        return res;
    }
};
