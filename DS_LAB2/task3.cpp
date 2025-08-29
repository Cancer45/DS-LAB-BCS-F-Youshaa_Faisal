#include <iostream>

class Course
{
    std::string name;
    float marks;

    public:
    Course () {}
    Course (std::string name, float marks) : name(name), marks(marks) {}

    void setMarks(float new_marks)
    {
        if (new_marks > 100 || new_marks < 0)
        {
            std::cout << "input marks between 0 and 100\ntry again\n";
            return;
        }

        marks = new_marks;
    }

    float getMarks ()
    {
        return marks;
    }
};

class Student
{
    Course* courses = nullptr;
    unsigned int num_courses;

    Student () {}
    Student (unsigned int num_courses) {}
};

int main ()
{

}
