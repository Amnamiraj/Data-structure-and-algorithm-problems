#include <iostream>
using namespace std;

class course {
    string name;
    int publication_date;
public:
    course() {
        name = "";
        publication_date = 0;
    }
    course(string name, int publication_date) {
        this->name = name;
        this->publication_date = publication_date;
    }
    void display() {
        cout << "Name of the course: " << name << endl;
        cout << "Publication date: " << publication_date << endl;
    }
    string get_name() {
        return name;
    }
    int get_publication_date() {
        return publication_date;
    }
};
class teacher {
    string name;
    int ID;
    course course_name;
public:
    teacher() {
        name="";
        ID=0;
    }
    teacher(string name,int ID,course course_name) {
        this->name = name;
        this->ID = ID;
        this->course_name = course_name;
    }
    string get_name() {
        return name;
    }
    int get_ID() {
        return ID;
    }
    void show() {
        cout << "Teacher name:" << name << endl;
        cout << "Teacher ID:" << ID << endl;
        course_name.display();
    }
};
int main()
{
    course course_name("Linear algebra", 2024);
    teacher t("Ahmad raza", 1150, course_name);
    t.show();
}
