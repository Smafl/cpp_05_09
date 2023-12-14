
#ifndef BTCEXCEPTIONS_HPP
#define BTCEXCEPTIONS_HPP

struct DataBaseException {
	enum Cause {
		CANNOT_OPEN_DATABASE,
		EMPTY_DATABASE,
		INVALID_DATE,
		INVALID_DATA,
		NEGATIVE_RATE,
		RATE_OUT_OF_RANGE
	};

	explicit DataBaseException(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case CANNOT_OPEN_DATABASE: return "Error: could not open database";
			case EMPTY_DATABASE: return "Error: database is empty";
			case INVALID_DATE: return "Error: date in database is unvalid";
			case INVALID_DATA: return "Error: data in database is unvalid";
			case NEGATIVE_RATE: return "Error: exchange rate is negative";
			case RATE_OUT_OF_RANGE: return "Error: exchange rate is out of range";
			default: return "Unknown error";
		}
	}

	Cause cause;
};

struct InputDataException {
	enum Cause {
		CANNOT_OPEN_INPUTFILE,
		BAD_INPUT,
		DATE_IS_TOO_EARLY,
		NEGATIVE_AMOUNT_BTC,
		BTC_OUT_OF_RANGE
	};

	explicit InputDataException(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case CANNOT_OPEN_INPUTFILE: return "Error: could not open input file";
			case BAD_INPUT: return "Error: bad input";
			case DATE_IS_TOO_EARLY: return "Error: rate on this date does not exist yet";
			case NEGATIVE_AMOUNT_BTC: return "Error: not a positive number";
			case BTC_OUT_OF_RANGE: return "Error: too large a number";
			default: return "Unknown error";
		}
	}

	Cause cause;
};

struct DateException {
	enum Cause {
		FAILED_EXTRACTION_OPERATOR
	};

	explicit DateException(Cause cause) : cause(cause) { }

	const char *what() const throw() {
		switch (cause)
		{
			case FAILED_EXTRACTION_OPERATOR: return "";
			default: return "Unknown error";
		}
	}

	Cause cause;
};

#endif // BTCEXCEPTIONS_HPP
