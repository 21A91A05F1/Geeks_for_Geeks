/*
Hard problem
=============
Given an array Arr of size N containing positive integers.
Count number of smaller elements on right side of each array element
============
Input:
N = 7
Arr[] = {12, 1, 2, 3, 0, 11, 4}
Output: 6 1 1 1 0 1 0
Explanation: There are 6 elements right
after 12. There are 1 element right after
1. And so on.
======================================
Approach:
=========
Using lower_bound:
The lower_bound() method in C++ is used to return an iterator pointing 
to the first element in the range [first, last) which has a value not less than val.
This means that the function returns an iterator pointing to the next smallest number just greater than
or equal to that number. If there are multiple values that are equal to val
Code:
=====
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<int>ve,res;
	    for(int i=0;i<n;i++)
	    {
	        ve.push_back(arr[i]);
	    }
	    sort(ve.begin(),ve.end());
	    for(int i=0;i<n;i++)
	    {
	        int index=lower_bound(ve.begin(),ve.end(),arr[i])-ve.begin();
	        res.push_back(index);
	        ve.erase(ve.begin()+index);
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
