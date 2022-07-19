//Kadane's Algorithm : Maximum Subarray Sum

//Question from Codestudio

#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{

    long long curr_sum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum < 0)
            curr_sum = 0;
        sum = max(curr_sum, sum);
    }
    return sum;
}