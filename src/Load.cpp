#include "Load.h"
#include <stb_image/stb_image.h>
#include <stdexcept>
#include <string>
#include "Image.h"

namespace img {

Image load(std::filesystem::path const& file_path, std::optional<int> desired_channels_count, img::FirstRowIs desired_row_order)
{
    assert((!desired_channels_count.has_value() || *desired_channels_count != 0) && "If you don't want to enforce a channels count, don't set desired_channels_count to 0, but to std::nullopt");
    assert(!desired_channels_count.has_value() || *desired_channels_count == 3 || *desired_channels_count == 4);

    stbi_set_flip_vertically_on_load(desired_row_order == img::FirstRowIs::Bottom ? 1 : 0);
    int      w, h, actual_channels_count_in_file; // NOLINT
    uint8_t* data = stbi_load(file_path.string().c_str(), &w, &h, &actual_channels_count_in_file, desired_channels_count.value_or(0));
    if (!data)
        throw std::runtime_error{"[img::load] Couldn't load image from \"" + file_path.string() + "\":\n" + stbi_failure_reason()};

    return Image{
        {
            static_cast<Size::DataType>(w),
            static_cast<Size::DataType>(h),
        },
        desired_channels_count.value_or(actual_channels_count_in_file) == 3 ? img::PixelFormat::RGB : img::PixelFormat::RGBA,
        desired_row_order,
        data,
    };
}

} // namespace img