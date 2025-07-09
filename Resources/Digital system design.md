	Designing digital systems to process binary information using logic

## Analog v/s Digital systems

### Digital system

	- Represented using 0s and 1s
	- N bits -> 2$^n$ states
	- 10 bits -> 2$^1$$^0$ states = 1024 = ~1000 = 1 kilobit
	- 20 bits -> 2$^1$$^0$ states = ~10$^6$ = 1 megabit

Analog input -> ADC -> Digital system -> DAC -> Analog output 

### Analog to Digital conversion

- Discretion in time - sampling rate
- Discretion in value - quantization

### Digital to Analog conversion

Nyquist criteria - if the sampling rate and the digital output we can generate an analog output
### Advantages of digital systems

- Accuracy
- Programmability
- Maintainability
- Design automation
### Disadvantages of digital systems

- Area
- Latency


## Binary number system

### Positional number system

Value of symbol depends on its position and radix

Example
1. (100101)$_2$ = 32 + 4 + 1 = (37)$_1$$_0$
2. (101.101)$_2$ = 8 + 1 + 0.5 + 0.125 = (9.625)$_1$$_0$

### Decimal to binary conversion
- Integer part 'N' by radix, remainder is a$_0$ and quotient becomes N
- For Integer part the output is taken from bottom up
- Multiply the fractional part 'F' by the radix, the non fractional part becomes a$_-$$_1$ and fractional part becomes F
- For fractional the output is taken from top down
## Hexa-decimal numer system
### Notations
- It requires 16 symbols, ie. 1 to 9 and A to F
- Generally it is prefixed by 0x

Example - 0x345A
### Binary to hex conversion
- Make groups of 4 bits from left to right

Examples - 1010111101 -> 10 1011 1101 -> 0x 2BD 

## Arithmetic in binary


### Addition
- 1 + 1 = (10)$_2$
- 1 + 0 = (1)$_2$
- 1 + 1 + 1 = (11)$_2$
### Subtraction
- 1 - 1 = (0)$_2$
- 1 - 0 = (1)$_2$
- 0 - 1 = (1)$_2$ , borrow 1
## Representation of negative numbers in binary
### Using sign bit
- MSB is designated as the sign bit, 1 means negative and 0 means positive.

Examples
- (1001 0101)$_2$ = (-21)$_1$$_0$
- (0111 1111)$_2$ = (127)$_1$$_0$

Disadvantages
- Two representations of zero, (1000 0000)$_2$ and (0000 0000)$_2$

Addition 
- If signs are same -> add
- If signs are different -> subtract (without sign bit)
- (result's sign will change if number to be subtracted is bigger)

Subtraction
- If signs are same -> subtract
- If signs are different -> add

### 1's complement
- For negative number flip all bits
- Nth bit denotes the sign
- N-1 bits represent the magnitude
- Range is - 2$^N$$^-$$^1$ to + 2$^N$$^-$$^1$

Example
- (0000 1101)$_2$ = (+13)$_1$$_0$
- (11110010)$_2$ = (-13)$_1$$_0$

Disadvantages
- Two representation of zeros, (0000 0000)$_2$ and (1111 1111)$_2$
- Addition and subtraction is challenging

(0000 1101)$_2$ + (1111 0010)$_2$ = (1111 1111)$_2$

(0000 1101)$_2$ + (1111 0011)$_2$ = (0000 0000)$_2$

### Bias
- A bias number is added to binary
- F(u) = u + bias
- Say bias for 4 bit number is 7
(1)$_1$$_0$ = (1000)$_2$
(-7)$_1$$_0$ = (0000)$_2$
(+7)$_1$$_0$ = (1111)$_2$
- Adding 2 numbers
F(u+v) = F(u) + F(v) - bias
- Subtracting 2 numbers
F(u-v) = F(u) - F(v) + bias

### 2's complement
- If number is positive, F(u) = |u|
- If number is negative, F(u) = 2$^n$ - |u|

Advantages
- Only one representation of zero
- MSB represents sign
- Range (- 2$^N$$^-$$^1$) to (2$^N$$^-$$^1$ - 1)
- Negation rule, F(-u) = 2$^n$ - F(u)

#### Arithmetic using 2's complement
Addition : F(u+v) = F(u) + F(v)

Subtraction : F(u-v) = F(u) + F(-v)

Multiplication : F(uxv) = F(u) x F(v), (assuming no overflow)


### Overflow and underflow conditions
Addition
- If sign of both operands are same and result is of opposite sign or zero -> overflow
- If signs of both operands are different overflow is not possible

Converting N bit number to M bit number
- Sign extensions
- 1011 in 4 bit is 1111 1011 in 8 bits

## Other number systems
Positional number system is not the only method we just need one to one mapping between binary and decimal numbers
### BCD number system
- Each decimal digit is represented by equivalent 4 bit binary number
- One to one mapping with each digit
- More intuitive representation

| BCD  | Decimal |
|:----:|:-------:|
| 0000 |    0    |
| 0001 |    1    |
| 0010 |    2    |
| 0011 |    3    |
| 0100 |    4    |
| 0101 |    5    |
| 0110 |    6    |
| 0111 |    7    |
| 1000 |    8    |
| 1001 |    9    |

Addition
1. Normal binary addition
2. If output of a nibble is more than 9 or carry is generated then 0110 is added to the nibble
3. Carry passes from one nibble to another in both step 1 and 2

### Excess-3 Code
- Self complementing
- After addition or subtraction of 2 numbers add/subtract 3 to fix the result

| Excess-3 code | Decimal |
|:-------------:|:-------:|
|     0011      |    0    |
|     0100      |    1    |
|     0101      |    2    |
|     0110      |    3    |
|     0111      |    4    |
|     1000      |    5    |
|     1001      |    6    |
|     1010      |    7    |
|     1011      |    8    |
|     1100      |    9    |                      

### 2 out of 5 code
- 2 out of the 5 bits are always high
- If output is anything other than the these then error is detected

| 2 out of 5 code | Decimal |
|:---------------:|:-------:|
|      00011      |    0    |
|      00101      |    1    |
|      00110      |    2    |
|      01001      |    3    |
|      01010      |    4    |
|      01100      |    5    |
|      10001      |    6    |
|      10010      |    7    |
|      10100      |    8    |
|      11000      |    9    |

### Gray code
- Adjacent 

| Gray code | decimal |
|:---------:|:-------:|
|   0000    |    0    |
|   0001    |    1    |
|   0011    |    2    |
|   0010    |    3    |
|   0110    |    4    |
|   1110    |    5    |
|   1010    |    6    |
|   1011    |    7    |
|   1001    |    8    |
|   1000    |    9    |

Or

| Gray code | decimal |
|:---------:|:-------:|
|   0000    |    0    |
|   0001    |    1    |
|   0011    |    2    |
|   0010    |    3    |
|   0110    |    4    |
|   0111    |    5    |
|   0101    |    6    |
|   0100    |    7    |
|   1100    |    8    |
|   1101    |    9    |
|   1111    |   10    |
|   1110    |   11    |
|   1010    |   12    |
|   1011    |   13    |
|   1001    |   14    |
|   1000    |   15    |

### Character representation
#### ASCII
- 8 bit numbers are used for representation of commonly used characters
- UTF-8 is a Unicode representation compatible with ASCII
- UTF-16 is not ASCII-compatible, but it is a Unicode encoding like UTF-8

## Representation of floating numberes

###