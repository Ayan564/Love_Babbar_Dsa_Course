#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    // Attributes
        int id;
        int age;
        string name;
        int nos;
        float *gpa;

    // default constructor
    Student(){
        cout << "Student default constractor called" << endl;
    }

    // parameterized constructor
    Student(int id, int age, string name, int nos, float gpa){
        cout << "Student parameterized constractor called" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new float(gpa);
    }

    // copy constructor
    Student(const Student &srcobj){
        cout << "Student copy constractor called" << endl;
        id = srcobj.id;
        age = srcobj.age;
        name = srcobj.name;
        nos = srcobj.nos;
        gpa = new float(*(srcobj.gpa)); // deep copy
        // gpa = srcobj.gpa; // shallow copy
    }

    // Behaviours / Methods / Functions
    void study(){
        cout << name << " studying" << endl;
    }
    void sleep(){
        cout << name << " sleeping" << endl;
    }
    void bunk(){
        cout << name << " bunking" << endl;
    }

    // destructor
    ~Student(){
        cout << "Student default destructor called" << endl;
        delete gpa;
    }
};

int main(){
    // Student A;
    // A.id = 1;
    // A.age = 18;
    // A.name = "Ram";
    // A.nos = 5;
    // A.gpa = new float(9.5);
    // cout << *(A.gpa) << endl;
    // A.bunk();

    // Student B;
    // B.id = 2;
    // B.age = 20;
    // B.name = "Shaym";
    // B.nos = 6;
    // B.gpa = new float(7.8);
    // cout << *(B.gpa) << endl;
    // B.study();

    // Student *A = new Student();
    // A->id = 1;
    // A->age = 18;
    // A->name = "Ram";
    // A->nos = 5;
    // A->gpa = new float(6.7);
    // A->bunk();
    // Student *C = new Student(*A);
    // cout << C->gpa << endl;
    // cout << *(C->gpa) << endl;
    // C->sleep();
    // delete A;
    // delete C;

    Student *A = new Student(1, 19, "Ram", 6, 8.2);
    Student *C = new Student(*A);
    cout << A->name << " " << C->name << endl;
    cout << A->gpa << endl;
    cout << *(A->gpa) << endl;
    cout << C->gpa << endl;
    cout << *(C->gpa) << endl;
    A->bunk();
    delete A;
    delete C;

    return 0;
}