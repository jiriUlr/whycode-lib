#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "whycode/types.h"

namespace py = pybind11;

namespace whycode {

void bind_types(py::module_ &m) {
  py::class_<Parameters>(m, "Parameters")
    .def(py::init<>())
    .def_readwrite("id_bits", &Parameters::id_bits)
    .def_readwrite("id_samples", &Parameters::id_samples)
    .def_readwrite("hamming_dist", &Parameters::hamming_dist)
    .def_readwrite("draw_coords", &Parameters::draw_coords)
    .def_readwrite("draw_segments", &Parameters::draw_segments)
    .def_readwrite("use_gui", &Parameters::use_gui)
    .def_readwrite("identify", &Parameters::identify)
    .def_readwrite("coords_method", &Parameters::coords_method)
    .def_readwrite("num_markers", &Parameters::num_markers)
    .def_readwrite("min_size", &Parameters::min_size)
    .def_readwrite("circle_diameter", &Parameters::circle_diameter)
    .def_readwrite("calib_dist_x", &Parameters::calib_dist_x)
    .def_readwrite("calib_dist_y", &Parameters::calib_dist_y)
    .def_readwrite("initial_circularity_tolerance", &Parameters::initial_circularity_tolerance)
    .def_readwrite("final_circularity_tolerance", &Parameters::final_circularity_tolerance)
    .def_readwrite("area_ratio_tolerance", &Parameters::area_ratio_tolerance)
    .def_readwrite("center_distance_tolerance_ratio", &Parameters::center_distance_tolerance_ratio)
    .def_readwrite("center_distance_tolerance_abs", &Parameters::center_distance_tolerance_abs);

  py::class_<SDecoded>(m, "SDecoded")
    .def(py::init<>())
    .def_readwrite("angle", &SDecoded::angle)
    .def_readwrite("id", &SDecoded::id)
    .def_readwrite("edgeIndex", &SDecoded::edgeIndex);

  py::class_<SSegment>(m, "SSegment")
    .def(py::init<>())
    .def_readwrite("x", &SSegment::x)
    .def_readwrite("y", &SSegment::y)
    .def_readwrite("angle", &SSegment::angle)
    .def_readwrite("horizontal", &SSegment::horizontal)
    .def_readwrite("size", &SSegment::size)
    .def_readwrite("maxy", &SSegment::maxy)
    .def_readwrite("maxx", &SSegment::maxx)
    .def_readwrite("miny", &SSegment::miny)
    .def_readwrite("minx", &SSegment::minx)
    .def_readwrite("mean", &SSegment::mean)
    .def_readwrite("type", &SSegment::type)
    .def_readwrite("roundness", &SSegment::roundness)
    .def_readwrite("bwRatio", &SSegment::bwRatio)
    .def_readwrite("round", &SSegment::round)
    .def_readwrite("valid", &SSegment::valid)
    .def_readwrite("m0", &SSegment::m0)
    .def_readwrite("m1", &SSegment::m1)
    .def_readwrite("v0", &SSegment::v0)
    .def_readwrite("v1", &SSegment::v1)
    .def_readwrite("r0", &SSegment::r0)
    .def_readwrite("r1", &SSegment::r1)
    .def_readwrite("ID", &SSegment::ID);

  py::class_<STrackedObject>(m, "STrackedObject")
    .def(py::init<>())
    .def_readwrite("u", &STrackedObject::u)
    .def_readwrite("v", &STrackedObject::v)
    .def_readwrite("x", &STrackedObject::x)
    .def_readwrite("y", &STrackedObject::y)
    .def_readwrite("z", &STrackedObject::z)
    .def_readwrite("d", &STrackedObject::d)
    .def_readwrite("roll", &STrackedObject::roll)
    .def_readwrite("pitch", &STrackedObject::pitch)
    .def_readwrite("yaw", &STrackedObject::yaw)
    .def_readwrite("angle", &STrackedObject::angle)
    .def_readwrite("n0", &STrackedObject::n0)
    .def_readwrite("n1", &STrackedObject::n1)
    .def_readwrite("n2", &STrackedObject::n2)
    .def_readwrite("qx", &STrackedObject::qx)
    .def_readwrite("qy", &STrackedObject::qy)
    .def_readwrite("qz", &STrackedObject::qz)
    .def_readwrite("qw", &STrackedObject::qw);

  // TODO: redo the fixed-size arrays and std::array
  // py::class_<SEllipseCenters>(m, "SEllipseCenters")
  //   .def(py::init<>())
  //   .def_readwrite("u", &SEllipseCenters::u)
  //   .def_readwrite("v", &SEllipseCenters::v)
  //   .def_readwrite("n", &SEllipseCenters::n)
  //   .def_readwrite("t", &SEllipseCenters::t);

  // py::class_<S3DTransform>(m, "S3DTransform")
  //   .def(py::init<>())
  //   .def_readwrite("orig", &S3DTransform::orig)
  //   .def_readwrite("simlar", &S3DTransform::simlar);

  py::class_<SMarker>(m, "SMarker")
    .def(py::init<>())
    .def_readwrite("valid", &SMarker::valid)
    .def_readwrite("seg", &SMarker::seg)
    .def_readwrite("obj", &SMarker::obj);

  // py::class_<CalibrationConfig>(m, "CalibrationConfig")
  //   .def(py::init<>())
  //   .def_readwrite("grid_dim_x_", &CalibrationConfig::grid_dim_x_)
  //   .def_readwrite("grid_dim_y_", &CalibrationConfig::grid_dim_y_)
  //   .def_readwrite("hom_", &CalibrationConfig::hom_)
  //   .def_readwrite("D3transform_", &CalibrationConfig::D3transform_);

  py::enum_<ETransformType>(m, "ETransformType")
    .value("TRANSFORM_NONE", TRANSFORM_NONE)
    .value("TRANSFORM_2D", TRANSFORM_2D)
    .value("TRANSFORM_3D", TRANSFORM_3D)
    .value("TRANSFORM_4D", TRANSFORM_4D)
    .value("TRANSFORM_INV", TRANSFORM_INV)
    .value("TRANSFORM_NUMBER", TRANSFORM_NUMBER);
}

}  // namespace whycode
