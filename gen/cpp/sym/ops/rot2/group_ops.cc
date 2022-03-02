// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/ops/CLASS/group_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./group_ops.h"

#include <sym/rot2.h>

namespace sym {

/**
 *
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: <lambda>
 *
 * Args:
 *
 * Outputs:
 *     res: Rot2
 *
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::Identity() {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = 1;
  _res[1] = 0;

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::Inverse(const sym::Rot2<Scalar>& a) {
  // Total ops: 1

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _a[0];
  _res[1] = -_a[1];

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::Compose(const sym::Rot2<Scalar>& a,
                                                  const sym::Rot2<Scalar>& b) {
  // Total ops: 6

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 2, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _a[0] * _b[0] - _a[1] * _b[1];
  _res[1] = _a[0] * _b[1] + _a[1] * _b[0];

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply `compose(inverse(a), b)`.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::Between(const sym::Rot2<Scalar>& a,
                                                  const sym::Rot2<Scalar>& b) {
  // Total ops: 6

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 2, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _a[0] * _b[0] + _a[1] * _b[1];
  _res[1] = _a[0] * _b[1] - _a[1] * _b[0];

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *     res_D_a: (1x1) jacobian of res (1) wrt arg a (1)
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::InverseWithJacobian(const sym::Rot2<Scalar>& a,
                                                              SelfJacobian* const res_D_a) {
  // Total ops: 5

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _a[0];
  _res[1] = -_a[1];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = -std::pow(_a[0], Scalar(2)) - std::pow(_a[1], Scalar(2));
  }

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (1x1) jacobian of res (1) wrt arg a (1)
 *     res_D_b: (1x1) jacobian of res (1) wrt arg b (1)
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::ComposeWithJacobians(const sym::Rot2<Scalar>& a,
                                                               const sym::Rot2<Scalar>& b,
                                                               SelfJacobian* const res_D_a,
                                                               SelfJacobian* const res_D_b) {
  // Total ops: 11

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 2, 1>& _b = b.Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = _a[0] * _b[0] - _a[1] * _b[1];
  const Scalar _tmp1 = _a[0] * _b[1];
  const Scalar _tmp2 = _a[1] * _b[0];
  const Scalar _tmp3 = _tmp1 + _tmp2;
  const Scalar _tmp4 = std::pow(_tmp0, Scalar(2)) - _tmp3 * (-_tmp1 - _tmp2);

  // Output terms (3)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp3;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp4;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp4;
  }

  return sym::Rot2<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply `compose(inverse(a), b)`.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *     res_D_a: (1x1) jacobian of res (1) wrt arg a (1)
 *     res_D_b: (1x1) jacobian of res (1) wrt arg b (1)
 */
template <typename Scalar>
sym::Rot2<Scalar> GroupOps<Rot2<Scalar>>::BetweenWithJacobians(const sym::Rot2<Scalar>& a,
                                                               const sym::Rot2<Scalar>& b,
                                                               SelfJacobian* const res_D_a,
                                                               SelfJacobian* const res_D_b) {
  // Total ops: 15

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 2, 1>& _b = b.Data();

  // Intermediate terms (6)
  const Scalar _tmp0 = _a[0] * _b[0];
  const Scalar _tmp1 = _a[1] * _b[1];
  const Scalar _tmp2 = _tmp0 + _tmp1;
  const Scalar _tmp3 = _a[0] * _b[1];
  const Scalar _tmp4 = _a[1] * _b[0];
  const Scalar _tmp5 = _tmp3 - _tmp4;

  // Output terms (3)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _tmp2;
  _res[1] = _tmp5;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp2 * (-_tmp0 - _tmp1) - std::pow(_tmp5, Scalar(2));
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = std::pow(_tmp2, Scalar(2)) - _tmp5 * (-_tmp3 + _tmp4);
  }

  return sym::Rot2<Scalar>(_res);
}

}  // namespace sym

// Explicit instantiation
template struct sym::GroupOps<sym::Rot2<double>>;
template struct sym::GroupOps<sym::Rot2<float>>;
