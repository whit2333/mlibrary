#ifndef  GDL_H
#define  GDL_H

// this code is based on this tutorial:
// https://0x00sec.org/t/c-dynamic-loading-of-shared-objects-at-runtime/1498

// plugin loading functions
#include <dlfcn.h>

typedef void* dlhandle;

static dlhandle load_lib(const string& path);
static void close_lib(dlhandle handle);

struct dynamic_lib {
	
	// default constructor
	dynamic_lib() = default;
	
	dlhandle handle;
	string   path;

	dynamic_lib(string p) : path(p), handle(nullptr) {
		cout << " Loading DL " << p << endl;
		handle = load_lib(p);
	}
	
	~dynamic_lib() {
		if (handle != nullptr)
			close_lib(handle);
		cout << " Closing DL " << path << endl;
	}
};


static dlhandle load_lib(const string& path) {

	return dlopen(path.data() , RTLD_NOW);
	// get a handle to the lib, may be nullptr.
	// RTLD_NOW ensures that all the symbols are resolved immediately. This means that
	// if a symbol cannot be found, the program will crash now instead of later.
}

static void close_lib(dlhandle handle) {
	dlclose(handle);
}

#endif
