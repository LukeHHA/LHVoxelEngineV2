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

		void OnUpdate();
		void OnEvent(Event &event);

	private:
	};
}