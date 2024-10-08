#pragma once

#define ___ KC_NO

#undef LAYOUT
#define LAYOUT(            \
  K00, K01, K02, K03, K04, \
  K10, K11, K12, K13, K14, \
  K20, K21, K22, K23, K24, \
                 K30, K31, \
                           \
  K40, K41, K42, K43, K44, \
  K50, K51, K52, K53, K54, \
  K60, K61, K62, K63, K64, \
  K70, K71                 \
  ) {                                \
  { ___, K00, K01, K02, K03, K04 }, \
  { ___, K10, K11, K12, K13, K14 }, \
  { ___, K20, K21, K22, K23, K24 }, \
  { ___, ___, ___, K30, K31, ___ }, \
                                    \
  { K40, K41, K42, K43, K44, ___ }, \
  { K50, K51, K52, K53, K54, ___ }, \
  { K60, K61, K62, K63, K64, ___ }, \
  { ___, K70, K71, ___, ___, ___ }  \
}
