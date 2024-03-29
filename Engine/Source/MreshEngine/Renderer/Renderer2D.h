#pragma once

#include "MreshEngine/Renderer/OrthographicCamera.h"

#include "MreshEngine/Renderer/Texture.h"
#include "MreshEngine/Renderer/SubTexture2D.h"

#include "MreshEngine/Renderer/Camera.h"
#include "MreshEngine/Renderer/EditorCamera.h"

#include "MreshEngine/Scene/Components.h"

namespace MreshEngine
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void BeginScene(const EditorCamera& camera);
		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void EndScene();

		static void Flush();

		// Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
	
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f,
			const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f,
			const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f,
			const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f,
			const glm::vec4& tintColor = glm::vec4(1.f));

		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color, int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const glm::vec2* textureCoords, const Ref<Texture2D>& texture, float tilingFactor = 1.0f,
			const glm::vec4& tintColor = glm::vec4(1.f), int entityID = -1);

		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation,
			const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation,
			const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation,
			const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation,
			const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.f));

		static void DrawSprite(const glm::mat4& transform, SpriteRendererComponent& sprite, int entityID);

		// Statistics
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }
		};

		static Statistics GetStatistics();
		static void ResetStatistics();

	private:
		static void FlushAndReset();
		static void StartBatch();
	};

}