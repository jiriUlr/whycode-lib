#ifndef WHYCODE__CRAWIMAGE_H
#define WHYCODE__CRAWIMAGE_H

#include "whycode/types.h"

namespace whycode {

class CRawImage {
public:
  CRawImage() = default;

  CRawImage(int height, int width, int bpp);

  CRawImage(const unsigned char* new_data, int height, int width, int bpp);

  void updateImage(const unsigned char* new_data, int height, int width, int bpp);

  void drawTimeStats(int eval_time, int num_markers);

  void drawStats(SMarker &marker, bool trans_2D);

  void drawGuideCalibration(int calib_num, float dim_x, float dim_y);
  
  int width_ = 0;
  int height_ = 0;
  int bpp_ = 0;
  int size_ = 0;  // width * height * bpp

  unsigned char * data_ = nullptr;
};

}  // namespace whycode

#endif  // WHYCODE__CRAWIMAGE_H
