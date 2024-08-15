#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    int id;
    int age;
    string name;
    int nos;
    float *gpa;
    string gf;

    void gfchatting(){
        cout << this->name << "chatting with gf" << endl;
    }

public:

    // set gpa (mutator)
    void setGpa(float gpa){
        // we can add a layer of authentication
        *this->gpa = gpa;
    }

    // get gpa (acesser)
    float getGpa() const{
        return *this->gpa;
    }

    // set age (mutator)
    void setAge(int age){
        this->age = age;
    }

    // get age (acesser)
    int getAge() const{
        return this->age;
    }

    // ctor1: default constructor
    Student(){
        cout << "Student default constructor called"<< endl;
    };

    // ctor2: parameterised constructor
    Student(int id, int age, string name, int nos, float gpa, string gf){
        cout << "Student parameterised constructor called"<< endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new float(gpa);
        this->gf = gf;
    };

    // ctor3: copy constructor
    Student(const Student &srcobj){
        cout << "Student copy constructor called"<< endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
        this->gf = srcobj.gf;
        this->gpa = new float(*(srcobj.gpa));
    }

    // behaviour / methods / functions
    void study(){
        cout << this->name << "studying" << endl;
    }
    void sleep(){
        cout << this->name << "sleeping" << endl;
    }
    void bunk(){
        cout << this->name << "bunking" << endl;
    }

    // dtor:
    ~Student(){
        cout << "Student default destructor called"<< endl;
        delete this->gpa;
    };
};

int main(){
    Student A(1, 18, "Rahul", 5, 8.4, "Menu");
    Student *C = new Student(A);
    cout << A.getGpa() << endl;
    A.setGpa(6);
    cout << A.getGpa() << endl;
    cout << A.getAge() << endl;
    A.setAge(20);
    cout << A.getAge() << endl;
    delete C;
    return 0;
}