
#ifndef DATE_HPP
#define DATE_HPP

#include <istream>	// istream

class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date &other);
	~Date();

	Date &operator=(const Date &other);
	bool operator<(const Date &other) const;
	bool operator==(const Date &other) const;

	bool dateIsValid() const;
	int daysInMonth() const;
	bool isLeapYear() const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;
};

std::istream &operator>>(std::istream &is, Date &date);

#endif // DATE_HPP
