class Solution {
public:
  int jump(vector<int>& nums) {
    int rez = 0, limit = nums.size() - 1;
    
    for(int i = 0; i != limit ; i++){
       int pos , j;
       rez++;
       int newmax = i + nums[i];
       if(newmax >= limit) break;
      
       for(j = i; j != limit && j < i + nums[i] ;j++){
         int t = nums[j] + j;
         if(t > newmax) newmax = t, pos = j;
       } 
         
       if(newmax > nums[j] + j) i = pos;
       else i = j;
      
       if(i + nums[i] >= limit) {rez++; break;}
       i--;
     } 
    return rez;   
  }
};