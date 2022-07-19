// Flip Bits : Codestudio

//A variation of Kadane's Algorithm

/*Explaination : Array can be divided into three sections one central section that we have to flip one
before this section and one after.

Central Section would be the biggest section where number of zeroes is greater than number of one
If we treat zero as '1' and one as '-1', we can also say that bigest section with largest sum

Max(Number of Zeroes - Number of Ones) in central section is the answer we are looking for.

No. 0s * 1 + No of 1s * -1 : A type of Kadane's algorithm.


Total Number of ones after flipping : No of 1s in Section 1 +  Number of 0s in Section 2(middle section) + No of 1s Section 3  -- required answer

Total Number of One : no of 1s in S1 + S2 + S3

required answer : no of 1s in (S1 + S2 + S3) - no of 1s in S1 + no of 0s in S2

required answer : total number of ones + answer obtained from kadane's algorithm

*/

int flipBits(int* arr, int n)
{
   int x = 0, y = 0;
   int curr = 0, sum = 0, ans = 0;
   for (int i = 0; i < n; i++)
   {
      ans += (arr[i] == 1 ? 1 : 0);
      curr += (arr[i] == 0 ? 1 : -1);
      if (curr < 0)
         curr = 0;
      sum = max(curr, sum);

   }

   return ans + sum;
}