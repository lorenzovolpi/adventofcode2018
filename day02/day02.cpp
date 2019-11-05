#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::string diff(std::string s1, std::string s2)
{
	std::string res;
	for (int i = 0, j = 0; i < s1.length() && j < s2.length(); ++i, ++j)
	{
		if (s1[i] == s2[j]) res.push_back(s1[i]);
	}

	return res;
}

int main()
{
	std::vector<std::string> arr;

	//Part 1
	std::ifstream in;
	int sum2 = 0, sum3 = 0;
	in.open("data/input01.txt");
	while (!in.eof())
	{
		std::string s;
		std::getline(in, s);
		arr.push_back(std::string(s));
		std::sort(s.begin(), s.end(), [](char c1, char c2)
			{
				return (int)c1 < (int)c2;
			});
		
		bool s2 = false, s3 = false;
		int cnt = 0;
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i] == s[i - 1]) cnt++;
			else
			{
				if (cnt == 1) s2 = true;
				if (cnt == 2) s3 = true;
				cnt = 0;
			}
		}
		if (cnt == 1) s2 = true;
		if (cnt == 2) s3 = true;

		if (s2) sum2++;
		if (s3) sum3++;
	}

	std::cout << "Part 1: " << sum2 * sum3 << std::endl;

	//Part 2
	bool found = false;
	for (int i = 0; i < arr.size() && !found; ++i)
	{
		for (int j = 0; j < i && !found; ++j)
		{
			std::string r = diff(arr[i], arr[j]);
			if (r.length() == arr[i].length() - 1)
			{
				std::cout << "Part 2: " << r << std::endl;
				found = true;
			}
		}
	}

}

