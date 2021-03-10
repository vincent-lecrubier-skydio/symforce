//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./group_ops.h"

namespace sym {
namespace pose2 {

/**
 *
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: <lambda>
 * Arg type(s):
 * Return type(s): Pose2
 *
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Scalar>::Identity() {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = 1;
  _res[1] = 0;
  _res[2] = 0;
  _res[3] = 0;

  return sym::Pose2<Scalar>(_res);
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
sym::Pose2<Scalar> GroupOps<Scalar>::Inverse(const sym::Pose2<Scalar>& a) {
  // Total ops: 16

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (3)
  const Scalar _tmp0 = 1.0 / ((_a[0] * _a[0]) + (_a[1] * _a[1]));
  const Scalar _tmp1 = _a[0] * _tmp0;
  const Scalar _tmp2 = _a[1] * _tmp0;

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp1;
  _res[1] = -_tmp2;
  _res[2] = -_a[2] * _tmp1 - _a[3] * _tmp2;
  _res[3] = _a[2] * _tmp2 - _a[3] * _tmp1;

  return sym::Pose2<Scalar>(_res);
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
sym::Pose2<Scalar> GroupOps<Scalar>::Compose(const sym::Pose2<Scalar>& a,
                                             const sym::Pose2<Scalar>& b) {
  // Total ops: 16

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0] * _b[0] - _a[1] * _b[1];
  _res[1] = _a[0] * _b[1] + _a[1] * _b[0];
  _res[2] = _a[0] * _b[2] - _a[1] * _b[3] + _a[2];
  _res[3] = _a[0] * _b[3] + _a[1] * _b[2] + _a[3];

  return sym::Pose2<Scalar>(_res);
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
sym::Pose2<Scalar> GroupOps<Scalar>::Between(const sym::Pose2<Scalar>& a,
                                             const sym::Pose2<Scalar>& b) {
  // Total ops: 33

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = 1.0 / ((_a[0] * _a[0]) + (_a[1] * _a[1]));
  const Scalar _tmp1 = _a[1] * _tmp0;
  const Scalar _tmp2 = _a[0] * _tmp0;
  const Scalar _tmp3 = _a[3] * _tmp0;
  const Scalar _tmp4 = _a[2] * _tmp0;

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _b[0] * _tmp2 + _b[1] * _tmp1;
  _res[1] = -_b[0] * _tmp1 + _b[1] * _tmp2;
  _res[2] = -_a[0] * _tmp4 - _a[1] * _tmp3 + _b[2] * _tmp2 + _b[3] * _tmp1;
  _res[3] = -_a[0] * _tmp3 + _a[1] * _tmp4 - _b[2] * _tmp1 + _b[3] * _tmp2;

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *     geo.Matrix: Jacobian for arg 0 (a)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Scalar>::InverseWithJacobian(
    const sym::Pose2<Scalar>& a, Eigen::Matrix<Scalar, 3, 3>* const res_D_a) {
  // Total ops: 97

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (24)
  const Scalar _tmp0 = (_a[1] * _a[1]);
  const Scalar _tmp1 = (_a[0] * _a[0]);
  const Scalar _tmp2 = _tmp0 + _tmp1;
  const Scalar _tmp3 = 1.0 / (_tmp2);
  const Scalar _tmp4 = _a[0] * _tmp3;
  const Scalar _tmp5 = _a[1] * _tmp3;
  const Scalar _tmp6 = _a[3] * _tmp3;
  const Scalar _tmp7 = _a[2] * _tmp3;
  const Scalar _tmp8 = std::pow(_tmp2, -2);
  const Scalar _tmp9 = _tmp0 * _tmp8;
  const Scalar _tmp10 = _tmp1 * _tmp8;
  const Scalar _tmp11 = -_tmp10 - _tmp9;
  const Scalar _tmp12 = _a[0] * _tmp11;
  const Scalar _tmp13 = _a[1] * _tmp11;
  const Scalar _tmp14 = 2 * _tmp9;
  const Scalar _tmp15 = 2 * _a[0] * _a[1] * _tmp8;
  const Scalar _tmp16 = -_a[3] * _tmp15;
  const Scalar _tmp17 = _a[2] * _tmp14 + _tmp16 - _tmp7;
  const Scalar _tmp18 = _a[2] * _tmp15;
  const Scalar _tmp19 = -_a[3] * _tmp14 - _tmp18 + _tmp6;
  const Scalar _tmp20 = 2 * _tmp10;
  const Scalar _tmp21 = -_a[3] * _tmp20 + _tmp18 + _tmp6;
  const Scalar _tmp22 = -_a[2] * _tmp20 + _tmp16 + _tmp7;
  const Scalar _tmp23 = 2 / (_tmp2 * _tmp2 * _tmp2);

  // Output terms (2)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp4;
  _res[1] = -_tmp5;
  _res[2] = -_a[0] * _tmp7 - _a[1] * _tmp6;
  _res[3] = -_a[0] * _tmp6 + _a[1] * _tmp7;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp12;
    _res_D_a(0, 1) = -_tmp13;
    _res_D_a(0, 2) =
        _a[0] * (_tmp17 * _tmp5 - _tmp19 * _tmp4) - _a[1] * (_tmp21 * _tmp5 - _tmp22 * _tmp4);
    _res_D_a(1, 0) = _tmp13;
    _res_D_a(1, 1) = _tmp12;
    _res_D_a(1, 2) =
        _a[0] * (-_tmp17 * _tmp4 - _tmp19 * _tmp5) - _a[1] * (-_tmp21 * _tmp4 - _tmp22 * _tmp5);
    _res_D_a(2, 0) = 0;
    _res_D_a(2, 1) = 0;
    _res_D_a(2, 2) = _a[0] * (-_a[0] * _tmp0 * _tmp23 + _tmp4 * (_tmp14 - _tmp3)) -
                     _a[1] * (_a[1] * _tmp1 * _tmp23 + _tmp5 * (-_tmp20 + _tmp3));
  }

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     geo.Matrix: Jacobian for arg 0 (a)
 *     geo.Matrix: Jacobian for arg 1 (b)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Scalar>::ComposeWithJacobians(
    const sym::Pose2<Scalar>& a, const sym::Pose2<Scalar>& b,
    Eigen::Matrix<Scalar, 3, 3>* const res_D_a, Eigen::Matrix<Scalar, 3, 3>* const res_D_b) {
  // Total ops: 65

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (13)
  const Scalar _tmp0 = _a[0] * _b[0] - _a[1] * _b[1];
  const Scalar _tmp1 = _a[0] * _b[1] + _a[1] * _b[0];
  const Scalar _tmp2 = _a[0] * _tmp0 + _a[1] * _tmp1;
  const Scalar _tmp3 = _a[0] * _tmp1;
  const Scalar _tmp4 = _a[1] * _tmp0;
  const Scalar _tmp5 = _tmp3 - _tmp4;
  const Scalar _tmp6 = _b[2] * _tmp1;
  const Scalar _tmp7 = _b[3] * _tmp0;
  const Scalar _tmp8 = _b[2] * _tmp0 + _b[3] * _tmp1;
  const Scalar _tmp9 = -_tmp3 + _tmp4;
  const Scalar _tmp10 = _b[0] * _tmp2;
  const Scalar _tmp11 = _b[1] * _tmp2;
  const Scalar _tmp12 = -_b[1] * _tmp9 + _tmp10;

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp1;
  _res[2] = _a[0] * _b[2] - _a[1] * _b[3] + _a[2];
  _res[3] = _a[0] * _b[3] + _a[1] * _b[2] + _a[3];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp2;
    _res_D_a(0, 1) = _tmp5;
    _res_D_a(0, 2) = _a[0] * (_tmp6 - _tmp7) - _a[1] * _tmp8;
    _res_D_a(1, 0) = _tmp9;
    _res_D_a(1, 1) = _tmp2;
    _res_D_a(1, 2) = _a[0] * _tmp8 - _a[1] * (-_tmp6 + _tmp7);
    _res_D_a(2, 0) = 0;
    _res_D_a(2, 1) = 0;
    _res_D_a(2, 2) =
        _a[0] * (_b[0] * _tmp0 + _b[1] * _tmp1) - _a[1] * (-_b[0] * _tmp1 + _b[1] * _tmp0);
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _b[1] * _tmp5 + _tmp10;
    _res_D_b(0, 1) = _b[0] * _tmp5 - _tmp11;
    _res_D_b(0, 2) = 0;
    _res_D_b(1, 0) = _b[0] * _tmp9 + _tmp11;
    _res_D_b(1, 1) = _tmp12;
    _res_D_b(1, 2) = 0;
    _res_D_b(2, 0) = 0;
    _res_D_b(2, 1) = 0;
    _res_D_b(2, 2) = _tmp12;
  }

  return sym::Pose2<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply `compose(inverse(a), b)`.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *     geo.Matrix: Jacobian for arg 0 (a)
 *     geo.Matrix: Jacobian for arg 1 (b)
 */
template <typename Scalar>
sym::Pose2<Scalar> GroupOps<Scalar>::BetweenWithJacobians(
    const sym::Pose2<Scalar>& a, const sym::Pose2<Scalar>& b,
    Eigen::Matrix<Scalar, 3, 3>* const res_D_a, Eigen::Matrix<Scalar, 3, 3>* const res_D_b) {
  // Total ops: 173

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (41)
  const Scalar _tmp0 = (_a[1] * _a[1]);
  const Scalar _tmp1 = (_a[0] * _a[0]);
  const Scalar _tmp2 = _tmp0 + _tmp1;
  const Scalar _tmp3 = 1.0 / (_tmp2);
  const Scalar _tmp4 = _b[1] * _tmp3;
  const Scalar _tmp5 = _b[0] * _tmp3;
  const Scalar _tmp6 = _a[0] * _tmp5 + _a[1] * _tmp4;
  const Scalar _tmp7 = _a[0] * _tmp4 - _a[1] * _tmp5;
  const Scalar _tmp8 = _a[3] * _tmp3;
  const Scalar _tmp9 = _a[2] * _tmp3;
  const Scalar _tmp10 = _b[3] * _tmp3;
  const Scalar _tmp11 = _b[2] * _tmp3;
  const Scalar _tmp12 = _tmp3 * _tmp7;
  const Scalar _tmp13 = _a[0] * _tmp12;
  const Scalar _tmp14 = _tmp3 * _tmp6;
  const Scalar _tmp15 = _a[1] * _tmp14;
  const Scalar _tmp16 = -_tmp13 - _tmp15;
  const Scalar _tmp17 = _a[1] * _tmp12;
  const Scalar _tmp18 = _a[0] * _tmp14;
  const Scalar _tmp19 = _tmp17 - _tmp18;
  const Scalar _tmp20 = _a[0] * _tmp19;
  const Scalar _tmp21 = _a[1] * _tmp19;
  const Scalar _tmp22 = 2 / (_tmp2 * _tmp2);
  const Scalar _tmp23 = _tmp0 * _tmp22;
  const Scalar _tmp24 = _a[0] * _a[1] * _tmp22;
  const Scalar _tmp25 = _a[3] * _tmp24 - _b[3] * _tmp24;
  const Scalar _tmp26 = -_a[2] * _tmp23 + _b[2] * _tmp23 - _tmp11 + _tmp25 + _tmp9;
  const Scalar _tmp27 = _a[2] * _tmp24;
  const Scalar _tmp28 = _b[2] * _tmp24;
  const Scalar _tmp29 = _tmp10 - _tmp8;
  const Scalar _tmp30 = _a[3] * _tmp23 - _b[3] * _tmp23 + _tmp27 - _tmp28 + _tmp29;
  const Scalar _tmp31 = _tmp1 * _tmp22;
  const Scalar _tmp32 = _a[3] * _tmp31 - _b[3] * _tmp31 - _tmp27 + _tmp28 + _tmp29;
  const Scalar _tmp33 = _a[2] * _tmp31 - _b[2] * _tmp31 + _tmp11 + _tmp25 - _tmp9;
  const Scalar _tmp34 = _tmp13 + _tmp15;
  const Scalar _tmp35 = -_b[1] * _tmp24;
  const Scalar _tmp36 = _b[0] * _tmp24;
  const Scalar _tmp37 = -_tmp17 + _tmp18;
  const Scalar _tmp38 = _b[0] * _tmp37;
  const Scalar _tmp39 = _b[1] * _tmp37;
  const Scalar _tmp40 = -_b[1] * _tmp16 + _tmp38;

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp6;
  _res[1] = _tmp7;
  _res[2] = _a[0] * _tmp11 - _a[0] * _tmp9 + _a[1] * _tmp10 - _a[1] * _tmp8;
  _res[3] = _a[0] * _tmp10 - _a[0] * _tmp8 - _a[1] * _tmp11 + _a[1] * _tmp9;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _a[1] * _tmp16 + _tmp20;
    _res_D_a(0, 1) = _a[0] * _tmp16 - _tmp21;
    _res_D_a(0, 2) =
        _a[0] * (_tmp26 * _tmp7 + _tmp30 * _tmp6) - _a[1] * (_tmp32 * _tmp7 + _tmp33 * _tmp6);
    _res_D_a(1, 0) = _a[0] * _tmp34 + _tmp21;
    _res_D_a(1, 1) = -_a[1] * _tmp34 + _tmp20;
    _res_D_a(1, 2) =
        _a[0] * (_tmp26 * _tmp6 - _tmp30 * _tmp7) - _a[1] * (_tmp32 * _tmp6 - _tmp33 * _tmp7);
    _res_D_a(2, 0) = 0;
    _res_D_a(2, 1) = 0;
    _res_D_a(2, 2) = _a[0] * (_tmp6 * (_b[0] * _tmp23 + _tmp35 - _tmp5) -
                              _tmp7 * (-_b[1] * _tmp23 - _tmp36 + _tmp4)) -
                     _a[1] * (_tmp6 * (-_b[1] * _tmp31 + _tmp36 + _tmp4) -
                              _tmp7 * (-_b[0] * _tmp31 + _tmp35 + _tmp5));
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _b[1] * _tmp34 + _tmp38;
    _res_D_b(0, 1) = _b[0] * _tmp34 - _tmp39;
    _res_D_b(0, 2) = 0;
    _res_D_b(1, 0) = _b[0] * _tmp16 + _tmp39;
    _res_D_b(1, 1) = _tmp40;
    _res_D_b(1, 2) = 0;
    _res_D_b(2, 0) = 0;
    _res_D_b(2, 1) = 0;
    _res_D_b(2, 2) = _tmp40;
  }

  return sym::Pose2<Scalar>(_res);
}

}  // namespace pose2
}  // namespace sym

// Explicit instantiation
template struct sym::pose2::GroupOps<double>;
template struct sym::pose2::GroupOps<float>;
