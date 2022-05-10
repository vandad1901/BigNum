# BigNum

Two C++ classes that implement Big Number functionality.

## Usage

### 1. UBigBum

The class `UBigNum` defines an unsigned Big Number with a maximum length of `std::String::max_size`.

It has two constructors with the following prototypes

```C++
UBignum(std::string =  "0");
UBignum(long  long  int);
```

### 2. SBigBum

The class `BigNum` defines an signed Big Number with a maximum length of `std::String::max_size`.

It has three constructors with the following prototypes

```C++
Bignum(std::string =  "0");
Bignum(UBignum,  bool  =  false);
Bignum(long  long  int);
```

## Overloads

Both classes overload all comparison operators, basic arithmetic operators `+, -, *, / and %` and the subscript operator. `BigNum` also overloads the unary `-` operator.

Both classes also support input/output via the stream insertion and stream extraction operators `<<` and `>>`.

## Additional functions

Both classes also have a function names `printWithDelimiter()` which is self-explanatory, a `length()` function which returns the length of the number (number of digits) and all relevant setters and getters
