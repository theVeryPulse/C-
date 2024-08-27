# Bitcoin Exchange
The value lookup comprises two stages: looking up the price in data.csv; read the input file and calculate the corresponding net value.

## Requirements
- Handle possible errors with messages.

### Data File
- Header -> "date,exchange_rate"
- data line format -> "YYYY-MM-DD,{positive value for exchange rate}"

### Input File
- Header -> "date | value"
- line format -> "YYYY-MM-DD | {positive value for coin amount}"

## Error Messages and Throw Exceptions

### 1. Read Data File Stage
This stage only throw exceptions and does not print a error message.
1. Cannot open data file.
2. Incorrect header in data file.
3. Incorrect line format in data file.
3. Same date appearing twice.


### 2. Calculation Stage
#### Throw Cases
1. Cannot open input file.
2. Incorrect header in input file.

#### Error message cases
1. Incorrect line format in file.
2. Invalid date in line.
3. Invalid coin amount.
