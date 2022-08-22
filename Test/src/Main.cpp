#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>
#include <PWMath/Projection.h>

int main()
{
	auto transform = PWMath::PerpectiveGL(1.57079632f, 1.0f, 0.1f, 1.0f);

	std::cout << transform << '\n';

	auto pos = PWMath::Vector4F32{ 0.5, 0.5, 1, 1 } * transform;
	pos /= pos.w;

	std::cout << pos << '\n';

	return 0;
}
