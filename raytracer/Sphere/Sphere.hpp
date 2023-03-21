/* File: Sphere.hpp
**
** Description: Declaration of the Sphere class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Vector.hpp"
    #include "Ray.hpp"

    namespace RayTracer
    {

        /** \class Sphere
         * @brief Class representing a primitive sphere
         * 
         */
        class Sphere
        {
            public:
                /** @name Constructor/Destructor
                 *
                 */
                ///@{

                /** @brief Default constructor
                 * 
                 */
                Sphere() noexcept = default;

                /** @brief Constructor
                 * 
                 * @param center Center of the sphere
                 * @param radius Radius of the sphere
                 */
                Sphere(Maths::Vector<3> const& center, double radius) noexcept;

                /** @brief Copy constructor
                 * 
                 * @param b Sphere to copy
                 */
                Sphere(Sphere const& b) noexcept = default;

                /** @brief Move constructor
                 * 
                 * @param b Sphere to move
                 */
                Sphere(Sphere&& b) noexcept = default;

                /** @brief Destructor
                 * 
                 */
                ~Sphere() noexcept = default;

                ///@}

                /** @name Operators
                 *
                 */
                ///@{

                /** @brief Copy assignment operator
                 * 
                 * @param rhs Sphere to copy
                 * @return `Sphere&` Reference to the current sphere
                 */
                Sphere& operator=(Sphere const& rhs) noexcept = default;

                /** @brief Move assignment operator
                 * 
                 * @param rhs Sphere to move
                 * @return `Sphere&` Reference to the current sphere
                 */
                Sphere& operator=(Sphere&& rhs) noexcept = default;

                ///@}

                /** @name Getters/Setters
                 *
                 */
                ///@{

                /** @brief Get the center of the sphere
                 * 
                 * @return `Maths::Vector<3> const&` Center of the sphere
                 */
                Maths::Vector<3> const& getCenter() const noexcept;

                /** @brief Set the center of the sphere
                 * 
                 * @param center Center of the sphere
                 */
                void setCenter(Maths::Vector<3> const& center) noexcept;

                /** @brief Get the radius of the sphere
                 * 
                 * @return `double` Radius of the sphere
                 */
                double getRadius() const noexcept;

                /** @brief Set the radius of the sphere
                 * 
                 * @param radius Radius of the sphere
                 */
                void setRadius(double radius) noexcept;

                ///@}

                /** @name Member functions
                 *
                 */
                ///@{

                /** @brief Check if the sphere is hit by a ray
                 * 
                 * @param ray Ray to check
                 * @return `bool` True if the sphere is hit by the ray, false otherwise
                 */
                bool hit(Ray const& ray) noexcept;

                ///@}

            private:
                /// @brief Center of the sphere
                Maths::Vector<3>    _center;
                /// @brief Radius of the sphere
                double              _radius = 0.;
        };

    } /* namespace RayTracer */

#endif /* !RAY_HPP_ */