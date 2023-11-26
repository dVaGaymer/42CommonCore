#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <cerrno>
#include <cmath>
#include <iostream>

enum types {
  CHAR_TYPE = 0,
  INT_TYPE,
  FLOAT_TYPE,
  FLOAT_TYPE_LARGE,
  DOUBLE_TYPE,
  DOUBLE_TYPE_LARGE,
  UNDEFINED_TYPE
};

#define MAX_CHAR 127
#define MAX_CHAR_DISPLAYABLE 126
#define MIN_CHAR -128
#define MIN_CHAR_DISPLAYABLE 32

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define MAX_FLOAT 340282346638528859811704183484516925440.0f
#define MIN_FLOAT -340282346638528859811704183484516925440.0f

#define MAX_DOUBLE                                                             \
  179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
#define MIN_DOUBLE                                                             \
  -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &o);
  ~ScalarConverter();
  ScalarConverter &operator=(ScalarConverter const &o);

public:
  static void convert(std::string const &literal);
};
#endif