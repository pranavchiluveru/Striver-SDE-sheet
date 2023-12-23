#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   // Brute force: TC=O(nlogn) sc=O(1) : sort(arr,arr+n);
   /*Better Approach TC=O(n+n) Sc=O(1)
   int ones=0,twos=0,zeros=0;
   for(int i=0;i<n;i++)
   {
      if(arr[i]==0)
         zeros++;
      else if(arr[i]==1)
         ones++;
      else
         twos++;
   }
   int i=0;
   while(i<zeros)
   {
      arr[i]=0;
      i++;
   }
   while(i<ones+zeros)
   {
      arr[i]=1;
      i++;
   }
   while(i<n)
   {
      arr[i]=2;
      i++;
   }
   */
   //Optimal: Dutch Algorithm :TC=O(n) SC=O(1)
   int low=0,high=n-1,i=0;
   while(i<=high)
   {
      if(arr[i]==0)
      {
         swap(arr[i],arr[low]);
         i++;
         low++;
      }
      else if(arr[i]==1)
      {
         i++;
      }
      else
      {
         swap(arr[i],arr[high]);
         high--;
      }
   }


}
