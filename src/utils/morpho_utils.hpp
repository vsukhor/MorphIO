/*
 * Copyright (C) 2015 Adrien Devresse <adrien.devresse@epfl.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **/
#ifndef MORPHO_UTILS_HPP
#define MORPHO_UTILS_HPP

#include <string>
#include <iostream>


namespace morpho{

//
// step by step logger utility
class step_logger{
public:
    inline step_logger() : _inc(1) {}

    inline void operator()(const std::string & message){
        std::cout << _inc++ << "- " << message << std::endl;
    }

private:
    std::size_t _inc;
};


}

#endif // MORPHO_UTILS_HPP