#include <pybind11/pybind11.h>
#include "funkcje.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)




namespace py = pybind11;

PYBIND11_MODULE(_core, m) {  

    m.def("sinus", &sinus, "Generuje sygnał sinusoidalny",
          py::arg("f"),py::arg("t_start"),py::arg("t_end"),py::arg("l_probek"));

    m.def("cosinus", &cosinus, "Generuje sygnał cosinusoidalny",
          py::arg("f"),py::arg("t_start"),py::arg("t_end"),py::arg("l_probek"));

    m.def("prostokatny", &prostokatny, "Generuje sygnał prostokatny",
          py::arg("f"),py::arg("t_start"),py::arg("t_end"),py::arg("l_probek"));

    m.def("piloksztaltny", &piloksztaltny, "Generuje sygnał piloksztaltny",
          py::arg("f"),py::arg("t_start"),py::arg("t_end"),py::arg("l_probek"));
    






#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
