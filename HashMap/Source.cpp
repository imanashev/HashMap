#include <iostream>
#include "HashMap.h"
#include <string>

using namespace std;
void main()
{
	HashMap<std::string,std::string> dict(100);

	//Вставка
	for (int i = 0; i < 1000; ++i)
	{
		std::string a, b;
		a = "key" + std::to_string(i);
		b = "value" + std::to_string(i);
		dict.insert(a, b);
	}

	//Поиск
	/*std::string input;
	cout << "Search: ";
	while (getline(std::cin, input))
	{
		cout << "Result: " << dict[input] << endl;
		cout << "Search: ";
	}*/
	
	//Удаление
	/*for (int i = 0; i < 100; ++i)
	{
		std::string a;
		a = "key" + std::to_string(i);
		dict.remove(a);
	}*/
	cout << "Load factor:" << dict.getLoad() << endl;
}