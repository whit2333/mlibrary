#ifndef  GDL_H
#define  GDL_H

// plugin loading functions
#include <dlfcn.h>

typedef void* dynamic_lib_handle;

static dynamic_lib_handle load_lib(const string& path);
static void close_lib(dynamic_lib_handle handle);

struct dynamic_lib {
	dynamic_lib_handle  handle;
	string			path;
	
	dynamic_lib(string p) : path(p), handle(nullptr) {
		cout << " Loading DL " << p << endl;
		handle = load_lib(p);
	}
	
	~dynamic_lib() {
		if (handle != nullptr)
			close_lib(handle);
		cout << " closing " << path << endl;
	}
};


static dynamic_lib_handle load_lib(const string& path) {

	cout << " Trying to open: " << path << endl;

	return dlopen(path.data() , RTLD_NOW);
	// get a handle to the lib, may be nullptr.
	// RTLD_NOW ensures that all the symbols are resolved immediately. This means that
	// if a symbol cannot be found, the program will crash now instead of later.
}

static void close_lib(dynamic_lib_handle handle) {
	dlclose(handle);
}

#endif
