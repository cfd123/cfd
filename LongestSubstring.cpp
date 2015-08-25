#include <iostream>
#include <string>
using std::cout; using std::string; using std::endl;

#include <cmath>
using std::max;

#include <unordered_set>
using std::unordered_set;

#include <string>
using std::string;

int lengthOfLongestSubstring(string s) 
{
	if (s.empty())
		return 0;
	unordered_set<char> set;
	int maxLength = 0;
	int leftTraversal = 0;
	int rightTraversal = 0;
	while (rightTraversal != s.size())
	{
		if (set.count(s[rightTraversal]))
		{
			if (maxLength < rightTraversal - leftTraversal)
			{
				maxLength = rightTraversal - leftTraversal;
			}
			while (s[leftTraversal] !=  s[rightTraversal])
			{
				set.erase(s[leftTraversal]);
				++leftTraversal;
			}
			++leftTraversal;
		}
		else
		{
			set.insert(s[rightTraversal]);
		}
		++rightTraversal;
	}
	maxLength = max(maxLength, (rightTraversal - leftTraversal));
	return maxLength;
}
int main()
{
	string str = "qpxrjxkltzyx";
	cout << lengthOfLongestSubstring(str) << endl;
	return 0;
}