#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "whycode/CRawImage.h"

namespace py = pybind11;

namespace whycode {

using ImageArray = py::array_t<unsigned char, py::array::forcecast | py::array::c_style>;

void apply_numpy_image(CRawImage& img, ImageArray& array) {
  if (array.ndim() == 3) {
    img.updateImage(array.data(), array.shape(0), array.shape(1), array.shape(2));
  } else if (array.ndim() == 2) {
    img.updateImage(array.data(), array.shape(0), array.shape(1), 1);
  } else {
    throw std::runtime_error("Expected NumPy array with shape (H, W) or (H, W, C), dtype=uint8");
  }
}

void bind_CRawImage(py::module_ &m) {
  py::class_<CRawImage>(m, "CRawImage")
    .def(py::init<>())
    .def(py::init<int, int, int>())

    .def(py::init([](ImageArray array) {
      CRawImage img;
      apply_numpy_image(img, array);
      return img;
    }))

    .def("updateImage", [](CRawImage &self, ImageArray array) {
      apply_numpy_image(self, array);
    })

    .def("drawTimeStats", &CRawImage::drawTimeStats)
    .def("drawStats", &CRawImage::drawStats)
    .def("drawGuideCalibration", &CRawImage::drawGuideCalibration)
    .def_readwrite("width_", &CRawImage::width_)
    .def_readwrite("height_", &CRawImage::height_)
    .def_readwrite("bpp_", &CRawImage::bpp_)
    .def_readwrite("size_", &CRawImage::size_)
    
    .def("getImage", [](CRawImage &self) {
      if (self.data_ == nullptr || self.width_ == 0 || self.height_ == 0 || self.bpp_ == 0) {
        throw std::runtime_error("CRawImage has no valid data");
      }
      // view on the image memory (no copy)
      return py::array_t<unsigned char>(
        {self.height_, self.width_, self.bpp_},   // shape
        {self.width_ * self.bpp_, self.bpp_, 1},  // strides
        self.data_,
        py::cast(&self)
      );
    });
}

}  // namespace whycode
