#include <iostream>


class Department
{
    std::string name;
    double* salaries = nullptr;
    unsigned int num_employees;
    
    public:
    Department() {}
    Department(unsigned int num_employees, std::string name, double* salaries) : num_employees(num_employees), name(name)
    {
        this->salaries = new double[num_employees];

        for (int i = 0; i < num_employees; i++)
        this->salaries[i] = salaries[i];
    }

    Department(const Department& other)
    {
        name = other.getName();
        num_employees = other.getNumEmployees();

        salaries = new double[num_employees];

        for (int i = 0; i < num_employees; i++)
        salaries[i] = other.getSalaries()[i];
    }

    Department& operator=(const Department& other)
    {
        if (&other == this)
        return *this;

        name = other.getName();
        num_employees = other.getNumEmployees();

        salaries = new double[num_employees];

        for (int i = 0; i < num_employees; i++)
        salaries[i] = other.getSalaries()[i];

        return *this;
    }

    ~Department()
    {
        delete [] salaries;
    }

    std::string getName() const
    {
        return name;
    }

    unsigned int getNumEmployees() const
    {
        return num_employees;
    }

    double* getSalaries() const
    {
        return salaries;
    }

    double getHighestSalary()
    {
        float highest = 0;

        for (int i = 0; i < num_employees; i++)
        {
            if (salaries[i] > highest)
            highest = salaries[i];
        }

        return highest;
    }

    double getAverage()
    {
        double average;

        for (int i = 0; i < num_employees; i++)
        average += salaries[i];

        average /= num_employees;

        return average;
    }
};

class Company
{
    Department* all_departments = nullptr;
    unsigned int num_department;

    public:
    Company() {}
    Company(unsigned int num_department, Department* all_departments) : num_department(num_department)
    {
        this->all_departments = new Department[num_department];

        for (int i = 0; i < num_department; i++)
        this->all_departments[i] = all_departments[i];
    }

    Company(const Company& other)
    {
        num_department = other.getNumDepartment();

        all_departments = new Department[num_department];

        for (int i = 0; i < num_department; i++)
        all_departments[i] = other.getDepartments()[i];
    }

    Company& operator=(const Company& other)
    {
        if (&other == this)
        return *this;

        num_department = other.getNumDepartment();

        all_departments = new Department[num_department];

        for (int i = 0; i < num_department; i++)
        all_departments[i] = other.getDepartments()[i];

        return *this;
    }

    ~Company()
    {
        delete [] all_departments;
    }

    Department* getDepartments() const
    {
        return all_departments;
    }

    unsigned int getNumDepartment() const
    {
        return num_department;
    }

    std::string getMaxAverage()
    {
        float max_average = 0;
        std::string department_name;

        for (int i = 0; i < num_department; i++)
        {
            if (all_departments[i].getAverage() > max_average)
            {
                max_average = all_departments[i].getAverage();
                department_name = all_departments[i].getName();
            }
            
        }

        return department_name;
    }
};

int main ()
{
    std::string name;
    unsigned int num_department, num_employees;
    Department* all_departments = nullptr;
    double* salaries = nullptr;

    std::cout << "Number of Departments: ";
    std::cin >> num_department;

    all_departments = new Department[num_department];

    for (int i = 0; i < num_department; i++)
    {
        std::cout << "\nDEPARTMENT " << i + 1 << std::endl;
        
        std::cout << "Number of Employees: ";
        std::cin >> num_employees;

        std::cout << "Department Name: ";
        std::cin >> name;

        salaries = new double[num_employees];

        for (int j = 0; j < num_employees; j++)
        {
            std::cout << "Employee " << j + 1 << " Salary: ";
            std::cin >> salaries[j]; 
        }
        
        all_departments[i] = Department(num_employees, name, salaries);
    }

    Company company(num_department, all_departments);

    for (int i = 0; i < company.getNumDepartment(); i++)
    std::cout << "\nDepartment " << i + 1 << ": " << company.getDepartments()[i].getHighestSalary();

    std::cout << "\n\nDepartment with Maximum Average Salary: " << company.getMaxAverage() << std::endl;

    delete [] all_departments;
    delete [] salaries;
}