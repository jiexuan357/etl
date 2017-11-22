//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

/*!
 * \file
 * \brief Contains generators for dropout mask
 */

#pragma once

#include <chrono> //for std::time

namespace etl {

/*!
 * \brief Selector helper to get an dropout_distribution based on the type (real or int)
 * \tparam T The type of return of the distribution
 */
template <typename T>
using dropout_distribution = std::conditional_t<
    std::is_floating_point<T>::value,
    std::uniform_real_distribution<T>,
    std::uniform_int_distribution<T>>;

/*!
 * \brief Generator from an uniform distribution
 */
template <typename T = double>
struct dropout_mask_generator_op {
    using value_type = T; ///< The value type

    T probability;                                 ///< The dropout probability
    random_engine rand_engine;                     ///< The random engine
    dropout_distribution<value_type> distribution; ///< The used distribution

    /*!
     * \brief Indicates if the operator can be computed on GPU
     */
    static constexpr bool gpu_computable = false;

    /*!
     * \brief Construct a new generator with the given start and end of the range
     */
    dropout_mask_generator_op(T probability)
            : probability(probability), rand_engine(std::time(nullptr)), distribution(T(0), T(1)) {}

    /*!
     * \brief Generate a new value
     * \return the newly generated value
     */
    value_type operator()() {
        if(distribution(rand_engine) < probability){
            return T(0);
        } else {
            return T(1);
        }
    }

    /*!
     * \brief Outputs the given generator to the given stream
     * \param os The output stream
     * \param s The generator
     * \return the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const dropout_mask_generator_op& s) {
        return os << "dropout(p=" << s.probability << ")";
    }
};

/*!
 * \brief Generator from an uniform distribution using a custom random engine.
 */
template <typename G, typename T = double>
struct dropout_mask_generator_g_op {
    using value_type = T; ///< The value type

    T probability;                                 ///< The dropout probability
    G& rand_engine;                                ///< The random engine
    dropout_distribution<value_type> distribution; ///< The used distribution

    /*!
     * \brief Indicates if the operator can be computed on GPU
     */
    static constexpr bool gpu_computable = false;

    /*!
     * \brief Construct a new generator with the given start and end of the range
     * \param start The beginning of the range
     * \param end The end of the range
     */
    dropout_mask_generator_g_op(G& g, T probability)
            : probability(probability), rand_engine(g), distribution(T(0), T(1)) {}

    /*!
     * \brief Generate a new value
     * \return the newly generated value
     */
    value_type operator()() {
        if(distribution(rand_engine) < probability){
            return T(0);
        } else {
            return T(1);
        }
    }

    /*!
     * \brief Outputs the given generator to the given stream
     * \param os The output stream
     * \param s The generator
     * \return the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const dropout_mask_generator_g_op& s) {
        return os << "dropout(p=" << s.probability << ")";
    }
};

} //end of namespace etl