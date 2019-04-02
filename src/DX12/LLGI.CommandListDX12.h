
#pragma once

#include "../LLGI.CommandList.h"
#include "LLGI.BaseDX12.h"
#include "LLGI.GraphicsDX12.h"

namespace LLGI
{

class CommandListDX12 : public CommandList
{
private:
	std::shared_ptr<GraphicsDX12> graphics_;
	std::shared_ptr<RenderPassDX12> renderPass_;
	std::shared_ptr<ID3D12CommandAllocator> commandAllocator_ = nullptr;

	ID3D12GraphicsCommandList* commandList_ = nullptr;

public:
	CommandListDX12();
	virtual ~CommandListDX12();
	bool Initialize(GraphicsDX12* graphics, ID3D12CommandAllocator* commandAllocator);

	void Begin() override;
	void End() override;
	void Clear(const Color8& color);
	void BeginRenderPass(RenderPass* renderPass) override;
	void EndRenderPass() override;
	void SetVertexBuffer(VertexBuffer* vertexBuffer, int32_t stride, int32_t offset);
	void SetIndexBuffer(IndexBuffer* indexBuffer);
	void SetPipelineState(PipelineState* pipelineState);
	void SetConstantBuffer(ConstantBuffer* constantBuffer, ShaderStageType shaderStage);

	ID3D12GraphicsCommandList* GetCommandList() { return commandList_; }
};

} // namespace LLGI
