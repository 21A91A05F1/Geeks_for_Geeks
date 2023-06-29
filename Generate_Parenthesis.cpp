/*
Given n pairs of parentheses,
write a function to generate all combinations of well-formed or valid parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void print(int ind,int open,int close,vector<string>&res,string s,int n)
    {
        if(ind==n)
        {
            res.push_back(s);
            return;
        }
        if(open>0 && open!=n-1)
        {
            s+="(";
            print(ind+1,open-1,close,res,s,n);
            s.pop_back();
        }
        if(close>0 && open<close)
        {
            s+=")";
            print(ind+1,open,close-1,res,s,n);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>res;
        string s="(";
        int open=n-1;
        int close=n;
        n=n*2;
        print(1,open,close,res,s,n);
        return res;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends
