#ifndef __H_superhero__
#define __H_superhero__
#include <string>

/** 
 *This class represents an interface for our superhero class
 *@author Nabeel Vali, Runquan Ye
 */

class superhero{

public:
	/**
	 *Constructor to initialize a superr hero
	 */	
  	superhero(int page_id, std::string name, std::string urlslug, std::string id,
		std::string alignment, std::string eye_color, std::string hair_color, char sex,
	  	std::string gsm, bool alive, int app,
            	std::string first_app, int year);

	/**
	 *Returns the name of the hero
	 *@return string, super hero's name
	 */
	std::string getName() const; 



private:
	/**Vector of vectors to hold our data*/
  	int page_id;

	/**super hero's name*/
  	std::string name;

	/**super hero's url slug*/
  	std::string urlslug;

	/**super hero's id**/
  	std::string id;

	/**super hero's alignment*/
  	std::string alignment;

	/**super hero's eye color*/
  	std::string eye_color;
	
	/**super hero's hair color*/
  	std::string hair_color;

	/**super hero's gender*/
  	char sex;

	/**super hero's gsm*/
  	std::string gsm;

	/**is the superhero still alive*/
  	bool alive;

	/**super hero's appearance time*/
  	int appearances;

	/**super hero's first appearance*/
  	std::string first_appearance;

	/**super hero's publish year*/
  	int year;	
};

#endif
