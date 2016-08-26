#pragma once
namespace Gravity {
	struct RGB {
		Uint8 r, g, b;
		Uint32 rgbaRepresentation;
		RGB(const Uint8 inputR, const Uint8 inputG, const Uint8 inputB) : r(inputR), g(inputG), b(inputB) {	
			rgbaRepresentation = convertToUint32();
		};
	private:
		Uint32 convertToUint32() {
			Uint32 color = 0;
			color += r;
			color <<= 8;
			color += g;
			color <<= 8;
			color += b;
			color <<= 8;
			color += 0xFF;
			return color;
		};
	};
}