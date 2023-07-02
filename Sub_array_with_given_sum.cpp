/*
Approach 1:
===========
Find all the subarrays formed by the given array and find their sum
But this approach takes o(n*n) time complexity and becomes complex to find all the subarrays.
Approach 2:
==========
Two - pointer technique . 
Take two pointers , one is left and another one is right . 
Add the elements to the current sum , by moving the right pointer until the csum <= given sum.
If the csum exceeds then , starting moving the left pointer and subtract the inital elements.
When the csum is equals to the sum  then return left and right indices , from left to right the required subarray is formed.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long sum)
    {
        // Your code here
        int left=0;
        int right=0;
        int csum=0;
        vector<int>ve;
        while(right<=n)
        {
            if(csum==sum)
            {
                ve.push_back(left+1);
                ve.push_back(right);
                return ve;
            }
            if(left==right or csum<sum)
            {
                right++;
                csum+=arr[right-1];
            }
            else
            {
                left++;
                csum-=arr[left-1];
            }
            
        }
        ve.push_back(-1);
        return ve;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
