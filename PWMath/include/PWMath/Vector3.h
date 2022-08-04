#pragma once
#include <PWMath/Vector.h>

#if PWM_DEFINE_OSTREAM
#include <ostream>
#endif // PWM_DEFINE_OSTREAM
#include <cmath>

namespace PWMath
{
	// 3 component template specialization of Vector
	template<typename T, PackingMode P>
	struct Vector<T, 3, P>
	{
	public:
		using type = T;
		static constexpr size_t length = 3;
		static constexpr PackingMode packingMode = P;

		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			T array[3];
		};

		// Default constuctors and destructors
		Vector() = default;
		Vector(const Vector&) = default;
		~Vector() = default;
		
		// Special constructors and destructors
		Vector(T values) noexcept :x{ values }, y{ values }, z{ values } {}
		Vector(T x, T y, T z) noexcept :x{ x }, y{ y }, z{ z }
		{}
		Vector(const Vector2<T, P>& xy, T z) noexcept :x{ xy.x }, y{ xy.y }, z{ z } {}
		Vector(T x, const Vector2<T, P>& yz) noexcept :x{ x }, y{ yz.y }, z{ yz.z } {}
		Vector(T(&values)[3]) noexcept :x{ values[0] }, y{ values[1] }, z{ values[2] } {}
		template<typename Tval>
		Vector(Tval values) noexcept :x{ static_cast<T>(values) }, y{ static_cast<T>(values) }, z{ static_cast<T>(values) } {}
		template<typename Tx, typename Ty, typename Tz>
		Vector(Tx x, Ty y, Tz z) noexcept :x{ static_cast<T>(x) }, y{ static_cast<T>(y) }, z{ static_cast<T>(z) } {}
		template<typename Tvec, PackingMode Pvec>
		Vector(const Vector2<Tvec, Pvec>& xy, Tvec z) noexcept :x{ static_cast<T>(xy.x) }, y{ static_cast<T>(xy.y) }, z{ static_cast<T>(z) } {}
		template<typename Tvec, PackingMode Pvec>
		Vector(Tvec x, const Vector2<Tvec, Pvec>& yz) noexcept :x{ static_cast<T>(x) }, y{ static_cast<T>(yz.y) }, z{ static_cast<T>(yz.z) } {}
		template<typename Tarr>
		Vector(Tarr (&values)[3]) noexcept :x{ static_cast<T>(values[0]) }, y{ static_cast<T>(values[1]) }, z{ static_cast<T>(values[2])} {}
		template<typename Tvec, PackingMode Pvec>
		Vector(const Vector<Tvec, 3, Pvec>& rhs) noexcept :x{ static_cast<T>(rhs.x) }, y{ static_cast<T>(rhs.y) }, z{ static_cast<T>(rhs.z) } {}

		T& operator[](size_t index) { return array[index]; }
		const T& operator[](size_t index) const { return array[index]; }

		Vector& operator=(const Vector& rhs) = default;

		bool operator==(const Vector& rhs) const = default;

		T Length();
		T Length2();
		Vector Normalize();
		T Dot(const Vector<T, 3, P>& rhs);
		Vector Cross(const Vector<T, 3, P>& rhs);


		constexpr Vector<T, 2, P> Swizzle(size_t index0, size_t index1) { return Vector<T, 2, P>{ array[index0], array[index1] }; }
		constexpr Vector<T, 3, P> Swizzle(size_t index0, size_t index1, size_t index2) { return Vector<T, 3, P>{ array[index0], array[index1], array[index2] }; }
		constexpr Vector<T, 4, P> Swizzle(size_t index0, size_t index1, size_t index2, size_t index3) { return Vector<T, 4, P>{ array[index0], array[index1], array[index2], array[index3] }; }
	};

	template<typename T, PackingMode P>
	Vector<T, 3, P> operator+(const Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator-(const Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator*(const Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator/(const Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator+=(Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator-=(Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator*=(Vector<T, 3, P>& lhs, T rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator/=(Vector<T, 3, P>& lhs, T rhs) noexcept;

	template<typename T, PackingMode P>	
	Vector<T, 3, P> operator+(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	Vector<T, 3, P> operator-(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	Vector<T, 3, P> operator*(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	Vector<T, 3, P> operator/(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator+=(Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator-=(Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator*=(Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>	
	const Vector<T, 3, P>& operator/=(Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	Vector<T, 3, P> operator+(T lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator-(T lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator*(T lhs, const Vector<T, 3, P>& rhs) noexcept;
	template<typename T, PackingMode P>
	Vector<T, 3, P> operator/(T lhs, const Vector<T, 3, P>& rhs) noexcept;

	template<typename T, PackingMode P>
	T Length(const Vector<T, 3, P>& vector);

	template<typename T, PackingMode P>
	T Length2(const Vector<T, 3, P>& vector);

	template<typename T, PackingMode P>
	Vector<T, 3, P> Normalize(const Vector<T, 3, P>& vector);

	template<typename T, PackingMode P>
	T Dot(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs);

	template<typename T, PackingMode P>
	Vector<T, 3, P> Cross(const Vector<T, 3, P>& lhs, const Vector<T, 3, P>& rhs);

#if PWM_DEFINE_OSTREAM
	template<typename T, PackingMode P>
	inline std::ostream& operator<<(std::ostream& stream, Vector<T, 3, P> vector)
	{
		stream << '[' << vector.x << ", " << vector.y << ", " << vector.z << ']';
		return stream;
	}
#endif // PWM_DEFINE_OSTREAM

	template<typename T, PackingMode P = PackingMode::Default>
	using Vector3 = Vector<T, 3, P>;

	using Vector3_F32		= Vector3<float>;
	using Vector3_F64		= Vector3<double>;
	using Vector3_I8		= Vector3<int8_t>;
	using Vector3_I16		= Vector3<int16_t>;
	using Vector3_I32		= Vector3<int32_t>;
	using Vector3_I64		= Vector3<int64_t>;
	using Vector3_U8		= Vector3<uint8_t>;
	using Vector3_U16		= Vector3<uint16_t>;
	using Vector3_U32		= Vector3<uint32_t>;
	using Vector3_U64		= Vector3<uint64_t>;
}

#include <PWMath/Impl/Vector3.inl>
