class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int> ans(queries.size()),temp(items.size(),0);
        temp[0]=items[0][1];
        for(int i=1;i<items.size();i++){
            temp[i]=max(temp[i-1],items[i][1]);
        }  
        for(int i=0;i<queries.size();i++){
            int l=0,r=items.size()-1,dum=-1,itr=queries[i];
            while(l<=r){
                int mid=(l+r)/2;
                if(itr>=items[mid][0]){
                    dum=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(dum!=-1){
                ans[i]=temp[dum];
            }
        }
        return ans;
    }
};