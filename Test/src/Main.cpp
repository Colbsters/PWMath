#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{
	PWMath::Vector2F32 a{ 2.0f, 1.0f };
	std::cout << a << '\n' << a.Swizzle(1) << '\n' << PWMath::Vector4F32{ a, a.Swizzle(0), 1.0f } << '\n';

	return 0;
}
