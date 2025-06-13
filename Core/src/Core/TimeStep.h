#pragma once

namespace Core
{
	class TimeStep
	{
	public:
		TimeStep(float time = 0.0f)
			: m_Time(time)
		{
		}
		~TimeStep()
		{
		}

		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }

		operator float() const { return m_Time; }

	private:
		float m_Time;
	};
}