#ifndef NUVOLA_UTILS_VERSIONUTILS
#define NUVOLA_UTILS_VERSIONUTILS
#include <string>

enum SupportedVersion {
	MC_1_17_11_1,
	MC_UNSUPPORTED
};

class VersionUtils {
    static inline SupportedVersion theVersion;
public:
    static auto retrieveVersion() -> SupportedVersion;
    static auto getVersion() -> SupportedVersion;
    static auto strToVer(std::string) -> SupportedVersion;
    static auto verToStr(SupportedVersion) -> std::string;
};

#endif /* NUVOLA_UTILS_VERSIONUTILS */
