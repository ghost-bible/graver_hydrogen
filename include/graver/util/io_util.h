#pragma once

#include <string>

enum class FileType {
    file,
    dir,
    unknown
};

struct FileInfo {
    bool     exist = false;
    FileType type  = FileType::unknown;
};

class IoUtil {
public:
    IoUtil()  = default;
    ~IoUtil() = default;

public:
    static FileInfo    getFileInfo(const char* filename);
    static std::string readToLine(const char* filename);
    static void        writeToFile(const std::string& filename, const std::string& content);
};