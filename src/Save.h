#pragma once

#include "Image.h"

namespace img {

/// Exports an image as PNG
/// @param file_path The destination path for the image: something like "out/myImage.png"
/// @param flip_vertically By default we use the OpenGL convention: the first row should be the bottom of the image. You can set flip_vertically to false if your first row is at the top of the image
void save_png(const char* file_path, const Image& image, bool flip_vertically = true);

/// Exports an image as PNG
/// @param file_path The destination path for the image : something like "out/myImage.png"
/// @param width The width in pixels of the image represented by data
/// @param height The height in pixels of the image represented by data
/// @param data An array of uint8_t (a.k.a. unsigned char) representing the image. The pixels should be written sequentially, row after row. Something like [255, 200, 100, 255, 120, 30, 80, 255, ...] where (255, 200, 100, 255) would be the first pixel and (120, 30, 80, 255) the second pixel and so on
/// @param channels_count The number of channels per pixel, e.g. 4 if the format is RGBA
/// @param flip_vertically By default we use the OpenGL convention: the first row should be the bottom of the image. You can set flip_vertically to false if your first row is at the top of the image
void save_png(const char*         file_path,
              ImageSize::DataType width,
              ImageSize::DataType height,
              const void*         data,
              int                 channels_count,
              bool                flip_vertically = true);

} // namespace img