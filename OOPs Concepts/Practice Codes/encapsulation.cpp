#include<iostream>
#include<string>
using namespace std;

class Student
{
private:

    /* data */
    int *gpa;
    string gf;
    
    /* data */
    int id;
    int age;
    string name;
    int nos;

    void gfchatting(){
        cout << this->name << "chatting with gf" << endl;
    }

public:

    // set gpa (mutator)
    void setGpa(int gpa){
        // we can add a layer of authentication
        *this->gpa = gpa;
    }

    // get gpa (acesser)
    int getGpa() const{
        return *this->gpa;
    }

    // get aget (acesser)
    int getAge() const{
        return this->age;
    }

    // ctor1: default constructor
    Student(){
        cout << "Student default constructor called"<< endl;
    };

    // ctor2: parameterised constructor
    Student(int id, int age, string name, int nos, int gpa, string gf){
        cout << "Student parameterised constructor called"<< endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new int(gpa);
        this->gf = gf;
    };

    // ctor3: copy constructor
    Student(const Student &srcobj){
        cout << "Student parameterised constructor called"<< endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
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
    return 0;
}