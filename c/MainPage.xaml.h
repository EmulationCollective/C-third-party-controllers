#pragma once

#include "MainPage.g.h"

namespace c
{
    public ref class MainPage sealed
    {
    public:
        MainPage();

    private:
        // Event handlers for keyboard events
        void OnKeyDown(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::KeyEventArgs^ args);
        void OnKeyUp(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::KeyEventArgs^ args);
    };
}
