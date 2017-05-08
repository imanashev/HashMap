#pragma once
#include <list> 
#include <iostream>
#include <exception>

template <class K, class V>
class HashMap
{
private:
	std::list<V>* table_;
	int n_; //size
	int l_; //max lenght of all lists
public:
	HashMap(int n);
	void insert(K& key, V& value);
	bool remove(K& key);
	V& operator[](K&);
};


template<class K, class V>
inline HashMap<K, V>::HashMap(int n)
{
	n_ = (int)(n * 1.4);
	table_ = new std::list<V>[n_];
}

template<class K, class V>
void HashMap<K, V>::insert(K & key, V & value)
{
	int hash = std::hash<K>()(key) % n_;
	table_[hash].insert
}