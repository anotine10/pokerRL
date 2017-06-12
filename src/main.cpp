#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = 1;
    // ...
    LOG(INFO) << "Found " << 3 << " cookies";
    std::cout << "coucou";
    return(0);

}

