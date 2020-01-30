// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <array>

#ifndef XCODE_APP_BUILD
#include <soundtouch/SoundTouch.h>
#else
#include "soundtouch/SoundTouch.h"
#endif

namespace AudioCommon
{
class AudioStretcher
{
public:
  explicit AudioStretcher(unsigned int sample_rate);
  void ProcessSamples(const short* in, unsigned int num_in, unsigned int num_out);
  void GetStretchedSamples(short* out, unsigned int num_out);
  void Clear();

private:
  unsigned int m_sample_rate;
  std::array<short, 2> m_last_stretched_sample = {};
  soundtouch::SoundTouch m_sound_touch;
  double m_stretch_ratio = 1.0;
};

}  // namespace AudioCommon
