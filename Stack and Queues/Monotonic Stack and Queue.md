Monotonic Stack Info:

https://leetcode.com/discuss/study-guide/2347639/a-comprehensive-guide-and-template-for-monotonic-stack-based-problems


Problem 1 : 
https://ali-ibrahim137.github.io/competitive/programming/2019/12/08/Monotonic-Queue.html

https://codeforces.com/contest/1195/problem/E


I know the basic idea behind the monotonic queue and stack, but how should I implement it in ambiguous questiond like above ?

Even if I know I have to implement mono q/s how to implement it in that question is an entirely different matter 


1. The simple question from the article : 
easy to solve, maintaine a deque whose front element is current minimum element insert a rear, pop from rear till the last element of the queue is smaller than the element to be inserted 

Then we will get a increasing queue, with front being the minimum of the current subarray, move the subarray and insert and pop the front accordingly.


How to use this to solve the bigger problem?


a. 

first intuition was to solve the problem just like the above, shit one block at a time, add b numbers remove b numbers : TC ; O(n.m.b)  which is not suitable 

b. 
Reducing time complexity to quadratic O(n.m)
use two monotonic queue methods : first use monotonic queue on rows to find the minimum in subarray of length b, get these results. Then use monotonic queue on columns of the results, to find the minimum in subarray of length a, sum the results from the second operation. This will be our answer


Problem 2: 
https://codeforces.com/contest/846/problem/E

