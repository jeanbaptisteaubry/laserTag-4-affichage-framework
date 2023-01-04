#include <Arduino.h> 
#include <TFT_eSPI.h>
#include <SPI.h>
#include <pgmspace.h>  

const uint8_t _img_eSprite_balleXAuto[] PROGMEM = {
  
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x39, 0xa7, 0x39, 0xa7, 0x39, 0xa7, 0x31, 0xa6, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xa5, 0x14, 0xa5, 0x14, 0xa5, 0x14, 0xc5, 0xf8, 0x8c, 0x71, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x73, 0xae, 0x63, 0x2c, 0x4a, 0x69, 0x29, 0x45, 0x08, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x21, 0xad, 0x75, 0x73, 0x6e, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x6a, 0x52, 0x8a, 0x63, 0x0c, 0x84, 0x10, 0xb5, 0x96, 0xb5, 0x96, 0x6b, 0x2d, 0x29, 0x45, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xad, 0x75, 0x31, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x62, 0x31, 0xa6, 0x84, 0x10, 0xc6, 0x18, 0x9c, 0xd3, 0x18, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xad, 0x75, 0x31, 0xa6, 0x08, 0x21, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x08, 0x41, 0x18, 0xa3, 0x39, 0xa7, 0x6b, 0x6d, 0xb5, 0xb6, 0xa4, 0xf4, 0x52, 0xaa, 0x08, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x21, 0x24, 0x21, 0x24, 0x29, 0x25, 0xb5, 0x96, 0xa5, 0x34, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0xa4, 0xf3, 0xb5, 0x96, 0xc6, 0x38, 0xad, 0x35, 0x6b, 0x2d, 0x29, 0x65, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xbd, 0xb7, 0xbd, 0xb7, 0xbd, 0xb6, 0xb5, 0xb6, 0x4a, 0x49, 0x31, 0xa6, 0x31, 0xa6, 0x31, 0xa6, 0x31, 0xa6, 0x31, 0x86, 0x29, 0x65, 0x18, 0xc3, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x61, 0x08, 0x61, 0x08, 0x61, 0x08, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x21, 0x6b, 0x2d, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x7b, 0xcf, 0x6b, 0x2d, 0x39, 0xc7, 0x18, 0xc3, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x10, 0xa2, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x41, 0xb5, 0xb6, 0x6b, 0x2d, 0x6b, 0x6d, 0xad, 0x55, 0x52, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x4a, 0x69, 0x6b, 0x2d, 0xa5, 0x14, 0xc6, 0x18, 0xc5, 0xf8, 0xc5, 0xf8, 0xc5, 0xf8, 0xc5, 0xf8, 0xc5, 0xf8, 0x63, 0x0c, 0x4a, 0x49, 0x4a, 0x49, 0x4a, 0x49, 0x4a, 0x49, 0x4a, 0x49, 0x41, 0xe8, 0x29, 0x45, 0x10, 0x82, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xa0, 0xbd, 0xb7, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xb2, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x18, 0xe3, 0xc6, 0x38, 0x29, 0x45, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xe3, 0xb5, 0x75, 0x94, 0xb2, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x84, 0x10, 0x8c, 0x31, 0x94, 0x92, 0xb5, 0x96, 0xbd, 0xd7, 0x83, 0xf0, 0x41, 0xe8, 0x10, 0x82, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xb3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xc6, 0x38, 0x10, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0xad, 0x75, 0x31, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x62, 0x29, 0x25, 0x5a, 0xab, 0xa4, 0xf4, 0xb5, 0x96, 0x6b, 0x4d, 0x10, 0x82, 
  0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xb3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xc6, 0x38, 0x10, 0xa2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xad, 0x75, 0x31, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x21, 0x18, 0xc3, 0x42, 0x28, 0x94, 0x92, 0xbd, 0xd7, 0x84, 0x10, 0x10, 0xa2, 
  0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xb3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xc6, 0x38, 0x20, 0xe4, 0x10, 0x62, 0x10, 0x62, 0x10, 0x82, 0xb5, 0x75, 0x84, 0x10, 0x6b, 0x2d, 0x6b, 0x2d, 0x6b, 0x2d, 0x6b, 0x2d, 0x6b, 0x4d, 0x7b, 0xaf, 0xa4, 0xf4, 0xc6, 0x18, 0x94, 0xb2, 0x52, 0x8a, 0x20, 0xe4, 0x00, 0x20, 0x00, 0x00, 
  0x08, 0x41, 0xb5, 0xb6, 0x5a, 0xcb, 0x62, 0xec, 0xad, 0x35, 0x39, 0xe7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x39, 0xc7, 0x52, 0x8a, 0x8c, 0x51, 0xc6, 0x18, 0xb5, 0xb6, 0xb5, 0x96, 0xb5, 0x96, 0xb5, 0x96, 0xc6, 0x18, 0x73, 0xae, 0x62, 0xec, 0x62, 0xec, 0x62, 0xec, 0x62, 0xec, 0x5a, 0xeb, 0x52, 0x8a, 0x39, 0xc7, 0x18, 0xe3, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x41, 0x84, 0x10, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x9c, 0xd3, 0x84, 0x10, 0x4a, 0x69, 0x29, 0x45, 0x21, 0x24, 0x21, 0x24, 0x21, 0x24, 0x21, 0x24, 0x21, 0x04, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x42, 0x08, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x39, 0xe7, 0x18, 0xc3, 0x08, 0x41, 0x08, 0x21, 0x08, 0x21, 
  0xf7, 0x36, 0xd3, 0x41, 0x00, 0x00, 0xf0, 0xe5, 0xff, 0xa0, 0x00, 0x00, 0xff, 0xa0, 0xb5, 0x60, 0x00, 0x00, 0xf7, 0x36, 0xb5, 0x60, 0x00, 0x00, 0x00, 0x00, 0xf7, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0xb5, 0xb6, 0x84, 0x30, 0x8c, 0x51, 0xb5, 0x96, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x73, 0x8e, 0x9c, 0xf3, 0xc5, 0xf8, 0xa5, 0x14, 0x9c, 0xd3, 0x9c, 0xd3, 
  0xf0, 0xe5, 0xfc, 0x05, 0xb5, 0x60, 0xd3, 0x41, 0xf0, 0xe5, 0xf7, 0x36, 0xf7, 0x36, 0xff, 0xa0, 0xf0, 0xe5, 0xff, 0xa0, 0xf7, 0x36, 0x00, 0x00, 0xfc, 0x05, 0xff, 0xa0, 0xb5, 0x60, 0xb5, 0x60, 0xf0, 0xe5, 0xff, 0xa0, 0xb5, 0xb6, 0x29, 0x65, 0x39, 0xa7, 0x9c, 0xb3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x21, 0x29, 0x45, 0xc6, 0x18, 0x42, 0x28, 0x39, 0xa7, 
  0xfc, 0x05, 0xff, 0xa0, 0xb5, 0x60, 0xf0, 0xe5, 0xff, 0xa0, 0xff, 0xa0, 0xdf, 0xa6, 0xf0, 0xe5, 0xff, 0xa0, 0xb5, 0x60, 0xf7, 0x36, 0xd3, 0x41, 0xd3, 0x41, 0xfc, 0x05, 0xf7, 0x36, 0xf0, 0xe5, 0xfc, 0x05, 0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xa7, 0x9c, 0xb3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xce, 0x39, 0x10, 0xa2, 0x00, 0x00, 
  0xdf, 0xa6, 0xf0, 0xe5, 0xb5, 0x60, 0xb5, 0x60, 0xdf, 0xa6, 0xfc, 0x05, 0xf0, 0xe5, 0xf0, 0xe5, 0xf0, 0xe5, 0xd3, 0x41, 0xd3, 0x41, 0xfc, 0x05, 0xb5, 0x60, 0xfc, 0x05, 0x00, 0x00, 0xff, 0xa0, 0xd3, 0x41, 0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xb2, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xce, 0x38, 0x10, 0xa2, 0x00, 0x00, 
  0xff, 0xa0, 0xf0, 0xe5, 0xf7, 0x36, 0xd3, 0x41, 0xfc, 0x05, 0xf7, 0x36, 0xf7, 0x36, 0xf0, 0xe5, 0xff, 0xa0, 0xf0, 0xe5, 0xdf, 0xa6, 0xb5, 0x60, 0xf0, 0xe5, 0xb5, 0x60, 0xfc, 0x05, 0x00, 0x00, 0xff, 0xa0, 0xff, 0xa0, 0xbd, 0xb6, 0x29, 0x65, 0x39, 0xc7, 0x9c, 0xd3, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc3, 0xce, 0x38, 0x10, 0xa2, 0x00, 0x00, 
  0xf0, 0xe5, 0xf0, 0xe5, 0xf7, 0x36, 0xf0, 0xe5, 0xf7, 0x36, 0xdf, 0xa6, 0x00, 0x00, 0xd3, 0x41, 0x00, 0x00, 0xfc, 0x05, 0xb5, 0x60, 0xf7, 0x36, 0x00, 0x00, 0xd3, 0x41, 0xf0, 0xe5, 0xf0, 0xe5, 0xfc, 0x05, 0xf7, 0x36, 0xb5, 0xb6, 0x41, 0xe8, 0x4a, 0x49, 0x9c, 0xf3, 0x18, 0xe3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x31, 0x66, 0x5a, 0xeb, 0xc6, 0x18, 0x8c, 0x30, 0x84, 0x10, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xa0, 0xf7, 0x36, 0x00, 0x00, 0xf0, 0xe5, 0xf0, 0xe5, 0x00, 0x00, 0xf7, 0x36, 0xf0, 0xe5, 0xb5, 0x60, 0xdf, 0xa6, 0xfc, 0x05, 0x00, 0x00, 0xfc, 0x05, 0x00, 0x00, 0xdf, 0xa6, 0x08, 0x41, 0xa5, 0x34, 0xbd, 0xd7, 0xbd, 0xf7, 0xbd, 0xf7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xbd, 0xd7, 0xad, 0x75, 0x83, 0xef, 0x52, 0x8a, 0x4a, 0x49, 0x4a, 0x49, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x82, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x10, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

   };

class eSprite_balleXAuto : public TFT_eSprite{

    private :
        int _width;
        int _height;
        
    public :
        eSprite_balleXAuto(TFT_eSPI *ecran) : TFT_eSprite (ecran)
        {
            setColorDepth(16);

        }

        void init()
        {
            setColorDepth(16);

            createSprite(38,31);
 
   
            pushImage(0, 0, 38,31, (uint16_t *)_img_eSprite_balleXAuto);
        }
};