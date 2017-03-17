#ifndef  GFACTORY_H
#define  GFACTORY_H

#include <string>
using namespace std;

/**
 * @class BaseFactory
 * @brief factory abstract base class that defines its API and is templated on the
 *        base class of the type that its factories are meant to instantiate.
 *        Actual factory classes will use the below Factory<Base, Derived>
 *        version that's defined immediately below.
 *		  Here T must have the class method RegisterFactory
 */
template <class T>
class BaseFactory
{
public:
	/**
	 * @param typeName The name of the 'type' of object that this factory can create.
	 */
	BaseFactory(string typeName) :  fTypeName(typeName) {
		T::RegisterFactory(typeName, this);
	}

	virtual ~BaseFactory() = default;

	virtual T* Create() = 0;

protected:
	/// the 'type name' for classes created by this factory, which may or
	/// may not be the same as the C++ name of the classes created by this
	/// factory.
	string fTypeName;
};

template <class T, class Derived>
class Factory : public BaseFactory<T>
{
public:
	Factory(string typeName) :  BaseFactory<T>(typeName) {
		// compile time assertion to make sure that there's a valid
		// base/derived relationship between the two classes that this
		// factory is templated on.
		static_assert(is_base_of<T, Derived>::value, "");
	}

	~Factory() = default;

	T* Create() override {
		T* retval = new Derived();
		// sets the derived typename
		if (retval) {
			retval->SetTypeName(BaseFactory<T>::fTypeName);
		}
		return retval;
	}
};

#endif
