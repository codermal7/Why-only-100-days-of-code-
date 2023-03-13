//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        int r,sum=0,temp,i=0; 
    	if(n==0)
    	return 0;
    	while(i<n)
    	{
    	    temp=a[i];
            while(a[i]>0)    
            {    
                r=a[i]%10;    
                sum=(sum*10)+r;    
                a[i]=a[i]/10;    
            }   
            if(sum!=temp)
            return 0;
            i++;
            sum=0;
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends