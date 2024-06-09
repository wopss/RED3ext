#include <exception>

#include <Windows.h>

#include <geecore/Common.hpp>
#include <geecore/Host.hpp>
#include <geecore/HostBuilder.hpp>
#include <geecore/MsgBox.hpp>
#include <geecore/MsgBoxPrimitives.hpp>

#include "AppMetadata.hpp"

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    GEECORE_UNUSED(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(module);

        try
        {
            auto host = geecore::HostBuilder()
                            .add_module_image(module)
                            .add_service<red3ext::AppMetadataService>()
                            .add_loader_lifetime()
                            .set_as_default()
                            .build();

            host->start();
        }
        catch (const std::exception& e)
        {
            geecore::Win32MsgBoxDriverAnsi driver;
            geecore::MsgBoxExceptionlessAnsi(driver)
                .with_title("RED3ext Loader: Application Exception")
                .with_text(e.what())
                .with_icon(geecore::MsgBoxIcon::Error)
                .with_buttons(geecore::MsgBoxButtons::Ok)
                .show();

            return FALSE;
        }
        catch (...)
        {
            geecore::Win32MsgBoxDriver driver;
            geecore::MsgBoxExceptionless(driver)
                .with_title(L"RED3ext Loader: Unknown Application Exception")
                .with_text(L"An unknown exception has occurred, preventing the application from starting up properly.")
                .with_icon(geecore::MsgBoxIcon::Error)
                .with_buttons(geecore::MsgBoxButtons::Ok)
                .show();

            return FALSE;
        }

        break;
    }
    case DLL_PROCESS_DETACH:
    {
        try
        {
            auto host = geecore::Host::instance();
            if (host)
            {
                host->stop();
            }
        }
        catch (...)
        {
            // Unfortunately, there are no specific actions we can take at this point.
        }

        break;
    }
    }

    return TRUE;
}
