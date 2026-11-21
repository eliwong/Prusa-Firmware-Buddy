#pragma once

#include "resources/revision.hpp"
#include <option/custom_board_no_onewire_otp.h>
#include <cstdint>

namespace buddy::resources {

bool has_resources(const Revision &revision);

bool bootstrap(const Revision &revision);

#if CUSTOM_BOARD_NO_ONEWIRE_OTP()
/// Last BBF search outcome for DIY splash text (Looking for BBF stuck at ~50%).
enum class DiyBbfHint : uint8_t {
    waiting_usb, ///< USB Host not mounted / no stick
    searching, ///< USB up, still scanning
    no_bbf, ///< USB up but no *.bbf at root
    digest_mismatch, ///< found .bbf but RESOURCES digest ≠ this firmware
};

DiyBbfHint diy_bbf_hint();
#endif

}; // namespace buddy::resources
