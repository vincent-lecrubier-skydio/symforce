// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     geo.Matrix: Jacobian for arg 0 (a)
 *     geo.Matrix: Jacobian for arg 1 (b)
 */
template <typename Scalar>
void ComposePose3_Jacobians(const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
                            Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr,
                            Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 679

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (211)
  const Scalar _tmp0 = _a[0] * _b[0];
  const Scalar _tmp1 = _a[1] * _b[1];
  const Scalar _tmp2 = _a[2] * _b[2];
  const Scalar _tmp3 = _a[3] * _b[3];
  const Scalar _tmp4 = -2 * _tmp0 - 2 * _tmp1 - 2 * _tmp2 + 2 * _tmp3;
  const Scalar _tmp5 = _b[0] * _tmp4;
  const Scalar _tmp6 = _a[0] * _b[1];
  const Scalar _tmp7 = 2 * _tmp6;
  const Scalar _tmp8 = _a[1] * _b[0];
  const Scalar _tmp9 = 2 * _tmp8;
  const Scalar _tmp10 = _a[2] * _b[3];
  const Scalar _tmp11 = 2 * _tmp10;
  const Scalar _tmp12 = _a[3] * _b[2];
  const Scalar _tmp13 = 2 * _tmp12;
  const Scalar _tmp14 = _tmp11 + _tmp13 + _tmp7 - _tmp9;
  const Scalar _tmp15 = _a[0] * _b[2];
  const Scalar _tmp16 = 2 * _tmp15;
  const Scalar _tmp17 = _a[1] * _b[3];
  const Scalar _tmp18 = 2 * _tmp17;
  const Scalar _tmp19 = _a[2] * _b[0];
  const Scalar _tmp20 = 2 * _tmp19;
  const Scalar _tmp21 = _a[3] * _b[1];
  const Scalar _tmp22 = 2 * _tmp21;
  const Scalar _tmp23 = _tmp16 - _tmp18 - _tmp20 - _tmp22;
  const Scalar _tmp24 = _b[2] * _tmp23;
  const Scalar _tmp25 = _a[0] * _b[3];
  const Scalar _tmp26 = 2 * _tmp25;
  const Scalar _tmp27 = _a[1] * _b[2];
  const Scalar _tmp28 = 2 * _tmp27;
  const Scalar _tmp29 = _a[2] * _b[1];
  const Scalar _tmp30 = 2 * _tmp29;
  const Scalar _tmp31 = _a[3] * _b[0];
  const Scalar _tmp32 = 2 * _tmp31;
  const Scalar _tmp33 = -_tmp26 - _tmp28 + _tmp30 - _tmp32;
  const Scalar _tmp34 = _b[3] * _tmp33;
  const Scalar _tmp35 = _b[1] * _tmp14 + _tmp24 + _tmp34 + _tmp5;
  const Scalar _tmp36 = (1.0 / 2.0) * _a[0];
  const Scalar _tmp37 = _b[3] * _tmp23;
  const Scalar _tmp38 = _b[1] * _tmp4;
  const Scalar _tmp39 = -_b[2] * _tmp33;
  const Scalar _tmp40 = _b[0] * _tmp14 + _tmp37 - _tmp38 + _tmp39;
  const Scalar _tmp41 = (1.0 / 2.0) * _a[1];
  const Scalar _tmp42 = _b[2] * _tmp4;
  const Scalar _tmp43 = -_b[0] * _tmp23;
  const Scalar _tmp44 = _b[1] * _tmp33;
  const Scalar _tmp45 = (1.0 / 2.0) * _b[3] * _tmp14 + (1.0 / 2.0) * _tmp42 + (1.0 / 2.0) * _tmp43 -
                        1.0 / 2.0 * _tmp44;
  const Scalar _tmp46 = _b[1] * _tmp23;
  const Scalar _tmp47 = _b[3] * _tmp4;
  const Scalar _tmp48 = _b[0] * _tmp33;
  const Scalar _tmp49 = -1.0 / 2.0 * _b[2] * _tmp14 + (1.0 / 2.0) * _tmp46 + (1.0 / 2.0) * _tmp47 -
                        1.0 / 2.0 * _tmp48;
  const Scalar _tmp50 = (1.0 / 2.0) * _a[2];
  const Scalar _tmp51 = (1.0 / 2.0) * _a[3];
  const Scalar _tmp52 = -_tmp11 - _tmp13 - _tmp7 + _tmp9;
  const Scalar _tmp53 = _b[0] * _tmp52;
  const Scalar _tmp54 = _tmp26 + _tmp28 - _tmp30 + _tmp32;
  const Scalar _tmp55 = _b[2] * _tmp54 + _tmp37 + _tmp38 + _tmp53;
  const Scalar _tmp56 = -_b[1] * _tmp52;
  const Scalar _tmp57 = _b[3] * _tmp54 - _tmp24 + _tmp5 + _tmp56;
  const Scalar _tmp58 = _b[2] * _tmp52;
  const Scalar _tmp59 = -_b[0] * _tmp54 - _tmp46 + _tmp47 + _tmp58;
  const Scalar _tmp60 = _b[3] * _tmp52;
  const Scalar _tmp61 = _b[1] * _tmp54 - _tmp42 + _tmp43 + _tmp60;
  const Scalar _tmp62 = -_tmp16 + _tmp18 + _tmp20 + _tmp22;
  const Scalar _tmp63 = _b[0] * _tmp62 + _tmp42 + _tmp44 + _tmp60;
  const Scalar _tmp64 = -_b[1] * _tmp62 + _tmp47 + _tmp48 - _tmp58;
  const Scalar _tmp65 = _b[2] * _tmp62 + _tmp34 - _tmp5 + _tmp56;
  const Scalar _tmp66 = _b[3] * _tmp62 + _tmp38 + _tmp39 - _tmp53;
  const Scalar _tmp67 = 2 * _b[6];
  const Scalar _tmp68 = _a[1] * _tmp67;
  const Scalar _tmp69 = 2 * _a[2];
  const Scalar _tmp70 = _b[5] * _tmp69;
  const Scalar _tmp71 = _tmp68 - _tmp70;
  const Scalar _tmp72 = -_tmp15 + _tmp17 + _tmp19 + _tmp21;
  const Scalar _tmp73 = -2 * (_tmp72 * _tmp72);
  const Scalar _tmp74 = _tmp10 + _tmp12 + _tmp6 - _tmp8;
  const Scalar _tmp75 = 1 - 2 * (_tmp74 * _tmp74);
  const Scalar _tmp76 = _tmp73 + _tmp75;
  const Scalar _tmp77 = _a[0] * _tmp67;
  const Scalar _tmp78 = 2 * _b[4];
  const Scalar _tmp79 = _a[2] * _tmp78;
  const Scalar _tmp80 = -_tmp77 + _tmp79;
  const Scalar _tmp81 = _tmp54 * _tmp72;
  const Scalar _tmp82 = -_tmp0 - _tmp1 - _tmp2 + _tmp3;
  const Scalar _tmp83 = _tmp14 * _tmp82;
  const Scalar _tmp84 = _tmp81 + _tmp83;
  const Scalar _tmp85 = 2 * _b[5];
  const Scalar _tmp86 = _a[0] * _tmp85;
  const Scalar _tmp87 = _a[1] * _tmp78;
  const Scalar _tmp88 = _tmp86 - _tmp87;
  const Scalar _tmp89 = _tmp54 * _tmp74;
  const Scalar _tmp90 = _tmp62 * _tmp82;
  const Scalar _tmp91 = _tmp89 - _tmp90;
  const Scalar _tmp92 = _tmp71 * _tmp76 + _tmp80 * _tmp84 + _tmp88 * _tmp91;
  const Scalar _tmp93 = 4 * _a[2];
  const Scalar _tmp94 = _a[3] * _tmp85;
  const Scalar _tmp95 = -_b[4] * _tmp93 + _tmp77 - _tmp94;
  const Scalar _tmp96 = _a[0] * _tmp78;
  const Scalar _tmp97 = _a[1] * _tmp85;
  const Scalar _tmp98 = _tmp96 + _tmp97;
  const Scalar _tmp99 = _a[3] * _tmp78;
  const Scalar _tmp100 = -_b[5] * _tmp93 + _tmp68 + _tmp99;
  const Scalar _tmp101 = _tmp100 * _tmp84 + _tmp76 * _tmp95 + _tmp91 * _tmp98;
  const Scalar _tmp102 = 4 * _a[1];
  const Scalar _tmp103 = _a[3] * _tmp67;
  const Scalar _tmp104 = -_b[4] * _tmp102 + _tmp103 + _tmp86;
  const Scalar _tmp105 = _b[6] * _tmp69;
  const Scalar _tmp106 = _tmp105 + _tmp96;
  const Scalar _tmp107 = -_b[6] * _tmp102 + _tmp70 - _tmp99;
  const Scalar _tmp108 = _tmp104 * _tmp76 + _tmp106 * _tmp84 + _tmp107 * _tmp91;
  const Scalar _tmp109 = _tmp105 + _tmp97;
  const Scalar _tmp110 = 4 * _a[0];
  const Scalar _tmp111 = -_b[5] * _tmp110 - _tmp103 + _tmp87;
  const Scalar _tmp112 = -_b[6] * _tmp110 + _tmp79 + _tmp94;
  const Scalar _tmp113 = _tmp109 * _tmp76 + _tmp111 * _tmp84 + _tmp112 * _tmp91;
  const Scalar _tmp114 = -2 * (_a[1] * _a[1]);
  const Scalar _tmp115 = 1 - 2 * (_a[2] * _a[2]);
  const Scalar _tmp116 = _tmp114 + _tmp115;
  const Scalar _tmp117 = 2 * _a[1];
  const Scalar _tmp118 = _a[0] * _tmp117;
  const Scalar _tmp119 = _a[3] * _tmp69;
  const Scalar _tmp120 = _tmp118 + _tmp119;
  const Scalar _tmp121 = _a[0] * _tmp69;
  const Scalar _tmp122 = _a[3] * _tmp117;
  const Scalar _tmp123 = _tmp121 - _tmp122;
  const Scalar _tmp124 = _tmp116 * _tmp76 + _tmp120 * _tmp84 + _tmp123 * _tmp91;
  const Scalar _tmp125 = _tmp118 - _tmp119;
  const Scalar _tmp126 = 2 * _a[0] * _a[3];
  const Scalar _tmp127 = _a[1] * _tmp69;
  const Scalar _tmp128 = _tmp126 + _tmp127;
  const Scalar _tmp129 = -2 * (_a[0] * _a[0]);
  const Scalar _tmp130 = _tmp115 + _tmp129;
  const Scalar _tmp131 = _tmp125 * _tmp76 + _tmp128 * _tmp91 + _tmp130 * _tmp84;
  const Scalar _tmp132 = _tmp121 + _tmp122;
  const Scalar _tmp133 = -_tmp126 + _tmp127;
  const Scalar _tmp134 = _tmp114 + _tmp129 + 1;
  const Scalar _tmp135 = _tmp132 * _tmp76 + _tmp133 * _tmp84 + _tmp134 * _tmp91;
  const Scalar _tmp136 =
      -2 * (_tmp25 + _tmp27 - _tmp29 + _tmp31 * _tmp25 + _tmp27 - _tmp29 + _tmp31);
  const Scalar _tmp137 = _tmp136 + _tmp75;
  const Scalar _tmp138 = _tmp62 * _tmp74;
  const Scalar _tmp139 = _tmp54 * _tmp82;
  const Scalar _tmp140 = _tmp138 + _tmp139;
  const Scalar _tmp141 = _tmp81 - _tmp83;
  const Scalar _tmp142 = _tmp137 * _tmp80 + _tmp140 * _tmp88 + _tmp141 * _tmp71;
  const Scalar _tmp143 = _tmp100 * _tmp137 + _tmp140 * _tmp98 + _tmp141 * _tmp95;
  const Scalar _tmp144 = _tmp104 * _tmp141 + _tmp106 * _tmp137 + _tmp107 * _tmp140;
  const Scalar _tmp145 = _tmp109 * _tmp141 + _tmp111 * _tmp137 + _tmp112 * _tmp140;
  const Scalar _tmp146 = _tmp116 * _tmp141 + _tmp120 * _tmp137 + _tmp123 * _tmp140;
  const Scalar _tmp147 = _tmp125 * _tmp141 + _tmp128 * _tmp140 + _tmp130 * _tmp137;
  const Scalar _tmp148 = _tmp132 * _tmp141 + _tmp133 * _tmp137 + _tmp134 * _tmp140;
  const Scalar _tmp149 = _tmp136 + _tmp73 + 1;
  const Scalar _tmp150 = _tmp89 + _tmp90;
  const Scalar _tmp151 = _tmp138 - _tmp139;
  const Scalar _tmp152 = _tmp149 * _tmp88 + _tmp150 * _tmp71 + _tmp151 * _tmp80;
  const Scalar _tmp153 = _tmp100 * _tmp151 + _tmp149 * _tmp98 + _tmp150 * _tmp95;
  const Scalar _tmp154 = _tmp104 * _tmp150 + _tmp106 * _tmp151 + _tmp107 * _tmp149;
  const Scalar _tmp155 = _tmp109 * _tmp150 + _tmp111 * _tmp151 + _tmp112 * _tmp149;
  const Scalar _tmp156 = _tmp116 * _tmp150 + _tmp120 * _tmp151 + _tmp123 * _tmp149;
  const Scalar _tmp157 = _tmp125 * _tmp150 + _tmp128 * _tmp149 + _tmp130 * _tmp151;
  const Scalar _tmp158 = _tmp132 * _tmp150 + _tmp133 * _tmp151 + _tmp134 * _tmp149;
  const Scalar _tmp159 = _a[2] * _tmp23;
  const Scalar _tmp160 = _a[0] * _tmp4;
  const Scalar _tmp161 = _a[3] * _tmp33 + _tmp160;
  const Scalar _tmp162 = _a[1] * _tmp14 + _tmp159 + _tmp161;
  const Scalar _tmp163 = (1.0 / 2.0) * _b[0];
  const Scalar _tmp164 = _a[2] * _tmp33;
  const Scalar _tmp165 = _a[1] * _tmp4;
  const Scalar _tmp166 = _a[3] * _tmp23 + _tmp165;
  const Scalar _tmp167 = -_a[0] * _tmp14 - _tmp164 + _tmp166;
  const Scalar _tmp168 = (1.0 / 2.0) * _b[1];
  const Scalar _tmp169 = _a[0] * _tmp23;
  const Scalar _tmp170 = _a[1] * _tmp33;
  const Scalar _tmp171 = _a[2] * _tmp4;
  const Scalar _tmp172 = (1.0 / 2.0) * _a[3] * _tmp14 + (1.0 / 2.0) * _tmp169 -
                         1.0 / 2.0 * _tmp170 - 1.0 / 2.0 * _tmp171;
  const Scalar _tmp173 = -_a[0] * _tmp33;
  const Scalar _tmp174 = _a[3] * _tmp4;
  const Scalar _tmp175 = -_a[1] * _tmp23 + _tmp174;
  const Scalar _tmp176 =
      (1.0 / 2.0) * _a[2] * _tmp14 + (1.0 / 2.0) * _tmp173 + (1.0 / 2.0) * _tmp175;
  const Scalar _tmp177 = (1.0 / 2.0) * _b[2];
  const Scalar _tmp178 = (1.0 / 2.0) * _b[3];
  const Scalar _tmp179 = _a[0] * _tmp52;
  const Scalar _tmp180 = _a[2] * _tmp54 + _tmp166 + _tmp179;
  const Scalar _tmp181 = _a[1] * _tmp52;
  const Scalar _tmp182 = _a[3] * _tmp54 - _tmp159 - _tmp160 + _tmp181;
  const Scalar _tmp183 = -_a[2] * _tmp52;
  const Scalar _tmp184 = _a[0] * _tmp54 + _tmp175 + _tmp183;
  const Scalar _tmp185 = _a[3] * _tmp52 + _tmp171;
  const Scalar _tmp186 = -_a[1] * _tmp54 - _tmp169 + _tmp185;
  const Scalar _tmp187 = _a[0] * _tmp62 + _tmp170 + _tmp185;
  const Scalar _tmp188 = _a[1] * _tmp62 + _tmp173 + _tmp174 + _tmp183;
  const Scalar _tmp189 = -_a[2] * _tmp62 + _tmp161 - _tmp181;
  const Scalar _tmp190 = _a[3] * _tmp62 + _tmp164 - _tmp165 - _tmp179;
  const Scalar _tmp191 = 2 * _b[1];
  const Scalar _tmp192 = _b[0] * _tmp191;
  const Scalar _tmp193 = 2 * _b[2];
  const Scalar _tmp194 = _b[3] * _tmp193;
  const Scalar _tmp195 = _tmp192 + _tmp194;
  const Scalar _tmp196 = _b[0] * _tmp193;
  const Scalar _tmp197 = _b[3] * _tmp191;
  const Scalar _tmp198 = _tmp196 - _tmp197;
  const Scalar _tmp199 = -2 * (_b[1] * _b[1]);
  const Scalar _tmp200 = 1 - 2 * (_b[2] * _b[2]);
  const Scalar _tmp201 = _tmp199 + _tmp200;
  const Scalar _tmp202 = _tmp192 - _tmp194;
  const Scalar _tmp203 = 2 * _b[0] * _b[3];
  const Scalar _tmp204 = _b[2] * _tmp191;
  const Scalar _tmp205 = _tmp203 + _tmp204;
  const Scalar _tmp206 = -2 * (_b[0] * _b[0]);
  const Scalar _tmp207 = _tmp200 + _tmp206;
  const Scalar _tmp208 = _tmp196 + _tmp197;
  const Scalar _tmp209 = -_tmp203 + _tmp204;
  const Scalar _tmp210 = _tmp199 + _tmp206 + 1;

  // Output terms (2)
  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _a[2] * _tmp45 + _a[3] * _tmp49 - _tmp35 * _tmp36 - _tmp40 * _tmp41;
    _res_D_a(0, 1) = -_a[2] * _tmp49 + _a[3] * _tmp45 - _tmp35 * _tmp41 + _tmp36 * _tmp40;
    _res_D_a(0, 2) = -_a[0] * _tmp45 + _a[1] * _tmp49 - _tmp35 * _tmp50 + _tmp40 * _tmp51;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = -_tmp36 * _tmp55 - _tmp41 * _tmp57 + _tmp50 * _tmp59 + _tmp51 * _tmp61;
    _res_D_a(1, 1) = _tmp36 * _tmp57 - _tmp41 * _tmp55 - _tmp50 * _tmp61 + _tmp51 * _tmp59;
    _res_D_a(1, 2) = -_tmp36 * _tmp59 + _tmp41 * _tmp61 - _tmp50 * _tmp55 + _tmp51 * _tmp57;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = -_tmp36 * _tmp63 - _tmp41 * _tmp64 + _tmp50 * _tmp65 + _tmp51 * _tmp66;
    _res_D_a(2, 1) = _tmp36 * _tmp64 - _tmp41 * _tmp63 - _tmp50 * _tmp66 + _tmp51 * _tmp65;
    _res_D_a(2, 2) = -_tmp36 * _tmp65 + _tmp41 * _tmp66 - _tmp50 * _tmp63 + _tmp51 * _tmp64;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = -_tmp101 * _tmp41 + _tmp108 * _tmp50 + _tmp113 * _tmp51 - _tmp36 * _tmp92;
    _res_D_a(3, 1) = _tmp101 * _tmp36 + _tmp108 * _tmp51 - _tmp113 * _tmp50 - _tmp41 * _tmp92;
    _res_D_a(3, 2) = _tmp101 * _tmp51 - _tmp108 * _tmp36 + _tmp113 * _tmp41 - _tmp50 * _tmp92;
    _res_D_a(3, 3) = _tmp124;
    _res_D_a(3, 4) = _tmp131;
    _res_D_a(3, 5) = _tmp135;
    _res_D_a(4, 0) = -_tmp142 * _tmp36 - _tmp143 * _tmp41 + _tmp144 * _tmp50 + _tmp145 * _tmp51;
    _res_D_a(4, 1) = -_tmp142 * _tmp41 + _tmp143 * _tmp36 + _tmp144 * _tmp51 - _tmp145 * _tmp50;
    _res_D_a(4, 2) = -_tmp142 * _tmp50 + _tmp143 * _tmp51 - _tmp144 * _tmp36 + _tmp145 * _tmp41;
    _res_D_a(4, 3) = _tmp146;
    _res_D_a(4, 4) = _tmp147;
    _res_D_a(4, 5) = _tmp148;
    _res_D_a(5, 0) = -_tmp152 * _tmp36 - _tmp153 * _tmp41 + _tmp154 * _tmp50 + _tmp155 * _tmp51;
    _res_D_a(5, 1) = -_tmp152 * _tmp41 + _tmp153 * _tmp36 + _tmp154 * _tmp51 - _tmp155 * _tmp50;
    _res_D_a(5, 2) = -_tmp152 * _tmp50 + _tmp153 * _tmp51 - _tmp154 * _tmp36 + _tmp155 * _tmp41;
    _res_D_a(5, 3) = _tmp156;
    _res_D_a(5, 4) = _tmp157;
    _res_D_a(5, 5) = _tmp158;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _b[2] * _tmp172 + _b[3] * _tmp176 - _tmp162 * _tmp163 - _tmp167 * _tmp168;
    _res_D_b(0, 1) = -_b[2] * _tmp176 + _b[3] * _tmp172 - _tmp162 * _tmp168 + _tmp163 * _tmp167;
    _res_D_b(0, 2) = -_b[0] * _tmp172 + _b[1] * _tmp176 - _tmp162 * _tmp177 + _tmp167 * _tmp178;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = -_tmp163 * _tmp180 - _tmp168 * _tmp182 + _tmp177 * _tmp184 + _tmp178 * _tmp186;
    _res_D_b(1, 1) = _tmp163 * _tmp182 - _tmp168 * _tmp180 - _tmp177 * _tmp186 + _tmp178 * _tmp184;
    _res_D_b(1, 2) = -_tmp163 * _tmp184 + _tmp168 * _tmp186 - _tmp177 * _tmp180 + _tmp178 * _tmp182;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = -_tmp163 * _tmp187 - _tmp168 * _tmp188 + _tmp177 * _tmp189 + _tmp178 * _tmp190;
    _res_D_b(2, 1) = _tmp163 * _tmp188 - _tmp168 * _tmp187 - _tmp177 * _tmp190 + _tmp178 * _tmp189;
    _res_D_b(2, 2) = -_tmp163 * _tmp189 + _tmp168 * _tmp190 - _tmp177 * _tmp187 + _tmp178 * _tmp188;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = _tmp124 * _tmp201 + _tmp131 * _tmp195 + _tmp135 * _tmp198;
    _res_D_b(3, 4) = _tmp124 * _tmp202 + _tmp131 * _tmp207 + _tmp135 * _tmp205;
    _res_D_b(3, 5) = _tmp124 * _tmp208 + _tmp131 * _tmp209 + _tmp135 * _tmp210;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp146 * _tmp201 + _tmp147 * _tmp195 + _tmp148 * _tmp198;
    _res_D_b(4, 4) = _tmp146 * _tmp202 + _tmp147 * _tmp207 + _tmp148 * _tmp205;
    _res_D_b(4, 5) = _tmp146 * _tmp208 + _tmp147 * _tmp209 + _tmp148 * _tmp210;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp156 * _tmp201 + _tmp157 * _tmp195 + _tmp158 * _tmp198;
    _res_D_b(5, 4) = _tmp156 * _tmp202 + _tmp157 * _tmp207 + _tmp158 * _tmp205;
    _res_D_b(5, 5) = _tmp156 * _tmp208 + _tmp157 * _tmp209 + _tmp158 * _tmp210;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
