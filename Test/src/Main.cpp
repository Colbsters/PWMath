#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{

	PWMath::Vector2_F32 a, b{ 2, 3 };
	a = b;
	auto c = a.Swizzle(0, 1, 0, 1);
	auto d = c.Swizzle(3, 2, 1);
	std::cout << d << '\n';

	return 0;
}
