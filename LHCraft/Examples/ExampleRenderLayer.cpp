#include "ExampleRenderLayer.h"
#include "Core/Debug/Instrumentor.h"

TestLayer::TestLayer() {
  CORE_PROFILE_FUNCTION();
  m_VertexArray = Core::VertexArray::Create();

  float vertices[] = {
      // front
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f, -0.5f, -0.5f, 0.1f, 0.0f, 0.5f,
      0.5f, -0.5f, 1.0f, 1.0f, -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,

      // top
      -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.5f, -0.5f, 0.1f, 0.0f, 0.5f, 0.5f,
      0.5f, 1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,

      // left
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -0.5f, 0.5f, -0.5f, 0.1f, 0.0f, -0.5f,
      0.5f, 0.5f, 1.0f, 1.0f, -0.5f, -0.5f, 0.5f, 0.0f, 1.0f,

      // right
      0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.5f, -0.5f, 0.1f, 0.0f, 0.5f, 0.5f,
      0.5f, 1.0f, 1.0f, 0.5f, -0.5f, 0.5f, 0.0f, 1.0f,

      // back
      -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, -0.5f, 0.5f, 0.1f, 0.0f, 0.5f, 0.5f,
      0.5f, 1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,

      // bottom
      -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, -0.5f, 0.5f, 0.1f, 0.0f, 0.5f,
      -0.5f, -0.5f, 1.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f};

  uint32_t indices[] = {
      // front
      0, 1, 2, // first triangle
      2, 3, 0, // second triangle

      // top
      4, 5, 6, // first triangle
      6, 7, 4, // second triangle

      // left
      8, 9, 10,  // first triangle
      10, 11, 8, // second triangle

      // right
      12, 13, 14, // first triangle
      14, 15, 12, // second triangle

      // back
      16, 17, 18, // first triangle
      18, 19, 16, // second triangle

      // bottom
      20, 21, 22, // first triangle
      22, 23, 20  // second triangle
  };
  std::shared_ptr<Core::VertexBuffer> vertexBuffer =
      Core::VertexBuffer::Create(vertices, sizeof(vertices));
  Core::BufferLayout layout = {{Core::ShaderDataType::Float3, "a_Position"},
                               {Core::ShaderDataType::Float2, "a_Color"}};

  vertexBuffer->SetLayout(layout);
  m_VertexArray->AddVertexBuffer(vertexBuffer);

  std::shared_ptr<Core::IndexBuffer> indexBuffer = Core::IndexBuffer::Create(
      indices,
      sizeof(indices) /
          sizeof(uint32_t)); // calculates the number of elements in the array,
                             // if using std::array could just be array.size()
  m_VertexArray->SetIndexBuffer(indexBuffer);

  m_Camera = std::make_unique<Core::ProjectionCamera>(45.0f, 1200.0f / 720.0f,
                                                      0.1f, 1000.0f);

  m_Texture =
      Core::Texture2D::Create("/Users/amyalex/Documents/Production_Projects/"
                              "LHVoxelEngineV2/LHCraft/assets/container.jpg");

  m_Shader = Core::Shader::Create("Core/Shaders/vertex.vs",
                                  "Core/Shaders/fragment.fs");

  m_Shader->SetInt("u_Texture", 0);
}

void TestLayer::OnUpdate(Core::TimeStep ts) {
  CORE_PROFILE_FUNCTION();

  m_Camera->OnUpdate(ts);

  Core::RenderCommands::SetClearColor({0.1, 0.3, 0.9, 1.0});
  Core::RenderCommands::Clear();

  Core::Renderer::BeginScene(*m_Camera);

  m_Texture->Bind();
  Core::Renderer::Submit(m_Shader, m_VertexArray,
                         glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(),
                                     glm::vec3(0.0f, 0.0f, -1.0f)));
  // CORE_LOG_TRACE("Submitting Vertex for render");
}

void TestLayer::OnEvent(Core::Event &event) { m_Camera->OnEvent(event); }
