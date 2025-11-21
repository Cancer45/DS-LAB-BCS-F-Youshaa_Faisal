#include <iostream>
#include <vector>

class Runner
{
	public:
	std::string name;
	int time;

	void display()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Time: " << time << "\n" << std::endl;
	}
};

void merge (std::vector<Runner>& input, int start, int end, int mid)
{
	std::vector<Runner> tmp1(input.begin() + start, input.begin() + mid + 1);
	std::vector<Runner> tmp2(input.begin() + mid + 1, input.begin() + end + 1);
	int i = 0, j = 0, k = start;

	int tmp1_size = tmp1.size();
	int tmp2_size = tmp2.size();
	
	//merge
	while(i < tmp1_size && j < tmp2_size)
	{
		if (tmp1[i].time <= tmp2[j].time)
		input[k++] = tmp1[i++];

		else if (tmp1[i].time > tmp2[j].time)
		input[k++] = tmp2[j++];
		
	}

	//leftovers
	while(j < tmp2_size)
	input[k++] = tmp2[j++];
	

	while(i < tmp1_size)
	input[k++] = tmp1[i++];
	
}

void mergeSort(std::vector<Runner>& input, int start, int end)
{
	if (start == end)
	return;

	int mid = (start + end) / 2;

	//call merge
	mergeSort(input, start, mid);
	mergeSort(input, mid + 1, end);

	merge(input, start, end, mid);
}

int main ()
{
	int num_runners;
	std::cout << "number of runners: ";
	std::cin >> num_runners;

	std::vector<Runner> runners(num_runners);

	for (int i = 0; i < num_runners; i++)
	{
		std::cout << "RUNNER " << i + 1 << std::endl;

		std::cout << "Name: ";
		std::cin >> runners[i].name;

		std::cout << "Time: ";
		std::cin >> runners[i].time;
	}

	mergeSort(runners, 0, runners.size() - 1);

	for (int i = 0; i < 5 && i < num_runners; i++)
	{
		runners[i].display();
	}
}