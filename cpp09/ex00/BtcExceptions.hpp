
#ifndef BTCEXCEPTIONS_HPP
#define BTCEXCEPTIONS_HPP

struct BtcExceptions {
	enum Cause {
		CANNOT_OPEN_INPUTFILE,
		CANNOT_OPEN_DATABASE,
		INVALID_DATA,
		INVALID_DATE,
		NEGATIVE_RATE,
		RATE_OUT_OF_RANGE,
		INVALID_AMOUNT_BTC
	};

	explicit BtcExceptions(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case CANNOT_OPEN_INPUTFILE: return "Error: could not open input file";
			case CANNOT_OPEN_DATABASE: return "Error: could not open database";
			case INVALID_DATA: return "Error: data in database is unvalid";
			case INVALID_DATE: return "Error: date in input file is unvalid";
			case NEGATIVE_RATE: return "Error: exchange rate is negative";
			case RATE_OUT_OF_RANGE: return "Error: exchange rate is out of range";
			case INVALID_AMOUNT_BTC: return "Error: amount of bitcoins in input file is invalid";
			default: return "Unknown error";
		}
	}

	Cause cause;
};

#endif // BTCEXCEPTIONS_HPP
