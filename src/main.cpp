#include <iostream>
#include <string>
#include "csv.h"
#include "my_hash.h"
#include "superhero.h"

/**
 *Main class of hashing program, here all functions and the 
 *two public methods can be tested
 *
 *Important to specify the superhero to be searched
 *please modify the variable nameSearch with the exact name
 *All insertion functions are ran and require no further input
 *The number of collisions will be output to the console 
 *
 * @author Nabeel Vali
 * @Version 1.0 Winter 2018
 **/


int main(int argc, char** argv){
	
	
	char getSex(std::string &sex);
	bool isAlive(std::string &alive);

	/**Instances of my_hash used to test each indiviual hashing function **/
	my_hash<superhero> hash1;
	my_hash<superhero> hash2;
	my_hash<superhero> hash3;

	/**Collion counters for the three hash functions **/
	int collision1 = 0;
	int collision2 = 0;
	int collision3 = 0;

	/**This function can be changed according to the name of the superhero to be searched for **/
	const std::string nameSearch = "Emma Frost (Earth-616)";

	//Implementation of CSV parser mentioned in class and found on github
	io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("superherodata.csv");
 	in.read_header(io::ignore_extra_column,
			 "page_id",
			 "name",
			 "urlslug",
			 "ID",
			 "ALIGN",
			 "EYE",
			 "HAIR",
			 "SEX",
			 "GSM",
			 "ALIVE",
			 "APPEARANCES",
			 "FIRST APPEARANCE",
			 "Year");

	//Variables representing each column name in the csv file
 	int page_id;
	std::string name;     
	std::string urlslug;
	std::string id;
	std::string align;
	std::string eye;	
	std::string hair;	
	std::string sex;	
	std::string gsm;
	std::string alive;	
	int appearances;
	std::string first_appearance;
	int year;

	//While full columns of data are present we will create new superhero objects
	//passing them to the three hashing functions
	while(in.read_row(page_id, name, urlslug, id, align, eye
		, hair, sex, gsm, alive, appearances, first_appearance, year)){
		
		superhero newHero(page_id, name, urlslug, id, align, eye, hair, getSex(sex),
					 gsm, isAlive(alive), appearances, first_appearance, year);
	
		//Upon insertion if we obtain a collison we will increment the collions counter
		if(hash1.insert(newHero, 1))
			collision1++;
		if(hash2.insert(newHero, 2))
			collision2++;
		if(hash3.insert(newHero, 3))
			collision3++;	 		
         }



	//All results of searches and hashes will be outputed here
	
	try{
		hash2.get(nameSearch);
	}catch(const char * str){
		std::cout << str << std::endl;
	}

	std::cout << "Collisions for hash 1: " << collision1 << std::endl;
	std::cout << "Collisions for hash 2: " << collision2 << std::endl;
	std::cout << "Collisions for hash 3: " << collision3 << std::endl;
}

	/**
	*Returns the first character in the string of the superhero's
	*Sex identifier 
	*@returns Char - representation of superhero's sex
	*/ 	
	char getSex(std::string &sex){
		if(!sex.length() == 0){
			return sex.at(0);
		}else{
			return 'U';
		}
	}

	/**
	*Returns a boolean value representing the living status of a superhero
	*@returns boolean - if the superhero is alive or not
	**/

	bool isAlive(std::string &alive){
		if(!alive.empty() && alive.at(0) == 'L'){
			return true;
		}
		return false;
	}
