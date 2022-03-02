// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     res_D_b: (6x6) jacobian of res (6) wrt arg b (6)
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 6, 6> ComposePose3Jacobian1(const sym::Pose3<Scalar>& a,
                                                  const sym::Pose3<Scalar>& b) {
  // Total ops: 149

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (64)
  const Scalar _tmp0 = _a[0] * _b[1];
  const Scalar _tmp1 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp2 = _a[2] * _b[3];
  const Scalar _tmp3 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp4 = _a[3] * _b[2];
  const Scalar _tmp5 = (Scalar(1) / Scalar(2)) * _tmp4;
  const Scalar _tmp6 = _a[1] * _b[0];
  const Scalar _tmp7 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp8 = _tmp1 + _tmp3 + _tmp5 - _tmp7;
  const Scalar _tmp9 = _tmp0 + _tmp2 + _tmp4 - _tmp6;
  const Scalar _tmp10 = 2 * _tmp9;
  const Scalar _tmp11 = _a[3] * _b[1];
  const Scalar _tmp12 = (Scalar(1) / Scalar(2)) * _tmp11;
  const Scalar _tmp13 = _a[1] * _b[3];
  const Scalar _tmp14 = (Scalar(1) / Scalar(2)) * _tmp13;
  const Scalar _tmp15 = _a[0] * _b[2];
  const Scalar _tmp16 = (Scalar(1) / Scalar(2)) * _tmp15;
  const Scalar _tmp17 = _a[2] * _b[0];
  const Scalar _tmp18 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp19 = -_tmp12 - _tmp14 + _tmp16 - _tmp18;
  const Scalar _tmp20 = _tmp11 + _tmp13 - _tmp15 + _tmp17;
  const Scalar _tmp21 = 2 * _tmp20;
  const Scalar _tmp22 = -_tmp19 * _tmp21;
  const Scalar _tmp23 = _a[2] * _b[1];
  const Scalar _tmp24 = (Scalar(1) / Scalar(2)) * _tmp23;
  const Scalar _tmp25 = _a[0] * _b[3];
  const Scalar _tmp26 = (Scalar(1) / Scalar(2)) * _tmp25;
  const Scalar _tmp27 = _a[1] * _b[2];
  const Scalar _tmp28 = (Scalar(1) / Scalar(2)) * _tmp27;
  const Scalar _tmp29 = _a[3] * _b[0];
  const Scalar _tmp30 = (Scalar(1) / Scalar(2)) * _tmp29;
  const Scalar _tmp31 = _tmp24 - _tmp26 - _tmp28 - _tmp30;
  const Scalar _tmp32 = -_tmp23 + _tmp25 + _tmp27 + _tmp29;
  const Scalar _tmp33 = 2 * _tmp32;
  const Scalar _tmp34 = _a[1] * _b[1];
  const Scalar _tmp35 = _a[3] * _b[3];
  const Scalar _tmp36 = _a[2] * _b[2];
  const Scalar _tmp37 = _a[0] * _b[0];
  const Scalar _tmp38 = -Scalar(1) / Scalar(2) * _tmp34 + (Scalar(1) / Scalar(2)) * _tmp35 -
                        Scalar(1) / Scalar(2) * _tmp36 - Scalar(1) / Scalar(2) * _tmp37;
  const Scalar _tmp39 = -2 * _tmp34 + 2 * _tmp35 - 2 * _tmp36 - 2 * _tmp37;
  const Scalar _tmp40 = _tmp38 * _tmp39;
  const Scalar _tmp41 = -_tmp31 * _tmp33 + _tmp40;
  const Scalar _tmp42 = _tmp10 * _tmp38;
  const Scalar _tmp43 = -_tmp24 + _tmp26 + _tmp28 + _tmp30;
  const Scalar _tmp44 = _tmp19 * _tmp33;
  const Scalar _tmp45 = -_tmp1 - _tmp3 - _tmp5 + _tmp7;
  const Scalar _tmp46 = _tmp10 * _tmp31;
  const Scalar _tmp47 = _tmp21 * _tmp38;
  const Scalar _tmp48 = 2 * _tmp45;
  const Scalar _tmp49 = _tmp12 + _tmp14 - _tmp16 + _tmp18;
  const Scalar _tmp50 = -_tmp48 * _tmp9;
  const Scalar _tmp51 = _tmp20 * _tmp48;
  const Scalar _tmp52 = _tmp33 * _tmp38;
  const Scalar _tmp53 = -2 * std::pow(_a[2], Scalar(2));
  const Scalar _tmp54 = -2 * std::pow(_a[1], Scalar(2));
  const Scalar _tmp55 = 2 * _a[0];
  const Scalar _tmp56 = _a[1] * _tmp55;
  const Scalar _tmp57 = 2 * _a[3];
  const Scalar _tmp58 = _a[2] * _tmp57;
  const Scalar _tmp59 = _a[2] * _tmp55;
  const Scalar _tmp60 = _a[1] * _tmp57;
  const Scalar _tmp61 = 1 - 2 * std::pow(_a[0], Scalar(2));
  const Scalar _tmp62 = 2 * _a[1] * _a[2];
  const Scalar _tmp63 = _a[3] * _tmp55;

  // Output terms (1)
  Eigen::Matrix<Scalar, 6, 6> _res_D_b;

  _res_D_b(0, 0) = _tmp10 * _tmp8 + _tmp22 + _tmp41;
  _res_D_b(0, 1) = -_tmp21 * _tmp43 + _tmp39 * _tmp45 + _tmp42 - _tmp44;
  _res_D_b(0, 2) = -_tmp32 * _tmp48 + _tmp39 * _tmp49 + _tmp46 - _tmp47;
  _res_D_b(0, 3) = 0;
  _res_D_b(0, 4) = 0;
  _res_D_b(0, 5) = 0;
  _res_D_b(1, 0) = -_tmp21 * _tmp31 + _tmp39 * _tmp8 - _tmp42 + _tmp44;
  _res_D_b(1, 1) = _tmp22 + _tmp33 * _tmp43 + _tmp40 + _tmp50;
  _res_D_b(1, 2) = -_tmp10 * _tmp49 + _tmp31 * _tmp39 - _tmp51 + _tmp52;
  _res_D_b(1, 3) = 0;
  _res_D_b(1, 4) = 0;
  _res_D_b(1, 5) = 0;
  _res_D_b(2, 0) = _tmp19 * _tmp39 - _tmp33 * _tmp8 - _tmp46 + _tmp47;
  _res_D_b(2, 1) = -_tmp10 * _tmp19 + _tmp39 * _tmp43 + _tmp51 - _tmp52;
  _res_D_b(2, 2) = _tmp21 * _tmp49 + _tmp41 + _tmp50;
  _res_D_b(2, 3) = 0;
  _res_D_b(2, 4) = 0;
  _res_D_b(2, 5) = 0;
  _res_D_b(3, 0) = 0;
  _res_D_b(3, 1) = 0;
  _res_D_b(3, 2) = 0;
  _res_D_b(3, 3) = _tmp53 + _tmp54 + 1;
  _res_D_b(3, 4) = _tmp56 - _tmp58;
  _res_D_b(3, 5) = _tmp59 + _tmp60;
  _res_D_b(4, 0) = 0;
  _res_D_b(4, 1) = 0;
  _res_D_b(4, 2) = 0;
  _res_D_b(4, 3) = _tmp56 + _tmp58;
  _res_D_b(4, 4) = _tmp53 + _tmp61;
  _res_D_b(4, 5) = _tmp62 - _tmp63;
  _res_D_b(5, 0) = 0;
  _res_D_b(5, 1) = 0;
  _res_D_b(5, 2) = 0;
  _res_D_b(5, 3) = _tmp59 - _tmp60;
  _res_D_b(5, 4) = _tmp62 + _tmp63;
  _res_D_b(5, 5) = _tmp54 + _tmp61;

  return _res_D_b;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
