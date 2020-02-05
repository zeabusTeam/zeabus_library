// FILE			: escape_code.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 07 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
// This file will manage about ANSI Escape sequence 
// This escape sequence can use in MISRA C++ 2018 by RULE 2-13-1 REQUIRED
//      DETAIL : Only those escape sequence that are defined in ISO/IEC 14882:2003 shall be use
// That ISO/IEC include \n, \t, \v, \b, \r, \f, \a, \\, \?, \', \", \<Oct Number>, \x<Hex Num>

// REFERENCE
// Refernece 
//  : http://ascii-table.com/ansi-escape-sequences-vt-100.php
//  : http://ascii-table.com/ansi-escape-sequences.php
//  : https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character
//  : https://stackoverflow.com/questions/37774983/clearing-the-screen-by-printing-a-character/37778152

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#ifndef _ZEABUS_ESCAPE_CODE_HPP_
#define _ZEABUS_ESCAPE_CODE_HPP_

namespace zeabus
{

namespace escape_code
{

    const static std::string normal_red = "\x1B[0;31m";
    const static std::string normal_green = "\x1B[0;32m";
    const static std::string normal_yellow = "\x1B[0;33m";
    const static std::string normal_blue = "\x1B[0;34m";
    const static std::string normal_margenta = "\x1B[0;35m";
    const static std::string normal_cyan = "\x1B[0;36m";
    const static std::string normal_white = "\x1B[0;37m";
 
    const static std::string bold_red = "\x1B[1;31m";
    const static std::string bold_green = "\x1B[1;32m";
    const static std::string bold_yellow = "\x1B[1;33m";
    const static std::string bold_blue = "\x1B[1;34m";
    const static std::string bold_margenta = "\x1B[1;35m";
    const static std::string bold_cyan = "\x1B[0;36m";
    const static std::string bold_white = "\x1B[1;37m";

    const static std::string screen_reset = "\033c";
    const static std::string screen_home = "\033[H";
    const static std::string screen_clear = "\033[2J";

} // namespace escape_code

} // namespace zeabus

#endif
