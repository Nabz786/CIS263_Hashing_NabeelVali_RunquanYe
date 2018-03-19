#include "superhero.h"
#include <string>


superhero::superhero(int page_id, const std::string &name, const std::string &urlslug,
                      const std::string &id, const std::string &alignment, char eye_color,
                       char hair_color, char sex, const std::string &gsm, bool alive,
                        int appearances, const std::string &first_appearance, int year) 
				
			 :page_id(page_id)
		         ,name(name)
			 ,urlslug(urlslug)
			 ,id(id)
			 ,alignment(alignment)
                         ,eye_color(eye_color)
                         ,hair_color(hair_color)
                         ,sex(sex)
                         ,gsm(gsm)
                         ,alive(alive)
                         ,appearances(appearances)
                         ,first_appearance(first_appearance)
                         ,year(year)
			{}




std::string superhero::getName() const{
	return name;
}
