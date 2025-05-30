#include "glm/glm.hpp"
#include "glad/glad.h"

#include <array>
#include <cstddef>

#include <vector>
struct BufferElement
{
	GLuint Index;
	GLuint Count;
	GLenum Type;
	GLboolean Normalized;
	size_t Offset;
};

template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
struct VertexPos
{
	glm::vec<L, T, Q> Pos;

	static constexpr auto Layout()
	{
		using Self = VertexPos<L, T, GLType, Q, Norm>;
		/// index, count,     GLenum,    normalized,      offset
		return std::array<BufferElement, 1>{
			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)}}};
	}
};

using C1_BufferVertex3f_Pos = VertexPos<3, float, GL_FLOAT>;

// template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
// struct VertexPosUv
//{
//	glm::vec<L, T, Q> Pos;
//	glm::vec<2, T, Q> UV;
//
//	static constexpr auto Layout()
//	{
//		using Self = VertexPosUv<L, T, GLType, Q, Norm>;
//		/// index, count,     GLenum,    normalized,      offset
//		return std::array<BufferElement, 2>{
//			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)},
//			 {1u, 2u, GLType, GLboolean(Norm), offsetof(Self, UV)}}};
//	}
// };
//
// template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
// struct VertexPosNormal
//{
//	glm::vec<L, T, Q> Pos;
//	glm::vec<L, T, Q> Normal;
//
//	static constexpr auto Layout()
//	{
//		using Self = VertexPosNormal<L, T, GLType, Q, Norm>;
//		/// index, count,     GLenum,    normalized,      offset
//		return std::array<BufferElement, 2>{
//			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)},
//			 {1u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Normal)}}};
//	}
// };
//
// template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
// struct VertexPosColor
//{
//	glm::vec<L, T, Q> Pos;
//	glm::vec<4, float, Q> Color;
//
//	static constexpr auto VertexPosColor()
//	{
//		using Self = Vertex<L, T, GLType, Q, Norm>;
//		/// index, count,     GLenum,    normalized,      offset
//		return std::array<BufferElement, 2>{
//			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)},
//			 {1u, 2u, GLType, GLboolean(Norm), offsetof(Self, Color)}}};
//	}
// };
//
///// 2 COMPONENT BUFFER
//
///// INT
///// 2 COMPONENT VEC
// using C2_BufferVertex2i_Uv = VertexPosUv<2, int, GL_INT>;
// using C2_BufferVertex2i_Norm = VertexPosNormal<2, int, GL_INT>;
// using C2_BufferVertex2i_Color = VertexPosColor<2, int, GL_INT>;
//
///// 3 COMPONENT VEC
// using C2_BufferVertex3i_Uv = VertexPosUv<3, int, GL_INT>;
// using C2_BufferVertex3i_Norm = VertexPosNormal<3, int, GL_INT>;
// using C2_BufferVertex3i_Color = VertexPosColor<3, int, GL_INT>;
//
///// FLOAT
///// 2 COMPONENT VEC
// using C2_BufferVertex2f_Uv = VertexPosUv<2, float, GL_FLOAT>;
// using C2_BufferVertex2f_Norm = VertexPosNormal<2, float, GL_FLOAT>;
// using C2_BufferVertex2f_Color = VertexPosColor<2, float, GL_FLOAT>;
//
///// 3 COMPONENT VEC
// using C2_BufferVertex3f_Uv = VertexPosUv<3, float, GL_FLOAT>;
// using C2_BufferVertex3f_Norm = VertexPosNormal<3, float, GL_FLOAT>;
// using C2_BufferVertex3f_Color = VertexPosColor<3, float, GL_FLOAT>;
//
// template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
// struct VertexPosNormUv
//{
//	glm::vec<L, T, Q> Pos;
//	glm::vec<L, T, Q> Normal;
//	glm::vec<2, T, Q> UV;
//
//	static constexpr auto Layout()
//	{
//		using Self = VertexPosNormUv<L, T, GLType, Q, Norm>;
//		/// index, count,     GLenum,    normalized,      offset
//		return std::array<BufferElement, 3>{
//			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)},
//			 {1u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Normal)},
//			 {2u, 2u, GLType, GLboolean(Norm), offsetof(Self, UV)}}};
//	}
// };
//
// template <glm::length_t L, typename T, GLenum GLType, glm::qualifier Q = glm::packed_highp, bool Norm = false>
// struct VertexPosNormColor
//{
//	glm::vec<L, T, Q> Pos;
//	glm::vec<L, T, Q> Normal;
//	glm::vec<4, T, Q> Color;
//
//	static constexpr auto Layout()
//	{
//		using Self = VertexPosNormColor<L, T, GLType, Q, Norm>;
//		/// index, count,     GLenum,    normalized,      offset
//		return std::array<BufferElement, 3>{
//			{{0u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Pos)},
//			 {1u, (GLuint)L, GLType, GLboolean(Norm), offsetof(Self, Normal)},
//			 {2u, 4u, GLType, GLboolean(Norm), offsetof(Self, Color)}}};
//	}
// };
//
///// 3 COMPONENT BUFFER
//
///// INT
///// 2 COMPONENT VEC
// using C3_BufferVertex2i_Uv = VertexPosNormUv<2, int, GL_INT>;
// using C3_BufferVertex2i_Color = VertexPosNormColor<2, int, GL_INT>;
///// 3 COMPONENT VEC
// using C3_BufferVertex3i_Uv = VertexPosNormUv<3, int, GL_INT>;
// using C3_BufferVertex3i_Color = VertexPosNormColor<3, int, GL_INT>;
//
///// FLOAT
///// 2 COMPONENT VEC
// using C3_BufferVertex2f_Uv = VertexPosNormUv<2, float, GL_FLOAT>;
// using C3_BufferVertex2f_Color = VertexPosNormColor<2, float, GL_FLOAT>;
///// 3 COMPONENT VEC
// using C3_BufferVertex3f_Uv = VertexPosNormUv<3, float, GL_FLOAT>;
// using C3_BufferVertex3f_Color = VertexPosNormColor<3, float, GL_FLOAT>;
//
///// NORMALIZED
//
///// 2 COMPONENT BUFFER
//
///// INT
///// 2 COMPONENT VEC
// using C2_NormalizedBufferVertex2i_Uv = VertexPosUv<2, int, GL_INT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex2i_Norm = VertexPosNormal<2, int, GL_INT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex2i_Color = VertexPosColor<2, int, GL_INT, glm::packed_highp, true>;
//
///// 3 COMPONENT VEC
// using C2_NormalizedBufferVertex3i_Uv = VertexPosUv<3, int, GL_INT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex3i_Norm = VertexPosNormal<3, int, GL_INT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex3i_Color = VertexPosColor<3, int, GL_INT, glm::packed_highp, true>;
//
///// FLOAT
///// 2 COMPONENT VEC
// using C2_NormalizedBufferVertex2f_Uv = VertexPosUv<2, float, GL_FLOAT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex2f_Norm = VertexPosNormal<2, float, GL_FLOAT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex2f_Color = VertexPosColor<2, float, GL_FLOAT, glm::packed_highp, true>;
//
///// 3 COMPONENT VEC
// using C2_NormalizedBufferVertex3f_Uv = VertexPosUv<3, float, GL_FLOAT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex3f_Norm = VertexPosNormal<3, float, GL_FLOAT, glm::packed_highp, true>;
// using C2_NormalizedBufferVertex3f_Color = VertexPosColor<3, float, GL_FLOAT, glm::packed_highp, true>;
//
///// 3 COMPONENT BUFFER
//
///// INT
///// 2 COMPONENT VEC
// using C3_NormalizedBufferVertex2i_Uv = VertexPosNormUv<2, int, GL_INT, glm::packed_highp, true>;
// using C3_NormalizedBufferVertex2i_Color = VertexPosNormColor<2, int, GL_INT, glm::packed_highp, true>;
///// 3 COMPONENT VEC
// using C3_NormalizedBufferVertex3i_Uv = VertexPosNormUv<3, int, GL_INT, glm::packed_highp, true>;
// using C3_NormalizedBufferVertex3i_Color = VertexPosNormColor<3, int, GL_INT, glm::packed_highp, true>;
//
///// FLOAT
///// 2 COMPONENT VEC
// using C3_NormalizedBufferVertex2f_Uv = VertexPosNormUv<2, float, GL_FLOAT, glm::packed_highp, true>;
// using C3_NormalizedBufferVertex2f_Color = VertexPosNormColor<2, float, GL_FLOAT, glm::packed_highp, true>;
///// 3 COMPONENT VEC
// using C3_NormalizedBufferVertex3f_Uv = VertexPosNormUv<3, float, GL_FLOAT>;
// using C3_NormalizedBufferVertex3f_Color = VertexPosNormColor<3, float, GL_FLOAT, glm::packed_highp, true>;
//