#include <iostream>

class DayTemp
{
    unsigned int num_samples;
    float* temps = nullptr;

    public:
    DayTemp() : num_samples(0) {}
    DayTemp(unsigned int num_samples, float* temps) : num_samples(num_samples)
    {
        this->temps = new float[num_samples];

        for (int i = 0; i < num_samples; i++)
        this->temps[i] = temps[i];
    }

    DayTemp(const DayTemp& other)
    {
        num_samples = other.getNumSamples();

        temps = new float[num_samples];

        for (int i = 0; i < num_samples; i++)
        this->temps[i] = other.temps[i];
    }

    DayTemp& operator=(const DayTemp& other)
    {
        if (this == &other)
        return *this;

        num_samples = other.getNumSamples();

        temps = new float[num_samples];

        for (int i = 0; i < num_samples; i++)
        this->temps[i] = other.temps[i];

        return *this;
    }

    ~DayTemp()
    {
        delete [] temps;
    }

    unsigned int getNumSamples() const
    {
        return num_samples;
    }

    float getAverage()
    {
        float average = temps[0];

        for (int i = 1; i < num_samples; i++)
        average += temps[i];

        average /= num_samples;

        return average;
    }
};

class TrackingPeriod
{
    //length in days
    unsigned int length;
    DayTemp* days = nullptr;

    public:
    TrackingPeriod(unsigned int length, DayTemp* days) : length(length)
    {
        this->days = new DayTemp[length];

        for (int i = 0; i < length; i++)
        this->days[i] = days[i];
    }

    ~TrackingPeriod()
    {
        delete [] days;
    }

    DayTemp* getDays()
    {
        return days;
    }

    unsigned int getLength()
    {
        return length;
    }

    unsigned int getHottest()
    {
        float max_temp = days[0].getAverage();
        unsigned int hottest = 0;

        for (int i = 1; i < length; i++)
        {
            if (max_temp < days[i].getAverage())
            {
                max_temp = days[i].getAverage();
                hottest = i;
            }
            
        }
        
        return hottest + 1;
    }

    unsigned int getColdest()
    {
        float min_temp = days[0].getAverage();
        unsigned int coldest = 0;
        
        for (int i = 1; i < length; i++)
        {
            if (min_temp > days[i].getAverage())
            {
                min_temp = days[i].getAverage();
                coldest = i;
            }
            
        }

        return coldest + 1;
    }
};

int main ()
{
    unsigned int num_days, num_samples;
    float* temps = nullptr;
    DayTemp* days = nullptr;

    std::cout << "Number of Days: ";
    std::cin >> num_days;
    days = new DayTemp[num_days];

    std::cout << "Readings per Day: ";
    std::cin >> num_samples;
    temps = new float[num_samples];

    for (int i = 0; i < num_days; i++)
    {
        std::cout << "\nDAY " << i + 1 << std::endl;
        for (int j = 0; j < num_samples; j++)
        {
            std::cout << "Sample " << j + 1 << ": ";
            std::cin >> temps[j];
        }

        days[i] = DayTemp(num_samples, temps);
    }

    TrackingPeriod tp(num_days, days);

    std::cout << "\nAVERAGE TEMPERATURE" << std::endl;
    for (int i = 0; i < tp.getLength(); i++)    
    std::cout << "Day " << i + 1 << ": " << tp.getDays()[i].getAverage() << std::endl;

    std::cout << "Hottest Day: " << tp.getHottest() << std::endl;
    std::cout << "Coldest Day: " << tp.getColdest() << std::endl;

    delete [] temps;
    delete [] days;
}