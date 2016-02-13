# Installation

Unix install instructions:

    git clone https://github.com/nicoaw/smi.git
    cd smi
    cmake src/
    make
    sudo make install

# Description

smi is a small command-line program to interpret simple math expressions. It should work on all major platforms (Linux, Mac, and Windows). To start the interpreter type:

    smi

As you can see, so far there are no options.

# Usage

The interpreter supports addition `+`, subtraction `-`, multiplication `*`, division `/`, exponents `^`, factorials `!`, and parenthesis `( )`. You can also assign values to names with `=`. Variable names must begin with a character but can contain numbers as well. Names are case-sensitive.

# Constants

All of the supported constants. Variables cannot share names with these constants.

    >> e
    2.7182818284590451

    >> inf
    inf

    >> nan
    nan

    >> pi
    3.1415926535897931

# Functions

All of the supported functions. Variables cannot share names with these functions.

    abs(x): absolute value of x
    acos(x): inverse cosine of x
    acosh(x): inverse hyperbolic cosine of x
    asin(x): inverse sine of x
    asinh(x): inverse hyperbolic sine of x
    atan(x): inverse tangent of x
    atanh(x): inverse hyperbolic tangent of x
    ceil(x): ceiling of x
    cos(x): cosine of x
    cosh(x): hyperbolic cosine of x
    exp(x): exponential of x
    floor(x): floor of x
    log(x): natural logarithm of x
    log10(x): logarithm base 10 of x
    log2(x): logarithm base 2 of x
    round(x): rounded value of x
    sgn(x): sign of x
    sin(x): sine of x
    sinh(x): hyperbolic sine of x
    sqrt(x): square root of x
    tan(x): tangent of x
    tanh(x): hyperbolic tangent of x
    trunc(x): truncated value of x

# Examples

Here are some example expressions the interpreter can calculate:

    >> (8^2+4^2)^0.5
    8.9442719099991592

    >> 9!/(9-3)!
    504

    >> cos(33)^2+sin(33)^2
    1

    >> a=1
    1
    >> a=a+a
    2
    >> a=a+a
    4
    >> a=a+a
    8
