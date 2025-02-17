//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.3.1 (serialization was enabled)
// Source file:   /home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl
// Generated at:  2025-02-12 14:20:09.910567 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     rr_data_types.sensors.BatteryTelemetry
// Type Version:  1.0
// Support
//    Support Namespace: nunavut.lang.cpp.support
//    Support Version:   (1, 0, 0)
// Template Set (package)
//    priority: 0
//    package:  nunavut.lang.cpp.templates
//    version:  (1, 0, 0)
// Platform
//     python_implementation:  CPython
//     python_version:  3.12.3
//     python_release_level:  final
//     python_build:  ('main', 'Jan 17 2025 18:03:48')
//     python_compiler:  GCC 13.3.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-6.8.0-52-generic-x86_64-with-glibc2.39
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     std:  c++17
//     cast_format:  static_cast<{type}>({value})
//     variable_array_type_include:  <vector>
//     variable_array_type_template:  std::vector<{TYPE}>
//     variable_array_type_constructor_args:
//     allocator_include:
//     allocator_type:
//     allocator_is_default_constructible:  True
//     ctor_convention:  default
// Uses Language Features
//     Uses std_variant:yes
#ifndef RR_DATA_TYPES_SENSORS_BATTERY_TELEMETRY_1_0_HPP_INCLUDED
#define RR_DATA_TYPES_SENSORS_BATTERY_TELEMETRY_1_0_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include "uavcan/time/SynchronizedTimestamp_1_0.hpp"
#include <array>
#include <cstdint>
#include <limits>

namespace rr_data_types
{
namespace sensors
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 3320664631,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 4227611599,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_constructor_args == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_include == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_type == 0,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_is_default_constructible == 1,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::ctor_convention == 3814588639,
              "/home/joe/Data/mk4_firmware/libs/external/107-Arduino-Cyphal/rr_data_types/sensors/BatteryTelemetry.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+

struct BatteryTelemetry_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        /// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
        static constexpr bool HasFixedPortID = false;

        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 95UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 95UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");

        struct TypeOf
        {
            TypeOf() = delete;
            using timestamp = uavcan::time::SynchronizedTimestamp_1_0;
            using battery_voltage = std::array<float,2>;
            using battery_temperature = std::array<float,2>;
            using battery_current = std::array<float,2>;
            using battery_charge = std::array<float,2>;
            using battery_capacity = std::array<float,2>;
            using battery_charge_percentage = std::array<float,2>;
            using battery_status = std::array<std::int8_t,2>;
            using battery_health = std::array<std::int8_t,2>;
            using charger_providing_voltage = std::array<std::int8_t,2>;
            using charger_temperature = std::array<float,2>;
            using charger_current_limiter_temperature = std::array<float,2>;
            using charger_current = std::array<float,2>;
            using charger_voltage = std::array<float,2>;
            using charger_status = std::array<std::int8_t,2>;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+

    _traits_::TypeOf::timestamp timestamp{};

    _traits_::TypeOf::battery_voltage battery_voltage{};

    _traits_::TypeOf::battery_temperature battery_temperature{};

    _traits_::TypeOf::battery_current battery_current{};

    _traits_::TypeOf::battery_charge battery_charge{};

    _traits_::TypeOf::battery_capacity battery_capacity{};

    _traits_::TypeOf::battery_charge_percentage battery_charge_percentage{};

    _traits_::TypeOf::battery_status battery_status{};

    _traits_::TypeOf::battery_health battery_health{};

    _traits_::TypeOf::charger_providing_voltage charger_providing_voltage{};

    _traits_::TypeOf::charger_temperature charger_temperature{};

    _traits_::TypeOf::charger_current_limiter_temperature charger_current_limiter_temperature{};

    _traits_::TypeOf::charger_current charger_current{};

    _traits_::TypeOf::charger_voltage charger_voltage{};

    _traits_::TypeOf::charger_status charger_status{};
};

inline nunavut::support::SerializeResult serialize(const BatteryTelemetry_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 760UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.time.SynchronizedTimestamp.1.0 timestamp
        std::size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.timestamp, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {   // saturated float32[2] battery_voltage
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_voltage[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] battery_temperature
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_temperature[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] battery_current
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_current[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] battery_charge
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_charge[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] battery_capacity
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_capacity[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] battery_charge_percentage
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.battery_charge_percentage[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated int8[2] battery_status
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setIxx(obj.battery_status[_index1_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated int8[2] battery_health
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setIxx(obj.battery_health[_index1_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated int8[2] charger_providing_voltage
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setIxx(obj.charger_providing_voltage[_index1_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] charger_temperature
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.charger_temperature[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] charger_current_limiter_temperature
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.charger_current_limiter_temperature[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] charger_current
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.charger_current[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated float32[2] charger_voltage
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- assume the native representation of float32 is conformant.
            static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
            auto _result4_ = out_buffer.setF32(obj.charger_voltage[_index1_]);
            if(not _result4_){
                return -_result4_.error();
            }
            out_buffer.add_offset(32U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {   // saturated int8[2] charger_status
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 2UL; ++_index1_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setIxx(obj.charger_status[_index1_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(BatteryTelemetry_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.time.SynchronizedTimestamp.1.0 timestamp
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.timestamp, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    // saturated float32[2] battery_voltage
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_voltage[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] battery_temperature
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_temperature[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] battery_current
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_current[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] battery_charge
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_charge[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] battery_capacity
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_capacity[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] battery_charge_percentage
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_charge_percentage[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated int8[2] battery_status
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_status[_index4_] = in_buffer.getI8(8U);
        in_buffer.add_offset(8U);
    }
    // saturated int8[2] battery_health
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.battery_health[_index4_] = in_buffer.getI8(8U);
        in_buffer.add_offset(8U);
    }
    // saturated int8[2] charger_providing_voltage
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_providing_voltage[_index4_] = in_buffer.getI8(8U);
        in_buffer.add_offset(8U);
    }
    // saturated float32[2] charger_temperature
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_temperature[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] charger_current_limiter_temperature
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_current_limiter_temperature[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] charger_current
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_current[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated float32[2] charger_voltage
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_voltage[_index4_] = in_buffer.getF32();
        in_buffer.add_offset(32U);
    }
    // saturated int8[2] charger_status
    for (std::size_t _index4_ = 0U; _index4_ < 2UL; ++_index4_)
    {
        obj.charger_status[_index4_] = in_buffer.getI8(8U);
        in_buffer.add_offset(8U);
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace sensors
} // namespace rr_data_types

#endif // RR_DATA_TYPES_SENSORS_BATTERY_TELEMETRY_1_0_HPP_INCLUDED
