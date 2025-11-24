#include "Inventory.hpp"
#include <iostream>
#include <print>
using std::println, std::cin, std::print;

// Function prototypes
int getMetalChoice();
int getOperationChoice();
void showBalance(int metalChoice, Inventory &inv);
void showInventoryView(Inventory &inv);

int main() {

  const int START_AMT = 20;
  int metalChoice;
  int operationChoice;
  int exchangeAmount;

  Inventory inv = Inventory(START_AMT, START_AMT, START_AMT);

  println("Welcome to Kaveh's inventory system:");

  while (true) {
    showInventoryView(inv);

    metalChoice = getMetalChoice();
    if (metalChoice == NO_METAL) {
      break;
    }

    showBalance(metalChoice, inv);

    operationChoice = getOperationChoice();
    if (operationChoice == QUIT) {
      break;
    }

    print("What's the amount: ");
    cin >> exchangeAmount;

    int balance;

    if (operationChoice == WITHDRAW) {
      balance = inv.withdraw(metalChoice, exchangeAmount);
    } else if (operationChoice == DEPOSIT) {
      balance = inv.deposit(metalChoice, exchangeAmount);
    }

    if (balance != -1)
      println("FINAL BALANCE: {}\n", balance);
    else
      println("INVALID OPERATION!");
  }

  return 0;
}

int getMetalChoice() {
  int choice;
  println("Please choose which metal you want to work with:\n 1. Gold\n 2. "
          "Silver\n 3. Copper\n 4. Quit");
  print("Metal Choice: ");
  cin >> choice;
  return choice;
} // end of getMetalChoice()

int getOperationChoice() {
  int choice;
  print("Choose what you want to do:\n  1. Withdraw\n  2. Deposit\n  3. "
        "Quit\nYour choice: ");
  cin >> choice;
  return choice;
} // end of getOperationChoice()

void showBalance(int metalChoice, Inventory &inv) {
  bool validChoice = true;
  int balance;
  switch (metalChoice) {
  case GOLD:
    balance = inv.getGoldBalance();
    break;
  case SILVER:
    balance = inv.getSilverBalance();
    break;
  case COPPER:
    balance = inv.getCopperBalance();
    break;
  default: {
    validChoice = false;
    println("INVALID CHOICE ERROR!\n");
    break;
  }
  }
  if (validChoice)
    println("Here is your current balance: {}", balance);
} // end of showBalance()


void showInventoryView(Inventory &inv) {

  println("\n|=========||====================|");
  println("|  Metal  ||  Current Amount    |");
  println("|---------||--------------------|");
  println("|  Gold   ||\t{}\t\t|", inv.getGoldBalance());
  println("|---------||--------------------|");
  println("|  Silver ||\t{}\t\t|", inv.getSilverBalance());
  println("|---------||--------------------|");
  println("|  Copper ||\t{}\t\t|", inv.getCopperBalance());
  println("|=========||====================|\n");
} // end of showInventoryView()
