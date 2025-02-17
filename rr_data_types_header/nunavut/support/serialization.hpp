// OpenCyphal common serialization support routines.                                                           -
// This file is based on canard_dsdl.h, which is part of Libcanard.                                          | C/-
//                                                                                                             -
// AUTOGENERATED, DO NOT EDIT.
//
//---------------------------------------------------------------------------------------------------------------------
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

#ifndef NUNAVUT_SUPPORT_SERIALIZATION_HPP_INCLUDED
#define NUNAVUT_SUPPORT_SERIALIZATION_HPP_INCLUDED

static_assert(__cplusplus >= 201402L,
              "Unsupported language: ISO C11, C++14, or a newer version of either is required.");

#include <cstring> // for std::size_t
#include <cmath>  // For isfinite().
#include <climits>
#include <cfloat>
#include <cstdint> // for memset
#include <array> // for std::array
#include <algorithm> // for std::max, std::min
#include <utility> // for std::move
#include <type_traits> // std::underlying_type, std::aligned_storage

/// Detect whether the target platform is compatible with IEEE 754.
#define NUNAVUT_PLATFORM_IEEE754_FLOAT \
    ((FLT_RADIX == 2) && (FLT_MANT_DIG == 24) && (FLT_MIN_EXP == -125) && (FLT_MAX_EXP == 128))
#define NUNAVUT_PLATFORM_IEEE754_DOUBLE \
    ((FLT_RADIX == 2) && (DBL_MANT_DIG == 53) && (DBL_MIN_EXP == -1021) && (DBL_MAX_EXP == 1024))
static_assert(sizeof(std::size_t) >= sizeof(std::size_t),
    "The bit-length type used by Nunavut, std::size_t, "
    "is smaller than this platform's std::size_t type. "
    "Nunavut serialization relies on std::size_t to std::size_t conversions "
    "that do not lose data. You will need to regenerate Nunavut serialization support with a larger "
    "unsigned_bit_length type specified.");

namespace nunavut
{
namespace support
{

template<typename T>
class span final{
    T* ptr_;
    std::size_t size_;
public:
    using value_type = T;
    template<std::size_t N>
    span(std::array<T, N>& data): ptr_(data.data()), size_(data.size()){}
    template<std::size_t N>
    span(const std::array<T, N>& data): ptr_(data.data()), size_(data.size()){}
    template<std::size_t N>
    span(T (&data)[N]): ptr_(data), size_(N){}
    span(T* ptr,  std::size_t size): ptr_(ptr), size_(size){}

    T* data(){ return ptr_;}
    T* data() const { return ptr_;}
    std::size_t size() const{ return size_; }
    T& operator[](std::size_t index){

        return ptr_[index];
    }
    T& operator[](std::size_t index) const {

        return ptr_[index];
    }
};

using bytespan = span<uint8_t> ;
using const_bytespan = span<const uint8_t> ;

/// Nunavut serialization will never define more than 127 errors and the reserved error numbers are [1,127]
/// (128 is not used). Error code 1 is currently also not used to avoid conflicts with 3rd-party software.
enum class Error{
    // API usage errors:
    SerializationBufferTooSmall = 3,
    // Invalid representation (caused by bad input data, not API misuse):
    SerializationBadArrayLength=10,
    RepresentationBadUnionTag=11,
    RepresentationBadDelimiterHeader=12
};

template<typename Err>
struct unexpected final{
    Err value;
    explicit unexpected(Err e):value(e){}
};

/// This is a dumbed down version of C++23 std::expected, made better suited for
/// embedded applications. It never throws, but uses NUNAVUT_ASSERT to signal
/// exceptional cases.
/// All versions of Ret are expected to be non-throwing.
template<typename Ret>
class expected final{
    // We can use a maximum of all types.
    using storage_t = typename std::aligned_storage<
         (std::max(sizeof(Ret), sizeof(Error))),
         (std::max(alignof(Ret), alignof(Error)))>::type;
    storage_t storage;
    bool is_expected_;
private:
    Ret* ret_ptr() { return reinterpret_cast<Ret*>(&storage); }
    const Ret* ret_ptr() const { return reinterpret_cast<const Ret*>(&storage); }
    Error* error_ptr() { return reinterpret_cast<Error*>(&storage); }
    const Error* error_ptr() const { return reinterpret_cast<const Error*>(&storage); }
public:
    expected():is_expected_(true){ new(ret_ptr()) Ret(); }
    expected(Ret r):is_expected_(true){ new(ret_ptr()) Ret(std::move(r)); }
    expected& operator=(Ret other){ this->~expected(); return *new(this) expected(std::move(other)); }
    expected(unexpected<Error> err):is_expected_(false){ new(error_ptr()) Error(std::move(err.value)); }
    expected(const expected& other): is_expected_(other.is_expected_){
        if(is_expected_){ new(ret_ptr()) Ret(*other.ret_ptr()); }
        else { new(error_ptr()) Error(*other.error_ptr()); }
    }
    expected& operator=(const expected& other){
        this->~expected();
        return *new(this) expected(other);
    }
    expected(expected&& other): is_expected_(other.is_expected_){
        if(is_expected_){ new(ret_ptr()) Ret(std::move(*other.ret_ptr())); }
        else { new(error_ptr()) Error(std::move(*other.error_ptr())); }
    }
    expected& operator=(expected&& other){
        this->~expected();
        return *new(this) expected(std::move(other));
    }
    ~expected(){
        if(is_expected_){ ret_ptr()->~Ret(); }
        else{ error_ptr()->~Error(); }
    }

    Ret& value(){  return *ret_ptr(); }
    const Ret& value() const {  return *ret_ptr(); }
    Ret& operator*(){ return value(); }
    const Ret& operator*()const { return value(); }
    Ret* operator->(){  return ret_ptr(); }
    const Ret* operator->() const {  return ret_ptr(); }
    Error& error(){  return *error_ptr(); }
    const Error& error() const {  return *error_ptr(); }

    bool has_value() const { return is_expected_; }
    operator bool() const { return has_value(); }
};

template<>
class expected<void> final{
    using underlying_type = typename std::underlying_type<Error>::type;
    underlying_type e;
public:
    expected():e(0){}
    expected(unexpected<Error> err):e(static_cast<underlying_type>(err.value)){ }
    Error error() const {  return static_cast<Error>(e); }

    bool has_value() const { return e == 0; }
    operator bool() const { return has_value(); }
};

template<typename Ret>
using Result = expected<Ret>;

using VoidResult = Result<void>;
using SerializeResult = Result<std::size_t>;

inline unexpected<Error> operator-(const Error& e){
    return unexpected<Error>{e};
}

namespace options
{
constexpr std::uint32_t target_endianness = 1693710260;
constexpr std::uint32_t omit_float_serialization_support = 0;
constexpr std::uint32_t enable_serialization_asserts = 0;
constexpr std::uint32_t enable_override_variable_array_capacity = 0;
constexpr std::uint32_t std = 628873475;
constexpr std::uint32_t cast_format = 1407868567;
constexpr std::uint32_t variable_array_type_include = 3320664631;
constexpr std::uint32_t variable_array_type_template = 4227611599;
constexpr std::uint32_t variable_array_type_constructor_args = 0;
constexpr std::uint32_t allocator_include = 0;
constexpr std::uint32_t allocator_type = 0;
constexpr std::uint32_t allocator_is_default_constructible = 1;
constexpr std::uint32_t ctor_convention = 3814588639;

} // end namespace options

// ---------------------------------------------------- BIT ARRAY ----------------------------------------------------
namespace detail{
template<typename derived_bitspan>
struct any_bitspan{
protected:
    const uint8_t* unchecked_aligned_ptr(std::size_t plus_offset_bits=0U) const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        const std::size_t offset_bytes = ((self.offset_bits_ + plus_offset_bits) / 8U);
        return self.data_.data() + offset_bytes;
    }
public:

    derived_bitspan at_offset(std::size_t bits) const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        return derived_bitspan(self.data_.data(), self.data_.size(), self.offset_bits_ + bits);
    }

    /// Create a copy of current bitspan, converting current offset into  pointer
    /// and shrinking size of underlying byte span.
    /// This operation is safe even on empty containers since we are only creating
    /// an invalid pointer, but dont dereference it - it is guarded by asserts in this
    /// class and in byte span.
    derived_bitspan subspan(std::size_t bits=0) const noexcept{
        auto& self  = *static_cast<const derived_bitspan*>(this);
        const std::size_t offset_bits = self.offset_bits_ + bits;
        const std::size_t offset_bytes = (offset_bits) / 8U;
        const std::size_t offset_bits_mod = (offset_bits) % 8U;
        const std::size_t newSize = (offset_bytes < self.data_.size())?(self.data_.size() - offset_bytes):(0U);
        return derived_bitspan(self.data_.data() + offset_bytes, newSize, offset_bits_mod);
    }

    void add_offset(std::size_t bits) noexcept{
        auto& self  = *static_cast<derived_bitspan*>(this);
        self.offset_bits_ += bits;
    }

    void set_offset(std::size_t bits) noexcept{
        auto& self  = *static_cast<derived_bitspan*>(this);
        self.offset_bits_ = bits;
    }

    std::size_t offset_misalignment(std::size_t alignment_bits) const noexcept{
        auto& self  = *static_cast<const derived_bitspan*>(this);
        return self.offset_bits_ % alignment_bits;
    }

    bool offset_alings_to(std::size_t alignment_bits) const noexcept{
        return offset_misalignment(alignment_bits) == 0U;
    }

    bool offset_alings_to_byte() const noexcept{
        return offset_alings_to(8U);
    }

    std::size_t size() const noexcept{
        auto& self  = *static_cast<const derived_bitspan*>(this);
        std::size_t bit_size = static_cast<std::size_t>(self.data_.size()) * 8U;
        if(bit_size < self.offset_bits_){
            return 0U;
        }
        return bit_size - self.offset_bits_;
    }

    std::size_t offset() const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        return self.offset_bits_;
    }

    std::size_t offset_bytes() const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        const std::size_t offset_bytes = (self.offset_bits_) / 8U;
        return offset_bytes ;
    }

    std::size_t offset_bytes_ceil() const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        const std::size_t offset_bytes = ((self.offset_bits_ + 7U) / 8U);
        return offset_bytes ;
    }

    uint8_t& aligned_ref(std::size_t plus_offset_bits=0U) noexcept {
        auto& self  = *static_cast<derived_bitspan*>(this);
        const std::size_t offset_bytes = ((self.offset_bits_ + plus_offset_bits) / 8U);

        return self.data_[offset_bytes];
    }

    const uint8_t& aligned_ref(std::size_t plus_offset_bits=0U) const noexcept {
        auto& self  = *static_cast<const derived_bitspan*>(this);
        const std::size_t offset_bytes = ((self.offset_bits_ + plus_offset_bits) / 8U);

        return self.data_[offset_bytes];
    }

    uint8_t* aligned_ptr(std::size_t plus_offset_bits=0U) noexcept {
        return &aligned_ref(plus_offset_bits);
    }

    const uint8_t* aligned_ptr(std::size_t plus_offset_bits=0U) const noexcept {
        return &aligned_ref(plus_offset_bits);
    }

};

} // namespace detail

struct bitspan final: public detail::any_bitspan<bitspan>{
    friend struct detail::any_bitspan<bitspan>;
    friend struct const_bitspan;
private:
    bytespan data_;
    std::size_t offset_bits_;
public:
    using value_type = typename bytespan::value_type;

    template<std::size_t N>
    bitspan(std::array<value_type, N>& data, std::size_t offset_bits=0)
        : data_(data.data(), data.size()), offset_bits_(offset_bits) {}

    template<std::size_t N>
    bitspan(const std::array<value_type, N>& data, std::size_t offset_bits=0)
        : data_(data.data(), data.size()), offset_bits_(offset_bits) {}

    template<std::size_t N>
    bitspan(value_type (&data)[N], std::size_t offset_bits=0)
        : data_(data, N), offset_bits_(offset_bits) {}

    bitspan(value_type* ptr,  std::size_t size, std::size_t offset_bits=0)
        : data_(ptr, size), offset_bits_(offset_bits) {}

    Result<bitspan> subspan(std::size_t bits_at, std::size_t size_bits) const noexcept;
    // ---------------------------------------------------- INTEGER ----------------------------------------------------
    /// Serialize a DSDL field value at the specified bit offset from the beginning of the destination buffer.
    /// The behavior is undefined if the input pointer is nullprt. The time complexity is linear of the bit length.
    /// One-bit-wide signed integers are processed without raising an error but the result is unspecified.
    ///
    /// Arguments:
    ///     value           The value itself (in case of integers it is promoted to 64-bit for unification).
    ///     len_bits        Length of the serialized representation, in bits. Zero has no effect. Values >64 bit saturated.
    VoidResult setBit(const bool value);

    VoidResult setUxx(const uint64_t value, const uint8_t len_bits);

    VoidResult setIxx(const int64_t value, const uint8_t len_bits);

    VoidResult setF16(const float value);

    VoidResult setF32(const float value);

    VoidResult setF64(const double value);

    VoidResult setZeros() { return setZeros(size()); }
    VoidResult setZeros(std::size_t length);

    VoidResult padAndMoveToAlignment(std::size_t length);
};

struct const_bitspan final: public detail::any_bitspan<const_bitspan>{
    friend struct detail::any_bitspan<const_bitspan>;
private:
    const_bytespan data_;
    std::size_t offset_bits_;
public:
    using value_type = typename const_bytespan::value_type;

    template<std::size_t N>
    const_bitspan(std::array<value_type, N>& data, std::size_t offset_bits=0)
        : data_(data.data(), data.size()), offset_bits_(offset_bits) {}

    template<std::size_t N>
    const_bitspan(const std::array<value_type, N>& data, std::size_t offset_bits=0)
        : data_(data.data(), data.size()), offset_bits_(offset_bits) {}

    template<std::size_t N>
    const_bitspan(const value_type (&data)[N], std::size_t offset_bits=0)
        : data_(data, N), offset_bits_(offset_bits) {}

    const_bitspan(const value_type* ptr,  std::size_t size, std::size_t offset_bits=0)
        : data_(ptr, size), offset_bits_(offset_bits) {}

    /// Copy the specified number of bits from the source buffer into the destination buffer in accordance with the
    /// DSDL bit-level serialization specification. The offsets may be arbitrary (may exceed 8 bits).
    /// If both offsets are byte-aligned, the function invokes memmove() and possibly adjusts the last byte separately.
    /// If the source and the destination overlap AND the offsets are not byte-aligned, the behavior is undefined.
    /// If either source or destination pointers are NULL, the behavior is undefined.
    /// Arguments:
    ///     dst         Destination buffer. Shall be at least ceil(length_bits/8) bytes large.
    ///     length_bits The number of bits to copy. Both source and destination shall be large enough.
    void copyTo(bitspan dst){copyTo(dst, size());}
    void copyTo(bitspan dst,std::size_t length_bits) const noexcept {

        if(length_bits > size()){
            length_bits = size();
        }
        if(length_bits == 0){
            return;
        }

        if ((0U == (offset_bits_ % 8U)) && (0U == (dst.offset_bits_ % 8U)))  // Aligned copy, optimized, most common case.
        {
            const std::size_t length_bytes = static_cast<std::size_t>(length_bits / 8U);

            (void) memmove(dst.aligned_ptr(), aligned_ptr(), length_bytes);
            const uint8_t length_mod = static_cast<uint8_t>(length_bits % 8U);
            if (0U != length_mod)  // If the length is unaligned, the last byte requires special treatment.
            {

                const uint8_t mask = static_cast<uint8_t>((1U << length_mod) - 1U);
                //dst.data_[length_bytes] = (dst.data_[length_bytes] & static_cast<uint8_t>(~mask)) | (data_[length_bytes] & mask);
                dst.aligned_ref(length_bits) = (dst.aligned_ref(length_bits) & static_cast<uint8_t>(~mask)) | (aligned_ref(length_bits) & mask);
            }
        }
        else
        {
            // The algorithm was originally designed by Ben Dyer for Libuavcan v0:
            // https://github.com/OpenCyphal-garage/libuavcan/blob/legacy-v0/libuavcan/src/marshal/uc_bit_array_copy.cpp
            // This version is modified for v1 where the bit order is the opposite.
            std::size_t       src_off  = offset_bits_;
            std::size_t       dst_off  = dst.offset_bits_;
            const std::size_t last_bit = src_off + length_bits;

            while (last_bit > src_off)
            {
                const uint8_t src_mod = (src_off % 8U);
                const uint8_t dst_mod = (dst_off % 8U);
                const uint8_t max_mod = (src_mod > dst_mod) ? src_mod : dst_mod;
                const std::size_t max_mod_inv = 8U - max_mod;
                const std::size_t last_off = last_bit - src_off;
                const uint8_t size = static_cast<uint8_t>(std::min(max_mod_inv, last_off));

                // Suppress a false warning from Clang-Tidy & Sonar that size is being over-shifted. It's not.
                const uint8_t mask = ((((1U << size) - 1U) << dst_mod) & 0xFFU);  // NOLINT NOSONAR

                // Intentional violation of MISRA: indexing on a pointer.
                // This simplifies the implementation greatly and avoids pointer arithmetics.
                const uint8_t in = static_cast<uint8_t>(static_cast<uint8_t>(data_[src_off / 8U] >> src_mod) << dst_mod) & 0xFFU;  // NOSONAR
                // Intentional violation of MISRA: indexing on a pointer.
                // This simplifies the implementation greatly and avoids pointer arithmetics.
                const uint8_t a = dst.data_[dst_off / 8U] & (static_cast<uint8_t>(static_cast<uint8_t>(~mask) & 0xFFU));  // NOSONAR
                const uint8_t b = in & mask;
                // Intentional violation of MISRA: indexing on a pointer.
                // This simplifies the implementation greatly and avoids pointer arithmetics.
                dst.data_[dst_off / 8U] = a | b;  // NOSONAR
                src_off += size;
                dst_off += size;
            }

        }
    }

    template<std::size_t n_bits>
    void align_offset_to(){
        static_assert((n_bits == 8) or (n_bits == 16) or (n_bits == 32) or (n_bits == 64), "Non-standard alignment!");
        offset_bits_ = (offset_bits_ + (n_bits - 1)) & ~(static_cast<std::size_t>(n_bits - 1));
    }

    /// Calculate the number of bits to safely copy from/to a serialized buffer.
    /// Mind the units! By convention, buffer size is specified in bytes, but fragment length and offset are in bits.
    ///
    ///      buffer                                                                buffer
    ///      origin                                                                 end
    ///         [------------------------------ data_.size() ------------------------]
    ///         [-------------------- offset_bits_ ------------------][--- fragment_length_bits ---]
    ///                                                               [-- out bits --]
    ///                                                                              ^
    ///                                       this position is returned -------------/
    ///
    std::size_t saturateBufferFragmentBitLength(const std::size_t fragment_length_bits) const noexcept
    {
        const std::size_t size_bits = static_cast<std::size_t>(data_.size()) * 8U;
        const std::size_t tail_bits = size_bits - std::min(size_bits, offset_bits_);
        return std::min(fragment_length_bits, tail_bits);
    }

    /// This function is intended for deserialization of contiguous sequences of zero-cost primitives.
    /// It extracts (len_bits) bits that are offset by (offset_bits_) from the origin of (data_) whose size is (data_.size()).
    /// If the requested (len_bits+offset_bits_) overruns the buffer, the missing bits are implicitly zero-extended.
    /// If (len_bits % 8 != 0), the output buffer is right-zero-padded up to the next byte boundary.
    /// If (off_bits % 8 == 0), the operation is delegated to memmove(); otherwise, a much slower unaligned bit copy
    /// algorithm is employed. See @ref nunavutCopyBits() for further details.
    void getBits(bytespan output, const std::size_t len_bits)
    {

        const std::size_t len_bytes = (len_bits + 7U) / 8U;

        const std::size_t sat_bits = saturateBufferFragmentBitLength(len_bits);
        // Apply implicit zero extension. Normally, this is a no-op unless (len_bits > sat_bits) or (len_bits % 8 != 0).
        // The former case ensures that if we're copying <8 bits, the MSB in the destination will be zeroed out.
        std::memset(output.data() + (sat_bits / 8U), 0, len_bytes - (sat_bits / 8U));
        copyTo(bitspan{output.data(), output.size(), 0U}, sat_bits);
    }

    /// Deserialize a DSDL field value located at the specified bit offset from the beginning of the source buffer.
    /// If the deserialized value extends beyond the end of the buffer, the missing bits are taken as zero, as required
    /// by the DSDL specification (see Implicit Zero Extension Rule, IZER).
    ///
    /// If len_bits is greater than the return type, extra bits will be truncated per standard narrowing conversion rules.
    /// If len_bits is shorter than the return type, missing bits will be zero per standard integer promotion rules.
    /// Essentially, for integers, it would be enough to have 64-bit versions only; narrower variants exist only to avoid
    /// narrowing type conversions of the result and for some performance gains.
    ///
    /// The behavior is undefined if the input pointer is NULL. The time complexity is linear of the bit length.
    /// One-bit-wide signed integers are processed without raising an error but the result is unspecified.
    ///
    /// Arguments:
    ///     len_bits        Length of the serialized representation, in bits. Zero returns 0. Out-of-range values saturated.

    bool getBit() const noexcept
    {
        return 1U == getU8(1U);
    }

    uint8_t getU8(const uint8_t len_bits) const noexcept;

    uint16_t getU16(const uint8_t len_bits) const noexcept;

    uint32_t getU32(const uint8_t len_bits) const noexcept;

    uint64_t getU64(const uint8_t len_bits) const noexcept;

    int8_t getI8(const uint8_t len_bits) const noexcept;

    int16_t getI16(const uint8_t len_bits) const noexcept;

    int32_t getI32(const uint8_t len_bits) const noexcept;

    int64_t getI64(const uint8_t len_bits) const noexcept;

    float getF16();

    float getF32();

    double getF64();
};

inline VoidResult bitspan::setZeros(std::size_t length){
    if(length > size()){
        return -Error::SerializationBufferTooSmall;
    }
    if(length == 0){
        return {};
    }
    const std::size_t offset_bytes = offset_bits_ / 8U;
    const std::size_t offset_bits_mod = offset_bits_ % 8U;
    const std::size_t length_bytes_ceil = (length + 7U) / 8U;

    const auto first_byte_temp = data_[offset_bytes] & static_cast<uint8_t>(0xFF >> (8U - offset_bits_mod));
    memset(&data_[offset_bytes], 0, length_bytes_ceil);
    data_[offset_bytes] =  static_cast<uint8_t>(data_[offset_bytes] | first_byte_temp);
    return {};
}

inline VoidResult bitspan::padAndMoveToAlignment(std::size_t n_bits){
    const auto padding = static_cast<uint8_t>(n_bits - offset_misalignment(n_bits));
    if (padding != n_bits)  // Pad to n_bits bits. TODO: Eliminate redundant padding checks.
    {

        auto ref_result = setZeros(padding);
        if(not ref_result){
            return ref_result;
        }
        add_offset( padding);

    }
    return {};
}

inline Result<bitspan> bitspan::subspan(std::size_t bits_at, std::size_t size_bits) const noexcept {
    const std::size_t offset_bits = offset_bits_ + bits_at;
    const std::size_t offset_bytes = offset_bits / 8U;
    const std::size_t new_offset_bits = offset_bits % 8U;

    if(offset_bytes > data_.size()){
        return -Error::SerializationBufferTooSmall;
    }
    const std::size_t new_size_bits = new_offset_bits + size_bits;
    const std::size_t size_available_bits = (data_.size() - offset_bytes) * 8U;
    if(new_size_bits > size_available_bits){
        return -Error::SerializationBufferTooSmall;
    }
    const std::size_t new_size_bytes = new_size_bits / 8U;
    return bitspan( data_.data() + offset_bytes, new_size_bytes, new_offset_bits);
}

inline uint8_t const_bitspan::getU8(const uint8_t len_bits) const noexcept
{

    const std::size_t bits = saturateBufferFragmentBitLength(std::min<uint8_t>(len_bits, 8U));

    uint8_t val = 0;
    copyTo(bitspan{ &val, 1U }, bits);
    return val;
}

inline uint16_t const_bitspan::getU16(const uint8_t len_bits) const noexcept
{

    const std::size_t bits = saturateBufferFragmentBitLength(std::min<uint8_t>(len_bits, 16U));

    uint8_t tmp[sizeof(uint16_t)] = {0};
    copyTo(tmp, bits);
    return static_cast<uint16_t>(static_cast<uint16_t>(tmp[0]) | ((static_cast<uint16_t>(tmp[1])) << 8U));
}

inline uint32_t const_bitspan::getU32(const uint8_t len_bits) const noexcept
{

    const std::size_t bits = saturateBufferFragmentBitLength(std::min<uint8_t>(len_bits, 32U));

    uint8_t tmp[sizeof(uint32_t)] = {0};
    copyTo(tmp, bits);
    return static_cast<uint32_t>(
        (static_cast<uint32_t>(tmp[0])) |
        (static_cast<uint32_t>(tmp[1]) << 8U) |
        (static_cast<uint32_t>(tmp[2]) << 16U) |
        (static_cast<uint32_t>(tmp[3]) << 24U));
}

inline uint64_t const_bitspan::getU64(const uint8_t len_bits) const noexcept
{

    const std::size_t bits = saturateBufferFragmentBitLength(std::min<uint8_t>(len_bits, 64U));

    uint8_t tmp[sizeof(uint64_t)] = {0};
    copyTo(tmp, bits);
    return static_cast<uint64_t>(static_cast<uint64_t>(tmp[0]) |
                    (static_cast<uint64_t>(tmp[1]) << 8U) |
                    (static_cast<uint64_t>(tmp[2]) << 16U) |
                    (static_cast<uint64_t>(tmp[3]) << 24U) |
                    (static_cast<uint64_t>(tmp[4]) << 32U) |
                    (static_cast<uint64_t>(tmp[5]) << 40U) |
                    (static_cast<uint64_t>(tmp[6]) << 48U) |
                    (static_cast<uint64_t>(tmp[7]) << 56U));
}

inline int8_t const_bitspan::getI8(const uint8_t len_bits) const noexcept
{
    const uint8_t sat = std::min<uint8_t>(len_bits, 8U);
    uint8_t       val = getU8(sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 8U) && neg) ? static_cast<uint8_t>(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? static_cast<int8_t>(-static_cast<int8_t>(static_cast<uint8_t>(~val)) - 1) : static_cast<int8_t>(val);
}

inline int16_t const_bitspan::getI16(const uint8_t len_bits) const noexcept
{
    const uint8_t sat = std::min<uint8_t>(len_bits, 16U);
    uint16_t      val = getU16(sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 16U) && neg) ? static_cast<uint16_t>(val | ~((1U << sat) - 1U)) : val;  // Sign extension
    return neg ? static_cast<int16_t>(-static_cast<int16_t>(static_cast<uint16_t>(~val)) - 1) : static_cast<int16_t>(val);
}

inline int32_t const_bitspan::getI32(const uint8_t len_bits) const noexcept
{
    const uint8_t sat = std::min<uint8_t>(len_bits, 32U);
    uint32_t      val = getU32(sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 32U) && neg) ? static_cast<uint32_t>(val | ~((1UL << sat) - 1U)) : val;  // Sign extension
    return neg ? static_cast<int32_t>((-static_cast<int32_t>(~val)) - 1) : static_cast<int32_t>(val);
}

inline int64_t const_bitspan::getI64(const uint8_t len_bits) const noexcept
{
    const uint8_t sat = std::min<uint8_t>(len_bits, 64U);
    uint64_t      val = getU64(sat);
    const bool    neg = (sat > 0U) && ((val & (1ULL << (sat - 1U))) != 0U);
    val = ((sat < 64U) && neg) ? static_cast<uint64_t>(val | ~((1ULL << sat) - 1U)) : val;  // Sign extension
    return neg ? static_cast<int64_t>((-static_cast<int64_t>(~val)) - 1) : static_cast<int64_t>(val);
}

inline VoidResult bitspan::setBit(const bool value)
{
    if ((data_.size() * 8U) <= offset_bits_)
    {
        return -Error::SerializationBufferTooSmall;
    }
    const uint8_t val = value ? 1U : 0U;
    const_bitspan{ &val, 1U }.copyTo(*this, 1U);
    return {};
}

inline VoidResult bitspan::setUxx(const uint64_t value, const uint8_t len_bits)
{
    static_assert(64U == (sizeof(uint64_t) * 8U), "Unexpected size of uint64_t");
    if ((data_.size() * 8) < (offset_bits_ + len_bits))
    {
        return -Error::SerializationBufferTooSmall;
    }
    const std::size_t saturated_len_bits = std::min<std::size_t>(len_bits, 64U);
    const std::array<const uint8_t, 8> tmp{
        static_cast<uint8_t>((value >> 0U) & 0xFFU),
        static_cast<uint8_t>((value >> 8U) & 0xFFU),
        static_cast<uint8_t>((value >> 16U) & 0xFFU),
        static_cast<uint8_t>((value >> 24U) & 0xFFU),
        static_cast<uint8_t>((value >> 32U) & 0xFFU),
        static_cast<uint8_t>((value >> 40U) & 0xFFU),
        static_cast<uint8_t>((value >> 48U) & 0xFFU),
        static_cast<uint8_t>((value >> 56U) & 0xFFU),
    };
    const_bitspan{ tmp }.copyTo(*this, saturated_len_bits);
    return {};
}

inline VoidResult bitspan::setIxx(const int64_t value, const uint8_t len_bits)
{
    // The naive sign conversion is safe and portable according to the C++ Standard 4.7/2 :
    // If the destination type is unsigned, the resulting value is the least unsigned integer
    // congruent to the source integer (modulo 2^n where n is the number of bits used to represent
    // the unsigned type). [Note: In a two's complement representation, this conversion is conceptual and there
    // is no change in the bit pattern (if there is no truncation). ]
    return setUxx(static_cast<uint64_t>(value), len_bits);
}

// ---------------------------------------------------- FLOAT16 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT,
              "The target platform does not support IEEE754 floating point operations.");
static_assert(32U == (sizeof(float) * 8U), "Unsupported floating point model");

/// Converts a single-precision float into the binary representation of the value as a half-precision IEEE754 value.
static inline uint16_t float16Pack(const float value)
{
    typedef union  // NOSONAR
    {
        uint32_t bits;
        float real;
    } Float32Bits;

    // The no-lint statements suppress the warning about the use of union. This is required for low-level bit access.
    const uint32_t round_mask = ~static_cast<uint32_t>(0x0FFFU);
    Float32Bits    f32inf;  // NOSONAR
    Float32Bits    f16inf;  // NOSONAR
    Float32Bits    magic;   // NOSONAR
    Float32Bits    in;      // NOSONAR
    f32inf.bits = static_cast<uint32_t>( 255U) << 23U;
    f16inf.bits = static_cast<uint32_t>( 31U) << 23U;
    magic.bits = static_cast<uint32_t>( 15U) << 23U;
    in.real = value;
    const uint32_t sign = in.bits & (static_cast<uint32_t>( 1U) << 31U);
    in.bits ^= sign;
    uint16_t out = 0;
    if (in.bits >= f32inf.bits)
    {
        if ((in.bits & 0x7FFFFFUL) != 0)
        {
            out = 0x7E00U;
        }
        else
        {
            out = (in.bits > f32inf.bits) ? static_cast<uint16_t>(0x7FFFU) : static_cast<uint16_t>(0x7C00U);
        }
    }
    else
    {
        in.bits &= round_mask;
        in.real *= magic.real;
        in.bits -= round_mask;
        if (in.bits > f16inf.bits)
        {
            in.bits = f16inf.bits;
        }
        out = static_cast<uint16_t>(in.bits >> 13U);
    }
    out |= static_cast<uint16_t>(sign >> 16U);
    return out;
}

static inline float float16Unpack(const uint16_t value)
{
    typedef union  // NOSONAR
    {
        uint32_t bits;
        float real;
    } Float32Bits;

    // The no-lint statements suppress the warning about the use of union. This is required for low-level bit access.
    Float32Bits magic;    // NOSONAR
    Float32Bits inf_nan;  // NOSONAR
    Float32Bits out;      // NOSONAR
    magic.bits = static_cast<uint32_t>( 0xEFU) << 23U;
    inf_nan.bits = static_cast<uint32_t>( 0x8FU) << 23U;
    out.bits = static_cast<uint32_t>(value & 0x7FFFU) << 13U;
    out.real *= magic.real;
    if (out.real >= inf_nan.real)
    {
        out.bits |= static_cast<uint32_t>( 0xFFU) << 23U;
    }
    out.bits |= static_cast<uint32_t>(value & 0x8000U) << 16U;
    return out.real;
}

inline VoidResult bitspan::setF16(const float value)
{
    return setUxx(float16Pack(value), 16U);
}

inline float const_bitspan::getF16()
{
    return float16Unpack(getU16(16U));
}

// ---------------------------------------------------- FLOAT32 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT,
              "The target platform does not support IEEE754 floating point operations.");
static_assert(32U == (sizeof(float) * 8U), "Unsupported floating point model");

inline VoidResult bitspan::setF32(const float value)
{
    // Intentional violation of MISRA: use union to perform fast conversion from an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        float fl;
        uint32_t in;
    } const tmp = {value};  // NOSONAR
    return setUxx(tmp.in, sizeof(tmp) * 8U);
}

inline float const_bitspan::getF32()
{
    // Intentional violation of MISRA: use union to perform fast conversion to an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        uint32_t in;
        float fl;
    } const tmp = {getU32(32U)};
    return tmp.fl;
}

// ---------------------------------------------------- FLOAT64 ----------------------------------------------------

static_assert(NUNAVUT_PLATFORM_IEEE754_DOUBLE,
              "The target platform does not support IEEE754 double-precision floating point operations.");
static_assert(64U == (sizeof(double) * 8U), "Unsupported floating point model");

inline VoidResult bitspan::setF64(const double value)
{
    // Intentional violation of MISRA: use union to perform fast conversion from an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        double fl;
        uint64_t in;
    } const tmp = {value};  // NOSONAR
    return setUxx(tmp.in, sizeof(tmp) * 8U);
}

inline double const_bitspan::getF64()
{
    // Intentional violation of MISRA: use union to perform fast conversion to an IEEE 754-compatible native
    // representation into a serializable integer. The assumptions about the target platform properties are made
    // clear. In the future we may add a more generic conversion that is platform-invariant.
    union  // NOSONAR
    {
        uint64_t in;
        double fl;
    } const tmp = {getU64(64U)};
    return tmp.fl;
}

} // end namespace support
} // end namespace nunavut

#endif // NUNAVUT_SUPPORT_SERIALIZATION_HPP_INCLUDED
