/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2014 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifndef MATRIX_H
#define MATRIX_H

namespace MaliSDK
{
    /**
     * \brief Functions for manipulating matrices.
     */
    class Matrix
    {
        private:
            /**
             * \brief A 16 element floating point array used to represent a 4x4 matrix.
             * \note Items are stored in column major order as OpenGL ES expects them.
             */
            float elements[16];

            /**
             * \brief Multiply 2 matrices to return a third.
             * \note When multiplying matrices the ordering of the parameters affects the result.
             * \param[in] left First matrix to multiply.
             * \param[in] right Second matrix to multiply.
             * \return The result of left * right 
             */
            static Matrix multiply(Matrix* left, Matrix* right);

            /**
             * \brief A 4x4 identity Matrix;
             */
            static const float identityArray[];

        public:
            /**
             * \brief Get the matrix elements as a column major order array.
             * \return A pointer to the matrix elements.
             */
            float* getAsArray(void);

            /**
             * \brief Default constructor.
             */
            Matrix(void);

            /**
             * \brief Array operator for accessing the elements of the matrix.
             * \param[in] element The element index of the matrix (accepts 0-15).
             * \return The element of the matrix.
             */
            float& operator[](unsigned element);

            /**
             * \brief Multiply operator to post multiply a matrix by another.
             * \param[in] right The matrix to post multiply by.
             * \return The result of matrix * right.
             */
            Matrix operator*(Matrix right);

            /**
             * \brief Overloading assingment operater to do deep copy of the Matrix elements.
             */
            Matrix& operator=(const Matrix& another);

            /**
             * \brief Constructor from element array.
             * \param[in] array A column major order array to use as the matrix elements.
             */
            Matrix(const float* array);

            /**
             * \brief The identity matrix.
             *
             * A matrix with 1's on the main diagonal and 0's everywhere else.
             */
            static Matrix identityMatrix;

            /**
             * \brief Create and return a rotation matrix around the x-axis matrix.
             * \param[in] angle Angle of rotation (in degrees).
             * \return A rotation matrix around the x-axis matrix with the required angle of rotation.
             */
            static Matrix createRotationX(float angle);

            /**
             * \brief Create and return a rotation matrix around the y-axis matrix.
             * \param[in] angle Angle of rotation (in degrees).
             * \return A rotation matrix around the y-axis matrix with the required angle of rotation.
             */
            static Matrix createRotationY(float angle);

            /**
             * \brief Create and return a rotation matrix around the z-axis matrix.
             * \param[in] angle Angle of rotation (in degrees).
             * \return A rotation matrix around the z-axis matrix with the required angle of rotation.
             */
            static Matrix createRotationZ(float angle);

            /**
             * \brief Create and return an orthographic projection matrix.
             *
             * Assumes Z is positive going away from the user's view (left-hand coordinate system).
             * \param[in] left The coordinate for the left vertical clipping plane.
             * \param[in] right The coordinate for the right vertical clipping plane.
             * \param[in] bottom The coordinate for the bottom horizontal clipping plane.
             * \param[in] top The coordinate for the top horizontal clipping plane.
             * \param[in] zNear The distance from the camera to the near clipping plane.
             * \param[in] zFar the distance from the camera to the far clipping plane.
             * \return An orthographic projection matrix.
             */
            static Matrix matrixOrthographic(float left, float right, float bottom, float top, float zNear, float zFar);

            /**
             * \brief Create and return a perspective projection matrix. 
             * \param[in] FOV The field of view angle (in degrees) in the y direction. 
             * \param[in] ratio The ratio used to calculate the field of view in the x direction. 
             * The ratio of x (width) to y (height).
             * \param[in] zNear The distance from the camera to the near clipping plane. 
             * \param[in] zFar the distance from the camera to the far clipping plane. 
             * \return A perspective projection matrix.
             */
            static Matrix matrixPerspective(float FOV, float ratio, float zNear, float zFar);
    };
}
#endif  /* MATRIX_H */