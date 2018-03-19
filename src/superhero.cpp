#include "superhero.h"
#include <string>

/** 
 *This class represents an interface for our superhero class
 *@author Nabeel Vali
 */

	/**
	 *Constructor to initialize the super hero
	 */
	superhero::superhero(int page_id, std::string name, std::string urlslug,
		             std::string id, std::string alignment, char eye_color,
		             char hair_color, char sex, std::string gsm, bool alive,
		             int appearances, std::string first_appearance, int year){
				
				  page_id = page_id;
				  name = name;
				  urlslug = urlslug;
				  id = id;
				  alignment = alignment;
		                  eye_color = eye_color;
		                  hair_color = hair_color;
		                  sex = sex;
		                  gsm = gsm;
		                  alive = alive;
		                  appearances = appearances;
		                  first_appearance = first_appearance;
		                  year = year;
				}



	/**
	 *get super hero's name
	 *@return string, super hero's name
	 */
	std::string superhero::getName(){
		return name;
	}
