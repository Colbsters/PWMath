#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{
	auto transform = PWMath::Rotate(PWMath::Matrix2x2F32{ 1 }, 3.141592654 / 2);

	std::cout << transform << '\n';

	std::cout << PWMath::Vector2F32{ 6, 3 } * transform << '\n';

	return 0;
}
