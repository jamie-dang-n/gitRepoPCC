/* Car class header file
 * CS162 Summer 2023, assessment files */

#ifndef ITEM
#define ITEM

const int STR_SIZE = 100;

class Car {
	double listPrice;
	double dealerCost;
	int year;
	char makeModel[STR_SIZE];

	public:
	Car();
	double getListPrice() const;
	double getDealerCost() const;
	const char * getMakeModel() const;
	int getYear() const;
	void setListPrice(double);
	void setDealerCost(double);
	void setMakeModel(char *, int strSize);
	void setYear(int);
	// Add any new function prototypes here.
	double calculateRevenue() const;
};

#endif
