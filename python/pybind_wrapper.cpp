#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace whycode {
  void bind_types(py::module_ &);
  void bind_CWhycode(py::module_ &);
  void bind_CRawImage(py::module_ &);
  void bind_CCircleDetect(py::module_ &);
  void bind_CTransformation(py::module_ &);
  void bind_CNecklace(py::module_ &);
}  // namespace whycode

PYBIND11_MODULE(whycode_cpp, m) {
  m.doc() = "WhyCode Python bindings";
  whycode::bind_types(m);
  whycode::bind_CWhycode(m);
  whycode::bind_CRawImage(m);
  // whycode::bind_CCircleDetect(m);
  // whycode::bind_CTransformation(m);
  // whycode::bind_CNecklace(m);
}
