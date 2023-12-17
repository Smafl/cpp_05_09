
#ifndef BTCEXCEPTIONS_HPP
#define BTCEXCEPTIONS_HPP

struct OpenFileException {
	enum File {
		DATABASE,
		INPUTFILE
	};

	File file;

	explicit OpenFileException(File file) : file(file) { }

	const char *what() const throw() {
		switch (file) {
			case DATABASE: return "Error: could not open database";
			case INPUTFILE: return "Error: could not open input file";
			default: return "Unknown error";
		}
	}
};

struct DataBaseException {
	enum Cause {
		EMPTY_DATABASE,
		INVALID_DATE,
		INVALID_DATA,
		NEGATIVE_RATE,
		RATE_OUT_OF_RANGE
	};

	Cause cause;
	int line;

	explicit DataBaseException(Cause cause, int line) :
		cause(cause),
		line(line) { }

	const char *what() const throw() {
		switch (cause) {
			case EMPTY_DATABASE: return "Error: database is empty";
			case INVALID_DATE: return "Error: date in database is unvalid";
			case INVALID_DATA: return "Error: data in database is unvalid";
			case NEGATIVE_RATE: return "Error: exchange rate is negative";
			case RATE_OUT_OF_RANGE: return "Error: exchange rate is out of range";
			default: return "Unknown error";
		}
	}
};

struct InputDataException {
	enum Cause {
		BAD_INPUT,
		DATE_IS_TOO_EARLY,
		NEGATIVE_AMOUNT_BTC,
		BTC_OUT_OF_RANGE
	};

	Cause cause;

	explicit InputDataException(Cause cause) :
		cause(cause) { }

	const char *what() const throw() {
		switch (cause) {
			case BAD_INPUT: return "Error: bad input";
			case DATE_IS_TOO_EARLY: return "Error: rate on this date does not exist yet";
			case NEGATIVE_AMOUNT_BTC: return "Error: not a positive number";
			case BTC_OUT_OF_RANGE: return "Error: too large a number";
			default: return "Unknown error";
		}
	}
};

struct DateException { };

#endif // BTCEXCEPTIONS_HPP
