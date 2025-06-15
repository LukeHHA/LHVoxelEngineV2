#pragma once

#include "Core/Layers/Layer.h"

namespace Core
{
	class ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate(TimeStep ts);
		void OnEvent(Event &event);

	private:
		float m_Time = 0.0f;
	};
}