#pragma once

#include <filesystem>
#include <string_view>

#include <kangaru/kangaru.hpp>

#include <geecore/IHostImage.hpp>
#include <geecore/ILoaderAppMetadata.hpp>
#include <geecore/SpecialMemberFunctions.hpp>

namespace red3ext
{
class AppMetadata : public geecore::ILoaderAppMetadata
{
public:
    AppMetadata(const geecore::IHostImage& host_image);
    ~AppMetadata() final = default;

    GEECORE_NOEXCEPT_COPYABLE_AND_MOVEABLE(AppMetadata);

    const std::wstring_view name() const final;
    const std::filesystem::path& root_directory() const noexcept final;

    std::filesystem::path module_path() const final;

private:
    static constexpr std::wstring_view APPLICATION_DIRECTORY = L"red3ext";
    static constexpr std::wstring_view MODULE_NAME = L"RED3ext.dll";

    static std::filesystem::path compute_root_directory(const geecore::IHostImage& host_image);

    std::filesystem::path m_root_directory;
};

struct AppMetadataService
    : kgr::single_service<AppMetadata, kgr::dependency<geecore::HostImageService>>
    , kgr::overrides<geecore::LoaderAppMetadataService>
{
};
} // namespace red3ext
