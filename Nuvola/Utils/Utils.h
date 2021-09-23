#ifndef NUVOLA_UTILS_UTILS
#define NUVOLA_UTILS_UTILS
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include "../Client/Bridge/ClientInstance.h"
#include "../Client/Bridge/Actor.h"
#include <gsl/gsl>
#include <sstream>

#define STRING_EXPAND(s) #s
#define STRING(s) STRING_EXPAND(s)

//Define the build ver if CMake failed to or it wasn't build with it
#ifndef NUVOLA_BUILD_VERSION
#define NUVOLA_BUILD_VERSION Unknown
#endif
#ifndef NUVOLA_BUILD_TAG
#define NUVOLA_BUILD_TAG Alpha Build 1.0.0
#endif

#define LOG_FILE
//#define LOG_CONSOLE
#define LOG_GAME

namespace lun {
	struct ostream;
}

class Utils {
	static inline ClientInstance* clientInstance;
	static inline class MaterialPtr* materialPtr;

	//List of ALL entities
	static inline std::vector<Actor*>* actorList;

	//Minecraft Output (mcout), how creative
	static lun::ostream* omcout;
public:
    static void DebugF(const char*);
    static void DebugF(std::string);
	static auto mcout() -> lun::ostream&;
	static void SetClientInstance(uintptr_t address);
	static auto GetClientInstance() -> ClientInstance*;
	static auto GetActorList() -> std::vector<Actor*>*;
	static auto GetUIMaterialPtr() -> class MaterialPtr*;
};

namespace lun {
	//Custom stream out object for std::cout like behavior within mc chat and other output methods
	struct ostream {
		std::stringstream stream;
	public:
		template<typename T>
		ostream& operator<<(T&& value) {
			stream << value;
			return *this;
		}

		ostream& operator<<(std::ostream& (*os)(std::ostream&)) {
			stream << os;
			
			return *this;
		}

		//Flush the output stream to DebugF
		ostream& flush() {
			std::string result = stream.str();
			Utils::DebugF(result);

			stream.flush();
			stream.clear();

			return *this;
		}
	};
}

#endif /* NUVOLA_UTILS_UTILS */
