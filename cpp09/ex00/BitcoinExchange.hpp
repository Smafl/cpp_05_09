
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>

struct BtcExceptions {
	enum Cause {
		CANNOTOPENINPUTFILE,
		CANNOTOPENDATABASE,
		DATAINVALIDDATE,
		INPUTINVALIDDATE,
		NEGATIVEDRATE,
		RATEOUTOFRANGE,
		INVALIDAMOUNTBTC
	};

	explicit BtcExceptions(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case CANNOTOPENINPUTFILE: return "Error: could not open input file.";
			case CANNOTOPENDATABASE: return "Error: could not open database.";
			case DATAINVALIDDATE: return "Error: date in database is unvalid.";
			case INPUTINVALIDDATE: return "Error: date in input file is unvalid.";
			case NEGATIVEDRATE: return "Error: exchange rate is negative.";
			case RATEOUTOFRANGE: return "Error: exchange rate is out of range";
			case INVALIDAMOUNTBTC: return "Error: amount of bitcoins in input file is invalid";
			default: return "Unknown error.";
		}
	}

	Cause cause;
};

class BitcoinExchange {
private:
	std::map<std::string,float> _exchangeRates;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	static void getDatabase();
};

void getInputData(char *input);

#endif // BITCOINEXCHANGE_HPP

/*
errors:
- empty files
- negativ rate or amount of btc
- wrong date
- take error from subject ?

- check subject for input requarement
*/
