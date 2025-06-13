#pragma once

#include <chrono>

namespace Core
{
	class PlatfromUtils
	{
	public:
		PlatfromUtils(/* args */) {}
		~PlatfromUtils() {}

		double GetTimeSeconds()
		{
			using namespace std::chrono;
			return duration<double>(steady_clock::now().time_since_epoch()).count();
		}

		float GetTimeMS()
		{
			using namespace std::chrono;
			auto sinceE = duration<float>(steady_clock::now().time_since_epoch());
			return duration_cast<milliseconds>(sinceE).count();
		}

	private:
		/* data */
	};

}