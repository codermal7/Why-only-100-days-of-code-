#define ll long long
class Solution {
public:
    bool satisfy(ll a, ll b, ll c, ll d, ll mid)
    {
        ll div1=mid/a, div2=mid/b;
        ll ndiv1=mid-div1, ndiv2=mid-div2;
        ll ndivall=mid-mid/lcm(a,b);

        if(ndiv1>=c && ndiv2>=d && ndivall>=c+d)
        return true;

        return false;
    }
    int minimizeSet(int a, int b, int c, int d) {
        ll ans=INT_MAX, l=1, h=INT_MAX;
        while(l<=h)
        {
            ll mid=l+(h-l)/2;
            if(satisfy(a,b,c,d,mid))
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};