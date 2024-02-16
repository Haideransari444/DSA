This code prompts the user to enter 10 integers into an array and then performs a linear search to find a target number entered by the user.
If the target number is found, the program checks its value and prints a corresponding message based on the grade range it falls into (A, B, or C).
If the target number is not found, the program prints "Not found!!"

The code uses a linear search algorithm to iterate through the elements of the array and checks if each element matches the target number.
If a match is found, the program checks the value of the element to determine the appropriate grade message to print.
If the target number is not found after iterating through all the elements, the program prints "Not found!".



#include <iostream>
using namespace std; 
int main() { 
    int arr [10]; 
    for (int i = 0; i<10; i++){ 
        cout<<"Enter The Number:  "; 
        cin>>arr[i];
    }
    cout<<"ENTER THE TARGET NUMBER YOU WANT TO FIND: "; 
    int Target;
    int Temporary;
    cin>>Target;
    //Liner Search
    for (int i=0; i<10;i++){
        if(arr[i]==Target){
            Temporary=i; 
            if(arr[Temporary]>90){ 
                cout<<"The Grade Is A";
                break;
            }            
            else if ((arr[Temporary]<=90) && (arr[Temporary]>=70)){ 
                cout<<"The Grade is B";
                break;
            }
              else if (arr[Temporary]<=70 && arr[Temporary]>=50){
                cout<<"The Grade is C";
                break;
            }
            else{ 
            cout<<"Failed";
            break;
            }
    }
    else if (i==9){ 
    cout<<"Not found!!"; 
	} 
	}
    }
    
    

    

