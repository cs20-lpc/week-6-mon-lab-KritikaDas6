#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i = 0);



/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays, one fixed and the other
 * random. Determines the maximum value by calling the local function and the
 * standard function.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i){
    if(i==SIZE-1){
        return arr[i];
    }

    T max = findMaxRecTail(arr, SIZE, i+1); //gets what is - a for loop
    if(max<arr[i]){
        return arr[i];
    }
    return max;


}


// The `findMaxRecTail` function has 3 parameters:

// 1. `arr` - a constant array containing the elements
// 2. `SIZE` - a constant integer that holds the number of elements in `arr`
// 3. `i` - an integer that represents the current position of the "head" of `arr`, with a default value of 0

// To continue practicing how to analyze code, you are suggested to perform a time complexity analysis. You can do so as a comment block above the function.


int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}
