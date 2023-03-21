/* File: Camera.hpp
**
** Description: Definition of the Camera class
**
** 2023, March 16
** Author: Corentin COUTRET-ROZET (corentin.rozet@epitech.eu)
**
** Copyright 2023, Corentin COUTRET-ROZET
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Vector.hpp"
    #include "Ray.hpp"

    namespace RayTracer
    {

        /** \class Camera
         * @brief Class representing a camera
         * 
         */
        class Camera
        {
            public:

                /** @name Constructor/Destructor
                 *
                 */
                ///@{

                /** @brief Default constructor
                 * 
                 */
                Camera() noexcept = default;

                /** @brief Copy constructor
                 * 
                 * @param b Camera to copy
                 */
                Camera(Camera const& b) noexcept = default;

                /** @brief Move constructor
                 * 
                 * @param b Camera to move
                 */
                Camera(Camera&& b) noexcept = default;

                /** @brief Destructor
                 * 
                 */
                ~Camera() noexcept = default;

                ///@}

                /* @name Operators
                 *
                 */
                ///@{

                /** @brief Copy assignment operator
                 * 
                 * @param rhs Camera to copy
                 * @return `Camera&` Reference to the current camera
                 */
                Camera& operator=(Camera const& rhs) noexcept = default;

                /** @brief Move assignment operator
                 * 
                 * @param rhs Camera to move
                 * @return `Camera&` Reference to the current camera
                 */
                Camera& operator=(Camera&& rhs) noexcept = default;
                ///@}

                /** @name Getters/Setters
                 *
                 */
                ///@{

                /** @brief Get the origin of the camera
                 * 
                 * @return `Maths::Vector<3> const&` Reference to the origin of the camera
                 */
                Maths::Vector<3> const& getOrigin() const noexcept;

                /** @brief Set the origin of the camera
                 * 
                 * @param origin New origin of the camera
                 */
                void setOrigin(Maths::Vector<3> const& origin) noexcept;

                /** @brief Get the horizontal size vector
                 * 
                 * @return `Maths::Vector<3> const&` Reference to the horizontal size vector
                 */
                Maths::Vector<3> const& getHorizontal() const noexcept;

                /** @brief Set the horizontal size vector
                 * 
                 * @param horizontal New horizontal size vector
                 */
                void setHorizontal(Maths::Vector<3> const& horizontal) noexcept;

                /** @brief Get the vertical size vector
                 * 
                 * @return `Maths::Vector<3> const&` Reference to the vertical size vector
                 */
                Maths::Vector<3> const& getVertical() const noexcept;

                /** @brief Set the vertical size vector
                 * 
                 * @param vertical New vertical size vector
                 */
                void setVertical(Maths::Vector<3> const& vertical) noexcept;

                /** @brief Get the lower left corner of the camera
                 * 
                 * @return `Maths::Vector<3> const&` Reference to the lower left corner of the camera
                 */
                Maths::Vector<3> const& getLowerLeftCorner() const noexcept;

                /** @brief Set the lower left corner of the camera
                 * 
                 * @param lowerLeftCorner New lower left corner of the camera
                 */
                void setLowerLeftCorner(Maths::Vector<3> const& lowerLeftCorner) noexcept;

                ///@}

                /** @name Member functions
                 *
                 */
                ///@{

                /** @brief Get a ray from the camera
                 * 
                 * @param u Horizontal coordinate
                 * @param v Vertical coordinate
                 * @return `Ray` Ray from the camera
                 */
                Ray ray(double u, double v) const noexcept;

                ///@}

            private:
                /// @brief Origin of the camera
                Maths::Vector<3>    _origin;
                /// @brief Horizontal size vector
                Maths::Vector<3>    _horizontal;
                /// @brief Vertical size vector
                Maths::Vector<3>    _vertical;
                /// @brief Lower left corner of the camera
                Maths::Vector<3>    _lowerLeftCorner;
        };

    } /* namespace RayTracer */

#endif /* !CAMERA_HPP_ */