#include <string>
#include <cstdlib>
#include <vector>

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
		int index1 = hash1(name);
		int index2 = hash2(name);
		int index3 = hash3(name)
		
		for(int i = 0; i < hashData[index1].size(); i++){
			if(hashData[index1][i].name == name){
				return hashData[index1][i];
			}			
		}	
		
		return NULL;
	}
	

	/**
	 *First hashing method is bash on the ascii values of the key
	 *@returns the index to hash to
	 */
	int Hash1(const std::string key){
		int hashval = 0;
		
		for(char ch: key) {
			hashval+= ch;
		}

		return hashval % HASH_SIZE;
	}

	/**
	 *second hashing method is bash on all the characters of the key.
	 *@returns 0 if the method finish
	 */
	int Hash2(const std::string key){
		int hash2 = 0;
		int index;

		for(int i = 0; i< key.length(); i++){
			hash2 = hash2 + (int)key[i];
		}
	
		index = hash2 % HASH_SIZE;

		return index;
	}

	/**
	 *Last hashing method is bash on the first 3 characters of the key.
	 *@returns 0 if the method finish
	 */
	int Hash3(const std::string key){
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

		return index;
 	}

  private:
  
	  /**Vector of vectors to hold our data .**/
	  std::vector<std::vector<T> > hashData;

	  /**Size of the hashtable .**/
	  static const int HASH_SIZE;
};
