// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-2.0.2 (serialization was enabled)
// Source file:   /home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan
// Generated at:  2023-02-13 09:25:43.651024 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     rr_data_types.feedback.Fan
// Version:       1.0
//
// Platform
//     python_implementation:  CPython
//     python_version:  3.8.10
//     python_release_level:  final
//     python_build:  ('default', 'Nov 14 2022 12:59:47')
//     python_compiler:  GCC 9.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.15.0-58-generic-x86_64-with-glibc2.29
//
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False
//     cast_format:  (({type}) {value})

#ifndef RR_DATA_TYPES_FEEDBACK_FAN_1_0_INCLUDED_
#define RR_DATA_TYPES_FEEDBACK_FAN_1_0_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <uavcan/time/SynchronizedTimestamp_1_0.h>

static_assert(
  NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 1693710260,
  "/home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan is trying to use a "
  "serialization library that was compiled with "
  "different language options. This is dangerous and therefore not allowed.");
static_assert(
  NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
  "/home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan is trying to use a "
  "serialization library that was compiled with "
  "different language options. This is dangerous and therefore not allowed.");
static_assert(
  NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
  "/home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan is trying to use a "
  "serialization library that was compiled with "
  "different language options. This is dangerous and therefore not allowed.");
static_assert(
  NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
  "/home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan is trying to use a "
  "serialization library that was compiled with "
  "different language options. This is dangerous and therefore not allowed.");
static_assert(
  NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
  "/home/pepe/mk4_ws/src/extrm_mk4/UAVCAN/rr_data_types/feedback/Fan.1.0.uavcan is trying to use a "
  "serialization library that was compiled with "
  "different language options. This is dangerous and therefore not allowed.");

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define rr_data_types_feedback_Fan_1_0_HAS_FIXED_PORT_ID_ false

#define rr_data_types_feedback_Fan_1_0_FULL_NAME_ "rr_data_types.feedback.Fan"
#define rr_data_types_feedback_Fan_1_0_FULL_NAME_AND_VERSION_ "rr_data_types.feedback.Fan.1.0"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define rr_data_types_feedback_Fan_1_0_EXTENT_BYTES_ 29UL
#define rr_data_types_feedback_Fan_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_ 29UL
static_assert(
  rr_data_types_feedback_Fan_1_0_EXTENT_BYTES_ >=
    rr_data_types_feedback_Fan_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_,
  "Internal constraint violation");

/// Array metadata for: saturated uint8[2] duty_cycle
#define rr_data_types_feedback_Fan_1_0_duty_cycle_ARRAY_CAPACITY_ 2U
#define rr_data_types_feedback_Fan_1_0_duty_cycle_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated int16[2] rpm
#define rr_data_types_feedback_Fan_1_0_rpm_ARRAY_CAPACITY_ 2U
#define rr_data_types_feedback_Fan_1_0_rpm_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated float32[2] temp_int
#define rr_data_types_feedback_Fan_1_0_temp_int_ARRAY_CAPACITY_ 2U
#define rr_data_types_feedback_Fan_1_0_temp_int_ARRAY_IS_VARIABLE_LENGTH_ false
/// Array metadata for: saturated float32[2] temp_ext
#define rr_data_types_feedback_Fan_1_0_temp_ext_ARRAY_CAPACITY_ 2U
#define rr_data_types_feedback_Fan_1_0_temp_ext_ARRAY_IS_VARIABLE_LENGTH_ false

typedef struct
{
  /// uavcan.time.SynchronizedTimestamp.1.0 timestamp
  uavcan_time_SynchronizedTimestamp_1_0 timestamp;

  /// saturated uint8[2] duty_cycle
  uint8_t duty_cycle[2];

  /// saturated int16[2] rpm
  int16_t rpm[2];

  /// saturated float32[2] temp_int
  float temp_int[2];

  /// saturated float32[2] temp_ext
  float temp_ext[2];
} rr_data_types_feedback_Fan_1_0;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see rr_data_types_feedback_Fan_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t rr_data_types_feedback_Fan_1_0_serialize_(
  const rr_data_types_feedback_Fan_1_0 * const obj, uint8_t * const buffer,
  size_t * const inout_buffer_size_bytes)
{
  if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL)) {
    return -NUNAVUT_ERROR_INVALID_ARGUMENT;
  }

  const size_t capacity_bytes = *inout_buffer_size_bytes;
  if ((8U * (size_t)capacity_bytes) < 232UL) {
    return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
  }
  // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
  // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
  size_t offset_bits = 0U;

  {  // uavcan.time.SynchronizedTimestamp.1.0 timestamp
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits + 56ULL) <= (capacity_bytes * 8U));
    size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
    int8_t _err0_ = uavcan_time_SynchronizedTimestamp_1_0_serialize_(
      &obj->timestamp, &buffer[offset_bits / 8U], &_size_bytes0_);
    if (_err0_ < 0) {
      return _err0_;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 56ULL);
    offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
    NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
  }

  {  // saturated uint8[2] duty_cycle
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
    const size_t _origin0_ = offset_bits;
    for (size_t _index0_ = 0U; _index0_ < 2UL; ++_index0_) {
      NUNAVUT_ASSERT(offset_bits % 8U == 0U);
      NUNAVUT_ASSERT((offset_bits + 8ULL) <= (capacity_bytes * 8U));
      // Saturation code not emitted -- native representation matches the serialized representation.
      buffer[offset_bits / 8U] =
        (uint8_t)(obj->duty_cycle[_index0_]);  // C std, 6.3.1.3 Signed and unsigned integers
      offset_bits += 8U;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT((offset_bits - _origin0_) == 16ULL);
    (void)_origin0_;
  }

  {  // saturated int16[2] rpm
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
    const size_t _origin1_ = offset_bits;
    for (size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_) {
      NUNAVUT_ASSERT(offset_bits % 8U == 0U);
      NUNAVUT_ASSERT((offset_bits + 16ULL) <= (capacity_bytes * 8U));
      // Saturation code not emitted -- native representation matches the serialized representation.
      const int8_t _err1_ =
        nunavutSetIxx(&buffer[0], capacity_bytes, offset_bits, obj->rpm[_index1_], 16U);
      if (_err1_ < 0) {
        return _err1_;
      }
      offset_bits += 16U;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT((offset_bits - _origin1_) == 32ULL);
    (void)_origin1_;
  }

  {  // saturated float32[2] temp_int
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
    const size_t _origin2_ = offset_bits;
    for (size_t _index2_ = 0U; _index2_ < 2UL; ++_index2_) {
      NUNAVUT_ASSERT(offset_bits % 8U == 0U);
      NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
      // Saturation code not emitted -- assume the native representation of float32 is conformant.
      static_assert(
        NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
      const int8_t _err2_ =
        nunavutSetF32(&buffer[0], capacity_bytes, offset_bits, obj->temp_int[_index2_]);
      if (_err2_ < 0) {
        return _err2_;
      }
      offset_bits += 32U;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT((offset_bits - _origin2_) == 64ULL);
    (void)_origin2_;
  }

  {  // saturated float32[2] temp_ext
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT((offset_bits + 64ULL) <= (capacity_bytes * 8U));
    const size_t _origin3_ = offset_bits;
    for (size_t _index3_ = 0U; _index3_ < 2UL; ++_index3_) {
      NUNAVUT_ASSERT(offset_bits % 8U == 0U);
      NUNAVUT_ASSERT((offset_bits + 32ULL) <= (capacity_bytes * 8U));
      // Saturation code not emitted -- assume the native representation of float32 is conformant.
      static_assert(
        NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
      const int8_t _err3_ =
        nunavutSetF32(&buffer[0], capacity_bytes, offset_bits, obj->temp_ext[_index3_]);
      if (_err3_ < 0) {
        return _err3_;
      }
      offset_bits += 32U;
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT((offset_bits - _origin3_) == 64ULL);
    (void)_origin3_;
  }

  if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
  {
    const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
    NUNAVUT_ASSERT(_pad0_ > 0);
    const int8_t _err4_ =
      nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
    if (_err4_ < 0) {
      return _err4_;
    }
    offset_bits += _pad0_;
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  }
  // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.

  NUNAVUT_ASSERT(offset_bits == 232ULL);

  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  *inout_buffer_size_bytes = (size_t)(offset_bits / 8U);

  return NUNAVUT_SUCCESS;
}

/// Deserialize an instance from the provided buffer.
/// The lifetime of the resulting object is independent of the original buffer.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original buffer where possible.
///
/// @param obj      The object to update from the provided serialized representation.
///
/// @param buffer   The source buffer containing the serialized representation. There are no alignment requirements.
///                 If the buffer is shorter or longer than expected, it will be implicitly zero-extended or truncated,
///                 respectively; see Specification for "implicit zero extension" and "implicit truncation" rules.
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the supplied serialized
///                                 representation, in bytes. Upon return this value will be updated with the
///                                 size of the consumed fragment of the serialized representation (in bytes),
///                                 which may be smaller due to the implicit truncation rule, but it is guaranteed
///                                 to never exceed the original buffer size even if the implicit zero extension rule
///                                 was activated. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t rr_data_types_feedback_Fan_1_0_deserialize_(
  rr_data_types_feedback_Fan_1_0 * const out_obj, const uint8_t * buffer,
  size_t * const inout_buffer_size_bytes)
{
  if (
    (out_obj == NULL) || (inout_buffer_size_bytes == NULL) ||
    ((buffer == NULL) && (0 != *inout_buffer_size_bytes))) {
    return -NUNAVUT_ERROR_INVALID_ARGUMENT;
  }
  if (buffer == NULL) {
    buffer = (const uint8_t *)"";
  }

  const size_t capacity_bytes = *inout_buffer_size_bytes;
  const size_t capacity_bits = capacity_bytes * (size_t)8U;
  size_t offset_bits = 0U;

  // uavcan.time.SynchronizedTimestamp.1.0 timestamp
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  {
    size_t _size_bytes1_ =
      (size_t)(capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes));
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    const int8_t _err5_ = uavcan_time_SynchronizedTimestamp_1_0_deserialize_(
      &out_obj->timestamp, &buffer[offset_bits / 8U], &_size_bytes1_);
    if (_err5_ < 0) {
      return _err5_;
    }
    offset_bits +=
      _size_bytes1_ * 8U;  // Advance by the size of the nested serialized representation.
  }

  // saturated uint8[2] duty_cycle
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  for (size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_) {
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if ((offset_bits + 8U) <= capacity_bits) {
      out_obj->duty_cycle[_index4_] = buffer[offset_bits / 8U] & 255U;
    } else {
      out_obj->duty_cycle[_index4_] = 0U;
    }
    offset_bits += 8U;
  }

  // saturated int16[2] rpm
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  for (size_t _index5_ = 0U; _index5_ < 2UL; ++_index5_) {
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->rpm[_index5_] = nunavutGetI16(&buffer[0], capacity_bytes, offset_bits, 16);
    offset_bits += 16U;
  }

  // saturated float32[2] temp_int
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  for (size_t _index6_ = 0U; _index6_ < 2UL; ++_index6_) {
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->temp_int[_index6_] = nunavutGetF32(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 32U;
  }

  // saturated float32[2] temp_ext
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  for (size_t _index7_ = 0U; _index7_ < 2UL; ++_index7_) {
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    out_obj->temp_ext[_index7_] = nunavutGetF32(&buffer[0], capacity_bytes, offset_bits);
    offset_bits += 32U;
  }

  offset_bits = (offset_bits + 7U) & ~(size_t)7U;  // Align on 8 bits.
  NUNAVUT_ASSERT(offset_bits % 8U == 0U);
  *inout_buffer_size_bytes = (size_t)(nunavutChooseMin(offset_bits, capacity_bits) / 8U);
  NUNAVUT_ASSERT(capacity_bytes >= *inout_buffer_size_bytes);

  return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void rr_data_types_feedback_Fan_1_0_initialize_(
  rr_data_types_feedback_Fan_1_0 * const out_obj)
{
  if (out_obj != NULL) {
    size_t size_bytes = 0;
    const uint8_t buf = 0;
    const int8_t err = rr_data_types_feedback_Fan_1_0_deserialize_(out_obj, &buf, &size_bytes);
    NUNAVUT_ASSERT(err >= 0);
    (void)err;
  }
}

#ifdef __cplusplus
}
#endif
#endif  // RR_DATA_TYPES_FEEDBACK_FAN_1_0_INCLUDED_
