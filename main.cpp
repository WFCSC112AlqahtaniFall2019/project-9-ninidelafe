#include <iostream>
#include <vector>
#include <string>
#include <array>

#include "Data.h"

using namespace std;


//code taken from powerpoint
template<typename T>
void BubbleSort(vector <T>& arr, int size) {
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        //if there wasn't any swap in the inner loop, stop
        if (!swapped) {
            break;
        }
    }
}
template <typename T>
void MinSort(vector <T>& arr, int size) {
    int min;
    for (int i = 0; i < size - 1; ++i) {
        // Find index of smallest remaining element
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}



int main() {





    return 0;
}