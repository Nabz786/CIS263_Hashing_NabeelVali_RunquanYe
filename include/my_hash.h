#include <string>
#include <cstdlib>
#include <vector>

/**
 *This file holds all the hashmap code, including the 3 hashing functions
 *Version 1.0, March 2018
 *@author Nabeel Vali, Runquan Ye
 */

template <typename T>

class my_hash{


  public:

	/**
	 *Constructor to resize our hashmap to the specified size of 17011
	 */
	my_hash(){
	  hashData.resize(HASH_SIZE);
	}

	/**
	 *Returns true or false depending on whether there was a collision
	 *upon inserting the data, data will be inserted regardless
	 *@returns true or false if collision occurred
	 */		
	bool insert(const T &data, int hashFunction){
		
		setFuncIdent(hashFunction);
		int index = getIndex(data.getName());
		

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

		int index = getIndex(name);
		
		for(int i = 0; i < hashData[index].size(); i++){
			if(hashData[index][i].getName() == name){
				return hashData[index][i];
			}		
		}

		throw "Sorry! Superhero not found!";
	}

  private:
	
	/**
 	*Returns index to hash at from specified hashing function
	*1 will get returned by default
	*/
	int getIndex(const std::string name){
		switch(getFuncIdent()){
			case 1:
				return Hash1(name);
				break;
			case 2: 
				return Hash2(name);
				break;
			case 3:
				return Hash3(name);
				break;	
		}
		return 1;	
	}

	/** 
 	*Returns index which indentifies a hashfunction	
	*returns int the function that was selected
 	**/ 	
	int getFuncIdent(){
		return whichHashFunction;
	}

	/** 
 	*Sets the function identifier param 	
 	*/
	void setFuncIdent(int funcIdent){
		whichHashFunction = funcIdent;
	}
	 
	 /**
	 *First hashing method is based on the ascii values of the key
	 *This was obtained from the lecture slides
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
	 *Last hashing method is based on the first 3 characters of the key.
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
  
	  /**Vector of vectors to hold our data .**/
	  std::vector<std::vector<T> > hashData;

	  /**Size of the hashtable .**/
	  const int HASH_SIZE = 17011;

	  /** Hash function identifier. **/
	  int whichHashFunction = 0;
};

