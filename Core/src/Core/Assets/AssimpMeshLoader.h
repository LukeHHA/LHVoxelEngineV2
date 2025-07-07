/**
 * @file AssimpMeshLoader.h
 * @brief Load mesh data from a source file using Assimp
 */

#pragma once

#include "Importer.h"

class MeshSource;

/// @namespace Core
namespace Core
{

	class AssimpMeshLoader : public Importer
	{
	public:
		AssimpMeshLoader(const std::string &path);
		~AssimpMeshLoader() {};

		std::shared_ptr<MeshSource> LoadToMeshSource() override;

	private:
		std::string m_Path;
	};
} // namespace Core
