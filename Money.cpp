#include <map>
class Money {
	
public:
	Money() {}


public:
	
	int v;
	std::map<int, int> m;
	enum moneyType {penny, cent, dollar};

	void print(moneyType t) const;
	
};


void Money::print(moneyType t) const
{
	int total;
	for (std::map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
		total += v;
}