#pragma once

#ifndef FACADE_FACADE_H
#define FACADE_FACADE_H

namespace Facade {

enum class VideoFormat {
	UNKNOWN,
	MP4, AVI, MKV,
	MOV, FLV, ASF
};

struct VideoFileName {
	const char* const name;
	VideoFormat format;
};


class BitrateReader;

class File {
private:
	BitrateReader* const m_buffer;

public:
	File();
	virtual ~File();
	explicit File(BitrateReader* const buffer);

	void Save();
};

class VideoFile : public File {
private:
	VideoFileName m_name;

public:
	explicit VideoFile(const VideoFileName& name);
};

class Codec {};
class OggCompressionCodec : public Codec {};
class MPEG4CompressionCodec : public Codec {};

class CodecFactory { // here must been Abstaract Factory
public:
	static Codec* Extract(const File* const filename);
};

class BitrateReader {
public:
	static BitrateReader* Read(const VideoFileName& filename, Codec* const sourceCodec);
	static BitrateReader* Convert(BitrateReader* const buffer, Codec* const codec);
};
class AudioMixer {
public:
	BitrateReader* Fix(BitrateReader* const buffer);
};


class VideoConverter {
public:
	File* Convert(
		const VideoFileName& filename,
		const VideoFormat& destinationFormat) const;
};


class VideoEditorApplication final {
private:
	VideoConverter* m_videoConverter = new VideoConverter {};

public:
	~VideoEditorApplication();

	void Run();
};

} // namespace Facade

#endif // !FACADE_FACADE_H
