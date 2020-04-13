//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "Drink.h"
#include <utility>
#include <vector>

/**
 * \brief Default constructor for Drink Class
 */
Drink::Drink() : price(0.), name("") {}

/**
 * \brief three parameter constructor for Drink Class
 *
 * @param price_ price of the drink being constructed
 * @param name_ name of the drink, case sensitive
 */
Drink::Drink(const double price_, std::string name_)
    : price(price_), name(std::move(name_)) {
}

std::string Drink::getName() const {
  return this->name;
}

const double Drink::getPrice() const {
  return this->price;
}

void Drink::setRecipe(std::vector<INGREDIENTS> list) {
  // we know everything in the list exists at-least once, we are looking
  // for duplicates
  int count = 1;
  // it does not need to updated since the list shrinks in size
  for (auto it = list.begin(); it != list.end();) {
    // search for another instance of the current ingredient
    auto search = std::find(it+1, list.end(), *it);
    if (search != list.end()) {
      ++count;
      list.erase(search);
    } else {
      this->recipe.insert(std::pair<INGREDIENTS, int>(*it, count));
      list.erase(it);
      count = 1;
    }
  }
}

std::map<INGREDIENTS, int> Drink::getRecipe() {
  return this->recipe;
}
