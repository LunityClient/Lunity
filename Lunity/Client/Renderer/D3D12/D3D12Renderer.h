#ifndef LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H
#define LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H

#include <exception>
#include "../../../Utils/Event.h"

struct D3D12InitializingEventArgs
{
    bool handled;
    bool cancel;
};

struct D3D12RenderEventArgs
{
    bool handled;
};

class D3D12Renderer
{
private:
    bool isInitialized = false;
    bool hooked = false;
    static bool isAlreadyHooked = false;
public:
    D3D12Renderer() { }
    ~D3D12Renderer() { }
    auto isHooked() -> bool;
    auto hookUnsafely() -> void;
    auto hook() -> void;
    auto unhook() -> void;
    auto reload() -> void;
    auto release() -> void;
public:
    // TODO: Add EventArgs
    Event<void(D3D12InitializingEventArgs&)> initializing; // Is being invoked before the hook initializes all its resources
    Event<void(D3D12RenderEventArgs&)> render; // Is being invoked when everything is being rendered
};


#endif //LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H