# cmake_minimum_required(VERSION 3.5)
# project(allegro_starter)

# # Allows us to get CMake stuff from other places
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
# set (CMAKE_CXX_STANDARD 14)

# # Use pkg-config for all deps
# find_package(PkgConfig)

# # if(PKG_CONFIG_FOUND)
# 	# if(APPLE)
# 		pkg_search_module(ALLEGRO REQUIRED allegro-5 allegro-5.0)
# 		pkg_search_module(ALLEGRO_MAIN REQUIRED allegro_main-5 allegro_main-5.0)
# 		pkg_search_module(ALLEGRO_IMAGE REQUIRED allegro_image-5 allegro_image-5.0)
# 	# else()
# 		pkg_search_module(ALLEGRO REQUIRED allegro-5 allegro-5.0)
# 		pkg_search_module(ALLEGRO_IMAGE REQUIRED allegro_image-5 allegro_image-5.0)
# 	# endif()

# 	pkg_check_modules(GLIB REQUIRED glib-2.0)
# 	pkg_check_modules(LIBXML REQUIRED libxml-2.0)
# 	pkg_check_modules(ZLIB REQUIRED zlib)
  
# # else()
# # 	message("pkg-config is not installed on this system, using environment variables.")
# # 	find_env_deps()
# # endif()

# link_directories(
# 	${ALLEGRO_LIBRARY_DIRS}
# 	${ALLEGRO_MAIN_LIBRARY_DIRS}
# 	${ALLEGRO_LIBRARY_LIBRARY_DIRS}
# 	${GLIB_LIBRARY_DIRS}
# 	${LIBXML_LIBRARY_DIRS}
# 	${ZLIB_LIBRARY_DIRS}
# )

# include_directories(
# 	${ALLEGRO_INCLUDE_DIRS}
# 	${ALLEGRO_MAIN_INCLUDE_DIRS}
# 	${ALLEGRO_INCLUDE_INCLUDE_DIRS}
# 	${GLIB_INCLUDE_DIRS}
# 	${LIBXML_INCLUDE_DIRS}
# 	${ZLIB_INCLUDE_DIRS}
# )

# add_executable (allegro_starter main.cpp app.cpp)
# target_link_libraries (allegro_starter  ${include_directories})

cmake_minimum_required(VERSION 3.5)
project(ask)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp app.cpp map.cpp player.cpp screen.cpp)
add_executable(ask ${SOURCE_FILES})

IF(UNIX)
  IF(APPLE)
    SET(GUI "Cocoa")
    INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.5.0/include )
    INCLUDE_DIRECTORIES( /usr/local/include )
    LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.5.0/lib )
    LINK_DIRECTORIES( /usr/local/lib )
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.5.0/lib/*.dylib" "/usr/local/lib/liballegro_tiled.dylib")
    message("LIBRARIES = ${LIBRARIES}")
  ELSE(APPLE)
    SET(GUI "X11")
    INCLUDE_DIRECTORIES(  /usr/local/include/allegro5 )
    LINK_DIRECTORIES(  /usr/lib/x86_64-linux-gnu/ )
    file(GLOB LIBRARIES "/usr/lib/x86_64-linux-gnu/liballegro*.*")
    message("LIBRARIES = ${LIBRARIES}")
  ENDIF(APPLE)
ELSE(UNIX)
  IF(WIN32)
    SET(GUI "Win32")
  ELSE(WIN32)
    SET(GUI "Unknown")
  ENDIF(WIN32)
ENDIF(UNIX)
MESSAGE("Compiled for... ${GUI}")

TARGET_LINK_LIBRARIES(ask  ${LIBRARIES})