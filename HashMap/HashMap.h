#pragma once
#include <list> 
#include <iostream>
#include <exception>

template <class K, class V>
class HashMap
{
private:
	std::list<std::pair<K,V>>* table_;
	int size_; //size
	int n_; //count of elements
	void rehash();
public:
	HashMap(int size);

	void insert(K& key, V& value);
	bool remove(K& key);
	V& operator[](K& key);
	double getLoad();
};

template<class K, class V>
void HashMap<K, V>::rehash()
{
	std::list<std::pair<K, V>>* tmp;
	tmp = new std::list<std::pair<K, V>>[size_ * 2];
	for (int i = 0; i < size_; ++i)
	{
		while (!table_[i].empty())
		{
			std::pair<K, V> cur = table_[i].front();
			int hash = std::hash<K>()(cur.first) % (size_ * 2);
			tmp[hash].push_front(cur);
			table_[i].pop_front();
		}
	}
	delete[] table_;
	table_ = tmp;
	size_ *= 2;

	//std::cout << "WOW! It's rehashing!!!" << std::endl;
	//std::cout << "size_ = " <<  size_ << std::endl;
	//std::cout << "n_ = " << n_ << std::endl<< std::endl;
}

template<class K, class V>
inline HashMap<K, V>::HashMap(int size)
{
	size_ = size;
	table_ = new std::list<std::pair<K, V>>[size_];
	n_ = 0;
}

template<class K, class V>
void HashMap<K, V>::insert(K & key, V & value)
{
	int hash = std::hash<K>()(key) % size_;
	table_[hash].push_front(std::make_pair(key, value));
	n_ += 1;
	if (n_ > 1.33 * size_)
	{
		rehash();
	}	
}

template<class K, class V>
bool HashMap<K, V>::remove(K & key)
{
	int hash = std::hash<K>()(key) % size_;

	for (auto it = table_[hash].begin(); it != table_[hash].end(); ++it)
	{
		if (it->first == key)
		{
			//delete
			table_[hash].erase(it);
			n_ -= 1;
			return true;
		}
	}

	return false;
}

template<class K, class V>
V & HashMap<K, V>::operator[](K & key)
{
	int hash = std::hash<K>()(key) % size_;

	for (auto it = table_[hash].begin(); it != table_[hash].end(); ++it)
	{
		if (it->first == key)
		{
			return it->second;
		}
	}

	std::cout << "Not found" << std::endl;
	//throw "Not found";

}

template<class K, class V>
inline double HashMap<K, V>::getLoad()
{
	return n_ / (double)size_;
}