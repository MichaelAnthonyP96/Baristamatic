//
// Created by Michael Anthony Pope on 4/8/20.
//

#include "Drink.h"

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
Drink::Drink(const double price_, std::string name_) : price(price_), name(name_) {
  /*if (hasEnoughIngredients){
    this->inStock = true;
  }*/
}

const std::string Drink::getName() const {
  return this->name;
}