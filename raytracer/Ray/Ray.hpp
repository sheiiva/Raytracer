/* File: Ray.hpp
**
** Description: Declaration of the Ray class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Vector.hpp"

    namespace RayTracer
    {

        /** \class Ray
         * @brief Class representing a ray
         * 
         */
        class Ray
        {
            public:
                /** @name Constructor/Destructor
                 *
                 */
                ///@{

                /** @brief Default constructor
                 * 
                 */
                Ray() noexcept = default;

                /** @brief Constructor
                 * 
                 * @param origin Origin of the ray
                 * @param direction Direction of the ray
                 */
                Ray(Maths::Vector<3> const& origin, Maths::Vector<3> const& direction) noexcept;

                /** @brief Copy constructor
                 * 
                 * @param b Ray to copy
                 */
                Ray(Ray const& b) noexcept;

                /** @brief Move constructor
                 * 
                 * @param b Ray to move
                 */
                Ray(Ray&& b) noexcept;

                /** @brief Destructor
                 * 
                 */
                ~Ray() noexcept = default;

                ///@}

                /** @name Operators
                 *
                 */
                ///@{

                /** @brief Copy assignment operator
                 * 
                 * @param rhs Ray to copy
                 * @return `Ray&` Reference to the current ray
                 */
                Ray& operator=(Ray const& rhs) noexcept;

                /** @brief Move assignment operator
                 * 
                 * @param rhs Ray to move
                 * @return `Ray&` Reference to the current ray
                 */
                Ray& operator=(Ray&& rhs) noexcept;

                ///@}

                /** @name Getters/Setters
                 *
                 */
                ///@{

                /** @brief Get the origin of the ray
                 * 
                 * @return `Maths::Vector<3> const&` Constant reference to the origin of the ray
                 */
                Maths::Vector<3> const& getOrigin() const noexcept;

                /** @brief Set the origin of the ray
                 * 
                 * @param origin New origin of the ray
                 */
                void setOrigin(Maths::Vector<3> const& origin) noexcept;

                /** @brief Get the direction of the ray
                 * 
                 * @return `Maths::Vector<3> const&` Constant reference to the direction of the ray
                 */
                Maths::Vector<3> const& getDirection() const noexcept;

                /** @brief Set the direction of the ray
                 * 
                 * @param direction New direction of the ray
                 */
                void setDirection(Maths::Vector<3> const& direction) noexcept;

                ///@}

            private:
                /// @brief Origin of the ray
                Maths::Vector<3> _origin;
                /// @brief Direction of the ray
                Maths::Vector<3> _direction;
        };

    } /* namespace RayTracer */

#endif /* !RAY_HPP_ */