#ifndef TEST_ADDONS_ABI_7_FACTORY_WRAP_MYOBJECT_H_
#define TEST_ADDONS_ABI_7_FACTORY_WRAP_MYOBJECT_H_

#include <node_jsvmapi.h>

class MyObject {
 public:
  static napi_status Init(napi_env env);
  static void Destructor(void* nativeObject, void* /*finalize_hint*/);
  static napi_status NewInstance(napi_env env,
                                 napi_value arg,
                                 napi_value* instance);

 private:
  MyObject();
  ~MyObject();

  static napi_ref constructor;
  static void New(napi_env env, napi_callback_info info);
  static void PlusOne(napi_env env, napi_callback_info info);
  double counter_;
  napi_env env_;
  napi_ref wrapper_;
};

#endif  // TEST_ADDONS_ABI_7_FACTORY_WRAP_MYOBJECT_H_
