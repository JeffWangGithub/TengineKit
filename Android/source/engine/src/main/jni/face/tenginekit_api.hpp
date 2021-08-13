
#ifndef TENGINEKIT_API_HPP
#define TENGINEKIT_API_HPP

#include <vector>
#include <string>
#include "tenginekit_struct.hpp"


enum ImageFormat {
    RGBA = 0,
    RGB,
    BGR,
    GRAY,
    BGRA,
    YUV_NV21 = 11,
    YUV_NV12 = 12,
};

//enum ModelType{
//    Detect,
//    Landmark,
//    Recognize,
//    Attribution,
//    Landmark3d,
//    GoDetect,
//    Iris,
//    BodyDetect,
//    BlazePoseDetect,
//    BlazePoseLandmark,
//    HandDetect,
//    HandLandmark3d,
//    Yolov5
//};

enum FaceSDKMode{
    Normal,
    Android_Front_Camera,
    Android_Back_Camera,
};

typedef struct FaceSDKConfig
{
    int img_w;
    int img_h;
    int screen_w;
    int screen_h;

    ImageFormat input_format;
    FaceSDKMode mode;
    int thread_num;

    char* packageName;
    char* uuid;
} FaceSDKConfig;




void facesdk_init(FaceSDKConfig config);
void facesdk_readModelFromFile(ModelType type, const char* model_path, ImageFormat modelInputFormat);
void facesdk_readModelFromFile(ModelType type, const char* model_path, ImageFormat modelInputFormat, bool is_encrypted);
void facesdk_readModelFromBuffer(ModelType type, char* buffer,int buffer_size, ImageFormat modelInputFormat, bool is_encrypted);
void facesdk_release();

sdkFaces facesdk_detect(char *imgData);
sdkFaces facesdk_landmark();
sdkFaces3d facesdk_landmark3d();
sdkFaces facesdk_attribute();
sdkFaces3d facesdk_eyelandmark3d();

sdkBody facesdk_bodydetect(char *imageData);
sdkBody facesdk_bodylandmark();

sdkHand3d facesdk_handdetect(char *imageData);
sdkHand3d facesdk_handlandmark3d();

sdkYolov5 facesdk_yolov5(char *imageData);

void facesdk_set_mode(FaceSDKMode mode);
void facesdk_set_orientation(int degree, bool screen_rotation, int screen_w, int screen_h);

void facesdk_create_handler(ImageFormat image_input_format, ImageFormat image_output_format);
char* facesdk_handle_image(char* imageData, int image_w, int image_h, int input_x1, int input_y1, int input_x2, int input_y2, int output_w, int output_h, int rotation, bool mirror);

#endif
