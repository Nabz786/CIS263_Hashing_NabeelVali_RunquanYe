#include <string>
#include <cstdlib>
#include <vector>

#define HASH_SIZE 17011;
/**
 *This file holds all the hashmap code
 *@author Nabeel Vali, Runquan Ye
 */

template <typename T>

class my_hash{


public:

/**
 *Constructor to initialize our hashtable
 */
	
my_hash(){
  //HASH_SIZE = 17011;
  hashData.resize(HASH_SIZE);
}

/**
 *Returns true or false depending on whether there was a collision
 *upon inserting the data
 *@returns true or false if collision occurred
 */		
bool insert(const T & data, int (*hashingFunc)()){
	int index = (*hashingFunc(data.getName()));
	hashData[index].insert(hashData[index].begin, std::swap(data));
	if(hashData[index].size > 1){
		return true;
	}
	return false;
}

/**
 *Returns data based on the name parameter
 *@returns superhero with specified name if present
 */
T & get(const std::string name){
	int index = hashData[name];
	if(hashData[index] -> name == name){
		return T;
	}
	return NULL;
}
		
//we will create the hash functions here 

int my_hash::Hash1(const std::string key){
	int hash1 = 0;
	int index;
	if(key.length() >= 3){
		for(int i = key.length() - 1; i > (key.length() - 3); i--){
			hash1 = hash1 + (int)key[i];
		}
	}else{
		for(int i = key.length(); i > 0; i--){
			hash1 = hash1 + (int)key[i];
		}
	}
	
	index = hash1 % HASH_SIZE;
	
	return 0;
}

int my_hash::Hash2(const std::string key){
	int hash2 = 0;
	int index;

	for(int i = 0; i< key.length(); i++){
		hash2 = hash2 + (int)key[i];
	}
	
	index = hash2 % HASH_SIZE;

	return 0;
}


int my_hash::Hash3(const std::string key){
	int hash3 = 0;
	int index;
	if(key.length() >= 3){
		for(int i = 0; i< 3; i++){
			hash3 = hash3 + (int)key[i];
		}
	}else{
		for(int i = 0; i< key.length(); i++){
			hash3 = hash3 + (int)key[i];
		}
	}
	
	index = hash3 % HASH_SIZE;

	return 0;
}

private:
  
  /**Vector of vectors to hold our data .**/
  std::vector<std::vector<T> > hashData;

  /**Size of the hashtable .**/
  static const int HASH_SIZE;
};
