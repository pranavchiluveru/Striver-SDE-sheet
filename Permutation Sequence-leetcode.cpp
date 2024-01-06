class Solution {
public:
    /*
    void find(int index,string s,vector<string> &res)
    {
    if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        find(ind + 1,s, res);
        swap(s[i], s[index]);
      }
    }
    */
    string getPermutation(int n, int k) {
        /*Approach 1 : Generate all permutations and store it in a vector
    n! permutations .each permutation takes n time.
    TC=O(n!*n)+O(n!logn!) SC=O(n!*n)
        string num;
        for(int i=1;i<=n;i++)
        {
            num+='0'+i;
        }
        vector<string> res;
        find(0,num,res);
        sort(res.begin(),res.end());
        return res[k-1];
        */
        //optimal approach TC=O(n2) SC=O(n)
        //first compute factorial of n-1
        int fact=1;
        string s="";
        vector<int> num;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            num.push_back(i);//store the numbers in a vector
        }
        num.push_back(n);
        k=k-1;//since we are starting from 0
        while(1)//takes O(n)
        {
        s+=to_string(num[k/fact]);
        num.erase(num.begin()+k/fact);//takes O(n)
        if(num.size()==0)
            break;
        k=k%fact;
        fact=fact/num.size();
        }
        return s;

    }
};
