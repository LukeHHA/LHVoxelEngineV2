#include "LHCpch.h"

#include "Importer.h"
#include "AssimpMeshLoader.h"

namespace Core
{
	std::shared_ptr<Importer> Importer::Create(const ImporterType &type, const std::string &path)
	{
		if (type == ASSIMP_IMPORTER)
		{
			return std::make_shared<AssimpMeshLoader>(path);
		}
		else
		{
			CORE_ASSERT(false, "Unkown Importer type");
		}
	}
} // namespace Core
