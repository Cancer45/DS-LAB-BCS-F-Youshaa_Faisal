#include <iostream>

class Course
{
    std::string name;
    float marks;

    public:
    Course () : name("default"), marks(0) {}
    Course (std::string name, float marks) : name(name), marks(marks)
    {}

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
    Student (unsigned int num_courses) 
    {
        courses = new Course[num_courses];
    }

    float getAverage()
    {
        float average = 0;

        for (int i = 0; i < num_courses; i++)
        {
            average += courses[i].getMarks();
        }
    }
};

int main ()
{

}
