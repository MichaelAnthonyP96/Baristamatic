//
// Created by Michael Anthony Pope on 4/12/20.
//

#ifndef BARISTAMATIC_INCLUDE_DRINKLIST_H_
#define BARISTAMATIC_INCLUDE_DRINKLIST_H_

constexpr auto DRINKS_BEGIN = __LINE__;
enum DRINKS {
  coffee,
  decafCoffee,
  caffeLatte,
  caffeAmericano,
  caffeMocha,
  cappuccino
};
constexpr auto DRINKS_SIZE = __LINE__ - DRINKS_BEGIN - 3;

#endif  // BARISTAMATIC_INCLUDE_DRINKLIST_H_