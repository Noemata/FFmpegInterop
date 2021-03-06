//*****************************************************************************
//
//	Copyright 2015 Microsoft Corporation
//
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
//
//	http ://www.apache.org/licenses/LICENSE-2.0
//
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.
//
//*****************************************************************************

#pragma once
#include "UncompressedSampleProvider.h"

namespace winrt::FFmpegInterop::implementation
{
	class UncompressedAudioSampleProvider :
		public UncompressedSampleProvider
	{
	public:
		UncompressedAudioSampleProvider(_In_ const AVStream* stream, _In_ Reader& reader);

		void SetEncodingProperties(_Inout_ const Windows::Media::MediaProperties::IMediaEncodingProperties& encProp, _In_ bool setFormatUserData) override;

	protected:
		std::tuple<Windows::Storage::Streams::IBuffer, int64_t, int64_t, std::map<GUID, Windows::Foundation::IInspectable>> GetSampleData() override;

	private:
		// Minimum duration (in ms) for uncompressed audio samples. 
		// We'll compact shorter decoded audio samples until this threshold is reached.
		static constexpr int64_t MIN_AUDIO_SAMPLE_DUR_MS{ 200 };

		int64_t m_minAudioSampleDur{ 0 };
		SwrContext_ptr m_swrContext;
	};
}
