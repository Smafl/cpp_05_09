
#ifndef BTCEXCEPTIONS_HPP
#define BTCEXCEPTIONS_HPP

struct BtcExceptions {
	enum Cause {
	//	data base
		CANNOT_OPEN_DATABASE,
		INVALID_DATE,
		DATE_IS_TOO_EARLY,
		INVALID_DATA,
		NEGATIVE_RATE,
		RATE_OUT_OF_RANGE,
	//	input data
		CANNOT_OPEN_INPUTFILE,
		BAD_INPUT,
		NEGATIVE_AMOUNT_BTC,
		BTC_OUT_OF_RANGE
	};

	explicit BtcExceptions(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
		//	data base
			case CANNOT_OPEN_DATABASE: return "Error: could not open database.";
			case INVALID_DATE: return "Error: date in database is unvalid";
			case DATE_IS_TOO_EARLY: return "Error: rate on this date does not exist yet";
			case INVALID_DATA: return "Error: data in database is unvalid";
			case NEGATIVE_RATE: return "Error: exchange rate is negative";
			case RATE_OUT_OF_RANGE: return "Error: exchange rate is out of range";
		// input data
			case CANNOT_OPEN_INPUTFILE: return "Error: could not open input file.";
			case BAD_INPUT: return "bad input";
			case NEGATIVE_AMOUNT_BTC: return "Error: not a positive number.";
			case BTC_OUT_OF_RANGE: return "Error: too large a number";
			default: return "Unknown error";
		}
	}

	Cause cause;
};

#endif // BTCEXCEPTIONS_HPP
