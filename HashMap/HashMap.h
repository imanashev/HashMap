#pragma once
#include <list> 
#include <iostream>
#include <exception>

#define SIZE_KOEF 1.4 //How much reserv
#define MAX_LOAD_FACTOR 5 //max load factor for rehash

template <class K, class V>
class HashMap
{
private:
	std::list<std::pair<K,V>>* table_;
	int n_; //size
	int l_; //max lenght of all lists - load factor
	void rehash();
public:
	HashMap(int n);

	void insert(K& key, V& value);
	bool remove(K& key);
	V& operator[](K& key);
	int getLoad();
};


template<class K, class V>
inline HashMap<K, V>::HashMap(int n)
{
	n_ = (int)(n * SIZE_KOEF);
	table_ = new std::list<std::pair<K, V>>[n_];
	l_ = 0;
}

template<class K, class V>
void HashMap<K, V>::insert(K & key, V & value)
{
	int hash = std::hash<K>()(key) % n_;
	table_[hash].push_front(std::make_pair(key, value));
	if (table_[hash].size() > l_)
	{
		l_ = (int)table_[hash].size();
		if (l_ > MAX_LOAD_FACTOR)
		{
			rehash();
		}
	}

	
}

template<class K, class V>
bool HashMap<K, V>::remove(K & key)
{
	int hash = std::hash<K>()(key) % n_;

	for (auto it = table_[hash].begin(); it != table_[hash].end(); ++it)
	{
		if (it->first == key)
		{
			//delete
			table_[hash].erase(it);
			return true;
		}
	}

	return false;
}

template<class K, class V>
V & HashMap<K, V>::operator[](K & key)
{
	int hash = std::hash<K>()(key) % n_;

	for (auto it = table_[hash].begin(); it != table_[hash].end(); ++it)
	{
		if (it->first == key)
		{
			return it->second;
		}
	}

	std::cout << "Not found" << std::endl;
	//TODO
	//return it->second;

}

template<class K, class V>
inline int HashMap<K, V>::getLoad()
{
	return l_;
}