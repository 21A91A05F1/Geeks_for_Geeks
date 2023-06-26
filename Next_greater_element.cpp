/*
Description:
=============
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in 
order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. 
For example, next greater of the last element is always -1
================
Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
===================
My approach
===================
We have to find the element which is next greatest to the given element.
Traverse from the back of an array ;
If the top of the stack is greater than the element then push the top most element to the stack.
else popout the elements , until you get an element greater than the array element.
My code:
========
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ve;
        stack<long long>st;
        for(long long i=n-1;i>=0;i-- )
        {
            while(!st.empty() && arr[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ve.push_back(-1);
            }
            if(!st.empty() && arr[i]<st.top())
            {
                ve.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ve.begin(),ve.end());
        return ve;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  
