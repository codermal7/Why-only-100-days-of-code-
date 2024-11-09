class Solution {
public:
    long long minEnd(int n, int x) {
        long long lastElement = x; // 01
        while(--n){
            lastElement = (lastElement + 1) | x;
        }
        return lastElement;
    }
};