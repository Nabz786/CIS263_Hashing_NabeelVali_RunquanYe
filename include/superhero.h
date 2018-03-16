#ifndef __H_superhero__
#define __H_superhero__
#include <string>

/** 
 *This class represents an interface for our superhero class
 *@author Nabeel Vali
 */

class superhero{

public:

  superhero(int page_id, std::string name, std::string urlslug, std::string id,
	std::string alignment, char eye_color, char hair_color, char sex,
	  std::string gsm, bool alive, int app,
            std::string first_app, int year);

std::string getName(); 



private:

  int page_id;


  std::string name;


  std::string urlslug;


  std::string id;


  std::string alignment;


  char eye_color;


  char hair_color;


  char sex;


  std::string gsm;


  bool alive;


  int appearances;


  std::string first_appearance;


  int year;	
};

#endif
