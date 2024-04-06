// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         stack<char> st;
//         for(char ch:s)
//         {
//             if(ch=='(')
//             st.push(ch);

//         }
//     }
// }x3;



#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();

class Solution {
public:
    Solution(){
        DPSolver; 
    }

    string minRemoveToMakeValid(string s) {
        int right = 0, s_len = s.length(), left = 0;
        for (int i = s_len - 1; i >= 0; i--) {
            if (s[i] == '(') {
                if (right == 0) s.erase(i, 1);
                else right--;
            } else if (s[i] == ')') {
                right++;
            }
        }
        while (right > 0) {
            if (s[left] == ')') {
                s.erase(left, 1);
                right--;
            }
            else left++;
        }
        return s;
    }
};