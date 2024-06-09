#include "AppMetadata.hpp"

#include <utility>

#include <Windows.h>
#include <wil/win32_helpers.h>

red3ext::AppMetadata::AppMetadata(const geecore::IHostImage& host_image)
    : m_root_directory(compute_root_directory(host_image))
{
}

const std::wstring_view red3ext::AppMetadata::name() const
{
    return L"RED3ext Loader";
}

const std::filesystem::path& red3ext::AppMetadata::root_directory() const noexcept
{
    return m_root_directory;
}

std::filesystem::path red3ext::AppMetadata::module_path() const
{
    return root_directory() / MODULE_NAME;
}

std::filesystem::path red3ext::AppMetadata::compute_root_directory(const geecore::IHostImage& host_image)
{
    auto game_root = host_image.directory()
                         .parent_path()  // Resolve to "bin" directory.
                         .parent_path(); // Resolve to game's root directory.

    return game_root / APPLICATION_DIRECTORY;
}
