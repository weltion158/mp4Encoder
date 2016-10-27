#ifndef CMP4ENCODE_H
#define CMP4ENCODE_H

#include "./inc/mp4v2/mp4v2.h"

// NALUµ¥Ôª
typedef struct _MP4ENC_NaluUnit
{
    int frameType;
    int frameLen;
    unsigned char *pframeBuf;
}MP4ENC_NaluUnit;

class CMp4Encode
{
public:
    CMp4Encode(void);
    ~CMp4Encode(void);

    // open or creat a mp4 file.
    int FileCreate(const char *pFileName,int width,int height,int frameRate);
    // wirte 264 data, data can contain  multiple frame.
    int FileWrite(int frameType, unsigned char *pframeBuf,int frameLen);
    // close mp4 file.
    int FileClose();

private:
    int WriteAudioTrack(unsigned char *pframeBuf,int frameLen);
    int WriteVideoTrack(unsigned char *pframeBuf,int frameLen);
    // read one nalu from H264 data buffer
    static int ReadOneNaluFromBuf(const unsigned char *buffer,unsigned int nBufferSize,unsigned int offSet,MP4ENC_NaluUnit &nalu);

private:
    bool m_bfindSps;
    bool m_bfindPps;
    int m_nWidth;
    int m_nHeight;
    int m_nFrameRate;
    int m_nTimeScale;
    MP4TrackId m_videoId;
    MP4FileHandle hMp4File;
};

#endif // CMP4ENCODE_H
