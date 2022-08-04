#pragma once
#include <PWMath/Vector.h>

#if PWM_DEFINE_OSTREAM
#include <ostream>
#endif // PWM_DEFINE_OSTREAM
#include <cmath>

namespace PWMath
{
	// 4 component template specialization of Vector
	template<typename T, PackingMode P>
	struct Vector<T, 4, P>
	{
	public:
		using Type = T;
		static constexpr size_t length = 4;
		static constexpr PackingMode packingMode = P;

		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			T array[4];
		};

		// Default constuctors and destructors
		constexpr Vector() = default;
		constexpr Vector(const Vector&) = default;
		constexpr ~Vector() = default;
		
		// Special constructors and destructors
		constexpr Vector(T values) noexcept :x{ values }, y{ values }, z{ values }, w{ values } {}
		constexpr Vector(T x, T y, T z, T w) noexcept :x{ x }, y{ y }, z{ z }, w{ w } {}
		constexpr Vector(const Vector2<T, P>& xy, T z, T w) noexcept :x{ xy.x }, y{ xy.y }, z{ z }, w{ w } {}
		constexpr Vector(T x, const Vector2<T, P>& yz, T w) noexcept :x{ x }, y{ yz.y }, z{ yz.z }, w{ w } {}
		constexpr Vector(T x, T y, const Vector2<T, P>& zw) noexcept :x{ x }, y{ y }, z{ zw.z }, w{ zw.w } {}
		constexpr Vector(const Vector2<T, P>& xy, const Vector2<T, P>& zw) noexcept :x{ xy.x }, y{ xy.y }, z{ zw.z }, w{ zw.w } {}
		constexpr Vector(const Vector3<T, P>& xyz, T w) noexcept :x{ xyz.x }, y{ xyz.y }, z{ xyz.z }, w{ w } {}
		constexpr Vector(T x, const Vector3<T, P>& yzw) noexcept :x{ x }, y{ yzw.y }, z{ yzw.z }, w{ yzw.w } {}
		constexpr Vector(T (&values)[4]) noexcept :x{ values[0] }, y{ values[1] }, z{ values[2] }, w{ values[3] } {}
		template<typename Tval>
		constexpr Vector(Tval values) noexcept :x{ static_cast<T>(values) }, y{ static_cast<T>(values) }, z{ static_cast<T>(values) }, w{ static_cast<T>(values) } {}
		template<typename Tx, typename Ty, typename Tz, typename Tw>
		constexpr Vector(Tx x, Ty y, Tz z, Tw w) noexcept :x{ static_cast<T>(x) }, y{ static_cast<T>(y) }, z{ static_cast<T>(z) }, w{ static_cast<T>(w) } {}
		template<typename Tvec, PackingMode Pvec>
		constexpr Vector(const Vector<Tvec, 4, Pvec>& rhs) noexcept :x{ static_cast<T>(rhs.x) }, y{ static_cast<T>(rhs.y) }, z{ static_cast<T>(rhs.z) }, w{ static_cast<T>(rhs.w) } {}

		constexpr T& operator[](size_t index) { return array[index]; }
		constexpr const T& operator[](size_t index) const { return array[index]; }

		Vector& operator=(const Vector& rhs) = default;

		bool operator==(const Vector& rhs) const = default;

		constexpr T Length();
		constexpr T Length2();
		constexpr Vector Normalize();
		constexpr T Dot(const Vector<T, 4, P>& rhs);


		constexpr Vector<T, 2, P> Swizzle(size_t index0, size_t index1) { return Vector<T, 2, P>{ array[index0], array[index1] }; }
		constexpr Vector<T, 3, P> Swizzle(size_t index0, size_t index1, size_t index2) { return Vector<T, 3, P>{ array[index0], array[index1], array[index2] }; }
		constexpr Vector<T, 4, P> Swizzle(size_t index0, size_t index1, size_t index2, size_t index3) { return Vector<T, 4, P>{ array[index0], array[index1], array[index2], array[index3] }; }
	};

	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator+(const Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator-(const Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator*(const Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator/(const Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator+=(Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator-=(Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator*=(Vector<T, 4, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator/=(Vector<T, 4, P>& lhs, T rhs) noexcept;

	template<typename T, PackingMode P>	
	constexpr Vector<T, 4, P> operator+(const Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 4, P> operator-(const Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 4, P> operator*(const Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr Vector<T, 4, P> operator/(const Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator+=(Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator-=(Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator*=(Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	constexpr const Vector<T, 4, P>& operator/=(Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator+(T lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator-(T lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator*(T lhs, const Vector<T, 4, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> operator/(T lhs, const Vector<T, 4, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	constexpr T Length(const Vector<T, 4, P>& vector);

	template<typename T, PackingMode P>
	constexpr T Length2(const Vector<T, 4, P>& vector);

	template<typename T, PackingMode P>
	constexpr Vector<T, 4, P> Normalize(const Vector<T, 4, P>& vector);

	template<typename T, PackingMode P>
	constexpr T Dot(const Vector<T, 4, P>& lhs, const Vector<T, 4, P>& rhs);

#if PWM_DEFINE_OSTREAM
	template<typename T, PackingMode P>
	inline std::ostream& operator<<(std::ostream& stream, Vector<T, 4, P> vector)
	{
		stream << '[' << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ']';
		return stream;
	}
#endif // PWM_DEFINE_OSTREAM

	template<typename T, PackingMode P = PackingMode::Default>
	using Vector4 = Vector<T, 4, P>;

	using Vector4_F32		= Vector4<float>;
	using Vector4_F64		= Vector4<double>;
	using Vector4_I8		= Vector4<int8_t>;
	using Vector4_I16		= Vector4<int16_t>;
	using Vector4_I32		= Vector4<int32_t>;
	using Vector4_I64		= Vector4<int64_t>;
	using Vector4_U8		= Vector4<uint8_t>;
	using Vector4_U16		= Vector4<uint16_t>;
	using Vector4_U32		= Vector4<uint32_t>;
	using Vector4_U64		= Vector4<uint64_t>;
}

#include <PWMath/Impl/Vector4.inl>
