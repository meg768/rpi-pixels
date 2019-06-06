#include "addon.h"



NAN_METHOD(Addon::render)
{
	Nan::HandleScope();

    try {
    	int argc = info.Length();

        if (info.Length() != 1) {
            return Nan::ThrowError("render() requires one argument.");
        }

        v8::Local<v8::Object> options = v8::Local<v8::Object>::Cast(info[0]);
        v8::Local<v8::Value> pixels = options->Get(Nan::New<v8::String>("pixels").ToLocalChecked()).As<v8::Uint32Array>();
        v8::Local<v8::Function> render = options->Get(Nan::New<v8::String>("render").ToLocalChecked()).As<v8::Function>();
        v8::Local<v8::Value> result;
	    v8::Local<v8::Context> context;
		
		render->Call(context, result, 1, &pixels);

		info.GetReturnValue().Set(Nan::Undefined());

    }
    
    catch (exception &error) {
        string what = error.what();
        string message = string("render() failed: ") + what;

		return Nan::ThrowError(message.c_str());
    }
    catch (...) {
        return Nan::ThrowError("Unhandled error");
    }

	info.GetReturnValue().Set(Nan::Undefined());

};



NAN_MODULE_INIT(initAddon)
{
	Nan::SetMethod(target, "render", Addon::render);
}


NODE_MODULE(addon, initAddon);