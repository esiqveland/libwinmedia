#include <map>
#include <string>

#include "Internal.hpp"

#ifndef TAGS_HEADER
#define TAGS_HEADER
#ifdef __cplusplus
extern "C" {
#endif


namespace wm {


class Tags;

/// Metadata tags of a music media.
class MusicTags {
public:
    std::wstring album;
    std::wstring albumArtist;
    std::wstring bitrate;
    std::wstring composers;
    std::wstring conductors;
    std::wstring duration;
    std::wstring genre;
    std::wstring producers;
    std::wstring publisher;
    std::wstring rating;
    std::wstring subtitle;
    std::wstring title;
    std::wstring trackNumber;
    std::wstring writers;
    std::wstring year;

private:
    static MusicTags* get(wchar_t** tags) {
        MusicTags* musicTags = new MusicTags();
        musicTags->album = tags[0];
        musicTags->albumArtist = tags[1];
        musicTags->bitrate = tags[2];
        musicTags->composers = tags[3];
        musicTags->conductors = tags[4];
        musicTags->duration = tags[5];
        musicTags->genre = tags[6];
        musicTags->producers = tags[7];
        musicTags->publisher = tags[8];
        musicTags->rating = tags[9];
        musicTags->subtitle = tags[10];
        musicTags->title = tags[11];
        musicTags->trackNumber = tags[12];
        musicTags->writers = tags[13];
        musicTags->year = tags[14];
        for (int index = 0; index < 15; index++) delete tags[index];
        delete[] tags;
        return musicTags;
    }

    friend class Tags;
};


/// Metadata tags of a video media.
class VideoTags {
public:
    std::wstring bitrate;
    std::wstring directors;
    std::wstring duration;
    std::wstring height;
    std::wstring keywords;
    std::wstring longitude;
    std::wstring latitude;
    std::wstring oridentation;
    std::wstring producers;
    std::wstring publisher;
    std::wstring rating;
    std::wstring subtitle;
    std::wstring title;
    std::wstring width;
    std::wstring writers;
    std::wstring year;

private:
    static VideoTags* get(wchar_t** tags) {
        VideoTags* videoTags = new VideoTags();
        videoTags->bitrate = tags[0];
        videoTags->directors = tags[1];
        videoTags->duration = tags[2];
        videoTags->height = tags[3];
        videoTags->keywords = tags[4];
        videoTags->longitude = tags[5];
        videoTags->latitude = tags[6];
        videoTags->oridentation = tags[7];
        videoTags->producers = tags[8];
        videoTags->rating = tags[9];
        videoTags->subtitle = tags[10];
        videoTags->title = tags[11];
        videoTags->width = tags[12];
        videoTags->writers = tags[13];
        videoTags->year = tags[14];
        videoTags->bitrate = tags[15];
        for (int index = 0; index < 16; index++) delete tags[index];
        delete[] tags;
        return videoTags;
    }

    friend class Tags;
};


/// Retrieves metadata tags and thumbnail of a music or video media.
///
/// Use `Tags::fromMusic` to get `MusicTags*` of a music file by passing uri.
/// Use `Tags::fromVideo` to get `VideoTags*` of a video file by passing uri.
/// Use `Tags::extractThumbnail` to extract thumbnail of a media file to a particular folder with a particular name.
class Tags {
public:

    static MusicTags* fromMusic(std::wstring uri) {
        return MusicTags::get(
            Internal::Tags_fromMusic(uri.data())
        );
    }

    static VideoTags* fromVideo(std::wstring uri) {
        return VideoTags::get(
            Internal::Tags_fromVideo(uri.data())
        );
    }

    static void extractThumbnail(std::wstring source, std::wstring save, std::wstring fileName, int32_t mode, int32_t size) {
        Internal::Tags_extractThumbnail(
            source.data(),
            save.data(),
            fileName.data(),
            mode,
            size
        );
    }
};


}


#ifdef __cplusplus
}
#endif
#endif
