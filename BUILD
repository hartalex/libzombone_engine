cc_library(
	name="libzombone_engine",
	srcs=glob(["src/*.cpp","src/*.hpp"]),
	visibility=["//visibility:public"],
	includes=["zombone_engine"],
  hdrs=glob(["zombone_engine.hpp","zombone_engine/*.hpp"]),	
  copts = ["--std=c++23"],
)

cc_test(
	name="engine_test",
	srcs=glob(["tests/engine/engine_test.cpp","zombone_engine/*.hpp"]),
	includes=["zombone_engine"],
  deps=[":libzombone_engine"],
  copts = ["--std=c++23"],
)
