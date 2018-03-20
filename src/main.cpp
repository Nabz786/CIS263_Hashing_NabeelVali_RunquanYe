#include <iostream>
#include <string>
#include "csv.h"
#include "my_hash.h"
#include "superhero.h"



int main(int argc, char** argv){

	char getEyeColor(std::string &eyeColor);
	char getHairColor(std::string &hairColor);
	char getSex(std::string &sex);
	bool isAlive(std::string &alive);


	 my_hash<superhero> hash1;
	 int collisions = 0;


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

	 while(in.read_row(page_id, name, urlslug, id, align, eye, hair, sex, gsm, alive, appearances, first_appearance, year)){
		superhero newHero(page_id, name, urlslug, id, align, eye, hair, getSex(sex), gsm, isAlive(alive), appearances, first_appearance, year);
		if(hash1.insert(newHero))
			collisions++;	 		
         }

	std::cout << "Collisions: " << collisions << std::endl;
}





//	char getEyeColor(std::string &eyeColor){
//		if(!eyeColor.length() == 0){
//			return eyeColor.at(0);
//		}else{
//			return 'U';
//		}
//	}

//	char getHairColor(std::string &hairColor){
//		if(!hairColor.length() == 0){
//			return hairColor.at(0);
//		}else{
//			return 'U';
//		}
//	}

	char getSex(std::string &sex){
		if(!sex.length() == 0){
			return sex.at(0);
		}else{
			return 'U';
		}
	}

	bool isAlive(std::string &alive){
		if(!alive.empty() && alive.at(0) == 'L'){
			return true;
		}
		return false;
	}
