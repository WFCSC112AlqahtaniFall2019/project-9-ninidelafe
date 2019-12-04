#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <ctime>

#include "Data.h"

using namespace std;

//code taken from powerpoint
template<typename T>
void BubbleSort(vector <T>& arr, T size) {
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
//code taken from power point
template <typename T>
void MinSort(vector <T>& arr, T size) {
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

//code taken from Zybooks
template<typename T>
int Partition(vector<T> &numbers, T i, T k) {
    T l;
    T h;
    T midpoint;
    T pivot;
    T temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = numbers.at(midpoint);

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (numbers.at(l) < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers.at(h)) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        } else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;

            ++l;
            --h;
        }
    }

    return h;
}
//code taken from Zybooks
template<typename T>
void QuickSort(vector<T> &numbers, T i, T k) {
    T j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    QuickSort(numbers, i, j);
    QuickSort(numbers, j + 1, k);
}

//code taken from Zybooks
template<typename T>
void Merge(vector<T> &numbers, T i, T j, T k) {

    T mergedSize; // Size of merged partition
    T mergePos; // Position to insert merged number
    T leftPos; // Position of elements in left partition
    T rightPos; // Position of elements in right partition
    //int *mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i; // Initialize left partition position
    rightPos = j + 1; // Initialize right partition position
    //mergedNumbers = vector<int> (mergedSize); // Dynamically allocates temporary array for merged numbers
    vector<T> mergedNumbers(mergedSize);

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers.at(mergePos) = numbers.at(leftPos);
            ++leftPos;
        } else {
            mergedNumbers.at(mergePos) = numbers.at(rightPos);
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    //delete[] mergedNumbers;
}
//code taken from Zybooks
template<typename T>
void MergeSort(vector<T> &numbers, T i, T k) {
    T j;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}

int main() {
    srand(time(0));
    //creates the two vectors
    vector<Data> dataV;
    vector<int> intV;

    //opens the files
    ifstream in;
    ofstream out;
    out.open("SortingTimes.csv");
    in.open("../wineReviews.csv");

    //checks to make sure the file is open if not stops running the program
    if (!in.is_open()){
        cout<<"File was not opened correctly!"<<endl;
        return 1;
    }

    cout<<"Reading wineReviews.csv..."<<endl;

    while (!in.eof()) {
        //i++;
        //cout<<"In while loop! i= "<< i; //<< endl;

        //getline will go until the comma then move on
        string crty, point, pric, prov, var;
        getline(in, crty, ',');
        getline(in, point, ',');
        getline(in, pric, ',');
        getline(in, prov, ',');
        getline(in, var, '\n');


        //changes from string to int
        int points = stoi(point);
        int price = stoi(pric);

        //takes the data read in from wineReviews.csv and puts it into the dataV vector
        Data info = Data(crty, points, price, prov, var);
        dataV.push_back(info);
    }

    //fills the intV vector with random numbers
    for (int i=0;i<dataV.size();i++){
        intV.push_back(rand()%100);
    }

    for (int j= dataV.size()/100;j<=dataV.size(); j+=dataV.size()/100) {

        //creates 4 copies of the vector dataV
        vector<Data> dataV_B = dataV;
        vector<Data> dataV_S = dataV;
        vector<Data> dataV_Q = dataV;
        vector<Data> dataV_M = dataV;

        //creates 4 copies of the vector intV
        vector<int> intV_B = intV;
        vector<int> intV_S = intV;
        vector<int> intV_Q = intV;
        vector<int> intV_M = intV;

        //begins the sorting using all the template algorithms and times each sorting
        cout << "Sorting using BubbleSort..." << endl;

        clock_t start_dataV_B = clock(); //start clock
        BubbleSort(dataV_B, dataV_B.size());
        clock_t end_dataV_B = clock(); //end clock
        double elapsed_dataV_B = double(end_dataV_B - start_dataV_B) / CLOCKS_PER_SEC;

        clock_t start_intV_B = clock(); //start clock
        BubbleSort(intV_B, intV_B.size());
        clock_t end_intV_B = clock(); //end clock
        double elapsed_intV_B = double(end_intV_B - start_intV_B) / CLOCKS_PER_SEC; //calculate seconds passed


        cout << "BubleSort Complete!" << endl << "Sorting using SelectionSort..." << endl;

        clock_t start_dataV_S = clock(); //start clock
        MinSort(dataV_S, dataV_S.size());
        clock_t end_dataV_S = clock(); //end clock
        double elapsed_dataV_S = double(end_dataV_S - start_dataV_S) / CLOCKS_PER_SEC;

        clock_t start_intV_S = clock(); //start clock
        MinSort(intV_S, intV_S.size());
        clock_t end_intV_S = clock(); //end clock
        double elapsed_intV_S = double(end_intV_S - start_intV_S) / CLOCKS_PER_SEC;

        cout << "SelectionSort Complete!" << endl << "Sorting using QuickSort..." << endl;

        clock_t start_dataV_Q = clock(); //start clock
        QuickSort(dataV_Q, 0, dataV_Q.size() - 1);
        clock_t end_dataV_Q = clock(); //end clock
        double elapsed_dataV_Q = double(end_dataV_Q - start_dataV_Q) / CLOCKS_PER_SEC; //calculate seconds passed

        clock_t start_intV_Q = clock(); //start clock
        QuickSort(intV_Q, 0, intV_Q.size() - 1);
        clock_t end_intV_Q = clock(); //end clock
        double elapsed_intV_Q = double(end_intV_Q - start_intV_Q) / CLOCKS_PER_SEC;

        cout << "QuickSort Complete!" << endl << "Sorting using MergeSort..." << endl;

        clock_t start_dataV_M = clock(); //start clock
        MergeSort(dataV_M, 0, dataV_M.size() - 1);
        clock_t end_dataV_M = clock(); //end clock
        double elapsed_dataV_M = double(end_dataV_M - start_dataV_M) / CLOCKS_PER_SEC; //calculate seconds passed

        clock_t start_intV_M = clock(); //start clock
        MergeSort(intV_M, 0, intV_M.size() - 1);
        clock_t end_intV_M = clock(); //end clock
        double elapsed_intV_M = double(end_intV_M - start_intV_M) / CLOCKS_PER_SEC;

        cout << "QuickSort Complete!" << endl;

        cout << "First round of sorting complete!" << endl;

        cout << "Sorting using BubbleSort..." << endl;

        clock_t start_dataV_B = clock(); //start clock
        BubbleSort(dataV_B, dataV_B.size());
        clock_t end_dataV_B = clock(); //end clock
        double elapsed_dataV_B2 = double(end_dataV_B - start_dataV_B) / CLOCKS_PER_SEC;

        clock_t start_intV_B = clock(); //start clock
        BubbleSort(intV_B, intV_B.size());
        clock_t end_intV_B = clock(); //end clock
        double elapsed_intV_B2 = double(end_intV_B - start_intV_B) / CLOCKS_PER_SEC; //calculate seconds passed


        cout << "BubleSort Complete!" << endl << "Sorting using SelectionSort..." << endl;

        clock_t start_dataV_S = clock(); //start clock
        MinSort(dataV_S, dataV_S.size());
        clock_t end_dataV_S = clock(); //end clock
        double elapsed_dataV_S2 = double(end_dataV_S - start_dataV_S) / CLOCKS_PER_SEC;

        clock_t start_intV_S = clock(); //start clock
        MinSort(intV_S, intV_S.size());
        clock_t end_intV_S = clock(); //end clock
        double elapsed_intV_S2 = double(end_intV_S - start_intV_S) / CLOCKS_PER_SEC;

        cout << "SelectionSort Complete!" << endl << "Sorting using QuickSort..." << endl;

        clock_t start_dataV_Q = clock(); //start clock
        QuickSort(dataV_Q, 0, dataV_Q.size() - 1);
        clock_t end_dataV_Q = clock(); //end clock
        double elapsed_dataV_Q2 = double(end_dataV_Q - start_dataV_Q) / CLOCKS_PER_SEC; //calculate seconds passed

        clock_t start_intV_Q = clock(); //start clock
        QuickSort(intV_Q, 0, intV_Q.size() - 1);
        clock_t end_intV_Q = clock(); //end clock
        double elapsed_intV_Q2 = double(end_intV_Q - start_intV_Q) / CLOCKS_PER_SEC;

        cout << "QuickSort Complete!" << endl << "Sorting using MergeSort..." << endl;

        clock_t start_dataV_M = clock(); //start clock
        MergeSort(dataV_M, 0, dataV_M.size() - 1);
        clock_t end_dataV_M = clock(); //end clock
        double elapsed_dataV_M2 = double(end_dataV_M - start_dataV_M) / CLOCKS_PER_SEC; //calculate seconds passed

        clock_t start_intV_M = clock(); //start clock
        MergeSort(intV_M, 0, intV_M.size() - 1);
        clock_t end_intV_M = clock(); //end clock
        double elapsed_intV_M2 = double(end_intV_M - start_intV_M) / CLOCKS_PER_SEC;

        cout << "QuickSort Complete!" << endl;

        cout << "Second round of sorting complete!" << endl;

        //prints out all of the times separated by a comma to a csv file created in the beginning of the main function
        out << j << "," << elapsed_dataV_B << "," << elapsed_intV_B << "," << elapsed_dataV_S << "," << elapsed_intV_S
            << "," << elapsed_dataV_Q << "," << elapsed_intV_Q << "," << elapsed_dataV_M << "," << elapsed_intV_M
            << "," << elapsed_dataV_B2 << "," << elapsed_intV_B2 << "," << elapsed_dataV_S2 << "," << elapsed_intV_S2
            << "," << elapsed_dataV_Q2 << "," << elapsed_intV_Q2 << "," << elapsed_dataV_M2 << "," << elapsed_intV_M2;

    }

    return 0;
}
