#include "videodevice.h"

videodevice::videodevice()
{
    quality=100;
}

int videodevice::open_device(char *dev_name)
{
    int v4l2_fd = -1;
    V_FORMAT fmt;
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    printf("Start Main \n");
    printf("Before openning video \n");
    v4l2_fd = open(dev_name, O_RDWR);
    if (v4l2_fd < 0) {
        printf(" open video ERR\n");
        return 0;
    }
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 320;
    fmt.fmt.pix.height = 240;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_RGB565;
    printf("VIDIOC_S_FMT is %x\n",VIDIOC_S_FMT);
    if((ioctl(v4l2_fd, VIDIOC_S_FMT, &fmt))<0)
    {
        printf("Error: failed to set video format.\n");
        return 0;
    }
    printf("VIDIOC_STREAMON is %x\n",VIDIOC_STREAMON);
    if((ioctl(v4l2_fd, VIDIOC_STREAMON, &type))<0){
        printf("error ioctl streamon\n");
        return 0;
    }
    printf("start to get pic %d\n",(int)fmt.fmt.pix.sizeimage);
    return v4l2_fd;
}

void videodevice::close_device(int fd)
{
    close(fd);
}

void videodevice::v4l2_save_rgb16_to_jpg(int cam_fp, int width, int height, char * filepath)
{
    quality=100;

    int x, y;
    FILE *jpg_fp = NULL;
    char file_name[100];
    unsigned char *rgb24 = NULL;
    unsigned short *rgb16 = NULL;
    JSAMPROW row_pointer[1];

    rgb24 = (unsigned char*)malloc(width*height*3);
    rgb16 = (unsigned short*)malloc(width*height*2);
    row_pointer[0] = (JSAMPROW)rgb24;

    /* read from device */
    if (read(cam_fp, (char*)rgb16, width*height*2) < 0) {
        perror("read()");
        goto err;
    }

    sprintf(&file_name[0], filepath);
    /* file create/open, note to "wb" */
    jpg_fp = fopen(&file_name[0], "wb");
    if (!jpg_fp) {
        perror(&file_name[0]);
        goto err;
    }

    printf("save to \"%s\"\n", file_name);

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    jpeg_stdio_dest(&cinfo, jpg_fp);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);

    jpeg_set_quality(&cinfo, quality, TRUE);

    jpeg_start_compress(&cinfo, TRUE);

    /* RGB565 -> RGB888, compress */
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            *(rgb24 + x*3+0) = ((*(rgb16 + y*width + x) & 0xf800) >> 8) & 0xff;
            *(rgb24 + x*3+1) = ((*(rgb16 + y*width + x) & 0x07e0) >> 3) & 0xff;
            *(rgb24 + x*3+2) = ((*(rgb16 + y*width + x) & 0x001f) << 3) & 0xff;
        }
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);

    fclose(jpg_fp);

err:
    if (rgb24)
        free(rgb24);
    if (rgb16)
        free(rgb16);
}
