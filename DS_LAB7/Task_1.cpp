#include <iostream>
#include <vector>

class StudentNode
{
	public:
	int score;
    std::string name;
	StudentNode* next = nullptr;

    StudentNode(int score, std::string name) : score(score) {}
    StudentNode() {}
};

class List
{
    public:
    StudentNode* head = nullptr;
    StudentNode* tail = nullptr;

    void addToTail(int score, std::string name)
    {
        StudentNode* new_node = new StudentNode(score, name);

        if (!head)
        head = new_node;

        else
        tail->next = new_node;

        tail = new_node;
    }

    StudentNode* deleteFromHead()
    {
        if (!head)
        return nullptr;

        StudentNode* tmp = head;
        head = head->next;

        delete tmp;
        return head;
    }
};

class Student
{
    public:
    std::string name;
    int score;

    void takeInput()
    {
        std::cout << "Name: ";
        std::cin >> name;

        std::cout << "Score: ";
        std::cin >> score;
    }

    void display()
    {
        std::cout << name << " " << score << std::endl;
    }
};

int intLength(int input)
{
    int i = 1;
    while(input >= 10)
    {
        input /= 10;
        i++;
    }

    return i;
}

int getNthDigit(int num, int n)
{
    int divisor = 1;

    for (int i = 0; i < n; i++)
    divisor *= 10;

    return (num / divisor) % 10;
}

void radixSort(std::vector<Student>& input)
{
    int vec_size = input.size(), max_length = 0, curr_length;
    List* buckets = new List[10];
    
    //get greatest length
    for (int i = 1; i < vec_size; i++)
    {
        curr_length = intLength(input[i].score);

        if (curr_length > max_length)
        max_length = curr_length;
    }

    for (int i = 0; i < max_length; i++)
    {
        //fill buckets
        for (int j = 0; j < vec_size; j++)
        buckets[getNthDigit(input[j].score, i)].addToTail(input[j].score, input[j].name);
        
        int bucket_count = 0;
        StudentNode* curr = nullptr;
        //refill array
        for (int j = 0; j < vec_size; j++)
        {
            while(!curr && bucket_count < 10)
            curr = buckets[bucket_count++].head;

            input[j].score = curr->score;
            input[j].name = curr->name;
            curr = buckets[bucket_count - 1].deleteFromHead();
        }

    }
}

bool binarySearch(const std::vector<Student>& input, Student student, int start, int end)
{
    if (start > end) return false;

    int mid = start + ((end - start) / 2);

    if (student.score < input[mid].score)
    return binarySearch(input, student, start, mid - 1);

    if (student.score > input[mid].score)
    return binarySearch(input, student, mid + 1, end);

    return student.name == input[mid].name;
}

int main ()
{
    unsigned int num_student;
    std::cout << "number of students: ";
    std::cin >> num_student;
    std::vector<Student> students(num_student);

    std::cout << "INPUT STUDENTS\n";
    for (int i = 0; i < num_student; i++)
    students[i].takeInput();
    std::cout << std::endl << "SEARCH\n";

    Student student;    

    std::cout << "Name: ";
    std::cin >> student.name;

    std::cout << "Score: ";
    std::cin >> student.score;

    if (binarySearch(students, student, 0, students.size() - 1))
    {
        for (int i = 0; i < students.size(); i++)
        students[i].display();
    }
}