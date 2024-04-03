//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool IsPerfect(int a[],int n)
    {
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=a[i];
        }
        int j=n-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=a[j])
            {
                // cout<<"NOT PERFECT";
                return false;
            }
            j--;
        }
        // cout<<"PERFECT";
        return true;
    }
};




//{ Driver Code Starts.
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        if(ob.IsPerfect(a,n))
            cout<<"PERFECT\n";
        else
            cout<<"NOT PERFECT\n";
        
    }
    
}
// } Driver Code Ends