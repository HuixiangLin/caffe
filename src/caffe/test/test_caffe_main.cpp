// The main caffe test code. Your test cpp code should include this hpp
// to allow a main function to be compiled into the binary.

#include "caffe/caffe.hpp"
#include "caffe/test/test_caffe_main.hpp"

using caffe::Caffe;

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  caffe::GlobalInit(&argc, &argv);
#ifndef CPU_ONLY
  int device = 0;
  if (argc > 1) {
    // Use the given device
    device = atoi(argv[1]);
  } else if (TEST_DEVICE >= 0) {
    // Use the device assigned in build configuration; but with a lower priority
    device = TEST_DEVICE;
  }
  cout << "Setting to use device " << device << endl;
  Caffe::SetDevice(device);
  //cudaSetDevice(device);
#endif
  // invoke the test.
  return RUN_ALL_TESTS();
}
