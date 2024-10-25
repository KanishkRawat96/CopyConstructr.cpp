#include <iostream>
using namespace std;

class ArraySum {
private:
    int *arr;
    int size;
    int sum;

public:
    // Parameterized constructor to initialize array
    ArraySum(int *inputArr, int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }
        sum = 0;
    }

    // Copy constructor to calculate sum of positive numbers
    ArraySum(const ArraySum &obj) {
        size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
            if (arr[i] > 0) {
                sum += arr[i];
            }
        }
    }

    // Function to display the sum
    void displaySum() const {
        cout << "Sum of all positive numbers in the array: " << sum << endl;
    }

    // Destructor to release allocated memory
    ~ArraySum() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *inputArr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> inputArr[i];
    }

    // Creating an object with parameterized constructor
    ArraySum originalArray(inputArr, size);

    // Creating a copy of the object using the copy constructor
    ArraySum sumArray(originalArray);

    // Displaying the sum of positive numbers
    sumArray.displaySum();

    // Free the dynamically allocated array
    delete[] inputArr;

    return 0;
}
