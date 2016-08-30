#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace EmoteEngineNet
{
		[UnmanagedFunctionPointer(CallingConvention::Cdecl)]
		public delegate void TextureFilterFunction(Byte[], unsigned long);
}
