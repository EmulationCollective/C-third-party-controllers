#include "pch.h"
#include "MainPage.xaml.h"

using namespace c;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::System; // NEEDED FOR VIRTUAL KEY

MainPage::MainPage()
{
    InitializeComponent();

    CoreWindow^ currentWindow = CoreWindow::GetForCurrentThread();

    // Subscribe to KeyDown and KeyUp events
    currentWindow->KeyDown += ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &MainPage::OnKeyDown);
    currentWindow->KeyUp += ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &MainPage::OnKeyUp);
}

void MainPage::OnKeyDown(CoreWindow^ sender, KeyEventArgs^ args)
{
    // Retrieve key information
    VirtualKey key = args->VirtualKey;
    int keyCode = static_cast<int>(key);
    String^ keyName = key.ToString();

    // Check if the key was already pressed
    bool wasKeyDown = args->KeyStatus.WasKeyDown;

    // Determine the status
    String^ status = wasKeyDown ? "Held" : "Pressed";

    // Check for modifier keys
    bool isShiftPressed = (sender->GetKeyState(VirtualKey::Shift) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;
    bool isCtrlPressed = (sender->GetKeyState(VirtualKey::Control) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;
    bool isAltPressed = (sender->GetKeyState(VirtualKey::Menu) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;

    String^ modifiers = "";
    if (isCtrlPressed) modifiers += "Ctrl + ";
    if (isAltPressed) modifiers += "Alt + ";
    if (isShiftPressed) modifiers += "Shift + ";

    // Construct the display string
    String^ displayText =
        "Key Down Event:\n" +
        "Key: " + keyName + "\n" +
        "Key Code: " + keyCode + "\n" +
        "Status: " + status + "\n" +
        "Modifiers: " + modifiers;

    // Update the TextBlock in XAML
    Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([=]()
        {
            KeyInfoTextBlock->Text = displayText;
        }));
}

void MainPage::OnKeyUp(CoreWindow^ sender, KeyEventArgs^ args)
{
    // Retrieve key information
    VirtualKey key = args->VirtualKey;
    int keyCode = static_cast<int>(key);
    String^ keyName = key.ToString();

    // Determine the status
    String^ status = "Released";

    // Check for modifier keys
    bool isShiftPressed = (sender->GetKeyState(VirtualKey::Shift) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;
    bool isCtrlPressed = (sender->GetKeyState(VirtualKey::Control) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;
    bool isAltPressed = (sender->GetKeyState(VirtualKey::Menu) & CoreVirtualKeyStates::Down) == CoreVirtualKeyStates::Down;

    String^ modifiers = "";
    if (isCtrlPressed) modifiers += "Ctrl + ";
    if (isAltPressed) modifiers += "Alt + ";
    if (isShiftPressed) modifiers += "Shift + ";

    // Construct the display string
    String^ displayText =
        "Key Up Event:\n" +
        "Key: " + keyName + "\n" +
        "Key Code: " + keyCode + "\n" +
        "Status: " + status + "\n" +
        "Modifiers: " + modifiers;

    // Update the TextBlock on the XAML
    Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([=]()
        {
            KeyInfoTextBlock->Text = displayText;
        }));
}
