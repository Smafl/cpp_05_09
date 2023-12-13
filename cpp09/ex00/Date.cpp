
#include "Date.hpp"
#include "BtcExceptions.hpp"

Date::Date() { }

Date::Date(int y, int m, int d) :
	_year(y),
	_month(m),
	_day(d) { }

Date::Date(const Date &other) :
	_year(other._year),
	_month(other._month),
	_day(other._day) { }

Date::~Date() { }

Date &Date::operator=(const Date &other) {
	if (this != &other) {
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return *this;
}

bool Date::operator<(const Date &other) const {
	if (_year != other._year)
		return _year < other._year;
	if (_month != other._month)
		return _month < other._month;
	return _day < other._day;
}

bool Date::operator==(const Date &other) const {
	if (_year != other._year)
		return _year == other._year;
	if (_month != other._month)
		return _month == other._month;
	return _day == other._day;
}

std::istream &operator>>(std::istream &is, Date &date) {
	int y, m, d;
	char dash;
	is >> y;
	if (!is.good())
		throw BtcExceptions(BtcExceptions::INVALID_DATE);
	is >> dash;
	if (dash != '-')
		throw BtcExceptions(BtcExceptions::INVALID_DATE);
	is >> m;
	if (!is.good())
		throw BtcExceptions(BtcExceptions::INVALID_DATE);
	is >> dash;
	if (dash != '-')
		throw BtcExceptions(BtcExceptions::INVALID_DATE);
	is >> d;
	if (!is.good())
		throw BtcExceptions(BtcExceptions::INVALID_DATE);
	date = Date(y, m, d);
	return is;
}

bool Date::dateIsValid() const {
    if (_year < 0 || _month < 1 || _month > 12 || _day < 1 || _day > daysInMonth())
        return false;
	return true;
}

int Date::daysInMonth() const {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInMonth = days[_month - 1];
    if (_month == 2 && isLeapYear())
        daysInMonth = 29;
    return daysInMonth;
}

bool Date::isLeapYear() const {
//	A leap year is divisible by 4, except for years divisible by 100 but not divisible by 400.
    return (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0));
}

int Date::getYear() const {
	return _year;
}

int Date::getMonth() const {
	return _month;
}

int Date::getDay() const {
	return _day;
}
