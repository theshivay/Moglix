// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
// Example 1:Input: s = "(()"Output: 2Explanation: The longest valid parentheses substring is "()".
// Example 2:Input: s = ")()())"Output: 4Explanation: The longest valid parentheses substring is "()()".
// Example 3:Input: s = ""Output: 0
// Constraints:
// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.


#include<bits/stdc++.h>
using namespace std;


int solve(string str){
    int size = str.size();

    stack<int> st;
    st.push(-1);
    int res = 0;

    for(int i = 0;i<size;i++){
        if (str[i] == '(') {
            st.push(i);
        } else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            } else {
                res = max(res, i - st.top());
            }
        }
    }

    return res;
}


int main(){
    string str;
    cin>>str;


    cout<<solve(str)<<endl;

    return 0;
}