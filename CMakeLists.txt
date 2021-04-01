cmake_minimum_required(VERSION 3.17)
project(obj_courier)

set(CMAKE_CXX_STANDARD 17)

add_executable(obj_courier main.cpp model/datastructures/Edge.cpp model/datastructures/Edge.h model/datastructures/Graph.cpp model/datastructures/Graph.h model/datastructures/Routes.cpp model/datastructures/Routes.h model/datastructures/Trip.cpp model/datastructures/Trip.h model/Mapper.cpp model/Mapper.h model/StringUtils.cpp model/StringUtils.h model/Algorithm.cpp model/Algorithm.h model/Utils.cpp model/Utils.h controller/Controller.cpp controller/Controller.h view/View.cpp view/View.h model/Params.cpp model/Params.h model/Constants.cpp model/Constants.h)