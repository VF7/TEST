// AUTHOR -> Viktor Fugel
// TEST Comment
#include <iostream>
#include "Gas.h"

using namespace std;

Gas::Gas() {
    setName(nullptr);
    setDefaultGasUsed();
}

Gas::Gas(const char* pName) {
    setName(pName);
    setDefaultGasUsed();
}

Gas::~Gas() {}

void Gas::setName(const char* pName) {
    if (pName == nullptr) {
        m_pName = nullptr;
        return;
    }
    m_pName = new char[strlen(pName)+1];
    strcpy_s(m_pName, strlen(pName)+1, pName);

}

char* Gas::getName() {
    return m_pName;
}

void Gas::setGasUse(int nUsed, int nMonth) {
    m_usedGasPerMonth[nMonth - 1] = nUsed;
}

int Gas::getGasUse(int nMonth) {
    return m_usedGasPerMonth[nMonth];
}

int Gas::getPricePerMonth(int nMonth) {
    int nPrice = 0;
    if (nMonth >= 1 && nMonth <= COUNT_OF_MONTH)
        nPrice = (nMonth >= 3 && nMonth <= 10) ? 5 : 8;
    return nPrice;

}

void Gas::setDefaultGasUsed() {
    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        m_usedGasPerMonth[i] = 0;
    }
}
int Gas::getSumPerMonth(int nMonth) {
    return getGasUse(nMonth) * getPricePerMonth(nMonth);
}
int Gas::getSumPerYear() {
    int sum = 0;
    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        sum += getGasUse(i) * getPricePerMonth(i);
    }
    return sum;
}

int main()
{
    Gas abonent1;
    abonent1.setName("Ivan Ivanovich");

    int use[COUNT_OF_MONTH] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        abonent1.setGasUse(use[i - 1], i);
    }

    char name[32];
    cout << "Set Name 2 Abonent: ";
    cin.getline(name, 32);

    Gas abonent2(name);

    cout << "Vvedit vykorystani kuby: " << endl;
    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        int used;
        cin >> used;
        abonent2.setGasUse(used, i);
    }

    cout << "Name abonent1: " << abonent1.getName() << endl;
    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        cout << " Month #" << i << " Used->" << abonent1.getGasUse(i) << " Sum= " << abonent1.getSumPerMonth(i) << endl;
    }
    cout << "SumPerYear abonent1 = " << abonent1.getSumPerYear() << endl << endl << endl;


    cout << "Name abonent2: " << abonent2.getName() << endl;
    for (int i = 1; i <= COUNT_OF_MONTH; i++) {
        cout << "Month #" << i << " Used->" << abonent2.getGasUse(i) << " Sum= " << abonent2.getSumPerMonth(i) << endl;
    }
    cout << "SumPerYear abonent2 = " << abonent2.getSumPerYear() << endl << endl << endl;

    system("pause");
  
}
