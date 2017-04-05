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
 *
 */
#ifndef MORPHO_TRANSFORM_FILTERS_HPP
#define MORPHO_TRANSFORM_FILTERS_HPP

#include <morpho/morpho_tree.hpp>
#include <morpho/morpho_transform.hpp>

namespace morpho{

class morpho_operation;

///
/// \brief  delete_duplicate_point_operation
///
/// transform operations : Remove any consecutive duplicated point in every branch
///  of a given morpho-tree
///
class delete_duplicate_point_operation : public morpho_operation{
public:
    delete_duplicate_point_operation();


    morpho_tree apply(const morpho_tree &tree) override;

    std::string name() const override;

};



} // morpho


#endif // MORPHO_TRANSFORM_FILTERS_HPP
