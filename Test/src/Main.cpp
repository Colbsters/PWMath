#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{

	PWMath::Vector3_F32 a, b{ 2, 3, 1 };
	a = b;
	std::cout << a << '\n';
	a += b;
	std::cout << a << '\n';
	std::cout << PWMath::Dot(a, b) << '\n';
	std::cout << PWMath::Vector3_F64{ a } << '\n';
	std::cout << PWMath::Vector3_F32{ 4, 3, 0 }.Length() << '\n';
	std::cout << PWMath::Vector3_F32{ 1, 0, 0 }.Cross(PWMath::Vector3_F32{ 0, 1, 0 }) << '\n';

	return 0;
}
