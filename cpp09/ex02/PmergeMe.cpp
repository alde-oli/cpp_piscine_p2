#include "PmergeMe.hpp"

std::deque<int> PmergeMDeque(std::deque<int> d)
{
	std::deque<int> dA;
	std::deque<int> dB;

	int 			elem1;
	int 			elem2;

	if (d.size() < 3)
	{
		if (d.size() == 2 && d[0] > d[1])
		{
			int tmp = d[0];
			d[0] = d[1];
			d[1] = tmp;
		}
		return d;
	}
	

	while(d.size() > 1)
	{
		elem1 = d.front();
		d.pop_front();
		elem2 = d.front();
		d.pop_front();
		if (elem1 > elem2)
		{
			dA.push_back(elem2);
			dB.push_back(elem1);
		}
		else
		{
			dA.push_back(elem1);
			dB.push_back(elem2);
		}
	}

	if (d.size() == 1)
	{
		dA.push_back(d.front());
		d.pop_front();
	}
	

	if (dA.size() > 1)
		dA = PmergeMDeque(dA);
	if (dB.size() > 1)
		dB = PmergeMDeque(dB);


	while (dB.size() && dA.size())
	{
		if (dA.front() > dB.front())
		{
			d.push_back(dB.front());
			dB.pop_front();
		}
		else
		{
			d.push_back(dA.front());
			dA.pop_front();
		}
	}

	while (dA.size())
	{
		d.push_back(dA.front());
		dA.pop_front();
	}
	while (dB.size())
	{
		d.push_back(dB.front());
		dB.pop_front();
	}


	return (d);
}

std::deque<int> parseInputDeque(int argc, char* argv[])
{
	std::deque<int>	result;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("invalid number");
		int value = std::atoi(arg.c_str());
		for (std::deque<int>::iterator it = result.begin(); it != result.end(); ++it)
			if (*it == value)
				throw std::invalid_argument("duplicate");
		result.push_back(value);
	}
	return result;
}


std::vector<int> PmergeMVector(std::vector<int> v)
{
	std::vector<int>	vA;
	std::vector<int>	vB;

	int					elem1;
	int					elem2;

	if (v.size() < 3)
	{
		if (v.size() == 2 && v[0] > v[1])
		{
			int tmp = v[0];
			v[0] = v[1];
			v[1] = tmp;
		}
		return v;
	}


	while(v.size() > 1)
	{
		elem1 = v.front();
		v.erase(v.begin());
		elem2 = v.front();
		v.erase(v.begin());

		if (elem1 > elem2)
		{
			vA.push_back(elem2);
			vB.push_back(elem1);
		}
		else
		{
			vA.push_back(elem1);
			vB.push_back(elem2);
		}
	}

	if (v.size() == 1)
	{
		vA.push_back(v.front());
		v.erase(v.begin());
	}
	

	if (vA.size() > 1)
		vA = PmergeMVector(vA);
	
	if (vB.size() > 1)
		vB = PmergeMVector(vB);


	while (!vA.empty() && !vB.empty())
	{
		if (vA.front() > vB.front())
		{
			v.push_back(vB.front());
			vB.erase(vB.begin());
		}
		else
		{
			v.push_back(vA.front());
			vA.erase(vA.begin());
		}
	}

	while (!vA.empty())
	{
		v.push_back(vA.front());
		vA.erase(vA.begin());
	}
	while (!vB.empty())
	{
		v.push_back(vB.front());
		vB.erase(vB.begin());
	}


	return v;
}

std::vector<int> parseInputVector(int argc, char* argv[])
{
	std::vector<int> result;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("invalid argument");
		int value = std::atoi(arg.c_str());
		for (size_t j = 0; j < result.size(); ++j)
			if (result[j] == value)
				throw std::invalid_argument("duplicate");
		result.push_back(value);
	}
	return result;
}
