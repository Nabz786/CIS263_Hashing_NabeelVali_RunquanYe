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
	 // HASH_SIZE = 17011;
	  hashData.resize(HASH_SIZE);
	}

	/**
	 *Returns true or false depending on whether there was a collision
	 *upon inserting the data, data will be inserted regardless
	 *@returns true or false if collision occurred
	 */		
	bool insert(const T &data){
		std::string name = data.getName();
	//	std::cout << name << std::endl;
	//	int index = Hash1(name);
	//	int index = Hash2(name);
		int index = Hash3(name);
		hashData[index].insert(hashData[index].begin(), data);
		if(hashData[index].size() > 1){
			return true;
		}
		return false;
	}

	/**
	 *Returns data based on the name parameter
	 *@returns superhero with specified name if present
	 */
	T & get(const std::string name){

		int index1 = Hash1(name);
		int index2 = Hash2(name);
		int index3 = Hash3(name);
		
		for(int i = 0; i < hashData[index1].size(); i++){
			if(hashData[index1][i].name == name){
				return hashData[index1][i];
			}			
		}
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
	 *Second algorithm is an implementation of the djb2 algorithm
	 *Found on stackoverflow at https://stackoverflow.com/questions/33325191/passing-a-string-object-into-a-djb2-hash-function
	 *@returns index to hash at
	 */
	int Hash2(const std::string key){
	
		unsigned long hash = 5381;
		int c; 
		
		for(int i = 0; i < key.length(); ++i){
			c = (int) key[i];
			hash = ((hash << 5) + hash ) + c;
		}

		return hash % HASH_SIZE;
	}

	/**
	 *Last hashing method is bash on the first 3 characters of the key.
	 *@returns 0 if the method finish
	 */
	int Hash3(const std::string key){
		int hash3 = 0;
		
		if(key.length() >= 3){
			for(int i = 0; i< 3; i++){
				hash3 = hash3 + (int)key[i];
			}
		}else{
			for(int i = 0; i< key.length(); i++){
				hash3 = hash3 + (int)key[i];
			}
		}
	
		return hash3 % HASH_SIZE;
 	}

  private:
  
	  /**Vector of vectors to hold our data .**/
	  std::vector<std::vector<T> > hashData;

	  /**Size of the hashtable .**/
	  const int HASH_SIZE = 17011;
};
