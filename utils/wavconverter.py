import errno
from os import makedirs, path
import textwrap

with open('../resources/sounds/blip.wav', 'rb') as i:
  data = i.read()

header = """\
#ifndef BLIP_H
#define BLIP_H

#include <cstdint>
#include <vector>

static std::vector<std::uint8_t> blip = {
  %s
};
#endif /* BLIP_H */
""" % '\n\t'.join(
  textwrap.wrap(
    ', '.join('0x%02x' % ord(y) for y in data),
  79)
)

try:
  makedirs('../src/res/')
except OSError:
  pass

with open('../src/res/blip.h', 'w') as f:
  f.write(header)