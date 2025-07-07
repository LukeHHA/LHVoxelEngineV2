#include "Scene.h"

namespace Core
{
	Scene::Scene()
	{
		entt::entity entity = m_Registry.create();
	}

	Scene::~Scene() {}
}