#include <String>
#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main() {
	
	Sales_data total;

	if (std::cin >> total.bookNo>>total.units_sold>>total.revenue) 
	{
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
				total = trans;
			}
		}
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}