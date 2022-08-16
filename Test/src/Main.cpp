#include <iostream>
#define PWM_DEFINE_OSTREAM 1
#include <PWMath/PWMath.h>

int main()
{
	PWMath::Vector3F32 v{ 1, 0, 0 };
	PWMath::Matrix3x3F32 A{
		1, 1, 0,
		0, 1, 0,
		0, 0, 1
	};

	std::cout << v << '\n' << A << '\n' << (v *= A) << '\n' << A * v << '\n';

	return 0;
}
