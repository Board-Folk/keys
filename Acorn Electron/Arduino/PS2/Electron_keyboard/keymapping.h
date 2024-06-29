
typedef struct {
  uint16_t noshift_1[Electron_KEYMAP_SIZE];
  uint16_t shift_1[Electron_KEYMAP_SIZE];
  uint16_t noshift_2[Electron_KEYMAP_SIZE];
  uint16_t shift_2[Electron_KEYMAP_SIZE];
} ElectronKeymap_t;

/* Maps are positional in relation to keyboard ASCII codes.

Each map has a normal (without shift) and shifted (with shift) array.

In situations where there is a shift difference, add 160 to the Electron key byte. 
This is when a key is shifted on keyboard, but not shifted on the Electron or vise-versa.

Unused ASCII codes need to have the IGNORE_KEYCODE value in place.(Default 340)

*/

const PROGMEM ElectronKeymap_t ElectronKeymap_main = {
  // map 1 without shift
   {340,340,340,340,340,340,  6,  6,// ASCII Codes 0x00 - 0x07
      2,  2,340,340,108,108,108,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340, 96,104, 92,// ASCII Codes 0x10 - 0x17
    100,340,340,  0,102,  4, 98,110,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340, 98,340,340,340,340,// ASCII Codes 0x28 - 0x2F
     80, 32, 16, 48,  8, 40, 24, 56,// ASCII Codes 0x30 - 0x37
     64, 72, 90, 70, 88, 78, 86,340,// ASCII Codes 0x38 - 0x3F
    340, 34, 46, 54, 50, 52, 10, 42,// ASCII Codes 0x40 - 0x47
     26, 68, 58, 66, 74, 62, 30, 76,// ASCII Codes 0x48 - 0x4F
     84, 36, 12, 18, 44, 60, 14, 20,// ASCII Codes 0x50 - 0x57
     22, 28, 38, 82,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F
    
  // map 1 with shift
   {340,340,340,340,340,340,  6,  6,// ASCII Codes 0x00 - 0x07
      2,  2,340,340,108,108,108,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340, 96,104, 92,// ASCII Codes 0x10 - 0x17
    100,340,340,  0,102,  4, 98,110,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340, 98,340,340,340,340,// ASCII Codes 0x28 - 0x2F
     80, 32, 16, 48,  8, 40, 24, 56,// ASCII Codes 0x30 - 0x37
     64, 72, 90, 70, 88, 78, 86,340,// ASCII Codes 0x38 - 0x3F
    340, 34, 46, 54, 50, 52, 10, 42,// ASCII Codes 0x40 - 0x47
     26, 68, 58, 66, 74, 62, 30, 76,// ASCII Codes 0x48 - 0x4F
     84, 36, 12, 18, 44, 60, 14, 20,// ASCII Codes 0x50 - 0x57
     22, 28, 38, 82,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F
    

  
  // Same for now....
  // map 2 without shift
   {340,340,340,340,340,340,340,340,// ASCII Codes 0x00 - 0x07
    340,340,340,340,340,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x10 - 0x17
    340,340,340,340,340,340,340,340,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x30 - 0x37
    340,340,340,340,340,340,340,340,// ASCII Codes 0x38 - 0x3F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x40 - 0x47
    340,340,340,340,340,340,340,340,// ASCII Codes 0x48 - 0x4F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x50 - 0x57
    340,340,340,340,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340},// ASCII Codes 0x88 - 0x8F
    
  // map 2 with shift
   {340,340,340,340,340,340,340,340,// ASCII Codes 0x00 - 0x07
    340,340,340,340,340,340,340,340,// ASCII Codes 0x08 - 0x0F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x10 - 0x17
    340,340,340,340,340,340,340,340,// ASCII Codes 0x18 - 0x1F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x20 - 0x27
    340,340,340,340,340,340,340,340,// ASCII Codes 0x28 - 0x2F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x30 - 0x37
    340,340,340,340,340,340,340,340,// ASCII Codes 0x38 - 0x3F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x40 - 0x47
    340,340,340,340,340,340,340,340,// ASCII Codes 0x48 - 0x4F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x50 - 0x57
    340,340,340,340,340,340,340,340,// ASCII Codes 0x58 - 0x5F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x60 - 0x67
    340,340,340,340,340,340,340,340,// ASCII Codes 0x68 - 0x6F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x70 - 0x77
    340,340,340,340,340,340,340,340,// ASCII Codes 0x78 - 0x7F
    340,340,340,340,340,340,340,340,// ASCII Codes 0x80 - 0x87
    340,340,340,340,340,340,340,340}// ASCII Codes 0x88 - 0x8F

};
