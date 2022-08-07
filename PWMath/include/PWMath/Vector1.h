#pragma once
#include <PWMath/Vector.h>

#if PWM_DEFINE_OSTREAM
#include <ostream>
#endif // PWM_DEFINE_OSTREAM
#include <cmath>

namespace PWMath
{
	// 1 component template specialization of Vector
	template<typename T, PackingMode P>
	struct Vector<T, 1, P>
	{
	public:
		using Type = T;
		static constexpr size_t size = 1;
		static constexpr PackingMode packingMode = P;

		union
		{
			struct { T x; };
			struct { T r; };
			T array[1];
		};

		// Default constuctors and destructors
		Vector() = default;
		Vector(const Vector&) = default;
		~Vector() = default;
		
		// Special constructors and destructors
		template<typename TVal>
		constexpr Vector(TVal values) noexcept :array{ static_cast<T>(values) } {}
		template<typename TX, typename TY>
		constexpr Vector(TX x) noexcept :array{ static_cast<T>(x) } {}
		template<typename TArr>
		constexpr Vector(TArr (&values)[1]) noexcept :array{ static_cast<T>(values[0]) } {}
		template<typename TVec, PackingMode PVec>
		constexpr Vector(const Vector<TVec, 1, PVec>& rhs) noexcept :array{ static_cast<T>(rhs.x) } {}

		constexpr T& operator[](size_t index) { return array[index]; }
		constexpr const T& operator[](size_t index) const { return array[index]; }

		Vector& operator=(const Vector& rhs) = default;

		bool operator==(const Vector& rhs) const = default;

		constexpr T Length();
		constexpr T Length2();
		constexpr Vector Normalize();
		constexpr T Dot(const Vector<T, 1, P>& rhs);

		constexpr Vector<T, 1, P> Swizzle(size_t index0) { return Vector<T, 1, P>{ array[index0] }; }
		constexpr Vector<T, 2, P> Swizzle(size_t index0, size_t index1) { return Vector<T, 2, P>{ array[index0], array[index1] }; }
		constexpr Vector<T, 3, P> Swizzle(size_t index0, size_t index1, size_t index2) { return Vector<T, 3, P>{ array[index0], array[index1], array[index2] }; }
		constexpr Vector<T, 4, P> Swizzle(size_t index0, size_t index1, size_t index2, size_t index3) { return Vector<T, 4, P>{ array[index0], array[index1], array[index2], array[index3] }; }
	};

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator+(const Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(const Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator*(const Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator/(const Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator+=(Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator-=(Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator*=(Vector<T, 1, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator/=(Vector<T, 1, P>& lhs, T rhs) noexcept;

	template<typename T, PackingMode P>	
	constexpr Vector<T, 1, P> operator+(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 1, P> operator-(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 1, P> operator*(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 1, P> operator/(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator+=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator-=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator*=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 1, P>& operator/=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator+(T lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(T lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator*(T lhs, const Vector<T, 1, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator/(T lhs, const Vector<T, 1, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	constexpr T Length(const Vector<T, 1, P>& vector);

	template<typename T, PackingMode P>
	constexpr T Length2(const Vector<T, 1, P>& vector);

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> Normalize(const Vector<T, 1, P>& vector);

	template<typename T, PackingMode P>
	constexpr T Dot(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs);

#if PWM_DEFINE_OSTREAM
	template<typename T, PackingMode P>
	inline std::ostream& operator<<(std::ostream& stream, Vector<T, 1, P> vector)
	{
		stream << '[' << vector.x << ']';
		return stream;
	}
#endif // PWM_DEFINE_OSTREAM

	template<typename T, PackingMode P = PackingMode::Default>
	using Vector1 = Vector<T, 1, P>;

	using Vector1F32	= Vector1<float>;
	using Vector1F64	= Vector1<double>;
	using Vector1I8		= Vector1<int8_t>;
	using Vector1I16	= Vector1<int16_t>;
	using Vector1I32	= Vector1<int32_t>;
	using Vector1I64	= Vector1<int64_t>;
	using Vector1U8		= Vector1<uint8_t>;
	using Vector1U16	= Vector1<uint16_t>;
	using Vector1U32	= Vector1<uint32_t>;
	using Vector1U64	= Vector1<uint64_t>;
}

#include <PWMath/Impl/Vector1.inl>
