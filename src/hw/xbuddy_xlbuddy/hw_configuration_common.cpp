/**
 * @file hw_configuration_common.cpp
 */

#include "hw_configuration_common.hpp"
#include "data_exchange.hpp"
#include "otp.hpp"
#include <device/hal.h>
#include <option/bootloader.h>
#include <option/custom_board_no_onewire_otp.h>

namespace buddy::hw {

ConfigurationCommon::ConfigurationCommon() {
    bom_id = otp_get_bom_id().value_or(0);
#if CUSTOM_BOARD_NO_ONEWIRE_OTP()
    // DIY boards often leave STM32 OTP blank; bom_id 0 trips "BOM ID not compatible".
    // 37 is the current xBuddy generation accepted by check_bom_compatible().
    if (bom_id == 0) {
        bom_id = 37;
    }
#endif
    bom_id_xlcd = data_exchange::get_xlcd_eeprom().bomID;
}

} // namespace buddy::hw
