//=======================================================================
// Copyright (c) 2014-2018 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

/*!
 * \file
 * \brief EGBLAS wrappers for the apxdbpy operation.
 */

#pragma once

#ifdef ETL_EGBLAS_MODE

#include "etl/impl/cublas/cuda.hpp"

#include <egblas.hpp>

#endif

namespace etl::impl::egblas {

#ifdef EGBLAS_HAS_SAPXDBPY_3
static constexpr bool has_sapxdbpy_3 = true;
#else
static constexpr bool has_sapxdbpy_3 = false;
#endif

/*!
 * \brief Wrappers for single-precision egblas apxdbpy operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n, float alpha, float* A, size_t lda, float beta, float* B, size_t ldb, float* C, size_t ldc) {
#ifdef EGBLAS_HAS_SAPXDBPY_3
    inc_counter("egblas");
    egblas_sapxdbpy_3(n, alpha, A, lda, beta, B, ldb, C, ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy_3");
#endif
}

#ifdef EGBLAS_HAS_DAPXDBPY_3
static constexpr bool has_dapxdbpy_3 = true;
#else
static constexpr bool has_dapxdbpy_3 = false;
#endif

/*!
 * \brief Wrappers for double-precision egblas apxdbpy_3 operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n, double alpha, double* A, size_t lda, double beta, double* B, size_t ldb, double* C, size_t ldc) {
#ifdef EGBLAS_HAS_DAPXDBPY_3
    inc_counter("egblas");
    egblas_dapxdbpy_3(n, alpha, A, lda, beta, B, ldb, C, ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy_3");
#endif
}

#ifdef EGBLAS_HAS_CAPXDBPY_3
static constexpr bool has_capxdbpy_3 = true;
#else
static constexpr bool has_capxdbpy_3 = false;
#endif

/*!
 * \brief Wrappers for complex single-precision egblas apxdbpy_3 operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n,
                      std::complex<float> alpha,
                      std::complex<float>* A,
                      size_t lda,
                      std::complex<float> beta,
                      std::complex<float>* B,
                      size_t ldb,
                      std::complex<float>* C,
                      size_t ldc) {
#ifdef EGBLAS_HAS_CAPXDBPY_3
    inc_counter("egblas");
    egblas_capxdbpy_3(n, complex_cast(alpha), reinterpret_cast<cuComplex*>(A), lda, complex_cast(beta), reinterpret_cast<cuComplex*>(B), ldb,
                      reinterpret_cast<cuComplex*>(C), ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy_3");
#endif
}

/*!
 * \brief Wrappers for complex single-precision egblas apxdbpy_3 operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n,
                      etl::complex<float> alpha,
                      etl::complex<float>* A,
                      size_t lda,
                      etl::complex<float> beta,
                      etl::complex<float>* B,
                      size_t ldb,
                      etl::complex<float>* C,
                      size_t ldc) {
#ifdef EGBLAS_HAS_CAPXDBPY_3
    inc_counter("egblas");
    egblas_capxdbpy_3(n, complex_cast(alpha), reinterpret_cast<cuComplex*>(A), lda, complex_cast(beta), reinterpret_cast<cuComplex*>(B), ldb,
                      reinterpret_cast<cuComplex*>(C), ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy");
#endif
}

#ifdef EGBLAS_HAS_ZAPXDBPY_3
static constexpr bool has_zapxdbpy_3 = true;
#else
static constexpr bool has_zapxdbpy_3 = false;
#endif

/*!
 * \brief Wrappers for complex double-precision egblas apxdbpy_3 operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n,
                      std::complex<double> alpha,
                      std::complex<double>* A,
                      size_t lda,
                      std::complex<double> beta,
                      std::complex<double>* B,
                      size_t ldb,
                      std::complex<double>* C,
                      size_t ldc) {
#ifdef EGBLAS_HAS_ZAPXDBPY_3
    inc_counter("egblas");
    egblas_zapxdbpy_3(n, complex_cast(alpha), reinterpret_cast<cuDoubleComplex*>(A), lda, complex_cast(beta), reinterpret_cast<cuDoubleComplex*>(B), ldb,
                      reinterpret_cast<cuDoubleComplex*>(C), ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy_3");
#endif
}

/*!
 * \brief Wrappers for complex double-precision egblas apxdbpy_3 operation
 * \param n The size of the vector
 * \param alpha The scaling factor alpha
 * \param A The memory of the vector a
 * \param lda The leading dimension of a
 * \param B The memory of the vector b
 * \param ldb The leading dimension of b
 */
inline void apxdbpy_3(size_t n,
                      etl::complex<double> alpha,
                      etl::complex<double>* A,
                      size_t lda,
                      etl::complex<double> beta,
                      etl::complex<double>* B,
                      size_t ldb,
                      etl::complex<double>* C,
                      size_t ldc) {
#ifdef EGBLAS_HAS_ZAPXDBPY_3
    inc_counter("egblas");
    egblas_zapxdbpy_3(n, complex_cast(alpha), reinterpret_cast<cuDoubleComplex*>(A), lda, complex_cast(beta), reinterpret_cast<cuDoubleComplex*>(B), ldb,
                      reinterpret_cast<cuDoubleComplex*>(C), ldc);
#else
    cpp_unused(n);
    cpp_unused(alpha);
    cpp_unused(A);
    cpp_unused(lda);
    cpp_unused(beta);
    cpp_unused(B);
    cpp_unused(ldb);
    cpp_unused(C);
    cpp_unused(ldc);

    cpp_unreachable("Invalid call to egblas::apxdbpy_3");
#endif
}

} //end of namespace etl::impl::egblas
