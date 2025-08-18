//  Sonia.one framework (c) by Alexander Pototskiy
//  Sonia.one is licensed under the terms of the Open Source GPL 3.0 license.
//  For a license to use the Sonia.one software under conditions other than those described here, please contact me at admin@sonia.one

#pragma once

#include "sonia/config.hpp"

#ifdef SONIA_ONE_UNIQUE_BUILDINFO
#  include SONIA_ONE_UNIQUE_BUILDINFO
#elif defined(SONIA_ONE_BUNDLE_BUILDINFO)
#  include SONIA_ONE_BUNDLE_BUILDINFO
#else
#  define SONIA_ONE_APP_VERSION_MAJOR 0
#  define SONIA_ONE_APP_VERSION_MINOR 1
#  define BUILD_NAME "Annium"
#  define REVISION_NAME "undefined"
#endif

#ifndef BUILD_DATETIME
#  define BUILD_DATETIME __DATE__ " " __TIME__
#endif

#ifndef HELLO_MESSAGE
#  define HELLO_MESSAGE ""
#endif

#ifndef BUILD_ID
#  define BUILD_ID BUILD_NAME ", rev: " REVISION_NAME
#endif
