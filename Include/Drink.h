//
// Created by Michael Anthony Pope on 4/8/20.
//

#ifndef BARISTAMATIC_INCLUDE_DRINK_H_
#define BARISTAMATIC_INCLUDE_DRINK_H_

#include "Inventory.h"
#include <map>
#include <string>

class Drink {
public:
  /**
   * \brief: zero argument constructor, provide default values to mem vars
   */
  Drink();

  /**
   * \brief: default destructor, no memory is dynamically allocated
   */
  ~Drink() = default;

  /**
   * \brief: copy constructor
   */
  Drink(Drink const &);

  /**
   * \brief three parameter constructor for Drink Class
   *
   * @param price_ price of the drink being constructed
   * @param name_ name of the drink, case sensitive
   */
  Drink(double price, std::string name);

  /**
   * \brief: member variable name getter
   * @return name of the drink
   */
  std::string getName() const;

  /**
   * \brief: member variable price getter
   * @return price of the drink
   */
  const double getPrice() const;

  /**
   * \brief: member variable recipe setter
   * @param list vector of enum INGREDIENTS
   */
  void setRecipe(std::vector<INGREDIENTS> list);

  /**
   * \brief: member variable recipe getter
   * @return vector of enum INGREDIENTS
   */
  std::map<INGREDIENTS, int> getRecipe();

private:
  const double price;     ///< the price of the drink
  const std::string name; ///< name of the drink
  std::map<INGREDIENTS, int>
      recipe; ///< Quantity of ingredients need to make drink
};

#endif // BARISTAMATIC_INCLUDE_DRINK_H_
