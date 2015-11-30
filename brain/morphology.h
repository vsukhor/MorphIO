
/* Copyright (c) 2013-2015, EPFL/Blue Brain Project
 *                          Juan Hernando <jhernando@fi.upm.es>
 *
 * This file is part of Brion <https://github.com/BlueBrain/Brion>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BRAIN_MORPHOLOGY
#define BRAIN_MORPHOLOGY

#include <brain/api.h>
#include <brain/types.h>

#include <boost/noncopyable.hpp>

namespace brain
{

/**
 * Wrapper around brion::Morphology with higher level functions.
 *
 * This class provides methods to facilitate some queries about morphologies
 * in the context of circuits.
 * Morphologies can be loaded with a transformation applied to its points,
 * which is useful for operating in global circuit coordinates.
 * The transformation is applied at construction so it cannot be modified or
 * reverted.
 *
 * Access to the raw data fields is still provided by getter functions.
 *
 * @version unstable
 */
class Morphology : public boost::noncopyable
{
public:
    /**
     * Create a morphology from a URI, load all the data and transform
     * the points.
     * @param source URI of the morphology data source.
     * @param transform the transformation matrix to apply to the points.
     *        Radii will not be affected by this transformation.
     */
    BRAIN_API Morphology( const URI& source, const Matrix4f& transform );

    /**
     * Create a morphology from a brion::Morphology, load all the data
     * and transform the points.
     * @param morphology the brion::Morphology to load from.
     * @param transform the transformation matrix to apply to the points.
     *        Radii will not be affected by this transformation.
     */
    BRAIN_API Morphology( const brion::Morphology& morphology,
                          const Matrix4f& transform );

    /**
     * Create a morphology from a URI and load all the data.
     * @param source URI of the morphology data source.
     */
    BRAIN_API Morphology( const URI& source );

    /**
     * Create a morphology from a brion::Morphology and load all the data.
     * @param morphology the brion::Morphology to load from.
     */
    BRAIN_API Morphology( const brion::Morphology& morphology );

    BRAIN_API ~Morphology();

    /** @copydoc brion::Morphology::getPoints */
    BRAIN_API const Vector4fs& getPoints() const;

    /** @copydoc brion::Morphology::getSections */
    BRAIN_API const Vector2is& getSections() const;

    /** @copydoc brion::Morphology::getSectionTypes */
    BRAIN_API const SectionTypes& getSectionTypes() const;

    /** @copydoc brion::Morphology::getApicals */
    BRAIN_API const Vector2is& getApicals() const;

    /**
     * Return the list of ids for the given section types.
     */
    BRAIN_API uint32_ts getSectionIDs( const SectionTypes& types ) const;

    /**
     * Return a list of points sampling a sections at discrete locations or all
     * the available points of no sample locations are given.
     *
     * @param sectionID Section to sample. If the section is the soma this
     *        function will return the soma position for all sampling positions.
     *        The soma position is assumed to be (0, 0, 0) unless the morphology
     *        has been transformed.
     * @param points Normalized positions of the sample points along the
     *        section. Values will be clampled to [0, 1] before sampling.
     * @return The vector with all the points of the section if points is empty.
     *         The section sampled at the given points otherwise.
     */
    BRAIN_API Vector4fs getSectionSamples(
        size_t sectionID, const floats& points = brion::floats( )) const;

private:
    class Impl;
    Impl* const _impl;
};

}
#endif
