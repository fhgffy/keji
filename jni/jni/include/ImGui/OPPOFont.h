#ifndef OPPOFONT_H
#define OPPOFONT_H

// OPPOFont.h - OPPO Sans font placeholder
// The original file contained a large binary font data array (OPPOSanss_H)
// embedded as a C header. You need to replace this with actual OPPO Sans TTF
// binary data converted to a C array.
//
// To generate this file from a real TTF font:
//   xxd -i OPPOSans-H.ttf > OPPOFont.h
// Then rename the array to OPPOSanss_H and the size to OPPOSanss_H_size.
//
// Alternatively, use ImGui's binary_to_compressed_c tool.

// Placeholder: minimal empty font data - REPLACE with real OPPO Sans TTF data
// Using a minimal valid TTF is not feasible, so we provide a small stub.
// The program will crash or show no Chinese text until real font data is provided.

static const unsigned char OPPOSanss_H[] = {
    0x00 // placeholder - replace with actual font binary data
};
static const unsigned int OPPOSanss_H_size = sizeof(OPPOSanss_H);

// NOTE: To make this work properly, you must:
// 1. Obtain the OPPO Sans Heavy (OPPOSans-H.ttf) font file
// 2. Convert it to a C array using: xxd -i OPPOSans-H.ttf
// 3. Replace the placeholder array above with the generated data
// 4. Ensure the size variable matches

#endif // OPPOFONT_H
