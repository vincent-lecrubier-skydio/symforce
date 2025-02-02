// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     geo_package/ops/scalar/lie_group_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <cstdint>
#include <type_traits>

#include "../lie_group_ops.h"

namespace sym {
namespace scalar {

/**
 * C++ LieGroupOps implementation for scalars.
 */
template <typename T>
struct LieGroupOps : public internal::LieGroupOpsBase<T, T> {
  using Scalar = T;
  static_assert(std::is_floating_point<T>::value, "");

  static constexpr int32_t TangentDim() {
    return 1;
  }
  using TangentVec = Eigen::Matrix<T, 1, 1>;
  static T FromTangent(const TangentVec& vec, const T epsilon) {
    return vec[0];
  }
  static TangentVec ToTangent(const T& a, const T epsilon) {
    return TangentVec::Constant(a);
  }
  static T Retract(const T& a, const TangentVec& vec, const T epsilon) {
    return a + vec[0];
  }
  static TangentVec LocalCoordinates(const T& a, const T& b, const T epsilon) {
    return TangentVec::Constant(b - a);
  }
};

}  // namespace scalar

template <>
struct LieGroupOps<double> : public scalar::LieGroupOps<double> {};
template <>
struct LieGroupOps<float> : public scalar::LieGroupOps<float> {};

}  // namespace sym

// Explicit instantiation
extern template struct sym::LieGroupOps<double>;
extern template struct sym::LieGroupOps<float>;
