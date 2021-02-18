// AUTHOR -> Viktor Fugel
#pragma once
#define COUNT_OF_MONTH 12

class Gas {

public:
	Gas();
	Gas(const char* pName);
	~Gas();

	void setName(const char* pName);
	char* getName();

	void setGasUse(int nUsed, int nMonth);
	int getGasUse(int nMonth);
	int getSumPerMonth(int nMonth);
	int getSumPerYear();

private:
	char* m_pName;
	int m_usedGasPerMonth[COUNT_OF_MONTH];
	int getPricePerMonth(int nMonth);
	void setDefaultGasUsed();
};
