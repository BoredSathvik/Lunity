#ifndef NUVOLA_UTILS_NUV
#define NUVOLA_UTILS_NUV

//This header holds templates for Release mode STL types
//Ex. a wrapper for std::vector with Minecraft's build settings
//This way Nuvola can be built with whatever STL standard.
//This is also a near instant replacement. Just swap std::vector with nuv::vector

#define PTR_SIZE sizeof(void*)
#define STR_FIRST_ALIGN 0xF

#include <string>

namespace nuv {
	class string {
		//textData union to help us a bit
		union textData
		{
			const char* contentPtr;
			char contentData[STR_FIRST_ALIGN+1];
		} text;
static_assert(sizeof(textData) == 16, "textData is misaligned!");
		size_t length;
		size_t lengthTillRealign;
	public:
		//nuv::string constructor
		string(std::string text) {
			this->lengthTillRealign = STR_FIRST_ALIGN;
			this->setString(text);
		}
		~string() {
			clearContent();
		}
		//setting the string content via std::string
		void setString(std::string text) {
			//Clear any existing content
			clearContent();

			//Check the text length, we may need to reallocate where the content is stored
			if(text.length() > this->lengthTillRealign) {
				//If we need to relocate, allocate new memory with the text length + 1
				//Also is this a memory leak?
				char* alloc = (char*)malloc(text.length()*2);
				//Set the content of the allocated memory
				for(int i = 0; i < text.length(); i++) {
					alloc[i] = text[i];
				}
				//Set the content pointer to the allocated mem
				this->text.contentPtr = alloc;
				this->lengthTillRealign = text.length()*2;
			}
			//If we do not need to re allocate
			else {
				//Set the contents to the text with no memory allocation
				for(int i = 0; i < text.length(); i++) {
					this->text.contentData[i] = text[i];
				}
			}
			//Set the length
			this->length = text.length();
		}
		//Convert back to std::string
		std::string getString() {
			//create a new string
			std::string newStr = "";
			//if the content is in a pointer
			if(isPtr()) {
				//Its a pointer, std::string can use a char* to form a new instance
				newStr = text.contentPtr;
			} else {
				//Its not a pointer, so we can append each character
				for(int i = 0; i < this->length; i++) {
					newStr += text.contentData[i];
				}
			}
			return newStr;
		}
		//Free memory allocated
		void clearContent() {
			if(isPtr()) {
				free((void*)text.contentPtr);
			}
			//Clear the contentData, make sure its all null
			memset(this->text.contentData, 0, STR_FIRST_ALIGN+1);
		}
		//Tells us if the content for the string is in the pointer
		bool isPtr() {
			//This tells us if its a pointer or if we can just copy the bytes
			return STR_FIRST_ALIGN != this->lengthTillRealign;
		}

		//C string ==
		bool operator==(const char* text) {
			return getString() == text;
		}
		//nuv::string ==
		bool operator==(string text) {
			return getString() == text.getString();
		}
		//std::string ==
		bool operator==(std::string text) {
			return getString() == text;
		}
	};
static_assert(sizeof(nuv::string) == 32, "nuv::string is misaligned!");

	//Quickly refreshing list
	//A list type that is good for when it needs to be quickly
	//modified constantly, with a fast clear function.
	//Useful for the entity list now since mojang made that code super confusing.
	//Its easier just to read the actor pointers when theyre ticked and store them.
	//This list type is here to do exactly that.
	template <typename T>
	class qrlist {
		T* data;
		size_t nextLocation = 0;
		size_t ptrsTillRealloc = 0;
	public:
		//We can specify a starting size until we reallocate.
		qrlist(size_t startingSize) {
			ptrsTillRealloc = size;
			data = (T*)malloc(ptrsTillRealloc*sizeof(size_t));
		};
		~qrlist() {
			free(data);
		}
		void reallocate(size_t nextRealloc) {
			newData = (T*)malloc(nextRealloc*sizeof(size_t));
			int i;
			while(i < nextLocation) {
				newData[i] = data[i];
				i++;
			}
			ptrsTillRealloc = nextRealloc;
			free(data);
		}
		void push(T*) {
			if(nextLocation == ptrsTillRealloc) {
				
			}
		}
		void pop(T*) {

		}
		void clear() {
			nextLocation = 0;
		}
		T* operator[](size_t location) {
			//If the data is outside of our range, pretend it doesn't exist
			if(location >= nextLocation || location < 0) {
				return nullptr;
			}
			//If that data was popped, pretend it doesn't exist
			if(data[location] == nullptr) {
				//We might lose time here if there are a ton of popped elements,
				//but most cases this happens, its more likely itll be cleared.
				//this also may be a means to read "cleared" data, but the first if check
				//should catch that
				return operator[](location+1);
			}
			return data[location];
		}
	};

	//TODO: finish kthx
	template <typename T>
	class vector {
		T* firstAddr;
		T* lastAddr;
		void* nextRealign;
	public:
		size_t size() {
			return ((size_t)firstAddr)-((size_t)lastAddr)/PTR_SIZE;
		}
		T* begin() {
			return firstAddr;
		}
		T* end() {
			return lastAddr;
		}
		T operator[](size_t pos) {
			size_t ptrOffset = pos*PTR_SIZE;
			size_t item = firstAddr+ptrOffset;
			return (T)item;
		}
		void realign() {
			//TODO: magically fix memory leak that is probably actually impossible for me to fix
			
			//Double the element count, and multiply that by the size of a pointer
			//Leaves double the room before needing to realloc
			size_t size = size();
			size_t b_size = size*PTR_SIZE;
			size_t newAllocSize = b_size*2;
			T* newFirst = malloc(newAllocSize);

			//Copy old objects
			for(int i = 0; i < size(); i++) {
				*((T*)(((size_t)newFirst)+(i*PTR_SIZE))) = this[i];
			}

			//set new vals
			firstAddr = newFirst;
			lastAddr = b_size+PTR_SIZE;
			nextRealign = ((size_t)newFirst)+newAllocSize;
		}
		void push_back(T val) {
			if((((size_t)lastAddr)+PTR_SIZE == nextRealign)) {
				realign();
			}
			*lastAddr = val;
			((size_t)lastAddr) += PTR_SIZE;
		}
		bool remove(size_t index) {
			size_t size = size();
			if(index >= size) {
				//Index is outside of the size like bruh
				return false;
			}

			size_t offset = index*PTR_SIZE;
			//Clear the pointer
			*((size_t*)firstAddr+offset) = nullptr;



			return true;
		}
	};
static_assert(sizeof(vector<void*>)==24, "nuv::vector is misaligned!");
}

#endif /* NUVOLA_UTILS_NUV */
