#include "gtest/gtest.h"
#include "CoffeeMachine.h"
#include "Drink.h"

TEST(ProcessInput, r_Restock) {
  CoffeeMachine c;
  testing::internal::CaptureStdout();
  c.processInput("1");
  c.processInput("2");
  std::string expected = "Dispensing: Caffe Americano\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,7\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Dispensing: Caffe Latte\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,5\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,9\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n";
  c.processInput("r");
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, R_Restock) {
  CoffeeMachine c;
  testing::internal::CaptureStdout();
  c.processInput("1");
  c.processInput("2");
  std::string expected = "Dispensing: Caffe Americano\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,7\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Dispensing: Caffe Latte\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,5\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,9\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n";
  c.processInput("R");
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, q_Quit) {
  CoffeeMachine c;
  EXPECT_EXIT(c.processInput("q"), ::testing::ExitedWithCode(0), "");
  std::cout << "After q user input, verifying that the death was successfully handled" << std::endl;
}

TEST(ProcessInput, Q_Quit) {
  CoffeeMachine c;
  EXPECT_EXIT(c.processInput("Q"), ::testing::ExitedWithCode(0), "");
  std::cout << "After Q user input, verifying that the death was successfully handled" << std::endl;
}

TEST(ProcessInput, InvalidLetter) {
  CoffeeMachine c;
  testing::internal::CaptureStdout();
  c.processInput("t");
  std::string programOutput = testing::internal::GetCapturedStdout();
  std::string expected = "Invalid selection: t\n"
                        "Inventory:\n"
                        "Cocoa,10\n"
                        "Coffee,10\n"
                        "Cream,10\n"
                        "Decaf Coffee,10\n"
                        "Espresso,10\n"
                        "Foamed Milk,10\n"
                        "Steamed Milk,10\n"
                        "Sugar,10\n"
                        "Whipped Cream,10\n"
                        "Menu:\n"
                        "1,Caffe Americano,$3.30,true\n"
                        "2,Caffe Latte,$2.55,true\n"
                        "3,Caffe Mocha,$3.35,true\n"
                        "4,Cappuccino,$2.90,true\n"
                        "5,Coffee,$2.75,true\n"
                        "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(programOutput, expected);
}

TEST(ProcessInput, InvalidNumber) {
  CoffeeMachine c;
  testing::internal::CaptureStdout();
  c.processInput("10");
  std::string programOutput = testing::internal::GetCapturedStdout();
  std::string expected = "Invalid selection: 10\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,10\n"
                         "Decaf Coffee,10\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,10\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(programOutput, expected);
}

TEST(ProcessInput, 1) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("1");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Americano\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,7\n"
             "Foamed Milk,10\n"
             "Steamed Milk,10\n"
             "Sugar,10\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(MakeDrink, 2) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("2");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Latte\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,8\n"
             "Foamed Milk,10\n"
             "Steamed Milk,9\n"
             "Sugar,10\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, 3) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("3");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Caffe Mocha\n"
             "Inventory:\n"
             "Cocoa,9\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,9\n"
             "Foamed Milk,10\n"
             "Steamed Milk,9\n"
             "Sugar,10\n"
             "Whipped Cream,9\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, 4) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("4");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Cappuccino\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,8\n"
             "Foamed Milk,9\n"
             "Steamed Milk,9\n"
             "Sugar,10\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, 5) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("5");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Coffee\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,7\n"
             "Cream,9\n"
             "Decaf Coffee,10\n"
             "Espresso,10\n"
             "Foamed Milk,10\n"
             "Steamed Milk,10\n"
             "Sugar,9\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, 6) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("6");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Dispensing: Decaf Coffee\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,9\n"
             "Decaf Coffee,7\n"
             "Espresso,10\n"
             "Foamed Milk,10\n"
             "Steamed Milk,10\n"
             "Sugar,9\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, 7) {

  testing::internal::CaptureStdout();
  CoffeeMachine c;
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  std::string expected =
      "Inventory:\n"
      "Cocoa,10\n"
      "Coffee,10\n"
      "Cream,10\n"
      "Decaf Coffee,10\n"
      "Espresso,10\n"
      "Foamed Milk,10\n"
      "Steamed Milk,10\n"
      "Sugar,10\n"
      "Whipped Cream,10\n"
      "Menu:\n"
      "1,Caffe Americano,$3.30,true\n"
      "2,Caffe Latte,$2.55,true\n"
      "3,Caffe Mocha,$3.35,true\n"
      "4,Cappuccino,$2.90,true\n"
      "5,Coffee,$2.75,true\n"
      "6,Decaf Coffee,$2.75,true\n";

  EXPECT_EQ(menuAndInventory, expected);
  testing::internal::CaptureStdout();
  c.processInput("7");
  menuAndInventory = testing::internal::GetCapturedStdout();
  expected = "Invalid selection: 7\n"
             "Inventory:\n"
             "Cocoa,10\n"
             "Coffee,10\n"
             "Cream,10\n"
             "Decaf Coffee,10\n"
             "Espresso,10\n"
             "Foamed Milk,10\n"
             "Steamed Milk,10\n"
             "Sugar,10\n"
             "Whipped Cream,10\n"
             "Menu:\n"
             "1,Caffe Americano,$3.30,true\n"
             "2,Caffe Latte,$2.55,true\n"
             "3,Caffe Mocha,$3.35,true\n"
             "4,Cappuccino,$2.90,true\n"
             "5,Coffee,$2.75,true\n"
             "6,Decaf Coffee,$2.75,true\n";
  EXPECT_EQ(menuAndInventory, expected);
}

TEST(ProcessInput, OutofStock) {
  CoffeeMachine c;
  testing::internal::CaptureStdout();
  c.processInput("6");
  c.processInput("6");
  c.processInput("6");
  c.processInput("6");
  std::string expected = "Dispensing: Decaf Coffee\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,9\n"
                         "Decaf Coffee,7\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,9\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Dispensing: Decaf Coffee\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,8\n"
                         "Decaf Coffee,4\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,8\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,true\n"
                         "Dispensing: Decaf Coffee\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,7\n"
                         "Decaf Coffee,1\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,7\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,false\n"
                         "Out of stock: Decaf Coffee\n"
                         "Inventory:\n"
                         "Cocoa,10\n"
                         "Coffee,10\n"
                         "Cream,7\n"
                         "Decaf Coffee,1\n"
                         "Espresso,10\n"
                         "Foamed Milk,10\n"
                         "Steamed Milk,10\n"
                         "Sugar,7\n"
                         "Whipped Cream,10\n"
                         "Menu:\n"
                         "1,Caffe Americano,$3.30,true\n"
                         "2,Caffe Latte,$2.55,true\n"
                         "3,Caffe Mocha,$3.35,true\n"
                         "4,Cappuccino,$2.90,true\n"
                         "5,Coffee,$2.75,true\n"
                         "6,Decaf Coffee,$2.75,false\n";
  std::string menuAndInventory = testing::internal::GetCapturedStdout();
  EXPECT_EQ(menuAndInventory, expected);
}