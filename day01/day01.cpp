#include <iostream>
#include <fstream>
#include <map>

int main()
{
	int x = 0, sum = 0;
	std::ifstream in;
	in.open("data/input01.txt");
	while (!in.eof())
	{
		in >> x;
		sum += x;
	}
	in.close();

	std::cout << "Part 1: " << sum << std::endl;

	std::map<int, int> d;
	bool found = false;
	sum = 0;
	
	in.open("data/input01.txt");
	while (!found)
	{
		while (!in.eof() && !found)
		{
			in >> x;
			sum += x;
			if (d.count(sum)) found = true;
			else d.insert(std::pair<int, int>(sum, 1));
		}
		in.clear();
		in.seekg(0, in.beg);
	}
	in.close();

	std::cout << "Part 2: " << sum << std::endl;
}
