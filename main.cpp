#include <iostream>
class Course{
    std::string name ;
    int unit;
    double* mark;
public:
    Course();
    Course(const Course& c);
    ~Course();
    void set();
    void get();
};
class Person{
protected:
    std::string firstName ;
    std::string lastName ;
    std::string id ;
    double* workHours;
public:
    Person(std::string  , std::string , std::string , double );
    Person(const Person& p);
    ~Person();
    void setFirstName(const std::string &firstName) {
        this->firstName=firstName;
    }
    void setLastName(const std::string &lastName) {
        this->lastName=lastName;
    }
    void setId(const std::string &id) {
        this->id=id;
    }
    void setWorkHours(const double &workHours) {
        *(this->workHours)=workHours;
    }
    std::string getFirstName() {
        return firstName;
    }
    std::string getLastName() {
        return lastName;
    }
    std::string getId() {
        return id;
    }
    friend std::ostream& operator << (std::ostream& strm, const Person& p){
        strm<<"first name: "<<p.firstName<<std::endl
        <<"last name:"<<p.lastName<<std::endl<<"id:"<<p.id<<std::endl
        <<"work hours: "<<*p.workHours<<std::endl;
        return strm;
    }
   /* friend std::istream& operator >> (std::istream& strm, const Person& p){
        strm<<"first name: "<<p.firstName<<std::endl
            <<"last name:"<<p.lastName<<std::endl<<"id:"<<p.id<<std::endl
            <<"work hours: "<<*p.workHours<<std::endl;
        return strm;
    }*/
    virtual double calculateSalary(double workHours){
        int payPerHour=1000;
        double salary=workHours*payPerHour;
        return salary;
    }
};
Person::Person(std::string  firstName, std::string lastName, std::string id, double workHours) {
    this->firstName= firstName;
    this->lastName=lastName;
    this->id=id;
    this->workHours=new double;
    *(this->workHours)=workHours;
    }
Person::Person(const Person &p) {
    firstName=p.firstName;
    lastName=p.lastName;
    id=p.id;
    workHours=new double;
    workHours=(p.workHours);
}
Person::~Person() {
    delete workHours;
}

class Student:public Person{
private:
    Course* courses ;
    std::string FieldOfStudy ;
    int numOfCourses;
public:
    Student(std::string  , std::string , std::string , double ,Course* ,std::string ,int);
    Student(const Person &p, const Student &s);
    ~Student();
    /*friend std::ostream& operator << (std::ostream& strm, const Student& s){
        strm<<"first name: "<<s.firstName<<std::endl
            <<"last name:"<<s.lastName<<std::endl<<"id:"<<s.id<<std::endl
            <<"work hours: "<<*s.workHours<<std::endl;
        return strm;
    }
     friend std::istream& operator >> (std::istream& strm, const Person& p){
         strm<<"first name: "<<p.firstName<<std::endl
             <<"last name:"<<p.lastName<<std::endl<<"id:"<<p.id<<std::endl
             <<"work hours: "<<*p.workHours<<std::endl;
         return strm;
     }*/

double gpa();
    double calculateSalary(double workHours,double grade){
            int payPerHour=20000;
            double salary=workHours*payPerHour;
        if(grade<17){
            return salary;}
        else if(grade>17){
            std::cout<<"Estedade Derakhshan"<<std::endl;
            double salary2=salary+(salary*0.1);
            return salary2;
        }
    }
    void setCourses(const Course &courses) {
//        this->courses=courses;
    }
    void setFieldOfStudy(const std::string &FieldOfStudy) {
        this->FieldOfStudy=FieldOfStudy;
    }
    void setNumberOfCourses(const std::string &numOfCourses) {
        this->FieldOfStudy=FieldOfStudy;
    }
    Course getCourses(){
        return *courses;
    }
    std::string getFieldOfStudy() {
        return FieldOfStudy;
    }
    int getNumOfCourses(){
        return numOfCourses;
    }

};
Student::Student(const Person &p, const Student &s) : Person(p) {
    firstName=s.firstName;
    lastName=s.lastName;
    id=s.id;
    courses=s.courses;
    FieldOfStudy=s.FieldOfStudy;
    numOfCourses=s.numOfCourses;
    workHours=new double;
    workHours=(s.workHours);
}
Student::~Student() {
    delete workHours;
}
class Professor:public Person {
private:
    std::string title;
public:
    Professor();

    double calculateSalary(double workHours, int title, double yearsOfWorkExperience) {
        int payPerHour = 50000;
        double salary = (payPerHour * workHours) + (title * 10000) + (yearsOfWorkExperience * 2000);
        return salary;
    }
    };
class University{
public:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    std::string *Professor;
    std::string *Student;
    University();
    University(const University& u);
    ~University();
};
    int main() {

        return 0;
    }
