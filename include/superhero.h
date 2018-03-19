#ifndef __H_superhero__
#define __H_superhero__
#include <string>

/** 
 *This class represents an interface for our superhero class
 *@author Nabeel Vali
 */

class superhero{

public:

  superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
	const std::string &alignment, char eye_color, char hair_color, char sex,
	  const std::string &gsm, bool alive, int appearances,
           const std::string &first_appearance, int year);

std::string getName() const;


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
