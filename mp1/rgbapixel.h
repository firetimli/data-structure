
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

#include <cstdint>
#include <ostream>

using std::uint8_t;


class RGBAPixel
{
	public:
    RGBAPixel();
    RGBAPixel(uint8_t red, uint8_t green, uint8_t blue);


		uint8_t red; /**< Byte for the red component of the pixel. */
		uint8_t green; /**< Byte for the green component of the pixel. */
		uint8_t blue; /**< Byte for the blue component of the pixel. */
		uint8_t alpha; /**< Byte for the alpha component of the pixel. */

  };

#endif // RGBAPIXEL_H
