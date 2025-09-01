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
    std::string name;
    Course* courses = nullptr;
    unsigned int num_courses;

    public:
    Student () {}
    Student (std::string name, unsigned int num_courses, Course* courses) : name(name), num_courses(num_courses)
    {
        this->courses = new Course[num_courses];

        for (int i = 0; i < num_courses; i++)
        this->courses[i] = courses[i];
    }

    ~Student()
    {
        delete [] courses;
    }

    float getAverage()
    {
        float average = 0;

        for (int i = 0; i < num_courses; i++)
        {
            average += courses[i].getMarks();
        }
        
        average /= num_courses;
        return average;
    }
    
    std::string getName()
    {
        return name;
    }
};

//NOTE: When inputting strings, do not use spaces. Keep Student names and Course names to a single word
int main ()
{
    Student* students = nullptr;
    Course* courses = nullptr;
    
    std::string student_name, course_name;
    unsigned int num_courses, num_students;
    float marks;

    std::cout << "Number of Students: ";
    std::cin >> num_students;

    students = new Student[num_students];
    
    for (int i = 0; i < num_students; i++)
    {
        std::cout << "Student Name: ";
        std::cin >> student_name;

        std::cout << "Number of Courses: ";
        std::cin >> num_courses;

        courses = new Course[num_courses];

        for (int j = 0; j < num_courses; j++)
        {
            std::cout << "Course " << j + 1 << " Name: ";
            std::cin >> course_name;
            
            do
            {
                std::cout << "Marks (out of 100): ";
                std::cin >> marks;    
            }while(marks < 0 && marks > 100);
            
            courses[j] = Course(course_name, marks);
        }

        students[i] = Student(student_name, num_courses, courses);
        
        delete [] courses;
    }

    std::cout << "\nAVERAGES\n";
    for (int i = 0; i < num_students; i++)
    std::cout << students[i].getName() << ": " << students[i].getAverage() << std::endl;

    delete [] students;
    delete [] courses;
}