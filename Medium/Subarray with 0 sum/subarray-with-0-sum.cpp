//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int nums[], int n)
    {
        std::unordered_set<int> prefixSumSet;
    int prefixSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += nums[i];

        // If the current prefix sum is zero or if it's already in the set, a zero sum subarray exists
        if (prefixSum == 0 || prefixSumSet.find(prefixSum) != prefixSumSet.end()) {
            return true;
        } else {
            prefixSumSet.insert(prefixSum);
        }
    }

    return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends