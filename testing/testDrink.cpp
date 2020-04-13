#include "Drink.h"
#include "gtest/gtest.h"

TEST(Drink, DefaultCTor) {
  Drink d;

  EXPECT_EQ(0, d.getPrice());
  EXPECT_EQ("", d.getName());
}

TEST(Drink, TwoParamCTor) {
  Drink d(3.60, "White Russian");

  EXPECT_EQ(3.60, d.getPrice());
  EXPECT_EQ("White Russian", d.getName());
}

TEST(Drink, CopyCTor) {
  Drink d1(3.60, "White Russian");
  Drink d2(d1);

  EXPECT_EQ(3.60, d2.getPrice());
  EXPECT_EQ("White Russian", d2.getName());
}

TEST(Drink, setRecipe) {
  std::vector<INGREDIENTS> recipe;
  recipe.push_back(INGREDIENTS::Cream);
  recipe.push_back(INGREDIENTS::WhippedCream);
  recipe.push_back(INGREDIENTS::Cocoa);
  recipe.push_back(INGREDIENTS::Coffee);
  recipe.push_back(INGREDIENTS::SteamedMilk);
  recipe.push_back(INGREDIENTS::FoamedMilk);

  Drink d(3.60, "White Russian");
  d.setRecipe(recipe);

  EXPECT_EQ(3.60, d.getPrice());
  EXPECT_EQ("White Russian", d.getName());
  EXPECT_EQ(6, d.getRecipe().size());
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::Cream]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::WhippedCream]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::Cocoa]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::Coffee]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::SteamedMilk]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::FoamedMilk]);
}

TEST(Drink, getRecipe) {
  std::vector<INGREDIENTS> recipe;
  recipe.push_back(INGREDIENTS::Cream);
  recipe.push_back(INGREDIENTS::Cream);
  recipe.push_back(INGREDIENTS::Cocoa);
  recipe.push_back(INGREDIENTS::Cocoa);
  recipe.push_back(INGREDIENTS::Cocoa);
  recipe.push_back(INGREDIENTS::FoamedMilk);

  Drink d(3.55, "Hot Chocolate");
  d.setRecipe(recipe);

  EXPECT_EQ(3, d.getRecipe().size());
  EXPECT_EQ(2, d.getRecipe()[INGREDIENTS::Cream]);
  EXPECT_EQ(3, d.getRecipe()[INGREDIENTS::Cocoa]);
  EXPECT_EQ(1, d.getRecipe()[INGREDIENTS::FoamedMilk]);
}