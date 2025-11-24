#include "Inventory.hpp"

Inventory::Inventory()
  : m_goldBalance(0)
  , m_silverBalance(0)
  , m_copperBalance(0)
{
}

Inventory::Inventory(int goldBalance, int silverBalance, int copperBalance)
  : m_goldBalance(goldBalance)
  , m_silverBalance(silverBalance)
  , m_copperBalance(copperBalance)
{
}

int  Inventory::getGoldBalance() const {
  return m_goldBalance;
}

int  Inventory::getSilverBalance() const {
  return m_silverBalance;
}
int  Inventory::getCopperBalance() const {
  return m_copperBalance;
}

void Inventory::setGoldBalance(int newBalance) {
  m_goldBalance = newBalance;
}

void Inventory::setSilverBalance(int newBalance) {
  m_silverBalance = newBalance;
}
void Inventory::setCopperBalance(int newBalance) {
  m_copperBalance = newBalance;
}

int  Inventory::withdraw(int metalType, int withdrawAmount) {

  bool isValid;
  int amount = withdrawAmount * -1;
  int newBalance;

  switch (metalType) {
    case GOLD: {
      isValid = validateTransaction(GOLD, amount);
      if (isValid) {
        m_goldBalance +=  amount;
      }
      newBalance = m_goldBalance;
      break;
    }
    case SILVER: {
      isValid = validateTransaction(SILVER, amount);
      if (isValid) {
        m_silverBalance +=  amount;
      }
      newBalance = m_silverBalance;
      break;
    }
    case COPPER: {
      isValid = validateTransaction(COPPER, amount);
      if (isValid) {
        m_copperBalance +=  amount;
      }
      newBalance = m_copperBalance;
      break;
    }
  }

  return newBalance;
}

int  Inventory::deposit(int metalType, int depositAmount) {

  bool isValid;
  int newBalance;

  switch (metalType) {
    case GOLD: {
      isValid = validateTransaction(GOLD, depositAmount);
      if (isValid) {
        m_goldBalance +=  depositAmount;
      }
      newBalance = m_goldBalance;
      break;
    }
    case SILVER: {
      isValid = validateTransaction(SILVER, depositAmount);
      if (isValid) {
        m_silverBalance +=  depositAmount;
      }
      newBalance = m_silverBalance;
      break;
    }
    case COPPER: {
      isValid = validateTransaction(COPPER, depositAmount);
      if (isValid) {
        m_copperBalance +=  depositAmount;
      }
      newBalance = m_copperBalance;
      break;
    }
  }

  return newBalance;
}

bool Inventory::validateTransaction(int type, int amount) {
  bool flag;
  switch (type) {
    case GOLD:
      flag = (getGoldBalance() + amount) >= 0 && (getGoldBalance() + amount) <= MAX_CAPACITY;
      break;
    case SILVER:
      flag = (getSilverBalance() + amount) >= 0 && (getSilverBalance() + amount) <= MAX_CAPACITY;
      break;
    case COPPER:
      flag = (getCopperBalance() + amount) >= 0 && (getCopperBalance() + amount) <= MAX_CAPACITY;
      break;
  }
  return flag;
}
