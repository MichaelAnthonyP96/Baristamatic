//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "Drink.h"
#include <iostream>
#include <utility>
#include <vector>

/**
 * \brief Default constructor for Drink Class
 */
Drink::Drink() : price(0.), inStock(false), name("") {}

/**
 * \brief three parameter constructor for Drink Class
 *
 * @param price_
 * @param inStock_
 * @param name_
 */
Drink::Drink(const double price_, std::string name_)
    : price(price_), name(std::move(name_)), inStock(true) {
}

const std::string Drink::getName() const { return this->name; }

void Drink::print() const {

}
const double Drink::getPrice() const {
  return this->price;
}
bool Drink::stocked() const {
  return this->inStock;
}

void Drink::setRecipe(std::vector<INGREDIENTS> list) {
  // we know everything in the list exists atleast once, we are looking
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
