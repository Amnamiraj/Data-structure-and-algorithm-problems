#include <iostream>
using namespace std;
int main()
{
    int age[10];
    // initilaze the array through for loop
    for (int i = 0; i < 10; i++) {
        cout << "Enter value at index " << i << ":";
        cin >> age[i];
    }
    cout << endl;
    // print the array
    cout << "Printing values of the array" << endl;
    for (int i = 0; i < 10; i++) {
        cout << age[i] << " ";
    }
    cout << endl;
    cout << endl;
    // updating values
    age[0] = 88;
    age[1] = 20;
    age[2] = 5;
    age[3] = 8;
    age[4] = 22;
    age[5] = 78;
    age[6] = 99;
    age[7] = 34;
    age[8] = 77;
    age[9] = 23;
    cout << "The values after updation in the age array" << endl;
    cout << age[0] << " ";
    cout << age[1] << " ";
    cout << age[2] << " ";
    cout << age[3] << " ";
    cout << age[4] << " ";
    cout << age[5] << " ";
    cout << age[6] << " ";
    cout << age[7] << " ";
    cout << age[8] << " ";
    cout << age[9] << " ";
}

