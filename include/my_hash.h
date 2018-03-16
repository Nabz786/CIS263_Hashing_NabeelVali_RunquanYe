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
  hashData.resize(HASH_SIZE);
}

/**
 *Returns true or false depending on whether there was a collision
 *upon inserting the data
 *@returns true or false if collision occurred
 */		
bool insert(const T & var){
//write insert code here, we may want to have a param
//for the index of where to insert the data


}

/**
 *Returns data based on the name parameter
 *@returns superhero with specified name if present
 */
T & get(const std::string name){



}
		
//we will create the hash functions here 

private:
  
  /**Vector of vectors to hold our data .**/
  std::vector<std::vector<T> > hashData;

  /**Size of the hashtable .**/
  final int HASH_SIZE = 17011;
}
