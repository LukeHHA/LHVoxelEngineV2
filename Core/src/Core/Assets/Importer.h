#pragma once

#include "LHCpch.h"

namespace Core
{
	enum ImporterType
	{
		ASSIMP_IMPORTER = 0
	};

	class MeshSource;

	class Importer
	{
	public:
		Importer();
		virtual ~Importer() = default;

		virtual std::shared_ptr<MeshSource> LoadToMeshSource() = 0;

		static std::shared_ptr<Importer> Create(const ImporterType &type, const std::string &path);
	};
} // namespace Core
