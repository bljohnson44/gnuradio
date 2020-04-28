/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* This file is automatically generated using bindtool */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/keep_m_in_n.h>
// pydoc.h is automatically generated in the build directory
#include <keep_m_in_n_pydoc.h>

void bind_keep_m_in_n(py::module& m)
{

    using keep_m_in_n = ::gr::blocks::keep_m_in_n;


    py::class_<keep_m_in_n, gr::block, gr::basic_block, std::shared_ptr<keep_m_in_n>>(
        m, "keep_m_in_n", D(keep_m_in_n))

        .def(py::init(&keep_m_in_n::make),
             py::arg("itemsize"),
             py::arg("m"),
             py::arg("n"),
             py::arg("offset"),
             D(keep_m_in_n, make))


        .def("set_m", &keep_m_in_n::set_m, py::arg("m"), D(keep_m_in_n, set_m))


        .def("set_n", &keep_m_in_n::set_n, py::arg("n"), D(keep_m_in_n, set_n))


        .def("set_offset",
             &keep_m_in_n::set_offset,
             py::arg("offset"),
             D(keep_m_in_n, set_offset))

        ;
}