#pragma once

#include "MreshEngine.h"

class Sandbox2D : public MreshEngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MreshEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MreshEngine::Event& e) override;

private:
	MreshEngine::OrthographicCameraController m_CameraController;
	
	// Temp
	MreshEngine::Ref<MreshEngine::VertexArray> m_SquareVA;
	MreshEngine::Ref<MreshEngine::Shader> m_FlatColorShader;

	MreshEngine::Ref<MreshEngine::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};