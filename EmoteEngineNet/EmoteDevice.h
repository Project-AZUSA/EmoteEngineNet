#pragma once

#include "iemote.h"
#include "EmoteDriverAdapter.h"
#include "Emote.h"
#include "EmotePlayer.h"
#include "Enums.h"
#include "TextureFilterFunction.h"
#include <vcclr.h>

using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace EmoteEngineNet {
	ref class EmotePlayer;
	ref class Emote;

	public ref class EmoteDevice : IDisposable
	{

	public:
		~EmoteDevice();
		uint32_t AddRef();

		AlphaOp GetAlphaOp();
		MaskMode GetMaskMode();
		bool GetMaskRegionClipping();
		bool GetMipMapEnabled();
		int GetPixelateDivision();
		bool GetProtectTranslucentTextureColor();
		ShaderModel GetShaderModel();

		void OnDeviceLost();

		void OnRenderTarget(IntPtr renderTargetTexture);

		void Release();

		void SetAlphaOp(AlphaOp op);
		void SetMaskMode(MaskMode mask);
		void SetMaskRegionClipping(bool state);
		void SetMaxTextureSize(uint32_t width, uint32_t height);
		void SetMipMapEnabled(bool state);
		void SetPixelateDivision(int division);
		void SetProtectTranslucentTextureColor(bool state);
		void SetShaderModel(ShaderModel shaderModel);

	internal:
		//EmoteDevice(::IEmoteDevice__TYPE* sDevice, Emote^ _emote);
		EmoteDevice(Adapter::EmoteDeviceBase^ sDevice, Emote^ _emote);
		void OnRenderTarget(IDirect3DTexture9* renderTargetTexture);
		EmotePlayer ^CreatePlayer(String^ path);
		EmotePlayer ^CreatePlayer(Stream^ stream);

	private:
		void EmoteDevice::CopyStreamToNativePtr(Stream^ src, unsigned char* dst);

	internal:
		//property ::IEmoteDevice__TYPE* NativeDevice {
		//	::IEmoteDevice__TYPE* get();
		//}

	public:
		property TextureFilterFunction^ EmoteDevice::TextureFilter;


		property bool UseTextureFilter;

	private:
		//IEmoteDevice__TYPE* device = NULL;
		Adapter::EmoteDeviceBase^ device = nullptr;

		Emote^ emote;
	};
}