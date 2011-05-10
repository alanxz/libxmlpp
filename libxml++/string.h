#ifndef __LIBXMLPP_STRING_H
#define __LIBXMLPP_STRING_H

#include <libxml++config.h>

#ifdef LIBXMLPP_USE_GLIBUSTRING
#include <glibmm/ustring.h>

namespace xmlpp
{
  typedef Glib::ustring string;
}
#else
#include <string>

namespace xmlpp
{
  typedef std::string string;
}
#endif // LIBXMLPP_USE_GLIBUSTRING

#endif // __LIBXMLPP_STRING_H
