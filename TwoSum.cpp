Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]





#include <iostream>
using namespace std; 
int main(){ 
int length; 
cout<<"Enter The length Of the Array"; 
cin>>length;
int array[length]; 
for(int i = 0; i<length;i++){ 
cin>>array[i];
}
int target; 
cout<<"enter the target: ";
cin>>target;
int result=1;
	for(int i = 0; i<length; i++){ 
		for (int j=0; j<length; j++){ 
			if(array[i]+array[j]==target){ 
			cout<<"["<<i<<","<<j<<"]";
			
		}						
}
			array[i]=0;
			result = 2;
}
	 
	 if (result != 2){ 
	 cout<<"not Found!!!";
	 }

}
