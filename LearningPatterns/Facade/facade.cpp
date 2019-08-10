#include "facade.h"

namespace Facade {
File::File() : m_buffer(nullptr) {}
File::~File() {
	if (m_buffer != nullptr) {
		delete m_buffer;
	}
}
File::File(BitrateReader* const buffer) : m_buffer(buffer) {}

void File::Save() {}

VideoFile::VideoFile(const VideoFileName& name) : m_name(name) {}

Codec* CodecFactory::Extract(const File* const filename) {
	return new MPEG4CompressionCodec {};
}

BitrateReader* BitrateReader::
Read(const VideoFileName& filename, Codec* const sourceCodec) {
	return new BitrateReader();
}

BitrateReader* BitrateReader::
Convert(BitrateReader* const buffer, Codec* const codec) {
	return new BitrateReader();
}

BitrateReader* AudioMixer::Fix(BitrateReader* const buffer) {
	return buffer;
}


File* VideoConverter::
Convert(const VideoFileName& filename, const VideoFormat& destinationFormat) const {
	File* file = new VideoFile { filename };
	Codec* sourceCodec = CodecFactory::Extract(file);

	Codec* destinationCodec = nullptr;
	switch (filename.format) {
		case Facade::VideoFormat::MP4:
			destinationCodec = new MPEG4CompressionCodec {};
			break;
		default:
			destinationCodec = new OggCompressionCodec {};
			break;
	}

	BitrateReader* buffer = BitrateReader::Read(filename, sourceCodec);
	BitrateReader* result = BitrateReader::Convert(buffer, destinationCodec);

	delete buffer;
	delete destinationCodec;
	delete sourceCodec;
	delete file;

	result = (AudioMixer()).Fix(result);

	return new File { result };
}

VideoEditorApplication::~VideoEditorApplication() {
	if (m_videoConverter != nullptr) {
		delete m_videoConverter;
	}
}

void VideoEditorApplication::Run() {
	VideoFileName vfn { "video", VideoFormat::FLV };
	File* file = m_videoConverter->Convert(vfn, VideoFormat::MP4);
	file->Save();
}

} // namespace Facade
