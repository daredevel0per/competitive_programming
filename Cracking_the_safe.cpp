/*
There is a safe protected by a password. The password is a sequence of n digits where each digit can be in the range [0, k - 1].

The safe has a peculiar way of checking the password. When you enter in a sequence, it checks the most recent n digits that were entered each time you type a digit.

For example, the correct password is "345" and you enter in "012345":
After typing 0, the most recent 3 digits is "0", which is incorrect.
After typing 1, the most recent 3 digits is "01", which is incorrect.
After typing 2, the most recent 3 digits is "012", which is incorrect.
After typing 3, the most recent 3 digits is "123", which is incorrect.
After typing 4, the most recent 3 digits is "234", which is incorrect.
After typing 5, the most recent 3 digits is "345", which is correct and the safe unlocks.
Return any string of minimum length that will unlock the safe at some point of entering it.

 

Example 1:

Input: n = 1, k = 2
Output: "10"
Explanation: The password is a single digit, so enter each digit. "01" would also unlock the safe.
Example 2:

Input: n = 2, k = 2
Output: "01100"
Explanation: For each possible password:
- "00" is typed in starting from the 4th digit.
- "01" is typed in starting from the 1st digit.
- "10" is typed in starting from the 3rd digit.
- "11" is typed in starting from the 2nd digit.
Thus "01100" will unlock the safe. "01100", "10011", and "11001" would also unlock the safe.
 

Constraints:

1 <= n <= 4
1 <= k <= 10
1 <= kn <= 4096
*/

/*
A de Bruijn sequence of order n on a size-k alphabet A is a cyclic sequence in which every possible length-n string on A occurs exactly once as a substring. It has length k^n, which is also the number of distinct substrings of length n on a size-k alphabet; de Bruijn sequences are therefore optimally short.

We can utilize DFS to find the password:

goal: to find the shortest input password such that each possible n-length combination of digits [0..k-1] occurs exactly once as a substring.

node: current input password

edge: if the last n - 1 digits of node1 can be transformed to node2 by appending a digit from 0..k-1, there will be an edge between node1 and node2

start node: n repeated 0's
end node: all n-length combinations among digits 0..k-1 are visited

visitedComb: all combinations that have been visited
*/
class Solution {
public:
    bool dfs(string &ans, int total, int n, int k, unordered_set<string>&vis){
        if (vis.size()==total){
            return true;
        }
        for (char c='0'; c<'0'+k; c++){
            ans=ans+c;
            string temp=ans.substr(ans.size()-n);
            if (vis.find(temp)==vis.end()){
                vis.insert(temp);
                if (dfs(ans,total,n,k,vis)){
                    return true;
                }
                vis.erase(temp);
            }
            ans.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        string ans(n,'0');
        int total=pow(k,n);
        unordered_set<string>vis;
        vis.insert(ans);
        dfs(ans,total,n,k, vis);
        return ans;
    }
};
