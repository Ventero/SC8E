#ifndef CHIP8_H
#define CHIP8_H

class chip8
{
public:
  // cpu variables
  std::uint16_t I;
  std::uint16_t opcode;
  std::uint16_t pc;
  std::uint16_t sp;
  std::array<std::uint16_t, 16>     stack;
  std::array<std::uint8_t,  4096>   memory;
  std::array<std::uint8_t,  16>     V;


  // timers
  std::uint8_t delay_timer;
  std::uint8_t sound_timer;

  // graphics variables
  std::array<std::uint8_t, (64 * 32)> gfx;
  bool drawFlag;

  // audio variable
  bool beep;

  // input variables
  std::array<std::uint8_t, 16> key;

  // font set
  std::array<std::uint8_t, 80> chip8_fontset{{
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
  }};

  chip8();
  bool loadGame(std::string);
  void emulateCycle();
  void setKeys(std::array<std::uint8_t, 16>);
  void debugRender();

};
#endif /* CHIP8_H */