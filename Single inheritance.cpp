#include <iostream>
#include<string>
using namespace std;
// Parent class: employee
class employee {
    int reg_num;
    string name;
    string designation;
public:
    // Default Constructor
    employee() {
        cout << "This is the parent class!" << endl;
    }
    // Parameterized Constructor
    employee(int reg_num,string name,string designation){
        this->reg_num = reg_num;
        this->name = name;
        this->designation = designation;
    }
    // Function to input employee details
    void input(){
        cout << "Enter employee's registration number: ";
        cin >> reg_num;
        cin.ignore();
        cout << "Enter the employee's name: ";
        getline(cin, name);
        cout << "Enter the designation of employee: ";
        getline(cin, designation);
    }
    // Getter functions
    int get_reg_num(){
        return reg_num;
    }
    string get_name(){
        return name;
    }
    string get_designation(){
        return designation;
    }
};
// Single Inheritance Derived class: salary
// Visibility mode public
class salary:public employee {
    int hrc;
    int sal;
    int fund;
public:
    salary() {
        cout << "This is child class !" << endl;
    }
    // Parameterized Constructor for salary class
    salary(int reg_num, string name, string designation, int hrc,int sal,int fund): employee(reg_num, name, designation){
        this->hrc = hrc;
        this->sal = sal;
        this->fund = fund;
    }
   // Function to input salary details
    void input1() {
        cout << "Enter the human resource allowance: ";
        cin >> hrc;
        cout << "Enter the basic salary: ";
        cin >> sal;
        cout << "Enter the profitable fund: ";
        cin >> fund;
    }
   // Getter functions
    int get_hrc() const {
        return hrc;
    }
    int get_sal() const {
        return sal;
    }
    int get_fund() const {
        return fund;
    }
   // Function to display employee details and salary
    void display() {
        cout << "Employee's registration number: " << get_reg_num() << endl;
        cout << "Employee's name: " << get_name() << endl;
        cout << "Employee's designation: " << get_designation() << endl;
        cout << "Human resource allowance: " << hrc << endl;
        cout << "Basic salary: " << sal << endl;
        cout << "Profitable fund: " << fund << endl;
    }
   // Function to calculate and display the sum of salary components
    void sum() {
        int sum1 = hrc + sal + fund;
        cout << "The sum is: " << sum1 << endl;
    }
};

int main() {
    // Create object using parameterized constructor
    salary s1(678, "Amna Miraj", "Marketing manager", 3000, 20000, 1500);
   // Display employee details and salary
    s1.display();
   // Calculate and display sum of salary components
    s1.sum();

    return 0;
}
