class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3) return 0;
        
        // curr is the count of current continuous sequence of arithmetic numbers
        // last_diff is A[i]-A[i-1], for any "i", that is last_difference of the previous arithmetic sequence(if exist)
        int ans=0,curr=0,last_diff=A[1]-A[0];
        
        for(int i=1;i<n-1;++i){
            int curr_diff=A[i+1]-A[i]; // current difference 
            
            if(curr_diff==last_diff){ // if last difference == current difference
                ++curr; // then "A[i+1]" also contribute to the last arithmetic sequence
            }
            else{
                last_diff=curr_diff; // we need to reset curr=0 and replace curr_diff with last_diff
                curr=0;
            }
            ans+=curr; // add current continuous arithmetic sequence count to ans
        }
        return ans;
    }
};