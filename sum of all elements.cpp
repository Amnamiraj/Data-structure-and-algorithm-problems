#include <iostream>
using namespace std;
int main()
{
    int age[10];
    // initilaze the array through for loop
    for (int i = 0; i < 10; i++) {
        cout << "Enter value at index " << i << ": ";
        cin >> age[i];
    }
    cout << endl;
    // print the array
    cout << "Printing all elements of an array" << endl;
    for (int i = 0; i < 10; i++) {
        cout << age[i] << " ";
    }
    cout << endl;
    cout << endl;
    // sum of all elements of an array
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += age[i];
    }
    cout << "The sum of all elements of array is:" << sum << endl;
}

