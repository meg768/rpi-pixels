#include "addon.h"

NAN_METHOD(Addon::render)
{
	Nan::HandleScope();

	if (info.Length() != 2) {
		return Nan::ThrowError("render() requires pixels and pixel mapping arguments.");
	}

    if (!info[0]->IsUint32Array())
		return Nan::ThrowError("render() requires pixels to be an Uint32Array.");

    if (!info[1]->IsUint32Array())
		return Nan::ThrowError("render() requires pixels mapping to be an Uint32Array.");


	info.GetReturnValue().Set(Nan::Undefined());

};



NAN_MODULE_INIT(initAddon)
{
	Nan::SetMethod(target, "render",     Addon::render);
}


NODE_MODULE(addon, initAddon);