all : fuzzer-tiff_parser fuzzer-piex

fuzzer-tiff_parser : tiff_parser.cpp
	$(CXX) $(CXXFLAGS) -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -I fuzzing-headers/include -I .. tiff_parser.cpp ../src/*.cc ../src/binary_parse/*.cc ../src/image_type_recognition/*.cc ../src/tiff_directory/*.cc $(LIB_FUZZING_ENGINE) -o fuzzer-tiff_parser

fuzzer-piex : piex.cpp
	$(CXX) $(CXXFLAGS) -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -I fuzzing-headers/include -I .. piex.cpp ../src/*.cc ../src/binary_parse/*.cc ../src/image_type_recognition/*.cc ../src/tiff_directory/*.cc $(LIB_FUZZING_ENGINE) -o fuzzer-piex
