// class Solution {
// public:
//     bool isPalindrome(string s) {
//         if(s.length()<=1)
//         return true;
//         string str="";
//         for(auto it:s)
//         {
//             if(isalnum(it))
//             str+=tolower(it);
//         }
//         // cout<<str<<endl;
//         int low=0,high=str.length()-1;
//         // cout<<high<<endl;
//         int mid=low+((high - low) / 2);
//         // cout<<mid<<endl;
//         while(low<high)
//         {
//             // cout<<"low :"<<str[low]<<", high :"<<str[high]<<endl;
//             if(str[low]!=str[high])
//             return false;
//             low++;
//             high--;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(!isalnum(s[l]))
                l++;
            else if(!isalnum(s[r]))
                r--;
            else if(tolower(s[l])!=tolower(s[r]))
                return false;
            else
            {
                l++;r--;
            }
                
        }
        return true;
    }
};