class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        // T.C.=O(nlogn), S.C.=O(n)
        int n=h.size();
        if(n==1)
        return 0;
        priority_queue<int> pq;  /* PQ takes log n times for all operations */
        int i=0;
        for(;i<n-1;i++)
        {
            if(h[i+1]<=h[i])
            continue;
            int diff=h[i+1]-h[i];
            if(b>=diff)
            {
                b-=diff;
                pq.push(diff);
            }
            else if(l>0)
            {
                if(!pq.empty())
                {
                    int past_b=pq.top();
                    if(past_b>diff)
                    {
                        b+=past_b;
                        pq.pop();
                        b-=diff;
                        pq.push(diff);                        
                    }
                }
                l--;
            }
            else
            break;
        }
        return i;
    }
};