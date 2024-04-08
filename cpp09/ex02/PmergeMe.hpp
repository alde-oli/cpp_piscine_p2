#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <string>
# include <deque>
# include <vector>
# include <iterator>
# include <set>
# include <stdexcept>

std::deque<int> PmergeMDeque(std::deque<int> d);
std::deque<int> parseInputDeque(int argc, char* argv[]);
std::vector<int> PmergeMVector(std::vector<int> v);
std::vector<int> parseInputVector(int argc, char* argv[]);

#endif