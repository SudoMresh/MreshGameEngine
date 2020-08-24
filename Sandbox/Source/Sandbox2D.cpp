#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	ME_PROFILE_FUNCTION();

	m_CheckerboardTexture = MreshEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	ME_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(MreshEngine::Timestep ts)
{
	ME_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		ME_PROFILE_SCOPE("Renderer Prep");
		MreshEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		MreshEngine::RenderCommand::Clear();
	}

	{
		ME_PROFILE_SCOPE("Renderer Draw");
		MreshEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		MreshEngine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		MreshEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		MreshEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		MreshEngine::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	ME_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(MreshEngine::Event& e)
{
	m_CameraController.OnEvent(e);
}