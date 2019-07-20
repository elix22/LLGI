
#include "TestHelper.h"
#include "test.h"

#ifdef _WIN32
#pragma comment(lib, "d3dcompiler.lib")

#ifdef ENABLE_VULKAN
#pragma comment(lib, "vulkan-1.lib")
#endif

#endif

// Empty
void test_empty(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

// About clear
void test_clear(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);
void test_clear_update(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

// Render
void test_simple_rectangle(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

void test_simple_constant_rectangle(LLGI::ConstantBufferType type, LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

void test_simple_texture_rectangle(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

// Compile
void test_compile(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

// About renderPass
void test_renderPass(LLGI::DeviceType deviceType = LLGI::DeviceType::Default);

void call_test(LLGI::DeviceType device)
{
	// Empty
	// test_empty(device);

	// About clear
	// test_clear(device);
	// test_clear_update(device);

	// About compile
	// test_compile(device);

	// Render
	// test_simple_rectangle(device);
	// test_simple_constant_rectangle(LLGI::ConstantBufferType::LongTime, device);
	// test_simple_texture_rectangle(device);

	// About renderPass
	test_renderPass(device);
}

#if defined(__linux__) || defined(__APPLE__) || defined(WIN32)
int main(int argc, char* argv[])
{
	auto device = LLGI::DeviceType::Default;

#if defined(__APPLE__)
	TestHelper::SetRoot("Shaders/Metal/");
#endif

	if (device == LLGI::DeviceType::Vulkan)
	{
		TestHelper::SetRoot("Shaders/SPIRV/");
	}

	call_test(LLGI::DeviceType::Default);
}
#endif
