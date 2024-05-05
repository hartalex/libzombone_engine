cc_library(
	name="libzombone_engine",
	srcs=glob(["src/*.cpp","src/*.hpp"]),
	visibility=["//visibility:public"],
	includes=["zombone_engine"],
  hdrs=glob(["zombone_engine.hpp","zombone_engine/*.hpp"]),	
  copts = ["--std=c++23"],
)

cc_test(
	name="libzombone_engine_test",
	srcs=glob(["tests/*.cpp","tests/*.hpp"]),
	deps=["//:libzombone_engine",
 "@gtest//:gtest_main"],
  copts = ["--std=c++23"]
)
