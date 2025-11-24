#include "Inventory.hpp"

Inventory::Inventory()
    : m_goldBalance(0), m_silverBalance(0), m_copperBalance(0) {}

Inventory::Inventory(int goldBalance, int silverBalance, int copperBalance)
    : m_goldBalance(goldBalance), m_silverBalance(silverBalance),
      m_copperBalance(copperBalance) {}

int Inventory::getGoldBalance() const { return m_goldBalance; }

int Inventory::getSilverBalance() const { return m_silverBalance; }
int Inventory::getCopperBalance() const { return m_copperBalance; }

void Inventory::setGoldBalance(int newBalance) { m_goldBalance = newBalance; }

void Inventory::setSilverBalance(int newBalance) {
  m_silverBalance = newBalance;
}
void Inventory::setCopperBalance(int newBalance) {
  m_copperBalance = newBalance;
}

int Inventory::withdraw(int metalType, int withdrawAmount) {

  int amount = withdrawAmount * -1;
  bool isValid = validateTransaction(metalType, amount);
  int newBalance = -1;

  if (isValid) {
    switch (metalType) {
    case GOLD: {
      m_goldBalance += amount;
      newBalance = m_goldBalance;
      break;
    }
    case SILVER: {
      m_silverBalance += amount;
      newBalance = m_silverBalance;
      break;
    }
    case COPPER: {
      m_copperBalance += amount;
      newBalance = m_copperBalance;
      break;
    }
    }
  }

  return newBalance;
}

int Inventory::deposit(int metalType, int depositAmount) {

  int amount = depositAmount;
  bool isValid = validateTransaction(metalType, amount);
  int newBalance = -1;

  if (isValid) {
    switch (metalType) {
    case GOLD: {
      m_goldBalance += amount;
      newBalance = m_goldBalance;
      break;
    }
    case SILVER: {
      m_silverBalance += amount;
      newBalance = m_silverBalance;
      break;
    }
    case COPPER: {
      m_copperBalance += amount;
      newBalance = m_copperBalance;
      break;
    }
    }
  }

  return newBalance;
}

bool Inventory::validateTransaction(int type, int amount) {
  bool flag;
  switch (type) {
  case GOLD:
    flag = (getGoldBalance() + amount) >= 0 &&
           (getGoldBalance() + amount) <= MAX_CAPACITY;
    break;
  case SILVER:
    flag = (getSilverBalance() + amount) >= 0 &&
           (getSilverBalance() + amount) <= MAX_CAPACITY;
    break;
  case COPPER:
    flag = (getCopperBalance() + amount) >= 0 &&
           (getCopperBalance() + amount) <= MAX_CAPACITY;
    break;
  }
  return flag;
}
