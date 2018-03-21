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
		             std::string id, std::string alignment, std::string eye_color,
		             std::string hair_color, char sex, std::string gsm, bool alive,
		             int appearances, std::string first_appearance, int year){
				
				  this->page_id = page_id;
				  this->name = name;
				  this->urlslug = urlslug;
				  this->id = id;
				  this->alignment = alignment;
				  this->eye_color = eye_color;
				  this->hair_color = hair_color;
			          this->sex = sex;
			          this->gsm = gsm;
				  this->alive = alive;
				  this->appearances = appearances;
				  this->first_appearance = first_appearance;
				  this->year = year;
				}



	/**
	 *Returns the name of the superhero
	 *@return string, super hero's name
	 */
	std::string superhero::getName() const{ 
		return name;
	}
