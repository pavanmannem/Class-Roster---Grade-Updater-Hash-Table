#pragma once
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
	int key; // UIN
	T value; // grade
public:
	Node (int k = 0, T v = 0): key(k), value(v) {}
	int getKey() { return key; } 
	T getValue() { return value; } 
	T* getValueRef() { return &value; } 
};



//templated class for multiple data types
template<typename T>
class HashTable {
private:
	int size;
	//vector container for linkedlist of custom node (key, value) type
	//list data structure allows creates chaining for collisions 
	vector<list<Node<T>>> table;

    int hash(const int _key) {
        return _key % size;
    }
public:
    HashTable(const int _size) {
		size = _size;
		table.resize(size);
    }
	
	~HashTable(){
		//stl handles deconstruction 
	}
    
    void insert(const int _key, T _value) {

		int idx = hash(_key);
		Node<T> newNode(_key, _value);
		table.at(idx).push_back(newNode);

    }


	T* search(int _key) {
		int idx = hash(_key);
		for (auto i : table.at(idx)) {
			if (i.getKey() == _key) {
				return i.getValueRef();
			}
		}
		return nullptr;
		
	} 

	int minChainLen(){
		int minChain = 9999;
		for (int i = 0; i < table.size(); i++) {
			if (table.at(i).size() < minChain)
				minChain = table.at(i).size();

		}
		return minChain;
	}
	
	int maxChainLen(){
		int maxChain = 0;
		for (int i = 0; i < table.size(); i++) {
			if (table.at(i).size() > maxChain)
				maxChain = table.at(i).size();

		}
		return maxChain;
		
	}
	
	
	double averageChainLen(){
		double sumChain = 0.0;
		double avgChain = 0.0;
		for (int i = 0; i < table.size(); i++) {
			sumChain = sumChain + table.at(i).size();

		}

		avgChain = sumChain / table.size();
		return avgChain;
	}

    
    
};
