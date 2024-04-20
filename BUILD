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
	srcs=glob(["tests/test.cpp"]),
	#deps=[":libzombone_engine","@com_google_googletest//:gtest_main"],
	deps=[
 "@gtest//:gtest_main"
	],
)
