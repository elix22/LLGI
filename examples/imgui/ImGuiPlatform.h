#pragma once

#include <LLGI.CommandList.h>
#include <LLGI.Graphics.h>
#include <LLGI.Platform.h>

#include "../thirdparty/imgui/imgui.h"

class ImguiPlatform
{
public:
	ImguiPlatform() = default;
	virtual ~ImguiPlatform() = default;

	virtual void NewFrame(LLGI::RenderPass* renderPass) = 0;

	virtual void RenderDrawData(ImDrawData* draw_data, LLGI::CommandList* commandList) = 0;

	virtual ImTextureID GetTextureIDToRender(LLGI::Texture* texture, LLGI::CommandList* commandList) { return nullptr; }
};
