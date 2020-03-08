#pragma once

#include "MreshEngine.h"

class ExampleLayer : public MreshEngine::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MreshEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MreshEngine::Event& e) override;
private:
	MreshEngine::ShaderLibrary m_ShaderLibrary;
	MreshEngine::Ref<MreshEngine::Shader> m_Shader;
	MreshEngine::Ref<MreshEngine::VertexArray> m_VertexArray;

	MreshEngine::Ref<MreshEngine::Shader> m_FlatColorShader;
	MreshEngine::Ref<MreshEngine::VertexArray> m_SquareVA;

	MreshEngine::Ref<MreshEngine::Texture2D> m_Texture;

	MreshEngine::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

