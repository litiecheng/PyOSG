// Copyright (C) 2016 Gideon May (gideon@borges.xyz)
//
// Permission to copy, use, sell and distribute this software is granted
// provided this copyright notice appears in all copies.
// Permission to modify the code and to distribute modified code is granted
// provided this copyright notice appears in all copies, and a notice
// that the code was modified is included with the copyright notice.
//
// This software is provided "as is" without express or implied warranty,
// and with no claim as to its suitability for any purpose.

#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include <boost/python/implicit.hpp>

#include <osg/ColorMask>

#include "StateAttribute.hpp"
#include "held_ptr.hpp"

using namespace boost::python;

namespace {
osg::ColorMask * asColorMask(osg::StateAttribute * self) { return dynamic_cast<osg::ColorMask*>(self); }
}

namespace PyOSG {
void init_ColorMask()
{
    register_castStateAttribute("asColorMask", &asColorMask);

    class_<osg::ColorMask, osg::ref_ptr<osg::ColorMask>, bases<osg::StateAttribute> >("ColorMask",
            "Encapsulate OpenGL glColorMaskFunc/Op/Mask functions.\n", no_init)
        .def(init<>())
        .def(init<bool, bool, bool, bool>())
        .def("setMask", &osg::ColorMask::setMask)
        .def("setRedMask", &osg::ColorMask::setRedMask)
        .def("getRedMask", (bool (osg::ColorMask::*)() const) &osg::ColorMask::getRedMask)
        .def("setGreenMask", &osg::ColorMask::setGreenMask)
        .def("getGreenMask", (bool (osg::ColorMask::*)() const) &osg::ColorMask::getGreenMask)
        .def("setBlueMask", &osg::ColorMask::setBlueMask)
        .def("getBlueMask", (bool (osg::ColorMask::*)() const) &osg::ColorMask::getBlueMask)
        .def("setAlphaMask", &osg::ColorMask::setAlphaMask)
        .def("getAlphaMask", (bool (osg::ColorMask::*)() const) &osg::ColorMask::getBlueMask)
        ;
}
}
