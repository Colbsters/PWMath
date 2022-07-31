#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{

	PWMath::Vector2_F32 a, b{ 2, 3 };
	a = b;
	std::cout << a << '\n';
	a += b;
	std::cout << a << '\n';
	std::cout << PWMath::Dot(a, b) << '\n';
	std::cout << PWMath::Vector2_F64{ a } << '\n';
	std::cout << PWMath::Vector2_F32{ 4, 3 }.Length() << '\n';

	return 0;
}
