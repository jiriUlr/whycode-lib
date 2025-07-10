#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "whycode/CWhycode.h"
#include "whycode/CRawImage.h"
#include "whycode/types.h"

namespace py = pybind11;

namespace whycode {

void bind_CWhycode(py::module_ &m) {
  py::class_<CWhycode>(m, "CWhycode")
    .def(py::init<>())
    .def(py::init<float, int, int, int>(),
      py::arg("diameter"),
      py::arg("id_bits"),
      py::arg("id_samples") = 360,
      py::arg("hamming_dist") = 1
    )
    .def("init", &CWhycode::init)
    .def("autocalibration", &CWhycode::autocalibration)
    .def("manualcalibration", &CWhycode::manualcalibration)
    .def("selectMarker", &CWhycode::selectMarker)
    .def("updateCameraInfo", &CWhycode::updateCameraInfo)
    .def("processImage", &CWhycode::processImage)
    .def("set_parameters", &CWhycode::set_parameters)
    .def("get_parameters", &CWhycode::get_parameters)
    .def("is_calibrated", &CWhycode::is_calibrated)
    .def("setCalibrationConfig", &CWhycode::setCalibrationConfig)
    .def("getCalibrationConfig", &CWhycode::getCalibrationConfig)
    .def("saveCalibration", &CWhycode::saveCalibration)
    .def("loadCalibration", &CWhycode::loadCalibration);
}

}  // namespace whycode
