#ifndef MYVIDEO_H
#define MYVIDEO_H

#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include <string.h>
#include <errno.h>

#include "linux/kernel.h"
#include "linux/videodev.h"
extern "C"
{
#include "jpeglib.h"
}

#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <asm/types.h>
#include <sys/ioctl.h>

#include <QString>
//#include <QObject>

class videodevice
{
public:
    videodevice();

    void v4l2_save_rgb16_to_jpg(int cam_fp, int width, int height, char * filepath);
    int open_device(char *dev_path);
    void close_device(int fd);
private:
    typedef struct v4l2_format   V_FORMAT;
    struct jpeg_compress_struct cinfo;
    int quality;
    struct jpeg_error_mgr jerr;

};

#endif // MYVIDEO_H
