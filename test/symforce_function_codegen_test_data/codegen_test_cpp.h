// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include "./codegen_test_cpp_types/constants_t.h"
#include "./codegen_test_cpp_types/states_t.h"

#include "./codegen_test_cpp_types/storage_ops.h"

namespace codegen_test_cpp_gen {

/**
* This function was autogenerated. Do not modify by hand.
*
* Arg type(s): Symbol, Symbol, Rot3, Values, Values
* Return type(s): Add, Add
*
*/
template <typename Scalar>
void CodegenTestCpp(const Scalar x, const Scalar y, const geo::Rot3<Scalar>& rot, const codegen_test_cpp_types::constants_t& constants, const codegen_test_cpp_types::states_t& states, Scalar* const foo, Scalar* const bar) {
    // Input arrays
    const Eigen::Matrix<Scalar, 4, 1>& _rot = rot.Data();
    std::vector<Scalar> constants_array;
    codegen_test_cpp_types::StorageOps::ToStorage<codegen_test_cpp_types::constants_t>(constants, &constants_array);
    const Eigen::Matrix<Scalar, 1, 1> _constants(constants_array.data());
    std::vector<Scalar> states_array;
    codegen_test_cpp_types::StorageOps::ToStorage<codegen_test_cpp_types::states_t>(states, &states_array);
    const Eigen::Matrix<Scalar, 2, 1> _states(states_array.data());
    assert( foo != nullptr );
    assert( bar != nullptr );

    // Intermediate terms (1)
    const Scalar _tmp0 = (x * x);

    // Output terms (2)
    Scalar _foo;
    _foo = _rot[3] + _tmp0;
    *foo = _foo;

    Scalar _bar;
    _bar = _constants[0] + _tmp0 + std::sin(y);
    *bar = _bar;


}

}  // namespace codegen_test_cpp_gen
