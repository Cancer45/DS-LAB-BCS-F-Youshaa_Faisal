#include <iostream>

typedef struct Date
{
    unsigned int day, month, year;
    Date () {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    
}Date;

class Exam
{
    std::string* student_names;
    Date* exam_dates;
    float* scores;
    unsigned int num_students = 0;
    
    public:
    Exam() : student_names(nullptr), exam_dates(nullptr), scores(nullptr) {}
    ~Exam()
    {
        delete [] student_names;
        delete [] exam_dates;
        delete [] scores;
    }
    
    void newEntry (std::string student_name, Date exam_date, float score)
    {
        std::string* tmp_names = new std::string[num_students + 1];
        Date* tmp_dates = new Date[num_students + 1];
        float* tmp_scores = new float[num_students + 1];
    
        for (int i = 0; i < num_students; i++)
        {
            tmp_names[i] = student_names[i];
            tmp_dates[i] = exam_dates[i];
            tmp_scores[i] = scores[i];
        }
        
        tmp_names[num_students] = student_name;
        tmp_dates[num_students] = exam_date;
        tmp_scores[num_students] = score;

        if (student_names != nullptr)
        {
            delete [] student_names;
            delete [] exam_dates;
            delete [] scores;
        }
       
        student_names = tmp_names;
        exam_dates = tmp_dates;
        scores = tmp_scores;
        
        num_students++;
    }
    
    void printAll()
    {
        for (int i = 0; i < num_students; i++)
        {
            std::cout << "\nName: " << student_names[i] << std::endl;
            std::cout << "Date: " <<  exam_dates[i].day << "." << exam_dates[i].month << "." << exam_dates[i].year << std::endl;
            std::cout << "Score: " << scores[i] << std::endl;
        }
    }
};

int main ()
{
    Exam english_exam_p1;
    Date date1(12, 3, 2025);
    
    english_exam_p1.newEntry("Ahmad Reza", date1, 78);
    english_exam_p1.newEntry("Shahzaib Ali", date1, 61);
    english_exam_p1.newEntry("Hammad Chaudry", date1, 54);

    english_exam_p1.printAll();
    
    Exam english_exam_p2(english_exam_p1);
    
    //code causes segfault at the end as the second destructor is called on values already deleted since both objects have arrays that point to the same block in memory and when the program tries to access it again to try and free it a second time, the OS throws a segfault
}