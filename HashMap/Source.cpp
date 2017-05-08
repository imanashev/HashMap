#include <iostream>
#include "HashMap.h"
#include <string>

using namespace std;
void main()
{
	HashMap<std::string,std::string> dict(1000);

	for (int i = 0; i < 1000; ++i)
	{
		std::string a, b;
		a = "key" + std::to_string(i);
		b = "value" + std::to_string(i);
		dict.insert(a, b);
	}

	cout << "Load factor:" << dict.getLoad() << endl;
	//std::string input;
	//while (getline(std::cin, input))
	//{
	//	cout << dict[input] << endl;
	//}
	
	for (int i = 0; i < 1000; ++i)
	{
		std::string a;
		a = "key" + std::to_string(i);
		cout << dict[a] << endl;
		dict.remove(a);
	}
	cout << "Load factor:" << dict.getLoad() << endl;
}