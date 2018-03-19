#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "csv.h"
#include "my_hash.h"
#include "superhero.h"



int main(int argc, char** argv){

	 my_hash<superhero> hash1;
	 int collisions = 0;

	 io::CSVReader<13> in("superherodata.csv");
 	 in.read_header(io::ignore_no_column, "page_id", "name", "urlslug", "ID", "ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", 
							"APPEARANCES", "FIRST APPEARANCE", "Year");

//	 io::CSVReader<1> in("superherodata.csv");
//	 in.read_header(io::ignore_extra_column, "page_id");

 	 int page_id;
	 std::string name;
	 std::string urlslug;
	 std::string ID;
	 std::string ALIGN;
	 char EYE;
	 char HAIR;
	 char SEX;
	 std::string GSM;
	 bool ALIVE;
	 int APPEARANCES;
	 std::string FIRST_Appearance;
	 int Year;

	 while(in.read_row(page_id, name, urlslug, ID, ALIGN, EYE, HAIR, SEX, GSM, ALIVE, APPEARANCES, FIRST_Appearance, Year)){
		superhero newHero(page_id, name, urlslug, ID, ALIGN, EYE, HAIR, SEX, GSM, ALIVE, APPEARANCES, FIRST_Appearance, Year);
		
		if(hash1.insert(newHero))
			collisions++;
		
  		 		
         }
//		while(in.read_row(page_id)){
//			collisions++;
//		}

	std::cout << "Collisions: " << collisions << std::endl;
}
