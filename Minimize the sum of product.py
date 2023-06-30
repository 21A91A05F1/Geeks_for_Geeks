/*
You are given two arrays, A and B, of equal size N.
The task is to find the minimum value of A[0] * B[0] + A[1] * B[1] + .... + A[N-1] * B[N-1], 
where shuffling of elements of arrays A and B is allowed.
Example 1:
Input:
N = 3 
A[] = {3, 1, 1}
B[] = {6, 5, 4}
Output:
23 
Explanation:
1*6+1*5+3*4 = 6+5+12
= 23 is the minimum sum
*/
#User function Template for python3

class Solution:
    def minValue(self, a, b, n):
        # Your code goes here
        a=sorted(a)
        b=sorted(b)[::-1]
        s=0
        for i in range(n):
            s+=a[i]*b[i]
        return s



#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob=Solution()
        print(ob.minValue(a, b, n))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
