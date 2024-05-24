#include "graver/util/io_util.h"

#include <sys/stat.h>

#include <fstream>
#include <sstream>
#include <string>

FileInfo IoUtil::getFileInfo(const char* filename) {
    FileInfo    info{};
    struct stat fileStat {};
    info.exist = 0 == stat(filename, &fileStat);
    if (S_ISREG(fileStat.st_mode)) {  // NOLINT
        info.type = FileType::file;
    } else if (S_ISDIR(fileStat.st_mode)) {  // NOLINT
        info.type = FileType::dir;
    }
    return info;
}
std::string IoUtil::readToLine(const char* filename) {
    auto info = IoUtil::getFileInfo(filename);
    if (!info.exist || FileType::file != info.type) {
        return "";
    }
    std::ifstream input(filename, std::ios::in);
    if (!input.is_open()) {
        return "";
    }

    std::stringstream ss;
    ss << input.rdbuf();

    return ss.str();
}

void IoUtil::writeToFile(const std::string& filename, const std::string& content) {
    std::fstream output(filename, std::ios::out);
    output << content;
}