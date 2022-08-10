#pragma once
#include <PWMath/Vector1.h>

namespace PWMath
{
#pragma region Unary operators

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator+(const Vector<T, 1, P>& vector) noexcept
	{
		return vector;
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(const Vector<T, 1, P>& vector) noexcept
	{
		return Vector<T, 1, P>{ -vector.x };
	}

#pragma endregion

#pragma region Vector and scalar

	template<typename T, PackingMode P>
	constexpr Vector<T, 2, P> operator+(const Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs + Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(const Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs - Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator*(const Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs * Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator/(const Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs / Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator+=(Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs += Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator-=(Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs -= Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator*=(Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs *= Vector<T, 1, P>{ rhs };
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator/=(Vector<T, 1, P>& lhs, T rhs) noexcept
	{
		return lhs /= Vector<T, 1, P>{ rhs };
	}

#pragma endregion

#pragma region Vector and vector

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator+(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs.x + rhs.x };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs.x - rhs.x };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator*(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs.x * rhs.x };
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator/(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs.x / rhs.x };
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator+=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return lhs = (lhs + rhs);
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator-=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return lhs = (lhs - rhs);
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator*=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return lhs = (lhs * rhs);
	}

	template<typename T, PackingMode P>
	constexpr const Vector<T, 1, P>& operator/=(Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return lhs = (lhs / rhs);
	}

#pragma endregion
	
#pragma region Scalar and vector

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator+(T lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs } + rhs;
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator-(T lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs } - rhs;
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator*(T lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs } * rhs;
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> operator/(T lhs, const Vector<T, 1, P>& rhs) noexcept
	{
		return Vector<T, 1, P>{ lhs } / rhs;
	}

#pragma endregion

#pragma region Other functions

	template<typename T, PackingMode P>
	constexpr T Length(const Vector<T, 1, P>& vector)
	{
		return std::abs(vector.x);
	}

	template<typename T, PackingMode P>
	constexpr T Length2(const Vector<T, 1, P>& vector)
	{
		return (vector.x * vector.x);
	}

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> Normalize(const Vector<T, 1, P>& vector)
	{
		return vector / Length(vector);
	}

	template<typename T, PackingMode P>
	constexpr T Dot(const Vector<T, 1, P>& lhs, const Vector<T, 1, P>& rhs)
	{
		return (lhs.x * rhs.x);
	}

#pragma endregion

#pragma region Member versions of functions

	template<typename T, PackingMode P>
	constexpr T Vector<T, 1, P>::Length() { return PWMath::Length(*this); }

	template<typename T, PackingMode P>
	constexpr T Vector<T, 1, P>::Length2() { return PWMath::Length2(*this); }

	template<typename T, PackingMode P>
	constexpr Vector<T, 1, P> Vector<T, 1, P>::Normalize() { return PWMath::Normalize(*this); }

	template<typename T, PackingMode P>
	constexpr T Vector<T, 1, P>::Dot(const Vector<T, 1, P>& rhs) { return PWMath::Dot(*this, rhs); }

#pragma endregion
}
