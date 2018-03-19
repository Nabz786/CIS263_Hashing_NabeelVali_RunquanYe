#include <string>
#include <cstdlib>
#include <vector>

/**
 *This file holds all the hashmap code
 *@author Nabeel Vali
 */

template <typename T>

class my_hash{


public:

/**
 *Constructor to initialize our hashtable
 */
	
my_hash(){
  HASH_SIZE = 17011;
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



}
		
//we will create the hash functions here 

int hash1(const std::string key){


return 0;
}

private:
  
  /**Vector of vectors to hold our data .**/
  std::vector<std::vector<T> > hashData;

  /**Size of the hashtable .**/
  const int HASH_SIZE;
};
