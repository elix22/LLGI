
#pragma once

#include "../LLGI.Texture.h"
#include "LLGI.BaseVulkan.h"
#include "LLGI.GraphicsVulkan.h"

namespace LLGI
{

// for Texture2D, RenderTarget, DepthBuffer
class TextureVulkan : public Texture
{
private:
	GraphicsVulkan* graphics_ = nullptr;
	bool isStrongRef_ = false;
	vk::Image image_ = nullptr;
	vk::ImageView view = nullptr;
	vk::DeviceMemory devMem = nullptr;
	vk::Format vkTextureFormat;

	Vec2I textureSize;

	int32_t memorySize = 0;
	std::unique_ptr<Buffer> cpuBuf;
	void* data = nullptr;

	bool isRenderPass_ = false;
	bool isDepthBuffer_ = false;
	bool isExternalResource_ = false;

public:
	TextureVulkan(GraphicsVulkan* graphics, bool isStrongRef);
	virtual ~TextureVulkan();

	bool Initialize(const Vec2I& size, bool isRenderPass, bool isDepthBuffer);
	bool Initialize(const vk::Image& image, const vk::ImageView& imageVew, vk::Format format, const Vec2I& size);

	void* Lock() override;
	void Unlock() override;
	Vec2I GetSizeAs2D() override;
	bool IsRenderTexture() const override;
	bool IsDepthTexture() const override;

	const vk::Image& GetImage() const { return image_; }
	const vk::ImageView& GetView() const { return view; }

	vk::Format GetVulkanFormat() const { return vkTextureFormat; }
	int32_t GetMemorySize() const { return memorySize; }
};

} // namespace LLGI
