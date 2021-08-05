//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <ostream>
#include <random>
#include <vector>

#include <Eigen/Dense>
#include <sym/ops/storage_ops.h>

namespace sym {

/**
 * Autogenerated C++ implementation of <class 'symforce.cam.linear_camera_cal.LinearCameraCal'>.
 *
 * Standard pinhole camera w/ four parameters [fx, fy, cx, cy].
 * (fx, fy) representing focal length; (cx, cy) representing principal point.
 */
template <typename ScalarType>
class LinearCameraCal {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = LinearCameraCal<Scalar>;
  using DataVec = Eigen::Matrix<Scalar, 4, 1>;

  // Construct from data vec
  explicit LinearCameraCal(const DataVec& data) : data_(data) {}

  // Access underlying storage as const
  inline const DataVec& Data() const {
    return data_;
  }

  // --------------------------------------------------------------------------
  // Handwritten methods included from "custom_methods/linear_camera_cal.h.jinja"
  // --------------------------------------------------------------------------

  // Construct from FocalLength and PrincipalPoint
  explicit LinearCameraCal(const Eigen::Matrix<Scalar, 2, 1>& focal_length,
                           const Eigen::Matrix<Scalar, 2, 1>& principal_point) {
    data_.template head<2>() = focal_length;
    data_.template tail<2>() = principal_point;
  }

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return sym::StorageOps<Self>::StorageDim();
  }

  void ToStorage(Scalar* const vec) const {
    return sym::StorageOps<Self>::ToStorage(*this, vec);
  }

  static LinearCameraCal FromStorage(const Scalar* const vec) {
    return sym::StorageOps<Self>::FromStorage(vec);
  }

  // --------------------------------------------------------------------------
  // Camera model methods
  // --------------------------------------------------------------------------

  /**
   * Return the focal length.
   */
  Eigen::Matrix<Scalar, 2, 1> FocalLength() const;

  /**
   * Return the principal point.
   */
  Eigen::Matrix<Scalar, 2, 1> PrincipalPoint() const;

  /**
   * Project a 3D point in the camera frame into 2D pixel coordinates.
   *
   * Return:
   *     pixel: (x, y) coordinate in pixels if valid
   *     is_valid: 1 if the operation is within bounds else 0
   *
   */
  Eigen::Matrix<Scalar, 2, 1> PixelFromCameraPoint(const Eigen::Matrix<Scalar, 3, 1>& point,
                                                   const Scalar epsilon,
                                                   Scalar* const is_valid = nullptr) const;

  /**
   * Project a 3D point in the camera frame into 2D pixel coordinates.
   *
   * Return:
   *     pixel: (x, y) coordinate in pixels if valid
   *     is_valid: 1 if the operation is within bounds else 0
   *     pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
   *     pixel_D_point: Derivative of pixel with respect to point
   *
   *
   */
  Eigen::Matrix<Scalar, 2, 1> PixelFromCameraPointWithJacobians(
      const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon,
      Scalar* const is_valid = nullptr, Eigen::Matrix<Scalar, 2, 4>* const pixel_D_cal = nullptr,
      Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point = nullptr) const;

  /**
   * Backproject a 2D pixel coordinate into a 3D ray in the camera frame.
   *
   * Return:
   *     camera_ray: The ray in the camera frame (NOT normalized)
   *     is_valid: 1 if the operation is within bounds else 0
   *
   */
  Eigen::Matrix<Scalar, 3, 1> CameraRayFromPixel(const Eigen::Matrix<Scalar, 2, 1>& pixel,
                                                 const Scalar epsilon,
                                                 Scalar* const is_valid = nullptr) const;

  /**
   * Backproject a 2D pixel coordinate into a 3D ray in the camera frame.
   *
   * Return:
   *     camera_ray: The ray in the camera frame (NOT normalized)
   *     is_valid: 1 if the operation is within bounds else 0
   *     point_D_cal: Derivative of point with respect to intrinsic calibration parameters
   *     point_D_pixel: Derivation of point with respect to pixel
   *
   */
  Eigen::Matrix<Scalar, 3, 1> CameraRayFromPixelWithJacobians(
      const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon,
      Scalar* const is_valid = nullptr, Eigen::Matrix<Scalar, 3, 4>* const point_D_cal = nullptr,
      Eigen::Matrix<Scalar, 3, 2>* const point_D_pixel = nullptr) const;

  // --------------------------------------------------------------------------
  // General Helpers
  // --------------------------------------------------------------------------

  bool IsApprox(const Self& b, const Scalar tol) const {
    // isApprox is multiplicative so we check the norm for the exact zero case
    // https://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ae8443357b808cd393be1b51974213f9c
    if (b.Data() == DataVec::Zero()) {
      return Data().norm() < tol;
    }

    return Data().isApprox(b.Data(), tol);
  }

  template <typename ToScalar>
  LinearCameraCal<ToScalar> Cast() const {
    return LinearCameraCal<ToScalar>(Data().template cast<ToScalar>());
  }

  bool operator==(const LinearCameraCal& rhs) const {
    return data_ == rhs.Data();
  }

 protected:
  DataVec data_;
};

// Shorthand for scalar types
using LinearCameraCald = LinearCameraCal<double>;
using LinearCameraCalf = LinearCameraCal<float>;

}  // namespace sym

// Externs to reduce duplicate instantiation
extern template class sym::LinearCameraCal<double>;
extern template class sym::LinearCameraCal<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const sym::LinearCameraCal<double>& a);
std::ostream& operator<<(std::ostream& os, const sym::LinearCameraCal<float>& a);

// Concept implementations for this class
#include "./ops/linear_camera_cal/storage_ops.h"
