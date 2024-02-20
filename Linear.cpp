#pragma once
#include  <iostream>
#include <vector>
using namespace std;
class linear {
    public:
    int linearsearch(vector <int> &arr, int Target){
         
        for (int i=0; i<=arr.size();i++){ 
            if(arr[i]==Target){ 
                return i;
                break; 
            } 
            else if (i == arr.size())    // If we reach here, then element is not present in array
            { 
                return -1;
            }
        }
    }

};
