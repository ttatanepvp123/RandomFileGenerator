#include <fstream> 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <iomanip>

#if !defined(LAST_COMMIT_ID)
#define LAST_COMMIT_ID "UNKOWN"
#endif

constexpr char version[] = "0.1.0";

int main(int argc, char const *argv[]){
    std::string FileName("output.rnd");
    long long FileSize{0};
    for(size_t i = 0; i < argc; i++){
        if (!strcmp(argv[i], "--version") || !strcmp(argv[i], "-v")) {
            std::cout << "Version : " << version << std::endl;
            std::cout << "Last Commit Id : " << LAST_COMMIT_ID << std::endl;
            exit(EXIT_SUCCESS);
        } else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            char margin[] = "     ";
            std::cout << "[ Size Options ]" << std::endl;
            std::cout << margin << "-E to choose the Exabyte number" << std::endl;
            std::cout << margin << "-P to choose the Petabyte number" << std::endl;
            std::cout << margin << "-T to choose the Terabyte number" << std::endl;
            std::cout << margin << "-G to choose the Gigabyte number" << std::endl;
            std::cout << margin << "-M to choose the Megabyte number" << std::endl;
            std::cout << margin << "-k to choose the Kilobyte number" << std::endl;
            exit(EXIT_SUCCESS);
        } else if (!strcmp(argv[i], "-E") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000000000000000000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        } else if (!strcmp(argv[i], "-P") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000000000000000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        } else if (!strcmp(argv[i], "-T") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000000000000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        } else if (!strcmp(argv[i], "-G") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000000000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        } else if (!strcmp(argv[i], "-M") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        } else if (!strcmp(argv[i], "-k") && i+1 < argc) {
            int tmp = 0;
            if(sscanf(argv[i+1], "%d", &tmp)){
                FileSize += tmp*1000;
            } else {
                std::cout << "ERROR: impossible to convert " << argv[i+1] << " in integer" << std::endl;
            }
        }
    }

    
    if(FileSize < 1) {
        std::cout << "ERROR: The number of octet is invalid to display the option used the --help or -h option" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::ofstream FileOut(FileName, std::ios_base::binary);
    long long CurrentSize{0};
    while(CurrentSize < FileSize){
        FileOut.write(reinterpret_cast<const char*>(&CurrentSize), sizeof(long long));
        CurrentSize += sizeof(long long);
        std::cout << CurrentSize*100/FileSize << "% | " << CurrentSize << "/" << FileSize << "\r"; 
    }
    FileOut.close();
    return EXIT_SUCCESS;
}
