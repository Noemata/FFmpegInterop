# FFmpegInterop library for Windows

#### This project is licensed from Microsoft under the [Apache 2.0 License](http://www.apache.org/licenses/LICENSE-2.0)

## Welcome to FFmpegInterop library for Windows.

FFmpegInterop is an open-source project that aims to provide an easy way to use FFmpeg in Windows 10, Windows 8.1, and Windows Phone 8.1 applications for playback of a variety of media contents. FFmpegInterop implements a [MediaStreamSource](https://msdn.microsoft.com/en-us/library/windows/apps/windows.media.core.mediastreamsource.aspx) which leverages FFmpeg to process media and uses the Windows media pipeline for playback.

One of the advantages of this approach is that audio and video synchronization is handled by the Windows media pipeline. You can also use the Windows built-in audio and video decoders which allows for better power consumption mobile devices.

## Prerequisites
Getting a compatible build of FFmpeg is required for this to work.

Use git to clone this repository.

	git clone --recursive git://github.com/microsoft/FFmpegInterop.git

Your `FFmpegInterop` folder should look as follows

	FFmpegInterop\
	    FFmpegInterop\       - FFmpegInterop WinRT component
	    Samples\             - Sample Media Player applications in C++ and C#
	    Tests\               - Unit tests for FFmpegInterop
	    FFmpegInterop.sln    - Microsoft Visual Studio 2019 solution file for Windows 10 apps development
	    LICENSE
	    README.md

To build FFmpeg support libs install vcpkg and do as follows

	.\vcpkg install ffmpeg[gpl]:x64-uwp --recurse	- Build x64 only
	.\vcpkg install ffmpeg[gpl]:x86-uwp --recurse   - Build x86 only

Simply open FFmpegInterop.sln, set one of the MediaPlayer as StartUp project, and run. FFmpegInterop should build cleanly giving you the interop object as well as the selected sample MediaPlayer (C++ or C#) that show how to connect the MediaStreamSource to a MediaElement or Video tag for playback.

### Using the FFmpegInterop object

Using the **FFmpegInterop** object is fairly straightforward and can be observed from the sample applications provided.

1. Get a stream for the media you want to playback.
2. Create a new FFmpegInteropObject using FFmpegInteropMSS.CreateFFmpegInteropMSSFromStream() passing it the stream and whether you want to force the decoding of the media (if you don't force decoding of the media, the MediaStreamSource will try to pass the compressed data for playback, this is currently enabled for mp3, aac and h.264 media).
3. Get the MediaStreamSource from the Interop object by invoking GetMediaStreamSource()
4. Assign the MediaStreamSource to your MediaElement or VideoTag for playback.

	##### You can try to use the method FFmepgInteropMSS.CreateFFmpegInteropMSSFromUri to create a MediaStreamSource on a streaming source (shoutcast for example).

This project is in an early stage and we look forward to engaging with the community and hearing your feedback to figure out where we can take this project.

### The Windows OSS Team.

### Notes:

This build is pulled from here and represents the most current sources as of February 2020:

https://github.com/microsoft/FFmpegInterop/tree/brbeec/cppwinrt

This is not a fork because vcpkg is used to build the FFmpeg libs.  Hopefully vcpkg will catch on, it makes life much easier.
