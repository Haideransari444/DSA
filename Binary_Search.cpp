#pragma once 
#include <iostream>
#include <vector>
using namespace std; 
class Search { 
public:
int binarysearch(vector<int> &arr, int Target){ 
    int Start = 0; 
    int End = arr.size()-1;
    bool  found = false; 
    int index;
    while (Start<=End){ 
        int mid = (Start + End)/2; 
        if (arr[mid]==Target){ 
            found=true;
            index = mid; 
            break;
        }
        else if(arr[mid]>Target){ 
            End = mid-1;
        }
        else { 
            Start = mid + 1;
        }
    }
    if (found){ 
        return index;
    }
    else {
        return -1;
    }
}
};
